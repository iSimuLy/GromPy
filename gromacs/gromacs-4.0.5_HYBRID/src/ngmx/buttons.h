/*
 * $Id: buttons.h,v 1.9 2003/11/17 21:51:14 spoel Exp $
 * 
 *                This source code is part of
 * 
 *                 G   R   O   M   A   C   S
 * 
 *          GROningen MAchine for Chemical Simulations
 * 
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 * 
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 * 
 * For more info, check our website at http://www.gromacs.org
 * 
 * And Hey:
 * Gyas ROwers Mature At Cryogenic Speed
 */

#ifndef _buttons_h
#define _buttons_h

#include <xutil.h>

enum { 
  IDROTX,IDROTY,IDROTZ,IDTRANSX,IDTRANSY,IDTRANSZ,IDZOOM,IDBUTNR,
  IDREWIND,IDSTEP,IDFF,IDSTOP_ANI,IDNR,
  IDDRAWMOL,IDLABEL
  };

#define AIR      3            /* extra space between child windows */
#define BORDER  1

#define EnterLeave (EnterWindowMask | LeaveWindowMask)

typedef struct {
  t_windata wd;
  int       ID;
} t_mwbut;

typedef struct {
  t_windata wd;
  int       nbut;
  t_mwbut   *b;
} t_butbox;

extern t_butbox *init_vbox(t_x11 *x11,Window Parent,Window SendTo,
			   unsigned long fg,unsigned long bg);

extern void set_vbtime(t_x11 *x11,t_butbox *vbox,char *text);

extern t_butbox *init_bbox(t_x11 *x11,Window Parent,Window SendTo,
			   int width,unsigned long fg,unsigned long bg);

extern void show_but(t_x11 *x11,t_butbox *bbox);

extern void hide_but(t_x11 *x11,t_butbox *bbox);

extern void done_bbox(t_x11 *x11,t_butbox *bbox);

#endif
