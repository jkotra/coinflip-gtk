#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include <stdbool.h>

void on_about_dialog_delete_event(GtkWidget *about, gpointer userdata)
{
    /* This hides `about` window on exit button press aka also called destroy or delete event.
       Note!: `After` attribute must be checked for this signal in glade.Refer https://developer.gnome.org/gobject/stable/gobject-Signals.html#g-signal-connect-after */
    gtk_widget_hide_on_delete(about);
}

void on_about_btn_clicked(GtkButton *about_btn, GtkAboutDialog *about)
{

    GdkPixbuf *about_logo = gdk_pixbuf_new_from_resource_at_scale("/com/github/jkotra/coinflip/images/cointoss.svg", -1, 128, true, NULL);
    gtk_about_dialog_set_logo(about, about_logo);

    gtk_widget_show(GTK_WIDGET(about));
}

void on_generate_btn_clicked(GtkButton *generate_btn, GtkLabel *coin_side)
{

    /* this function generates random number and sets label accordingly >50=Heads else Tails */

    int randInt = (rand() % 100) + 1;   //random int between 0 and 100
    g_message("randInt = %d", randInt); // print to stdout.

    if (randInt > 50)
    {
        gtk_label_set_text(coin_side, (gchar *)"Heads");
    }
    else
    {
        gtk_label_set_text(coin_side, (gchar *)"Tails");
    }
}

static void activate(GtkApplication *app, gpointer user_data)
{

    /* builder to retrive objects */
    GtkBuilder *builder;

    /* Main window (GtkApplicationwindow) */
    GtkWindow *window;

    gtk_window_set_icon_name(GTK_WINDOW(window), "com.github.jkotra.coinflip");

    /* load builder from gresource */
    builder = gtk_builder_new_from_resource("/com/github/jkotra/coinflip/ui/coinflip.glade");

    //get `window` object and add to it to application (`app`)
    window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
    gtk_application_add_window(app, window);

    //connect signals
    gtk_builder_connect_signals(builder, NULL);

    // show window on screen.
    gtk_window_present(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.github.jkotra.coinflip", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
