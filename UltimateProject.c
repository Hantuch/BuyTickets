#include <gtk/gtk.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//Hanif Rachmadani - 1606870774
//Ahmad Aufar Husaini - 1606904730

//Buy Tickets! - Improved Ticketing App with Gtk GUI - 18/12/18

//Mohon maaf harusnya kodingannya dibagi 2 source file, yang function signaling dan Initializing
//Tapi saya kurang tahu cara buat makefile
//Jadi ini fungsiya saya grouping serapi mungkin

struct film
{
    char judul[40];
    char sinopsis[2][50];
    char jadwal[4][10];
}film[4];

struct seat
{
    char position[2];
    int status;
}seat[4];

char jadwallong[4][40];
int ticket = 0;
int i, filmpil, jadwalpil;

GtkNotebook *notebook;
GtkWidget *window0;
GtkWidget *window1;
GtkWidget *window2;
GtkBuilder *builder;

GdkPixbuf *create_pixbuf(const gchar * filename);
int price();
void intfilmtab();
void intscheduletab();
void intsinopsistab();
void intseatwindow();
void intsummary();
void hidetab();
void showtab();
void readFilm();
void readJadwal();
void readSinopsis();

int main(int argc, char** argv)
{
   strcpy(seat[0].position,"A1");
   seat[0].status = 0;
   strcpy(seat[1].position,"A2");
   seat[1].status = 0;
   strcpy(seat[2].position,"B1");
   seat[2].status = 0;
   strcpy(seat[3].position,"B2");
   seat[3].status = 0;

   readFilm();
   readJadwal();
   readSinopsis();
   gtk_init(&argc, &argv);

   builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "testmainmenu.glade", NULL);

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

void intsummary()
{
    char tickets[4] = {0}, prices[20] = {0};

    sprintf(tickets,"%d",ticket);
    sprintf(prices,"Rp %d",price(ticket));

    GtkWidget *g_label_summary_title;
    GtkWidget *g_label_summary_schedule;
    GtkWidget *g_label_summary_ticket;
    //GtkWidget *g_label_summary_seating; (unfinished)
    GtkWidget *g_label_summary_price;

    g_label_summary_title = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_title"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_title), film[filmpil].judul);
    g_label_summary_schedule = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_schedule"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_schedule), film[filmpil].jadwal[jadwalpil]);
    g_label_summary_ticket = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_ticket"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_ticket), tickets);
    //g_label_summary_seating = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_seating")); (unfinished)
    //gtk_label_set_text(GTK_LABEL(g_label_summary_seating),seating); (unfinished)
    g_label_summary_price = GTK_WIDGET(gtk_builder_get_object(builder,"label_summary_price"));
    gtk_label_set_text(GTK_LABEL(g_label_summary_price),prices);

    return;
}

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
    GtkToggleButton *toggle_button[4];

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
    hidetab(notebook,2);
    hidetab(notebook,3);
    intsummary();
    return;
}

void on_button_cancel_clicked()
{
    GtkToggleButton *toggle_button[4];
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
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "windowcomplete"));


}

void on_button_summary_cancel_clicked() //Incomplete
{


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

void hidetab(GtkNotebook *Notebook, int tabnumber)
{
    GtkWidget *tab;
    tab = gtk_notebook_get_nth_page(Notebook, tabnumber);
    gtk_widget_hide(tab);
    return;
}

void showtab(GtkNotebook *Notebook, int tabnumber)
{
    GtkWidget *tab;
    tab = gtk_notebook_get_nth_page(Notebook,tabnumber);
    gtk_widget_show(tab);
    return;
}

int price(int jumlah)
{
	time_t rawtime;
	struct tm *info;

	char day[2];

	time( &rawtime );
	info = localtime( &rawtime );
	strftime(day,2,"%w", info);

	switch(day[0])
	{
		case '0' : case '6' :
			return 60000*jumlah;
			break;
		case '1' : case '2' : case '3' : case '4' : case '5' :
			return 40000*jumlah;
			break;
	}
	return 0;
}

GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);

   if(!pixbuf)
   {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
   }
   return pixbuf;
}

void readFilm() //Reads the List of Films from text
{
	int i= 0;
	FILE *ptrfile;

	ptrfile = fopen("data/ListFilm.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(film[i].judul, 40, ptrfile) != NULL)
		{
			film[i].judul[strcspn(film[i].judul, "\n")] = 0;
			i++;
		}
	}
	fclose(ptrfile);
	return;
}

void readJadwal() //Reads the schedule from text
{
    int i = 0, j = 0;
	FILE *ptrfile;

	ptrfile = fopen("data/Jadwal.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(jadwallong[i], 40, ptrfile) != NULL)
		{
			jadwallong[i][strcspn(jadwallong[i], "\n")] = 0;
			i++;
		}
	}
	fclose(ptrfile);

	for(i=0;i<4;i++)
    {
		sscanf(jadwallong[i], "%s %s %s %s", film[i].jadwal[j], film[i].jadwal[j+1], film[i].jadwal[j+2], film[i].jadwal[j+3]);
	}
	return;
}

void readSinopsis() //Reads the sinopsis from text
{
	char temp[8][50];
	int i= 0, j=0, k;
	FILE *ptrfile;
	ptrfile = fopen("data/Sinopsis.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(temp[i], 50, ptrfile) != NULL)
		{
			temp[i][strcspn(temp[i], "\n")] = 0;
			i++;
		}
	}
	fclose(ptrfile);
	i = 0;

	for(j=0;j<4;j++)
	{
		k = 0;
		while(k<2)
		{
			strcpy(film[j].sinopsis[k], temp[i]);
			i++;
			k++;
		}
	}
	return;
}
