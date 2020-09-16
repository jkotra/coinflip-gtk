static void activate(GtkApplication *app, gpointer user_data);
void on_generate_btn_clicked(GtkButton *generate_btn, GtkLabel *coin_side);
void on_about_btn_clicked (GtkButton *about_btn, gpointer userdata);
void on_about_dialog_delete_event (GtkWidget *about, gpointer userdata);
void on_about_dialog_focus_out_event(GtkButton *about_btn, gpointer userdata);