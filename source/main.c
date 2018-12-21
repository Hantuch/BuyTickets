#include <gtk/gtk.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

//Kelompok 13
//Hanif Rachmadani - 1606870774
//Ahmad Aufar Husaini - 1606904730

//Buy Tickets! - Improved Ticketing App with Gtk GUI - 18/12/18
//Link Github : https://github.com/Hantuch/BuyTickets

//Codes are divided into 3 source code files - main.c signals.c & misc.c

//main.c contains the main function and multiple initializer functions
//signals.c contains signaling functions which are called by GUI
//misc.c contains supporting functions such as read function, PixBuff creator function, etc.

//All of these source code files are compiled through a makefile located in the root folder
//last edit : 22/12/2018

struct film //Struct for each film
{
    char judul[40];
    char sinopsis[2][50];
    char jadwal[4][10];
}film[4];

struct seat //Struct for the seating array
{
    char position[3];
    int status;
}seat[4];

GdkPixbuf *create_pixbuf(const gchar * filename);  //Create a Pixel Buffer from image
int price();                                       //Calculate the Total Payment Based on Date
void intfilmtab();                                 //Initialize The Film Tab
void intscheduletab();                             //Initialize Schedule Tab
void intsinopsistab();                             //Initialize Sinopsis Tab (based on chosen film)
void intseatwindow();                              //Initialize the Seating Layout Window
void intsummary();                                 //Initialize the Summary Tab based on collected info
void hidetab();                                    //Hide a Tab
void showtab();                                    //Show a Tab
void readFilm();                                   //Read The Films from a File
void readJadwal();                                 //Read the Schedules from a File
void readSinopsis();                               //Read the Sinopsis from a File
void checkseating();                               //Check Seating Status and Concatenate its Position into a String

char jadwallong[4][40];                            //Long strings of schedules cobbled up for each film
int ticket = 0;                                    //Number of tickets bought
int i, filmpil, jadwalpil;                         //Chosen Film/Schedule & Counter

GtkNotebook *notebook;                             //Notebook Widget (the one with tabs)
GtkWidget *window0;                                //Main Window
GtkWidget *window1;                                //Seating Window
GtkWidget *window2;                                //Success Window
GtkBuilder *builder;                               //Builder for .Glade file
GtkToggleButton *toggle_button[4];                 //Toggle Widget in Seating Window

int main(int argc, char** argv)
{
   strcpy(seat[0].position,"A1 ");
   seat[0].status = 0;
   strcpy(seat[1].position,"A2 ");
   seat[1].status = 0;
   strcpy(seat[2].position,"B1 ");
   seat[2].status = 0;
   strcpy(seat[3].position,"B2 ");
   seat[3].status = 0;

   readFilm();
   readJadwal();
   readSinopsis();
   gtk_init(&argc, &argv);

   builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "glade/testmainmenu.glade", NULL);

   window0 = GTK_WIDGET(gtk_builder_get_object(builder, "windowmain"));
   notebook = GTK_NOTEBOOK((gtk_builder_get_object(builder,"Menu")));

   gtk_builder_connect_signals(builder, NULL);

   hidetab(notebook, 3);
   hidetab(notebook, 4);
   intfilmtab();
   intscheduletab();

   gtk_widget_show(window0);
   gtk_main();
   return 0;
}

