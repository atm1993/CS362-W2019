/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the villageCardEffect() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testVillageCardEffect() {
    int testHandCount, testHandPos, testDiscardCount, testDeckCount, testNumActions;
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

    testHandCount = 5;
    testDiscardCount = 5;
    testDeckCount = 10;
    testHandPos = 4;
    testNumActions = 3;
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    state.deckCount[testPlayer] = testDeckCount;
    state.numActions = testNumActions;

    cardEffect(village, 0, 0, 0, &state, testHandPos, &testBonus);

    if(state.handCount[testPlayer] == testHandCount) {
        printf("villageCardEffect(): PASS adding 1 card and discarding 1 card from hand\n");
    }
    else {
        printf("villageCardEffect(): FAIL adding 1 card and discarding 1 card from hand\n");
    }
    if(state.deckCount[testPlayer] == testDeckCount-1) {
        printf("villageCardEffect(): PASS drew 1 card from deck\n");
    }
    else {
       printf("villageCardEffect(): FAIL drew 1 card from deck\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount+1) {
        printf("villageCardEffect(): PASS add 1 card to discard pile\n");
    }
    else {
        printf("villageCardEffect(): FAIL add 1 card to discard pile\n");
    }
    if(state.hand[testPlayer][testHandPos] != village) {
        printf("villageCardEffect(): PASS village removed from hand\n");
    }
    else {
        printf("villageCardEffect(): FAIL village removed from hand\n");
    }
    if(state.numActions == testNumActions+2) {
        printf("villageCardEffect(): PASS add 2 actions to turn\n");
    }
    else {
        printf("villageCardEffect(): FAIL add 2 actions to turn\n");
    }
}


int main(int argc, char *argv[]) {
    printf("TESTING villageCardEffect()\n\n");
    testVillageCardEffect();
    printf("\n");
    return 0;
}