#include "voiture.h"
#include <stdio.h>
#include <stdlib.h>



Voiture voitures[MAX_CARS];
int nombreVoitures = 0;


void chargerVoitures(const char* nomFichier)
{
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    while (fscanf(fichier, "%d,%49[^,],%49[^,],%49[^,],%d,%49[^,],%f,%d\n",
                  &voitures[nombreVoitures].id,
                  voitures[nombreVoitures].marque,
                  voitures[nombreVoitures].modele,
                  voitures[nombreVoitures].typeCarburant,
                  &voitures[nombreVoitures].places,
                  voitures[nombreVoitures].transmission,
                  &voitures[nombreVoitures].prixParJour,
                  &voitures[nombreVoitures].disponible) == 8) {
        nombreVoitures++;
    }

    fclose(fichier);
}


void sauvegarderVoitures(const char* nomFichier) {
    int i;
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    for (i = 0; i < nombreVoitures; i++) {
        fprintf(fichier, "%d,%s,%s,%s,%d,%s,%.2f,%d\n",
                voitures[i].id,
                voitures[i].marque,
                voitures[i].modele,
                voitures[i].typeCarburant,
                voitures[i].places,
                voitures[i].transmission,
                voitures[i].prixParJour,
                voitures[i].disponible);
    }

    fclose(fichier);
}


void afficherVoitures() {
    int i;
    printf("Liste des voitures disponibles :\n");
    printf("ID | Marque | Modele | Carburant | Places | Transmission | Prix/Jour | Disponibilite\n");
    printf("--------------------------------------------------------------------------------------\n");
    for ( i = 0; i < nombreVoitures; i++) {
        printf("%d | %s | %s | %s | %d | %s | %.2f | %s\n",
               voitures[i].id,
               voitures[i].marque,
               voitures[i].modele,
               voitures[i].typeCarburant,
               voitures[i].places,
               voitures[i].transmission,
               voitures[i].prixParJour,
               voitures[i].disponible ? "Disponible" : "Non disponible");
    }
}


void ajouterVoiture() {
     Voiture nouvelleVoiture;
    if (nombreVoitures >= MAX_CARS) {
        printf("Nombre maximum de voitures atteint.\n");
        return;
    }


    nouvelleVoiture.id = nombreVoitures + 1;

    printf("Entrez la marque : ");
    scanf("%s", nouvelleVoiture.marque);

    printf("Entrez le modele : ");
    scanf("%s", nouvelleVoiture.modele);

    printf("Entrez le type de carburant : ");
    scanf("%s", nouvelleVoiture.typeCarburant);

    printf("Entrez le nombre de places : ");
    scanf("%d", &nouvelleVoiture.places);

    printf("Entrez la transmission (Automatique/Manuelle) : ");
    scanf("%s", nouvelleVoiture.transmission);

    printf("Entrez le prix par jour : ");
    scanf("%f", &nouvelleVoiture.prixParJour);

    nouvelleVoiture.disponible = 1;

    voitures[nombreVoitures++] = nouvelleVoiture;
    printf("Voiture ajoutée avec succès !\n");
}
