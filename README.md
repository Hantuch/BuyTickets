# BuyTickets+

BuyTickets is a rather simple & bodgy movie ticketing program based in C with GUI using Gtk+ library and compiled with MinGW-w64 Compiler

Before we explain further we would like to apologize for there are still some (a lot) imperfections in this program and a lot of unreached expectations/target, thank you for the understanding

This Program's design is based on popular mobile ticketing apps such as m-tix, cgv, etc with features including a film list, schedules, sinopsis, seating layout, & summary.
The Main objective of this program is to allow the user to easily purchase a ticket of a desired movie alone, which explains the usage of GUI instead of normal command window, this allows a more personal touch with the user on a whole new level.

The flow of this program is rather nonlinear since one can access early the schedules, film list & sinopsis interchangeably, but it can be said that the flow of this program is choosing the film, choosing the desired schedule, choosing the seating position, rechecking the summary, and finishing the transaction, afterwhich the user (or others) can use the program again from the beginning.

the GUI of this program is made using Gtk+2.0 Library developed by GNOME Developer (developer.gnome.org) with Glade as GUI designer program.

since this program read the movies info (names, schedules, synopsis, poster) from files it can be easily changed to fit the occasion thus making this program more convenient to use.

images of program in-action : https://imgur.com/a/StCZhra

For more technical details, this program uses some basic concepts/features of C programming and some other library-derived concepts.
the lists are as follows :

- Loops
- Modularity
- Call by Reference passing
- Arrays
- Pointers
- Structs
- Aqcuiring current time/date
- Reading data from files
- Gtk+ Library (and its dependencies)
- Changeable Poster, Film Titles, Schedules, & Sinpopsys

Future Plan for This Program 

We "hope" to improve the program further since it hasn't met our expectations & we were faced with many difficulties when trying to reach realize this expectation. Planned improvement includes better seating layout, memories of previous transactions & seating, and simulations of "filled" seats. another idea is to combine the program with our other program (C-PHP Browser Ticketing) to be able to print a HTML based ticket on a browse. our last possible plan is to do nothing to it and let it be.

Thank you for reading this readme, we bid you a good day/night

Hanif Rachmadani - 1606870774

Ahmad Aufar Husaini - 1606904730

-This program is a remade & improved version from "Ticketing-Apps" using GUI coding paradigm
