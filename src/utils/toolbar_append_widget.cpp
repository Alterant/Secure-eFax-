/* Copyright (C) 2006 Chris Vine

The library comprised in this file or of which this file is part is
distributed by Chris Vine under the GNU Lesser General Public
License as follows:

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License, version 2.1, for more details.

   You should have received a copy of the GNU Lesser General Public
   License, version 2.1, along with this library (see the file LGPL.TXT
   which came with this source code package in the src/utils sub-directory);
   if not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA, 02111-1307, USA.

*/

#include <gtk/gtkversion.h>
#if GTK_CHECK_VERSION(2,4,0)
#include <gtk/gtktoolitem.h>
#include <gtk/gtktooltips.h>
#include <gtk/gtkcontainer.h>
#endif

#include "toolbar_append_widget.h"


void toolbar_append_widget(GtkToolbar* toolbar_p, GtkWidget* widget_p,
			   const char* tooltip_text_p, const char* tooltip_private_text_p) {

#if GTK_CHECK_VERSION(2,4,0)
  GtkToolItem* toolitem_p = gtk_tool_item_new();
  gtk_container_add(GTK_CONTAINER(toolitem_p), widget_p);
  // this is OK as tooltips is a public member of GtkToolbar
  gtk_tool_item_set_tooltip(toolitem_p, toolbar_p->tooltips, tooltip_text_p, tooltip_private_text_p);
  gtk_toolbar_insert(toolbar_p, toolitem_p, -1);
#else
  gtk_toolbar_append_widget(toolbar_p, widget_p, tooltip_text_p, tooltip_private_text_p);
#endif
}