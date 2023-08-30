#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecisionTreeGame.h"

int main()
{
    int playAgain = 1;

    while(playAgain)
        {
        DecisionTreeNode* root = createNode("Greetings, mighty warrior! You are on your path to great adventures! Would you like to start?\n");
    
        //insertQuestion(root, "Off we go! But wait! Isn't there a sword lying on the ground? Will you pick it up?\n", 'y');
        //insertQuestion(root, "Alrighty then, back to the tavern we go!\n", 'n');
        //insertQuestion(root, "Oh no! The sword gave you a itchy rash on both your hands. Ugly blisters are on your hands. But there is a strange looking plant right next to you on the way. Maybe you should pick it and rub it on your hands?\n", 'y');
        //insertQuestion(root, "That's the spirit! Fight with your bare hands! But wait - what's that? A troll is attacking you! You try to flee but oops - too late! The troll just ripped off your arms and legs. Too bad, your adventure ends here.\n", 'n');
        //insertQuestion(root, "Phew, the rash stopped and the itch stopped.\n", 'y');
        //insertQuestion(root, "Oh wow, the little bubbles on your hands turned into little scales and give you extra armour.\n", 'n');
    
        root->yes = createNode("Off we go! But wait! Isn't there a sword lying on the ground? Will you pick it up?\n");
        root->no = createNode("Alrighty then, back to the tavern we go!\n");
    
        root->yes->yes = createNode("Oh no! The sword gave you a itchy rash on both your hands. Ugly blisters are on your hands. But there is a strange looking plant right next to you on the way. Maybe you should pick it and rub it on your hands?\n");
        root->yes->no = createNode("That's the spirit! Fight with your bare hands! But wait - what's that? A troll is attacking you! You try to flee but oops - too late! The troll just ripped off your arms and legs. Too bad, your adventure ends here.\n");
    
        root->yes->yes->yes = createNode("Phew, the rash stopped and the itch stopped. But before we go you see a goofy looking dog on the side of the road. He could be helpful, but on the opposite side there is a majestic horse standing. Choose 'y' for the dog and 'n' for the horse!\n");
        root->yes->yes->no = createNode("Oh wow, the little bubbles on your hands turned into little scales and give you extra armour. Suddenly, a huge dragon appears right in front of you! Will you fight it?\n");
    
        root->yes->yes->yes->yes = createNode("The dog might not be the brightest boy in the world, but he makes up for it with his loyalty and escorts you to a dungeon. Will you go inside?\n");
        root->yes->yes->yes->no = createNode("The horse carries you quickly through the fields... And eventually throws you off it's back. Too bad, not such a mighty warrior after all, huh?\n");
    
        root->yes->yes->no->yes = createNode("You hit the dragon with your sword, it screams! Again, you try hitting it with all your strength, but did you really think you might defeat a huge dragon with just a sword? You get eaten of course and no one will find your remains. Bye!\n");
        root->yes->yes->no->no = createNode("The dragon sees your scales and thinks you are it's child. It adopts you and you end up being the dragon reign. Not a bad job you did here, well done!\n");
    
        root->yes->yes->yes->yes->yes = createNode("Turns out the dog has led you to a dungeon full of food. Not bad! Go enjoy yourself and have a nice meal together!\n");
        root->yes->yes->yes->yes->no = createNode("Yeah, better stay out of it. You go home, build a house and you and the dog live happily ever after.\n");
    
    
    
        printf("Welcome to this adventure game!\n");
        playGame(root);
    
        freeTree(root);

        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &playAgain);

        while (getchar() != '\n'); //Es muss sichergegangen werden, dass der Input Buffer gereinigt ist.
        }

    printf("Thanks for playing! See you again!\n");
    
    return 0;
}
