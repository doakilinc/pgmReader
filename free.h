/*
 *     free.h
 *     by Doga Kilinc (dkilin01) & Cansu Birsen (cbirse01), September 18
 *     HW1: Filesofpix
 *
 *     About: This file holds two functions that is used to 
 *     
 */

#ifndef FREE_INCLUDED
#define FREE_INCLUDED

#include <table.h>

extern void tableFree(Table_T patternMap);
extern void freeIntAndSequence(const void *key, void **value, void *cl);


#endif