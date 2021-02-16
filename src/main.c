#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include <stdbool.h>

void on_about_btn_clicked(GtkButton *about_btn, gpointer user_data)
{
    GtkWidget* about = gtk_about_dialog_new();

    gtk_about_dialog_set_program_name(about, "coinflip");
    gtk_about_dialog_set_version(about, "0.02");
    gtk_about_dialog_set_website(about, "https://stdin.top/");
    
    GdkPixbuf *about_logo = gdk_texture_new_from_resource("/com/github/jkotra/coinflip/images/com.github.jkotra.coinflip.svg");

    gtk_about_dialog_set_logo(about, GDK_PAINTABLE(about_logo));
    g_object_unref(about_logo);

    gtk_about_dialog_set_license_type(about, GTK_LICENSE_GPL_3_0);

    const char *authors[] = {"Jagadeesh Kotra", NULL};
    gtk_about_dialog_set_authors(about, authors);

    gtk_window_present(about);
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


    /* load builder from gresource */
    builder = gtk_builder_new_from_resource("/com/github/jkotra/coinflip/ui/coinflip.ui");

    //get `window` object and add to it to application (`app`)
    window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
    gtk_window_set_icon_name(GTK_WINDOW(window), "com.github.jkotra.coinflip");
    gtk_application_add_window(app, window);

    //connect signals
    //gtk_builder_connect_signals(builder, NULL);

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
