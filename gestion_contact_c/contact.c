#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définir la structure pour les contacts
typedef struct {
    char nom[50];
    char prenom[50];
    char numero[15];
} Contact;

// Fonction pour ajouter un contact
void ajouterContact(Contact *contacts, int *nombreContacts) {
    printf("Nom: ");
    scanf("%s", contacts[*nombreContacts].nom);
    printf("Prenom: ");
    scanf("%s", contacts[*nombreContacts].prenom);
    printf("Numero: ");
    scanf("%s /n", contacts[*nombreContacts].numero);
    (*nombreContacts)++;
}

// Fonction pour afficher les contacts
void afficherContacts(Contact *contacts, int nombreContacts) {
    for (int i = 0; i < nombreContacts; i++) {
        printf("Contact %d\n", i + 1);
        printf("Nom: %s\n", contacts[i].nom);
        printf("Prenom: %s\n", contacts[i].prenom);
        printf("Numero: %s\n\n", contacts[i].numero);
    }
}

// Fonction pour supprimer un contact
void supprimerContact(Contact *contacts, int *nombreContacts, int index) {
    if (index < 0 || index >= *nombreContacts) {
        printf("Index invalide\n");
        return;
    }
    for (int i = index; i < (*nombreContacts) - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*nombreContacts)--;
}

// Fonction pour sauvegarder les contacts dans un fichier
void sauvegarderContacts(Contact *contacts, int nombreContacts) {
    FILE *fichier = fopen("contact.txt", "wb");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier pour sauvegarde.\n");
        return;
    }
    fwrite(&nombreContacts, sizeof(int), 1, fichier);
    fwrite(contacts, sizeof(Contact), nombreContacts, fichier);
    fclose(fichier);
}

// Fonction pour charger les contacts depuis un fichier
void chargerContacts(Contact *contacts, int *nombreContacts) {
    FILE *fichier = fopen("contact.txt", "rb");
    if (fichier == NULL) {
        printf("Aucun fichier trouvé. Aucune donnée chargée.\n");
        *nombreContacts = 0;
        return;
    }
    fread(nombreContacts, sizeof(int), 1, fichier);
    fread(contacts, sizeof(Contact), *nombreContacts, fichier);
    fclose(fichier);
}

int main() {
    Contact contacts[100];
    int nombreContacts = 0;
    int choix, index;

    // Charger les contacts depuis le fichier
    chargerContacts(contacts, &nombreContacts);

    while (1) {
        printf("Menu:\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher les contacts\n");
        printf("3. Supprimer un contact\n");
        printf("4. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact(contacts, &nombreContacts);
                break;
            case 2:
                afficherContacts(contacts, nombreContacts);
                break;
            case 3:
                printf("Index du contact à supprimer: ");
                scanf("%d", &index);
                supprimerContact(contacts, &nombreContacts, index - 1);
                break;
            case 4:
                // Sauvegarder les contacts dans le fichier avant de quitter
                sauvegarderContacts(contacts, nombreContacts);
                exit(0);
                break;
            default:
                printf("Choix invalide\n");
        }
    }
    return 0;
}
