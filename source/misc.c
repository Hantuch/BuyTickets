#include <gtk/gtk.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "main.h"

//misc.c contains supporting functions or tools
//such as hidetab() which hides a tab
//or readfilm() which reads the films' title
//or price() which calculates ticket price based on current date

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

void checkseating(char seating[])
{
    for(i=0;i<4;i++)
    {
        switch(seat[i].status)
        {
            case 1 : strcat(seating,seat[i].position); break;
        }
    }
    return;
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
