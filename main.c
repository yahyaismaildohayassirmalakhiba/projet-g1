#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* fichierCSV = "voitures.csv";
    int choix;

    chargerVoitures(fichierCSV);

    do {
        printf("\n--- Gestion de Location de Voitures ---\n");
        printf("1. Afficher les voitures\n");
        printf("2. Ajouter une voiture\n");
        printf("3. Sauvegarder et quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherVoitures();
                break;
            case 2:
                ajouterVoiture();
                break;
            case 3:
                sauvegarderVoitures(fichierCSV);
                printf("Données sauvegardées. Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 3);

    return 0;
}
