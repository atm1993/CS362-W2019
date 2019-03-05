/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the greatHallCardEffect() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testGreatHallCardEffect() {
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

    cardEffect(great_hall, 0, 0, 0, &state, testHandPos, &testBonus);

    if(state.handCount[testPlayer] == testHandCount) {
        printf("greatHallCardEffect(): PASS adding 1 card and discarding 1 card from hand\n");
    }
    else {
        printf("greatHallCardEffect(): FAIL adding 1 card and discarding 1 card from hand\n");
    }
    if(state.deckCount[testPlayer] == testDeckCount-1) {
        printf("greatHallCardEffect(): PASS drew 1 card from deck\n");
    }
    else {
        printf("greatHallCardEffect(): FAIL drew 1 card from deck\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount+1) {
        printf("greatHallCardEffect(): PASS add 1 card to discard pile\n");
    }
    else {
        printf("greatHallCardEffect(): FAIL add 1 card to discard pile\n");
    }
    if(state.hand[testPlayer][testHandPos] != great_hall) {
        printf("greatHallCardEffect(): PASS great_hall removed from hand\n");
    }
    else {
        printf("greatHallCardEffect(): FAIL great_hall removed from hand\n");
    }
    if(state.numActions == testNumActions+1) {
        printf("greatHallCardEffect(): PASS add 2 actions to turn\n");
    }
    else {
        printf("greatHallCardEffect(): FAIL add 2 actions to turn\n");
    }
}


int main(int argc, char *argv[]) {
    printf("TESTING greatHallCardEffect()\n\n");
    testGreatHallCardEffect();
    printf("\n");
    return 0;
}