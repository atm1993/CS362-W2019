/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the drawCard() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testDrawCard() {
    int i, testDeckCount, testHandCount, testDiscardCount;
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

    //TEST SUITE 1: Testing draw with non empty deck
    printf("TESTING drawCard() on non empty deck\n");
    testDeckCount = 10;
    testHandCount = 5;
    state.deckCount[testPlayer] = testDeckCount;
    state.handCount[testPlayer] = testHandCount;
    for(i = 0; i < testDeckCount; i++) {
        state.deck[testPlayer][i] = smithy;
    }
    state.deck[testPlayer][testDeckCount-1] = copper;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = adventurer;
    }
    drawCard(testPlayer, &state);
    if(state.deckCount[testPlayer] == (testDeckCount - 1)) {
        printf("drawCard(): PASS decrement deck count when draw from non empty deck\n");
    }
    else {
        printf("drawCard(): FAIL decrement deck count when draw from non empty deck\n");
    }
    if(state.handCount[testPlayer] == (testHandCount + 1)) {
        printf("drawCard(): PASS increment hand count when draw from non empty deck\n");
    }
    else {
        printf("drawCard(): FAIL increment hand count when draw from non empty deck\n");
    }
    if(state.hand[testPlayer][state.handCount[testPlayer]-1] == copper) {
        printf("drawCard(): PASS adds top card of deck to player's hand\n");
    }
    else {
        printf("drawCard(): FAIL adds top card of deck to player's hand\n");
    }
    
    //TEST SUITE 2: Testing on an empty deck
    printf("TESTING drawCard() on an empty deck\n");
    testDeckCount = 0;
    testDiscardCount = 50;
    testHandCount = 5;
    state.deckCount[testPlayer] = testDeckCount;
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    for(i = 0; i < testDiscardCount; i++) {
        state.discard[testPlayer][i] = silver;
        if(i == testDiscardCount-1) 
            state.discard[testPlayer][i] = gold;
    }
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = copper;
    }
    drawCard(testPlayer, &state);
    if(state.discardCount[testPlayer] == 0) {
        printf("drawCard(): PASS clears discard pile\n");
    }
    else {
        printf("drawCard(): FAIL clears discard pile\n");
    }
    if(state.handCount[testPlayer] == testHandCount + 1) {
        printf("drawCard(): PASS increment hand count\n");
    }
    else {
        printf("drawCard(): FAIL increment hand count\n");
    }
    if(state.deckCount[testPlayer] == testDiscardCount - 1) {
        printf("drawCard(): PASS populate empty deck and decrement\n");
    }
    else {
        printf("drawCard(): FAIL populate empty deck and decrement\n");
    }
    if(state.deck[testPlayer][state.deckCount[testPlayer]-1] != gold) {
        printf("drawCard(): PASS discard pile shuffled in deck\n");
    }
    else {
        printf("drawCard(): FAIL discard pile shuffled in deck\n");
    }
    if(state.hand[testPlayer][state.handCount[testPlayer]-1] == silver) {
        printf("drawCard(): PASS adds top deck card into player hand\n");
    }
    else {
        printf("drawCard(): FAIL adds top deck card into player hand\n");
    }

    //TEST SUITE 3: Testing with empty deck and empty discard
    printf("TESTING drawCard() on empty deck and empty discard)\n");
    int retVal;
    testHandCount = 5;
    testDeckCount = 0;
    testDiscardCount = 0;
    state.deckCount[testPlayer] = testDeckCount;
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = copper;
    }
    retVal = drawCard(testPlayer, &state);
    if(state.deckCount[testPlayer] == testDeckCount) {
        printf("drawCard(): PASS no change to deck count\n");
    }
    else {
        printf("drawCard(): FAIL no change to deck count\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount) {
        printf("drawCard(): PASS no change to discard count\n");
    }
    else {
        printf("drawCard(): FAIL no change to discard count\n");
    }
    if(state.handCount[testPlayer] == testHandCount) {
        printf("drawCard(): PASS no change to hand count\n");
    }
    else {
        printf("drawCard(): FAIL no change to hand count\n");
    }
    if(retVal == -1) {
        printf("drawCard(): PASS draw card fails\n");
    }
    else {
        printf("drawCard(): FAIL draw card fails\n");
    }
}

int main(int argc, char *argv[]) {
    printf("TESTING drawCard()\n\n");
    testDrawCard();
    printf("\n");
    return 0;
}