void intfilmtab()
{
    GtkWidget *g_label_film0;
    GtkWidget *g_label_film1;
    GtkWidget *g_label_film2;
    GtkWidget *g_label_film3;
    GtkImage *imgfilm0;
    GtkImage *imgfilm1;
    GtkImage *imgfilm2;
    GtkImage *imgfilm3;
    GdkPixbuf *img_film0;
    GdkPixbuf *img_film1;
    GdkPixbuf *img_film2;
    GdkPixbuf *img_film3;

    img_film0 = create_pixbuf("img/film0.png");
    img_film1 = create_pixbuf("img/film1.png");
    img_film2 = create_pixbuf("img/film2.png");
    img_film3 = create_pixbuf("img/film3.png");
    imgfilm0 = GTK_IMAGE(gtk_builder_get_object(builder,"img_film0"));
    imgfilm1 = GTK_IMAGE(gtk_builder_get_object(builder,"img_film1"));
    imgfilm2 = GTK_IMAGE(gtk_builder_get_object(builder,"img_film2"));
    imgfilm3 = GTK_IMAGE(gtk_builder_get_object(builder,"img_film3"));
    gtk_image_set_from_pixbuf(imgfilm0,img_film0);
    gtk_image_set_from_pixbuf(imgfilm1,img_film1);
    gtk_image_set_from_pixbuf(imgfilm2,img_film2);
    gtk_image_set_from_pixbuf(imgfilm3,img_film3);
    g_label_film0 = GTK_WIDGET(gtk_builder_get_object(builder,"label_film0"));
    gtk_label_set_text(GTK_LABEL(g_label_film0), film[0].judul);
    g_label_film1 = GTK_WIDGET(gtk_builder_get_object(builder,"label_film1"));
    gtk_label_set_text(GTK_LABEL(g_label_film1), film[1].judul);
    g_label_film2 = GTK_WIDGET(gtk_builder_get_object(builder,"label_film2"));
    gtk_label_set_text(GTK_LABEL(g_label_film2), film[2].judul);
    g_label_film3 = GTK_WIDGET(gtk_builder_get_object(builder,"label_film3"));
    gtk_label_set_text(GTK_LABEL(g_label_film3), film[3].judul);

    return;
}

void intscheduletab()
{
    GtkWidget *g_label_title_film0;
    GtkWidget *g_label_title_film1;
    GtkWidget *g_label_title_film2;
    GtkWidget *g_label_title_film3;
    GtkWidget *g_label_schedule_film0;
    GtkWidget *g_label_schedule_film1;
    GtkWidget *g_label_schedule_film2;
    GtkWidget *g_label_schedule_film3;

    g_label_title_film0 = GTK_WIDGET(gtk_builder_get_object(builder,"label_title_film0"));
    gtk_label_set_text(GTK_LABEL(g_label_title_film0), film[0].judul);
    g_label_title_film1 = GTK_WIDGET(gtk_builder_get_object(builder,"label_title_film1"));
    gtk_label_set_text(GTK_LABEL(g_label_title_film1), film[1].judul);
    g_label_title_film2 = GTK_WIDGET(gtk_builder_get_object(builder,"label_title_film2"));
    gtk_label_set_text(GTK_LABEL(g_label_title_film2), film[2].judul);
    g_label_title_film3 = GTK_WIDGET(gtk_builder_get_object(builder,"label_title_film3"));
    gtk_label_set_text(GTK_LABEL(g_label_title_film3), film[3].judul);
    g_label_schedule_film0 = GTK_WIDGET(gtk_builder_get_object(builder,"label_schedule_film0"));
    gtk_label_set_text(GTK_LABEL(g_label_schedule_film0), jadwallong[0]);
    g_label_schedule_film1 = GTK_WIDGET(gtk_builder_get_object(builder,"label_schedule_film1"));
    gtk_label_set_text(GTK_LABEL(g_label_schedule_film1), jadwallong[1]);
    g_label_schedule_film2 = GTK_WIDGET(gtk_builder_get_object(builder,"label_schedule_film2"));
    gtk_label_set_text(GTK_LABEL(g_label_schedule_film2), jadwallong[2]);
    g_label_schedule_film3 = GTK_WIDGET(gtk_builder_get_object(builder,"label_schedule_film3"));
    gtk_label_set_text(GTK_LABEL(g_label_schedule_film3), jadwallong[3]);

    return;
}

