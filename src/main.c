#include "include/main.h"
#include <gtk/gtk.h>
#include <pthread.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication* app,gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Spotlight");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
  button = gtk_button_new_with_label ("Press s to activate");
  gtk_window_set_child (GTK_WINDOW (window), button);

  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc,char **argv)
{
  pthread_t gated;
  if (pthread_create(&gated, NULL, gatekeeper, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
  }
  GtkApplication *app;
  int status;
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  offSpot();
  return status;
}

