#include <stdio.h>

typedef struct DecisionTreeNode
{
    char* question; //Pointer auf die Frage im jeweiligen Knoten
    struct DecisionTreeNode* yes; //Pointer auf die "Ja"-Entscheidung
    struct DecisionTreeNode* no; //Pointer auf die "Nein"-Entscheidung
} DecisionTreeNode;

DecisionTreeNode* createNode(const char* question); //Diese Funktion erzeugt einen neuen BST

void insertQuestion(DecisionTreeNode* root, const char* question, char answer); //Fügt einen Knoten mit einer Frage hinzu. Die Antwortparameter beinhalten 'y' für yes und 'n' für no.

void playGame(DecisionTreeNode* root); //Traversiert den Baum und lässt das Spielen zu.

void freeTree(DecisionTreeNode* root); //Befreit den für das Spiel reservierten Speicher.
