#include <stdio.h>
#include <stdlib.h>
#include <free.h>
#include <seq.h>
#include <table.h>

/**********tableFree********
 *
 * About: frees the patternMap and the values of the patternMap by calling
 *        freeIntAndSequence
 * Inputs:
 *      Table_T patternMap: Hanson table that stores the pattern and the
 *      integer sequence from the same line as a pair
 * Return: none
 * Expects
 *      patternMap to be nonnull
 ************************/
void tableFree(Table_T patternMap) {

        /* freeing the integers in the sequences and the table values */
        Table_map(patternMap, freeIntAndSequence, NULL);
        Table_free(&patternMap);

}

/**********freeIntAndSequence********
 *
 * About: frees the Seq_T data structures stored as values in patternMap and
 *        malloced integer values stored in these Seq_T structures
 * Inputs:
 *      const void *key: pointer to an arbitrary key of the patternMap
 *      void **value: pointer to a pointer to an arbitrary value of the
 *      patternMap
 *      void *cl: application-specific pointer, required by the Hanson 
 *      interface
 * Return: none
 * Expects
 *      key and value to be nonnull
 ************************/
void freeIntAndSequence(const void *key, void **value, void *cl) {
    
        Seq_T valueSeq = *value;
        
        /* traversing the integer sequence */
        for (int i = 0; i < Seq_length(valueSeq); i++) {
                /* obtaining the integer from the sequence */
                int *num = Seq_remlo(valueSeq);
                free(num);
        }
        
        /* freeing the sequence itself */
        Seq_free(&valueSeq); 

        (void) key;
        (void) cl;
}
