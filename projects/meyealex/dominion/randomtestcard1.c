/**
 * Assignment 4 CS 362
 * Alex Meyer
 * Random tests for the villageCardEffect() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testVillageCardEffect(int handPos, struct gameState *post) {
    struct gameState pre;
    int player = post->whoseTurn;

    memcpy(&pre, post, sizeof(struct gameState));

    cardEffect(village, 0, 0, 0, post, handPos, 0);
    if(post->numActions != pre.numActions + 2)
        return 1;
    if(post->discardCount[player] != pre.discardCount[player]+1)
        return 1;
    if(post->hand[player][handPos] == village)
        return 1;
    return 0;
    
}


int main(int argc, char *argv[]) {
    printf("TESTING villageCardEffect()\n\n");
    
    SelectStream(2);
    PutSeed(3);
    struct gameState state;
   
    int n, i, p, r, handPos, numFails;
    for(n = 0; n < 2000; n++) {
        for(i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&state)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
    
        state.whoseTurn = p;
        state.numPlayers = 2;
        state.deckCount[p] = floor(Random() * MAX_DECK);
        state.discardCount[p] = floor(Random() * MAX_DECK);
        state.handCount[p] = floor(Random() * MAX_HAND);
        handPos = floor(Random() * state.handCount[p]);
        state.hand[p][handPos] = village;
        state.playedCardCount = 0;
        state.numActions = floor(Random() * 10);
        r = testVillageCardEffect(handPos, &state);
        numFails += r;
    }

    printf("Failed %d of %d tests\n", numFails, 2000);

    printf("\n");
    return 0;
}
