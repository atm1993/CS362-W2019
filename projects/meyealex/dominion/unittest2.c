/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the fullDeckCount() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NUM_CARDS 27

int cardCosts[NUM_CARDS] = {
    0, //Curse
    2, //Estate
    5, //Dutchy
    8, //Province
    0, //Copper
    3, //Silver
    6, //Gold
    6, //Adventurer
    5, //Council Room
    4, //Feast
    4, //Gardens
    5, //Mine
    4, //Remodel
    4, //Smithy
    3, //Village
    4, //Baron
    3, //Great Hall
    5, //Minion
    3, //Steward
    5, //Tribute
    3, //Ambassador
    4, //Cutpurse
    2, //Embargo
    5, //Outpost
    4, //Salvager
    4, //Sea Hag
    4, //Treasure Map
};

const char* cardNames[NUM_CARDS] = {
    "curse",
    "estate",
    "dutchy",
    "province",
    "copper",
    "silver",
    "gold",
    "adventurer",
    "council room",
    "feast",
    "gardens",
    "mine",
    "remodel",
    "smithy",
    "village",
    "baron",
    "great hall",
    "minion",
    "steward",
    "tribute",
    "ambassador",
    "cutpurse",
    "embargo",
    "outpost",
    "salvager",
    "sea hag",
    "treasure map"
};

void testGetCost() {
    int i;

    for(i = 0; i < NUM_CARDS; i++) {
        if(getCost(i) == cardCosts[i]) {
            printf("getCost(): PASS for %s card\n", cardNames[i]);
        }
        else {
            printf("getCost(): FAIL for %s card\n", cardNames[i]);
        }
    }

    if(getCost(-1) == -1) {
        printf("getCost(): PASS for nonexistent card\n");
    }
    else {
        printf("getCost(): FAIL for nonexistent card\n");
    }
}

int main(int argc, char *argv[]) {
    printf("TESTING getCost()\n\n");
    testGetCost();
    printf("\n");
    return 0;
}