#include <gtk/gtk.h>

int main (int argc, char **argv) {
  gtk_init(&argc,&argv);
  // Init window.
  GtkWidget* window;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // Makes window visible for users.
  gtk_widget_show_all(window);
  // Lets the user close the window if "destroy" signal is TRUE.
  g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit) , NULL);
  gtk_main();

  return 0;
}
