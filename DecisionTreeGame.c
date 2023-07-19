#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecisionTreeGame.h"

DecisionTreeNode* createNode(const char* question)
{
  DecisionTreeNode* newNode = (DecisionTreeNode*)malloc(sizeof(DecisionTreeNode));

  if(newNode)
  {
    newNode->question
