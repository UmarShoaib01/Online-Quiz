/*
 -----------------------------------
 File:    common.c
 Project: shoa1600_a08_t01
 file description
 -----------------------------------
 Author:  Umar Shoaib
 ID:      190961600
 Email:   shoa1600@mylaurier.ca
 Version  2021-04-02
 -----------------------------------
 */

#include <stdio.h>
#include <malloc.h>
#include "common.h"

NODE *new_node(int data, int type) {
    NODE *np = (NODE *) malloc(sizeof(NODE));
    // Successful memory allocation
    if (np != NULL)
    {
      np->data = data;
      np->type = type;
      np->next = NULL;
    }
    return np;
}

void display(NODE *start) {
  while (start) {
    if (start->type == 0) 
      printf("%d ", start->data);
    else 
      printf("%c ", start->data);      
    
    start = start->next;
  }
}

void clean(NODE **topp) {
    NODE *curr = *topp;
    NODE *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    *topp = NULL;
}