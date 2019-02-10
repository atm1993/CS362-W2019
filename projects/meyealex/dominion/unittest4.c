/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the updateCoins() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testUpdateCoins() {
    int i, testHandCount, testBonus;
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

    //TEST 1 no coins or bonus
    testHandCount = 5;
    testBonus = 0;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    updateCoins(testPlayer, &state, testBonus);
    if(state.coins == 0) {
        printf("updateCoins(): PASS with no coins or bonus\n");
    }
    else {
        printf("updateCoins(): FAIL with no coins or bonus\n");
    }
    //TEST 2 no coins but bonus
    testHandCount = 5;
    testBonus = 5;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    updateCoins(testPlayer, &state, testBonus);
    if(state.coins == testBonus) {
        printf("updateCoins(): PASS with no coins but bonus\n");
    }
    else {
        printf("updateCoins(): FAIL with no coins but bonus\n");
    }
    //TEST 3 with copper and bonus
    testHandCount = 5;
    testBonus = 5;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = copper;
    }
    updateCoins(testPlayer, &state, testBonus);
    if(state.coins == testBonus + (1*testHandCount)) {
        printf("updateCoins(): PASS with copper and bonus\n");
    }
    else {
        printf("updateCoins(): FAIL with copper and bonus\n");
    }
    //TEST 4 with silver and bonus
    testHandCount = 5;
    testBonus = 5;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = silver;
    }
    updateCoins(testPlayer, &state, testBonus);
    if(state.coins == testBonus + (2*testHandCount)) {
        printf("updateCoins(): PASS with silver and bonus\n");
    }
    else {
        printf("updateCoins(): FAIL with silver and bonus\n");
    }
    //TEST 5 with gold and bonus
    testHandCount = 5;
    testBonus = 5;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = gold;
    }
    updateCoins(testPlayer, &state, testBonus);
    if(state.coins == testBonus + (3*testHandCount)) {
        printf("updateCoins(): PASS with gold and bonus\n");
    }
    else {
        printf("updateCoins(): FAIL with gold and bonus\n");
    }
}

int main(int argc, char *argv[]) {
    printf("TESTING updateCoins()\n\n");
    testUpdateCoins();
    printf("\n");
    return 0;
}