void intsinopsistab(int n)
{
    GtkWidget *g_label_film_title;
    GtkWidget *g_label_film_sinopsis0;
    GtkWidget *g_label_film_sinopsis1;
    GtkWidget *g_label_film_schedule0;
    GtkWidget *g_label_film_schedule1;
    GtkWidget *g_label_film_schedule2;
    GtkWidget *g_label_film_schedule3;
    GtkImage *g_img_film_poster;
    GdkPixbuf *img_film_poster;

    g_label_film_title = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_title"));
    gtk_label_set_text(GTK_LABEL(g_label_film_title), film[n].judul);
    g_label_film_sinopsis0 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_sinopsis0"));
    gtk_label_set_text(GTK_LABEL(g_label_film_sinopsis0), film[n].sinopsis[0]);
    g_label_film_sinopsis1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_sinopsis1"));
    gtk_label_set_text(GTK_LABEL(g_label_film_sinopsis1), film[n].sinopsis[1]);
    g_label_film_schedule0 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_schedule0"));
    gtk_label_set_text(GTK_LABEL(g_label_film_schedule0), film[n].jadwal[0]);
    g_label_film_schedule1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_schedule1"));
    gtk_label_set_text(GTK_LABEL(g_label_film_schedule1), film[n].jadwal[1]);
    g_label_film_schedule2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_schedule2"));
    gtk_label_set_text(GTK_LABEL(g_label_film_schedule2), film[n].jadwal[2]);
    g_label_film_schedule3 = GTK_WIDGET(gtk_builder_get_object(builder, "label_film_schedule3"));
    gtk_label_set_text(GTK_LABEL(g_label_film_schedule3), film[n].jadwal[3]);

    switch(n)
    {
        case 0 :
            img_film_poster = create_pixbuf("img/mediumfilm0.png");
            g_img_film_poster = GTK_IMAGE(gtk_builder_get_object(builder, "img_film_poster"));
            gtk_image_set_from_pixbuf(g_img_film_poster, img_film_poster);
            break;
        case 1 :
            img_film_poster = create_pixbuf("img/mediumfilm1.png");
            g_img_film_poster = GTK_IMAGE(gtk_builder_get_object(builder, "img_film_poster"));
            gtk_image_set_from_pixbuf(g_img_film_poster, img_film_poster);
            break;
        case 2 :
            img_film_poster = create_pixbuf("img/mediumfilm2.png");
            g_img_film_poster = GTK_IMAGE(gtk_builder_get_object(builder, "img_film_poster"));
            gtk_image_set_from_pixbuf(g_img_film_poster, img_film_poster);
            break;
        case 3 :
            img_film_poster = create_pixbuf("img/mediumfilm3.png");
            g_img_film_poster = GTK_IMAGE(gtk_builder_get_object(builder, "img_film_poster"));
            gtk_image_set_from_pixbuf(g_img_film_poster, img_film_poster);
            break;
    }
    return;
}

void intseatwindow()
{
    window1 = GTK_WIDGET(gtk_builder_get_object(builder,"windowseat"));
    gtk_widget_show(window1);
    return;
}

void intsummary(char seating[])
{
    char tickets[4] = {0}, prices[20] = {0};

    sprintf(tickets,"%d",ticket);
    sprintf(prices,"Rp %d",price(ticket));

    GtkWidget *g_label_summary_title;
    GtkWidget *g_label_summary_schedule;
    GtkWidget *g_label_summary_ticket;
    GtkWidget *g_label_summary_seating;
    GtkWidget *g_label_summary_price;

    g_label_summary_title = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_title"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_title), film[filmpil].judul);
    g_label_summary_schedule = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_schedule"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_schedule), film[filmpil].jadwal[jadwalpil]);
    g_label_summary_ticket = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_ticket"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_ticket), tickets);
    g_label_summary_seating = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_seating"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_seating),seating);
    g_label_summary_price = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_price"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_price),prices);

    return;
}
