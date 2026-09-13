#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char source[50];
    char destination[50];
    int seats;
};

struct Booking {
    int bookingId;
    char passengerName[50];
    int flightNumber;
    int seatNumber;
};

struct Flight flights[3] = {
    {101, "Hyderabad", "Delhi", 5},
    {102, "Mumbai", "Bangalore", 5},
    {103, "Chennai", "Kolkata", 5}
};

struct Booking bookings[100];

int bookingCount = 0;
int bookingId = 1001;

void displayFlights() {
    printf("\n===== AVAILABLE FLIGHTS =====\n");

    for (int i = 0; i < 3; i++) {
        printf("\nFlight Number : %d", flights[i].flightNumber);
        printf("\nSource        : %s", flights[i].source);
        printf("\nDestination   : %s", flights[i].destination);
        printf("\nAvailable Seats: %d\n", flights[i].seats);
    }
}

void searchFlight() {
    int choice;
    int flightNumber;
    char destination[50];
    int found = 0;

    printf("\nSearch Flight By:\n");
    printf("1. Flight Number\n");
    printf("2. Destination City\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        printf("Enter flight number: ");
        scanf("%d", &flightNumber);

        for (int i = 0; i < 3; i++) {

            if (flights[i].flightNumber == flightNumber) {

                printf("\nFlight Found!\n");
                printf("Flight Number : %d\n", flights[i].flightNumber);
                printf("Source        : %s\n", flights[i].source);
                printf("Destination   : %s\n", flights[i].destination);
                printf("Available Seats: %d\n", flights[i].seats);

                found = 1;
                break;
            }
        }

    } else if (choice == 2) {

        printf("Enter destination city: ");
        scanf(" %[^\n]", destination);

        for (int i = 0; i < 3; i++) {

            if (strcmp(flights[i].destination, destination) == 0) {

                printf("\nFlight Found!\n");
                printf("Flight Number : %d\n", flights[i].flightNumber);
                printf("Source        : %s\n", flights[i].source);
                printf("Destination   : %s\n", flights[i].destination);
                printf("Available Seats: %d\n", flights[i].seats);

                found = 1;
            }
        }

    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (found == 0) {
        printf("\nNo flight found.\n");
    }
}

void bookTicket() {

    int choice;
    int flightNumber;
    char destination[50];
    int found = 0;

    printf("\nBook Flight Using:\n");
    printf("1. Flight Number\n");
    printf("2. Destination City\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        printf("Enter flight number: ");
        scanf("%d", &flightNumber);

        for (int i = 0; i < 3; i++) {

            if (flights[i].flightNumber == flightNumber) {

                found = 1;

                if (flights[i].seats == 0) {
                    printf("No seats available.\n");
                    return;
                }

                printf("Enter passenger name: ");
                scanf(" %[^\n]", bookings[bookingCount].passengerName);

                bookings[bookingCount].bookingId = bookingId++;
                bookings[bookingCount].flightNumber = flightNumber;
                bookings[bookingCount].seatNumber = 6 - flights[i].seats;

                flights[i].seats--;

                printf("\nTicket booked successfully!\n");
                printf("Booking ID : %d\n", bookings[bookingCount].bookingId);
                printf("Passenger  : %s\n", bookings[bookingCount].passengerName);
                printf("Flight No. : %d\n", bookings[bookingCount].flightNumber);
                printf("Seat No.   : %d\n", bookings[bookingCount].seatNumber);

                bookingCount++;
                return;
            }
        }

    } else if (choice == 2) {

        printf("Enter destination city: ");
        scanf(" %[^\n]", destination);

        for (int i = 0; i < 3; i++) {

            if (strcmp(flights[i].destination, destination) == 0) {

                found = 1;

                if (flights[i].seats == 0) {
                    printf("No seats available.\n");
                    return;
                }

                printf("Enter passenger name: ");
                scanf(" %[^\n]", bookings[bookingCount].passengerName);

                bookings[bookingCount].bookingId = bookingId++;
                bookings[bookingCount].flightNumber = flights[i].flightNumber;
                bookings[bookingCount].seatNumber = 6 - flights[i].seats;

                flights[i].seats--;

                printf("\nTicket booked successfully!\n");
                printf("Booking ID : %d\n", bookings[bookingCount].bookingId);
                printf("Passenger  : %s\n", bookings[bookingCount].passengerName);
                printf("Flight No. : %d\n", bookings[bookingCount].flightNumber);
                printf("Seat No.   : %d\n", bookings[bookingCount].seatNumber);

                bookingCount++;
                return;
            }
        }

    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (found == 0) {
        printf("\nFlight not found.\n");
    }
}

void viewBookings() {

    if (bookingCount == 0) {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\n===== BOOKING DETAILS =====\n");

    for (int i = 0; i < bookingCount; i++) {

        printf("\nBooking ID : %d", bookings[i].bookingId);
        printf("\nPassenger  : %s", bookings[i].passengerName);
        printf("\nFlight No. : %d", bookings[i].flightNumber);
        printf("\nSeat No.   : %d\n", bookings[i].seatNumber);
    }
}

void cancelTicket() {

    int id;
    int found = 0;

    printf("\nEnter Booking ID to cancel: ");
    scanf("%d", &id);

    for (int i = 0; i < bookingCount; i++) {

        if (bookings[i].bookingId == id) {

            found = 1;

            for (int j = 0; j < 3; j++) {

                if (flights[j].flightNumber == bookings[i].flightNumber) {
                    flights[j].seats++;
                    break;
                }
            }

            for (int j = i; j < bookingCount - 1; j++) {
                bookings[j] = bookings[j + 1];
            }

            bookingCount--;

            printf("Ticket cancelled successfully.\n");
            return;
        }
    }

    if (found == 0) {
        printf("Booking ID not found.\n");
    }
}

int main() {

    int choice;

    do {

        printf("\n\n===== FLIGHT TICKET BOOKING SYSTEM =====\n");
        printf("1. Display Flights\n");
        printf("2. Search Flight\n");
        printf("3. Book Ticket\n");
        printf("4. View Bookings\n");
        printf("5. Cancel Ticket\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayFlights();
                break;

            case 2:
                searchFlight();
                break;

            case 3:
                bookTicket();
                break;

            case 4:
                viewBookings();
                break;

            case 5:
                cancelTicket();
                break;

            case 6:
                printf("\nThank you for using the Flight Ticket Booking System!\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}