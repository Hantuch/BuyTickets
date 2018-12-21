#include <gtk/gtk.h>
#include <stdio.h>
#include "main.h"

//signals.c contains callback functions which are called when certain event occurred
//the signaling mechanism itself is handled Gtk library and designed with glade

//Functions redeclaration
void hidetab();
void showtab();
void intsinopsistab();
void intseatwindow();
void intsummary();
void checkseating();

void on_film0_button_press_event()
{
    filmpil = 0;
    showtab(notebook,3);
    intsinopsistab(0);
    gtk_notebook_set_current_page(notebook, 3);
    return;
}

void on_film1_button_press_event()
{
    filmpil = 1;
    showtab(notebook,3);
    intsinopsistab(1);
    printf("hai");
    gtk_notebook_set_current_page(notebook, 3);
    return;
}

void on_film2_button_press_event()
{
    filmpil = 2;
    showtab(notebook,3);
    intsinopsistab(2);
    gtk_notebook_set_current_page(notebook, 3);
    return;
}

void on_film3_button_press_event()
{
    filmpil = 3;
    showtab(notebook,3);
    intsinopsistab(3);
    gtk_notebook_set_current_page(notebook, 3);
    return;
}

void on_schedule0_button_press_event()
{
    jadwalpil = 0;
    intseatwindow();
    return;
}

void on_schedule1_button_press_event()
{
    jadwalpil = 1;
    intseatwindow();
    return;
}

void on_schedule2_button_press_event()
{
    jadwalpil = 2;
    intseatwindow();
    return;
}

void on_schedule3_button_press_event()
{
    jadwalpil = 3;
    intseatwindow();
    return;
}

void on_button_continue_clicked()
{

    char seating[20] = {0};

    toggle_button[0] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A1"));
    toggle_button[1] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A2"));
    toggle_button[2] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B1"));
    toggle_button[3] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B2"));

    for(i=0;i<4;i++)
    {
        if(gtk_toggle_button_get_active(toggle_button[i]) == TRUE){seat[i].status = 1; ticket++;}
        else{seat[i].status = 0;}
    }


    gtk_widget_hide(window1);
    showtab(notebook,4);
    gtk_notebook_set_current_page(notebook,4);
    hidetab(notebook,0);
    hidetab(notebook,1);
    hidetab(notebook,3);
    checkseating(seating);
    intsummary(seating);
    return;
}

void on_button_cancel_clicked()
{
    toggle_button[0] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A1"));
    toggle_button[1] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A2"));
    toggle_button[2] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B1"));
    toggle_button[3] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B2"));

    for(i=0;i<4;i++)
    {
        gtk_toggle_button_set_active(toggle_button[i],FALSE);
    }

    gtk_widget_hide(window1);
    return;
}

void on_button_summary_continue_clicked() //Incomplete
{
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "windowsuccess"));
    gtk_widget_show(window2);
}

void on_button_summary_cancel_clicked() //Incomplete
{
    toggle_button[0] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A1"));
    toggle_button[1] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A2"));
    toggle_button[2] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B1"));
    toggle_button[3] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B2"));

    hidetab(notebook,4);
    showtab(notebook,0);
    showtab(notebook,1);
    gtk_notebook_set_current_page(notebook,0);

    ticket = 0;
    filmpil = 0;
    jadwalpil = 0;

    for(i=0;i<4;i++)
    {
        gtk_toggle_button_set_active(toggle_button[i], FALSE);
    }
    return;
}

void on_button_success_clicked()
{
    toggle_button[0] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A1"));
    toggle_button[1] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_A2"));
    toggle_button[2] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B1"));
    toggle_button[3] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "toggle_B2"));

    gtk_widget_hide(window2);
    hidetab(notebook,4);
    showtab(notebook,0);
    showtab(notebook,1);
    gtk_notebook_set_current_page(notebook,0);

    ticket = 0;
    filmpil = 0;
    jadwalpil = 0;

    for(i=0;i<4;i++)
    {
        gtk_toggle_button_set_active(toggle_button[i], FALSE);
    }
    return;
}

void on_tab_hide_check()
{
    int page = gtk_notebook_get_current_page(notebook);
    if(page == 3)
    {
        hidetab(notebook, 3);
    }
    printf("%d", page);
    return;
}

void on_window_destroy()
{
    gtk_main_quit();
    return;
}
