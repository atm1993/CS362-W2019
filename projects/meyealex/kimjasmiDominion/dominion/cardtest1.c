/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the smithyCardEffect() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testSmithyCardEffect() {
    int i, testHandCount, testHandPos, testDiscardCount, testDeckCount;
    int testBonus = 0;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState state;
    int testPlayer = 0;

    memset(&state, 23, sizeof(struct gameState));
    if(initializeGame(numPlayer, k, seed, &state) != 0) {
        printf("ERROR: initializeGame failed, exiting drawCard() tests\n");
        exit(1);
    }

    //TEST SUITE 1 normal smithy functions
    testHandCount = 5;
    testDeckCount = 10;
    testDiscardCount = 5;
    testHandPos = 4;
    testPlayer = whoseTurn(&state);
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    state.deckCount[testPlayer] = testDeckCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = copper;
    }
    for(i = 0; i < testDiscardCount; i++) {
        state.discard[testPlayer][i] = silver;
    }
    state.hand[testPlayer][testHandPos] = smithy;
    cardEffect(smithy, 0, 0, 0, &state, testHandPos, &testBonus);
    if(state.handCount[testPlayer] == testHandCount+2) {
        printf("smithyCardEffect(): PASS adding 3 and removing 1 from hand\n");
    }
    else {
        printf("smithyCardEffect(): FAIL adding 3 and removing 1 from hand\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount+1) {
        printf("smithyCardEffect(): PASS discarding 1 card\n");
    }
    else {
        printf("smithyCardEffect(): FAIL discarding 1 card\n");
    }
    if(state.discard[testPlayer][state.discardCount[testPlayer]-1] == smithy) {
        printf("smithyCardEffect(): PASS smithy card on top of discard pile\n");
    }
    else {
        printf("smithyCardEffect(): FAIL smithy card on top of discard pile\n");
    }
    if(state.hand[testPlayer][testHandPos] != smithy) {
        printf("smithyCardEffect(): PASS smithy discarded from hand\n");
    }
    else {
        printf("smithyCardEffect(): FAIL smithy discarded from hand\n");
    }
    if(state.deckCount[testPlayer] == testDeckCount - 3) {
        printf("smithyCardEffect(): PASS 3 cards drawn from player deck\n");
    }
    else {
        printf("smithyCardEffect(): FAIL 3 cards drawn from player deck\n");
    }
}

int main(int argc, char *argv[]) {
    printf("TESTING smithyCardEffect()\n\n");
    testSmithyCardEffect();
    printf("\n");
    return 0;
}