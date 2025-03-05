// Libraries and macros are defined.
#include <gtk/gtk.h>
// Prototype of functions are defined.
void printMessage1(GtkWidget *widget, gpointer data);
void printMessage2(GtkWidget *widget, gpointer data);
// Main function is defined.
int main (int argc, char **argv) {
  gtk_init(&argc, &argv);
   // Window is init.
  GtkWidget* window;
  // Window will appear as a toplevel.
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // Create a container to hold both buttons
  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  // Window will be shown in user's GI.
  gtk_widget_show_all(window);
  // if "destroy" is true, then the user exits from the window.
  g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit), NULL);
  // First button is created.
  GtkWidget* button;
  button = gtk_button_new_with_label("Button (1)");
  g_signal_connect(button,"clicked",G_CALLBACK(printMessage1), NULL);
  gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
  // Second button
  GtkWidget* button_2;
  button_2 = gtk_button_new_with_label("Button (2)");
  g_signal_connect(button_2,"clicked",G_CALLBACK(printMessage2), NULL);
  gtk_box_pack_start(GTK_BOX(box), button_2, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window),box);
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}
// Functions are defined.
void printMessage1(GtkWidget *widget, gpointer data){
  g_print("You clicked the (1) first button!\n");

  return;
}
void printMessage2(GtkWidget *widget, gpointer data){
  g_print("You clicked the (2) second button!\n");
  return;
}
