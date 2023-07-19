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
          strcpy(newNode->question, question)
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
