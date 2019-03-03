/**
 * Assignment 4 CS 362
 * Alex Meyer
 * Random tester for the adventurerCardEffect() function
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

int testAdventurerCardEffect(int handPos, struct gameState *post) {
    struct gameState pre;
    int player = post->whoseTurn;

    memcpy(&pre, post, sizeof(struct gameState));
    
    cardEffect(adventurer, 0, 0, 0, post, handPos, 0);

    if(post->handCount[player] != pre.handCount[player]+2) 
        return 1;
    if(post->hand[player][handPos] == adventurer)
        return 1;
    return 0;

}

int main(int argc, char *argv[]) {
    printf("TESTING adventurerCardEffect()\n\n");
    
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
        
        state.deckCount[p] = floor(Random() * MAX_DECK) + 2;
        int randPos = floor(Random() * (state.deckCount[p]-2));
        state.deck[p][randPos] = floor(Random()*3) + 4;
        randPos = floor(Random() * (state.deckCount[p]-2));
        state.deck[p][randPos] = floor(Random()*3) + 4;
        
        state.discardCount[p] = floor(Random() * MAX_DECK) + 2;
        randPos = floor(Random() * (state.discardCount[p] - 2));
        state.discard[p][randPos] = floor(Random()*3) + 4;
        randPos = floor(Random() * (state.discardCount[p]-2));
        state.discard[p][randPos] = floor(Random()*3) + 4;
        
        state.handCount[p] = floor(Random() * MAX_HAND);
        randPos = floor(Random() * state.handCount[p]);
        state.hand[p][randPos] = floor(Random()*3) + 4;
 
        handPos = floor(Random() * state.handCount[p]);
        state.hand[p][handPos] = adventurer;

        state.playedCardCount = 0;
        state.numActions = floor(Random() * 10);
        r = testAdventurerCardEffect(handPos, &state);
        numFails += r;
    }

    printf("Failed %d of %d tests\n", numFails, 2000);

    printf("\n");
    return 0;
}