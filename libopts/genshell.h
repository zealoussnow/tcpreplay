/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (genshell.h)
 *  
 *  It has been AutoGen-ed  Monday February 14, 2005 at 08:42:37 AM PST
 *  From the definitions    genshell.def
 *  and the template file   options
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the genshellopt program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_GENSHELL_H_GUARD
#define AUTOOPTS_GENSHELL_H_GUARD

/*
 * genshellopt copyright 1999-2005 Bruce Korb - all rights reserved
 *
 * genshellopt is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * genshellopt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with genshellopt; if not, write to:
 *            The Free Software Foundation, Inc.,
 *            59 Temple Place - Suite 330,
 *            Boston,  MA  02111-1307, USA.
 */
#include <autoopts/options.h>

/*
 *  Enumeration of each option:
 */
typedef enum {
        INDEX_OPT_SCRIPT           =  0,
        INDEX_OPT_SHELL            =  1,
        INDEX_OPT_VERSION          = 2,
        INDEX_OPT_HELP             = 3,
        INDEX_OPT_MORE_HELP        = 4
} teOptIndex;

#define OPTION_CT    5
#define GENSHELLOPT_VERSION       "1"
#define GENSHELLOPT_FULL_VERSION  "genshellopt - Generate Shell Option Processing Script - Ver. 1"

/*
 *  Interface defines for all options.  Replace "n" with
 *  the UPPER_CASED option name (as in the teOptIndex
 *  enumeration above).  e.g. HAVE_OPT( SCRIPT )
 */
#define         DESC(n) genshelloptOptions.pOptDesc[INDEX_OPT_ ## n]
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).pzLastArg)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT;   \
                if ( (DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/*
 *  Interface defines for specific options.
 */
#define VALUE_OPT_SCRIPT         'o'
#define VALUE_OPT_SHELL          's'

#define VALUE_OPT_VERSION       'v'
#define VALUE_OPT_HELP          '?'
#define VALUE_OPT_MORE_HELP     '!'

/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS( genshelloptOptions.fOptSet &= ~OPTPROC_ERRSTOP )
#define ERRSTOP_OPTERR  STMTS( genshelloptOptions.fOptSet |= OPTPROC_ERRSTOP )
#define RESTART_OPT(n)  STMTS( \
                genshelloptOptions.curOptIdx = (n); \
                genshelloptOptions.pzCurOpt  = NULL )
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*genshelloptOptions.pUsageProc)( &genshelloptOptions, c )
/* extracted from opthead.tpl near line 247 */

/* * * * * *
 *
 *  Declare the genshellopt option descriptor.
 */
#ifdef  __cplusplus
extern "C" {
#endif

extern tOptions   genshelloptOptions;

#ifndef _
#  if ENABLE_NLS
#    include <stdio.h>
     static inline char* aoGetsText( const char* pz ) {
         if (pz == NULL) return NULL;
         return (char*)gettext( pz );
     }
#    define _(s)  aoGetsText(s)
#  else  /* ENABLE_NLS */
#    define _(s)  s
#  endif /* ENABLE_NLS */
#endif

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_GENSHELL_H_GUARD */
