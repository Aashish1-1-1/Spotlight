#include <gtk/gtk.h>

static void toggle_button_clicked(GtkToggleButton *toggle_button, gpointer user_data) {
  gboolean is_active = gtk_toggle_button_get_active(toggle_button);
  if (is_active) {
    g_print("Spotlight is active.\n");
  } else {
    g_print("Spotlight is inactive\n");
  }
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Spotlight");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  GtkWidget *toggle_button = gtk_toggle_button_new_with_label("Click to activate");
  g_signal_connect(toggle_button, "toggled", G_CALLBACK(toggle_button_clicked), NULL);
  gtk_container_add(GTK_CONTAINER(window), toggle_button);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
