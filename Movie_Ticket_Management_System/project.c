#include <stdio.h>
#include <string.h>
struct Movie 
{
    int id;
    char title[50];
    char genre[20];
    char showtimes[4][10];
    int price_2d;
    int price_3d;
};

int main() 
{
struct Movie movies[8] = {
        {1, "GADAR 2", "Action/Drama", {"10:00 AM", "1:00 PM", "4:00 PM", "7:00 PM"}, 250, 400},
        {2, "OMG 2", "Comedy/Drama", {"10:15 AM", "1:15 PM", "4:15 PM", "7:15 PM"}, 250, 400},
        {3, "JAILER", "Thriller/mystery", {"10:30 AM", "1:30 PM", "4:30 PM", "7:30 PM"}, 250, 400},
        {4, "MEG 2: THE TRENCH", "Action/Adventure", {"10:45 AM", "1:45 PM", "4:45 PM", "7:45 PM"}, 250, 400},
        {5, "ROCKY AUR RANI KII PREM KAHAANI", "Romance/Family flim", {"11:00 AM", "2:00 PM", "5:00 PM", "8:00 PM"}, 250, 400},
        {6, "TALK TO ME", "Horror/Thriller", {"11:15 AM", "2:15 PM", "5:15 PM", "8:15 PM"}, 250, 400},
        {7, "BARBIE", "Comedy/Drama", {"11:30 AM", "2:30 PM", "5:30 PM", "8:30 PM"}, 250, 400},
        {8, "OPPENHEIMER", "Drama/Thriller", {"11:45 AM", "2:45 PM", "5:45 PM", "8:45 PM"}, 250, 400}
    };


    int nameofmovie, showtime, no, ticketType, totalPrice, i;
    
    printf("Welcome to the Movie Ticket Booking System!\n");

    printf("\n");

    printf("Available Movies are shown on the screen:\n"); 

    printf("\n");

    for (int i = 0; i < 8; i++) 
    {
        printf("%d. %s (%s)\n", movies[i].id, movies[i].title, movies[i].genre);
    }

    printf("\nPlease select a movie by entering its ID: ");
    scanf("%d", &nameofmovie);

    if (nameofmovie < 1 || nameofmovie > 8) 
    {
        printf("Invalid movie selection\n");
        return 1;
    }

     printf("\n");

    printf("Available Showtimes are shown on the screen:\n");
    for (i = 0; i < 4; i++) 
    {
        printf("%d. %s\n", i + 1, movies[nameofmovie - 1].showtimes[i]);
    }

    printf("\nSelect a showtime by entering its ID: ");
    scanf("%d", &showtime);

    if (showtime < 1 || showtime > 4) 
    {
        printf("Invalid showtime selection.\n");
        return 1;
    }
     printf("\n");

    printf("Select ticket type:\n");
    printf("1. 2D (Rs %d)\n", movies[nameofmovie - 1].price_2d);
    printf("2. 3D (Rs %d)\n", movies[nameofmovie - 1].price_3d);
    scanf("%d", &ticketType);

    if (ticketType != 1 && ticketType != 2) 
    {
        printf("Invalid ticket type selection.\n");
        return 1;
    }
     printf("\n");

    printf("Enter the number of tickets to book: ");
    scanf("%d", &no);

    if (ticketType == 1) 
    {
        totalPrice = no * movies[nameofmovie - 1].price_2d;
    } 
    else
    {
        totalPrice = no * movies[nameofmovie - 1].price_3d;
    }

    printf("You have successfully booked %d ticket(s) for %s at %s. \nYour total cost is Rs %d.\n", no, movies[nameofmovie - 1].title, movies[nameofmovie - 1].showtimes[showtime - 1], totalPrice);

    return 0;
}
