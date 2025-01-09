#pragma once
#define MAX_CARS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    int id;
    char marque[100];
    char modele[100];
    char typeCarburant[100];
    int places;
    char transmission[100];
    float prixParJour;
    int disponible;
} Voiture;

void chargerVoitures(const char* nomFichier);
void sauvegarderVoitures(const char* nomFichier);
void afficherVoitures();



