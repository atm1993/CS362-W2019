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

void testFullDeckCount() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState state;
    int testPlayer = 0;

    memset(&state, 23, sizeof(struct gameState));
    if(initializeGame(numPlayer, k, seed, &state) != 0) {
        printf("ERROR: initializeGame failed, exiting testFullDeckCount tests\n");
        exit(1);
    }
    state.deckCount[testPlayer] = MAX_DECK;
    state.discardCount[testPlayer] = MAX_DECK;
    state.handCount[testPlayer] = MAX_HAND;

    //TEST 1: Testing counting deck only
    for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = adventurer;
        state.discard[testPlayer][i] = smithy;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    if(fullDeckCount(testPlayer, adventurer, &state) == state.deckCount[testPlayer]) {
        printf("fullDeckCount(): PASS when counting cards in deck only\n");
    }
    else {
        printf("fullDeckCount(): FAIL when counting cards in deck only\n");
    }

    //TEST 2: Testing counting discard only
     for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = smithy;
        state.discard[testPlayer][i] = adventurer;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    if(fullDeckCount(testPlayer, adventurer, &state) == state.discardCount[testPlayer]) {
        printf("fullDeckCount(): PASS when counting cards in discard only\n");
    }
    else {
        printf("fullDeckCount(): FAIL when counting cards in discard only\n");
    }

    //TEST 3: Testing counting hand only
     for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = smithy;
        state.discard[testPlayer][i] = smithy;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = adventurer;
    }
    if(fullDeckCount(testPlayer, adventurer, &state) == state.handCount[testPlayer]) {
        printf("fullDeckCount(): PASS when counting cards in hand only\n");
    }
    else {
        printf("fullDeckCount(): FAIL when counting cards in hand only\n");
    }

    //TEST 4: Testing count deck, hand, and discard
    for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = adventurer;
        state.discard[testPlayer][i] = adventurer;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = adventurer;
    }
    int totalCount = state.deckCount[testPlayer] + state.handCount[testPlayer] + state.discardCount[testPlayer];
    if(fullDeckCount(testPlayer, adventurer, &state) == totalCount) {
        printf("fullDeckCount(): PASS when counting cards in all piles\n");
    }
    else {
        printf("fullDeckCount(): FAIL when counting cards in all piles\n");
    }

    //TEST 5: Testing count when cards not present
    for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = adventurer;
        state.discard[testPlayer][i] = adventurer;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = adventurer;
    }
    if(fullDeckCount(testPlayer, smithy, &state) == 0) {
        printf("fullDeckCount(): PASS when counting cards not present\n");
    }
    else {
        printf("fullDeckCount(): FAIL when counting cards not present\n");
    }
}

int main(int argc, char *argv[]) {
    printf("TESTING fullDeckCount()\n\n");
    testFullDeckCount();
    printf("\n");
    return 0;
}
