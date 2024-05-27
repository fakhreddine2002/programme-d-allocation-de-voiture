#include <stdio.h>
struct Voyageur {
    char nom[50];
    char prenom[50];
    int id;
};

struct Bus {
    int numbus;
    char model[50];
    int capacite;
};

struct Reservation {
    int numeroReservation;
    int numeroBus;
    struct Voyageur voyageur;
};

struct Voyageur creer_voyageur() {
    struct Voyageur nouveauVoyageur;
    printf("Nom du voyageur : ");
    scanf("%s", nouveauVoyageur.nom);
    printf("Prenom du voyageur : ");
    scanf("%s", nouveauVoyageur.prenom);
    printf("ID du voyageur : ");
    scanf("%d", &nouveauVoyageur.id);
    return nouveauVoyageur;
}

struct Reservation creer_reservation(int numeroReservation, int numeroBus) {
    struct Reservation nouvelleReservation;
    nouvelleReservation.numeroBus = numeroBus;
    nouvelleReservation.numeroReservation = numeroReservation;
    nouvelleReservation.voyageur = creer_voyageur();
    return nouvelleReservation;
}

struct Bus ajouter_un_bus() {
    struct Bus bus;
    printf("Donner le numero du bus : ");
    scanf("%d", &bus.numbus);
    printf("Donner le modele du bus : ");
    scanf("%s", bus.model);
    printf("Donner la capacite de ce bus : ");
    scanf("%d", &bus.capacite);
    return bus;
}

void afficher_detail_bus(struct Bus bus) {
    printf("Detail du bus :\n");
    printf("Numero du bus : %d\n", bus.numbus);
    printf("Modele du bus : %s\n", bus.model);
    printf("Capacite du bus : %d\n", bus.capacite);
}

void afficherDetailsReservation(struct Reservation reservation) {
    printf("Detail de la reservation :\n");
    printf("Numero de la reservation : %d\n", reservation.numeroReservation);
    printf("Numero du bus : %d\n", reservation.numeroBus);
    printf("ID du voyageur : %d\n", reservation.voyageur.id);
}

void modifier_une_reservation(struct Reservation *reservation) {
    printf("Donner le nouveau voyageur de cette reservation (nom prenom id, respectivement) : ");
    scanf("%s %s %d", reservation->voyageur.nom, reservation->voyageur.prenom, &reservation->voyageur.id);
    printf("Donner le nouveau numero du bus : ");
    scanf("%d", &reservation->numeroBus);
}

int main() {
    struct Bus listeBuses[80];
    struct Reservation listeReservations[100];

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1/ ajouter un bus\n");
        printf("2/ ajouter une reservation\n");
        printf("3/ voir les detaille d'une bus\n");
        printf("4/ voire la detaille d'une reservation\n");
        printf("5/ modifier une reservation\n");
        printf("0/ sortir\n");
        printf("tapez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                struct Bus newBus = ajouter_un_bus();
                if (newBus.numbus >= 0 && newBus.numbus < 10) {
                    listeBuses[newBus.numbus] = newBus;
                } else {
                    printf("numero du bus invalide : \n");
                }
                break;
            case 2:
                printf("tapez le numero du reservation et le numero du bus: ");
                int y,g;
                scanf("%d", &y);
                scanf("%d" , &g);
                struct Reservation newReservation = creer_reservation(y, g); 
                if (newReservation.numeroReservation >= 0 && newReservation.numeroReservation < 50) {
                    listeReservations[newReservation.numeroReservation] = newReservation;
                } else {
                    printf("numero du reservation invalide : \n");
                }
                break;
            case 3:
                printf("Enter le numero d'une bus: ");
                int busNumber;
                scanf("%d", &busNumber);
                if (busNumber >= 0 && busNumber < 10) {
                    afficher_detail_bus(listeBuses[busNumber]);
                } else {
                    printf("bus invalide . \n");
                }
                break;
            case 4:
                printf("tapez le numero d'une reservation : ");
                int x;
                scanf("%d", &x);
                if (x >= 0 && x < 50) {
                    afficherDetailsReservation(listeReservations[x]);
                } else {
                    printf("numero reservation invalide : \n");
                }
                break;
            case 5:
                printf("tapez le numero de reservation a modifiez : ");
                int modifyReservationNumber;
                scanf("%d", &modifyReservationNumber);
                if (modifyReservationNumber >= 0 && modifyReservationNumber < 50) {
                    modifier_une_reservation(&listeReservations[modifyReservationNumber]);
                } else {
                    printf("numero reservation invalide .\n");
                }
                break;

            case 0:
                printf("sortir du programme : \n");
                break;
            default:
                printf("choix invalide .... repetez : \n");
        }
    } while (choice != 0);

    return 0;
}

