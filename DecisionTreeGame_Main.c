#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecisionTreeGame.h"

int main()
{
    DecisionTreeNode* root = createNode("Greetings, mighty warrior! You are on your path to great adventures! Would you like to start?\n");

    insertQuestion(root, "Off we go! But wait! Isn't there a sword lying on the ground? Will you pick it up?\n", 'y');
    insertQuestion(root, "Alrighty then, back to the tavern we go!\n", 'n');

    printf("Welcome to this adventure game!\n");
    playGame(root);

    freeTree(root);

    return 0;
}
