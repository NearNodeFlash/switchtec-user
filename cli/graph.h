/*
 * Microsemi Switchtec(tm) PCIe Management Command Line Interface
 * Copyright (c) 2021, Microsemi Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define GRAPH_SHADE_MAX 16
#define GRAPH_SHADE_MASK	0x1F
#define GRAPH_SHADE_HIGHLIGHT  (1 << 5)

struct range;

typedef int graph_anim_fn(struct range *X, struct range *Y, int *data,
		int *shades, char *status, bool *redraw, void *opaque);

void graph_draw_text(struct range *X, struct range *Y, int *data,
		     const char *title, char x_title, char y_title);
int graph_draw_win(struct range *X, struct range *Y, int *data, int *shades,
		   const char *title, char x_title, char y_title, char *status,
		   graph_anim_fn *anim, void *opaque);

#endif
