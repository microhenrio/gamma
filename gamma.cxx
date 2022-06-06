/*
 * gamma.cxx
 * 
 * Copyright 2022  <hexentronics.com>
 * 	
 * User interface to communicate and configure the electronic
 * boardgame Helvetios (https://www.hexentronics.com/en/helvetios/)
 * 
 */
 
#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <gtk/gtk.h>
//#include <usb-1.0/usb.h>
#include <libusb-1.0/libusb.h>

using namespace std;

/**
 * @brief To manage the exit of the program
 */
void exit_handler (int ev, void *arg)
{
	printf("\nApadeu!\n");
}

int main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget  *window;
	//char *cwd = get_current_dir_name();
	//char path[256];
	
	//strcpy(path, cwd);
	//strcat(path,"/gamma_hmi.glade");
	//cout << "Current working directory: " << path << endl;
    //free(cwd);
    libusb_init(NULL);
    
	on_exit(exit_handler, NULL);										// on exit, a handler to make a safe stop

	gtk_init (&argc, &argv);											// pass arguments to gtk
	
	builder = gtk_builder_new_from_file ( "gamma_hmi.glade");//path );		// loads xml with hmi info
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

