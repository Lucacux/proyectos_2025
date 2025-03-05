// Libraries and functions are included.
#include <gtk/gtk.h>
// Main function
// Function prototypes
void printMessage(GtkWidget *widget, gpointer data);
// Main function
int main (int argc, char **argv) {
  gtk_init(&argc, &argv);
  // A window is init
  GtkWidget* window;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // Window is shown to the user.
  gtk_widget_show_all(window);
  // Lets the user eliminate the window
  g_signal_connect(window,"destroy", G_CALLBACK(gtk_main_quit), NULL);
  // A button is init
  GtkWidget* button;
  // Label of button
  button = gtk_button_new_with_label("Click on me!");
  // Message is a function defined to use gprint in GTK
  g_signal_connect(button,"clicked", G_CALLBACK(printMessage), NULL);
  gtk_container_add(GTK_CONTAINER(window),button);
  // Button and window are shown at the same time.
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
void printMessage(GtkWidget *widget, gpointer data){
  g_print("Hello world!\n");

  return;
}
