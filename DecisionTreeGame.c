#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecisionTreeGame.h"

DecisionTreeNode* createNode(const char* question)
{
  DecisionTreeNode* newNode = (DecisionTreeNode*)calloc(1, sizeof(DecisionTreeNode));
  if(newNode)
  {
      newNode->question = (char*)malloc(strlen(question) + 1);
      if(newNode->question)
      {
          strcpy(newNode->question, question);
          newNode->yes = NULL;
          newNode->no = NULL;
      }
      else
      {
          free(newNode);
          newNode = NULL;
      }
  } 
  return newNode;
}

void insertQuestion(DecisionTreeNode* root, const char* question, char answer)
{
    if(root == NULL)
    {
        return;
    }
    
    if(answer == 'y')
    {
        if(root->yes == NULL)
        {
            root->yes == createNode(question);
        }
        else
        {
            insertQuestion(root->yes, question, answer);
        }
    }
    else if(root->no == NULL)
    {
        if(root->no == NULL)
        {
            root->no == createNode(question);
        }
        else
        {
            insertQuestion(root->no, question, answer);
        }
    }
}

void playGame(DecisionTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    char response;
    printf("%s (y/n): ", root->question);

    if(root->yes == NULL && root->no == NULL)
    {
        printf("You've reached the end of the story. Until next time!\n");
        return;
    }

    printf("Enter 'y' for yes and 'n' for no: ");
    scanf("%c", &response);

    if(response == 'y')
    {
        playGame(root->yes);
    }
    else if(response == 'n')
    {
        playGame(root->no);
    }
    else
    {
        printf("Invalid answer. Please enter 'y' for yes and 'n' for no.");
        playGame(root);
    }
}

void freeTree(DecisionTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    freeTree(root->yes);
    freeTree(root->no);

    free(root->question);
    root->question = NULL;

    free(root);
}
