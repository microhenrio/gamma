/*
 * gamma.cxx
 * 
 * Copyright 2022  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <gtk/gtk.h>

using namespace std;

int main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget  *window;
	std::cout << "Hello World2!" <<  std::endl;
	
	gtk_init (&argc, &argv);											// pass arguments to gtk
	
	builder = gtk_builder_new_from_file ("gamma_hmi.glade");		// loads xml with hmi info
	/* Connect signal handlers to the constructed widgets. */
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	//gtk_builder_connect_signals(builder, NULL); 						//To connect the signals defined in the .glade, but signals callbacks are already defined in code
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);	// callback to close the window
	
	//-------- SHOW WINDOW --------//
	//g_object_unref(builder);//???????
	gtk_widget_show(window);
	gtk_main ();
	
	return 0;
}

