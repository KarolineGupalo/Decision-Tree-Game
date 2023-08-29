#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecisionTreeGame.h"

DecisionTreeNode* createNode(const char* question)
{
  DecisionTreeNode* newNode = (DecisionTreeNode*)calloc(1, sizeof(DecisionTreeNode)); //Wir resesrvieren Speicher für den BST und initialisieren ihn. 
  //Vorerst werden alle Felder des Knotens auf NULL gesetzt. Bei erfolgreicher Speicherzuweisung -> Pointer auf Node (newNode)
  if(newNode) // ist newNode != NULL?
  {
      newNode->question = (char*)malloc(strlen(question) + 1); //Reservieren des Speichers für den String 'question' inkl. dem NULL-Terminator nach dem String (deshalb + 1)
      if(newNode->question)
      {
          strcpy(newNode->question, question);//Inhalt des strings 'question' wird in den zuvor reservierten Speicher kopiert.
          newNode->yes = NULL; //Der Knoten hat noch keine Kinder, deshalb werden yes und no auf NULL gesetzt.
          newNode->no = NULL;
      }
      else
      {
          free(newNode); //bei fehlgeschlagener Speicherreservierung --> Speicher wird wieder freigegeben.
          newNode = NULL;
      }
  } 
  return newNode; //Es wird ein Zeiger auf den gerade erstellten Knoten zurückgegeben.
}

//void insertQuestion(DecisionTreeNode* root, const char* question, char answer)
//{
//    if(root == NULL)
//    {
//        return;
//    }
//
//    if(answer == 'y')
//    {
//        if(root->yes == NULL)
//        {
//            root->yes = createNode(question);
//        }
//        else
//        {
//            insertQuestion(root->yes, question, answer);
//        }
//    }
//    else if(answer == 'n')
//    {
//        if(root->no == NULL)
//        {
//            root->no = createNode(question);
//        }
//        else
//        {
//            insertQuestion(root->no, question, answer);
//        }
//    }
//}
//Diese Funktion wurde inaktiv gesetzt, weil sie für die Main-Funktion nicht mehr notwendig ist. Grundsätzlich hätte sie auch bleiben können, da sie in der Main-Function nicht verwendet wird, der Einfachheit halber wurde sie aber auskommentiert.

void playGame(DecisionTreeNode* root)
{
    if(root == NULL) //Sorgt dafür, dass die rekursive Funktion gestoppt wird, sobald ein Zeiger auf NULL geht (Ende der Story).
    {
        return;
    }

    char response; //Variable für die Antwort der spielenden Person.
    printf("%s (y/n): ", root->question); //Ausgabe der Frage und call to action.

    if(root->yes == NULL && root->no == NULL) //Wenn keine yes oder no Kinder mehr vorhanden sind, bedeutet dies das Ende der Story.
    {
        printf("You've reached the end of the story. Until next time!\n");
        return;
    }

    printf("Enter 'y' for yes and 'n' for no: \n");
    scanf(" %c", &response); //WICHTIG - wenn kein Leerzeichen vor dem %c steht, wird die Antwort nicht korrekt eingelesen.

    if(response == 'y') //Die playGame Funktion wird mit der Auswahl der spielenden Person rekursiv aufgerufen. Führt zur nächsten Aktion im Spiel.
    {
        playGame(root->yes);
    }
    else if(response == 'n')
    {
        playGame(root->no);
    }
    else //Falls weder 'y' noch 'n' ausgewählt wurde.
    {
        printf("Invalid answer. Please enter 'y' for yes and 'n' for no. You typed %c", response);
        playGame(root);
    }
}

void freeTree(DecisionTreeNode* root)
{
    if(root == NULL) //Wenn der Knoten NULL ist, wird hier gestoppt.
    {
        return;
    }

    freeTree(root->yes);
    freeTree(root->no);

    free(root->question);
    root->question = NULL;

    free(root);
}
