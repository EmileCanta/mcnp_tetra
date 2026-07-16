#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void readandwrite(const std::string& inputFile, const std::string& outputFile, const std::string& phrase) {
    std::ifstream inFile(inputFile);  // Fichier en lecture
    std::ofstream outFile(outputFile, std::ios::app);  // Fichier en écriture

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return;
    }

    std::string currentLine;
    std::string nextLine;
    bool phraseFound = false;
    int count;

    while (std::getline(inFile, currentLine)) {
        if (phraseFound) {
            // Écrire la ligne suivante si la phrase a été trouvée dans la ligne précédente
            outFile << currentLine << std::endl;
            cout << "found" << endl;
            phraseFound = false;  // Réinitialiser le flag
        }

        if (currentLine.find(phrase) != std::string::npos) {
            // Phrase trouvée dans la ligne actuelle
            phraseFound = true;
        }
    }

    inFile.close();
    outFile.close();

    std::cout << "Recherche terminée. Résultat enregistré dans " << outputFile << std::endl;
}
