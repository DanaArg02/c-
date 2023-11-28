#include <iostream>
#include <fstream> // Pour la gestion des fichiers
#include <string>
using namespace std;

// Fonction pour comparer le contenu de deux fichiers et calculer le pourcentage de ressemblance
double compareFiles(const std::string& file1, const std::string& file2) {
    ifstream f1(file1), f2(file2); // Ouvre les deux fichiers en lecture
    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Impossible d'ouvrir l'un des fichiers" << endl; // Utilise cerr pour les messages d'erreur
        return 0.0;
    }

    string line1, line2;
    double totalLines = 0.0;
    double matchingLines = 0.0;

    // Compare les fichiers ligne par ligne et compte les lignes identiques
    while (getline(f1, line1) && getline(f2, line2)) {
        totalLines += 1.0;
        if (line1 == line2) {
            matchingLines += 1.0;
        }
    }

    // Calcule le pourcentage de ressemblance si les deux fichiers ont été lus en entier
    if (f1.eof() && f2.eof()) {
        return (matchingLines / totalLines) * 100.0;
    }

    // Si les fichiers diffèrent en longueur, le pourcentage de ressemblance est de 0
    return 0.0;
}

// Fonction principale
int main() {
    string file1 = "file1.txt"; // Chemin du premier fichier
    string file2 = "file2.txt"; // Chemin du deuxième fichier

    // Appelle la fonction pour comparer les fichiers et récupère le pourcentage de ressemblance
    double resemblancePercentage = compareFiles(file1, file2);
    if (resemblancePercentage > 0.0) {
        cout << "Le pourcentage de ressemblance est de : " << resemblancePercentage << "%" << endl;
    } else {
        cout << "Les fichiers sont différents ou vides." << endl;
    }

    return 0;
}
