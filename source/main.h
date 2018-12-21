
// This header will declares the existence of the following variables from main.c
// To wherever it's called

extern struct film
{
    char judul[40];
    char sinopsis[2][50];
    char jadwal[4][10];
}film[4];

extern struct seat
{
    char position[3];
    int status;
}seat[4];

extern char jadwallong[4][40];
extern int ticket;
extern int i;
extern int filmpil;
extern int jadwalpil;

extern GtkNotebook *notebook;
extern GtkWidget *window0;
extern GtkWidget *window1;
extern GtkWidget *window2;
extern GtkBuilder *builder;
extern GtkToggleButton *toggle_button[4];
