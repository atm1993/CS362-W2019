/**
 * Assignment 3 CS 362
 * Alex Meyer
 * Unit tests for the adventurerCardEffect() function
 * 
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testAdventurerCardEffect() {
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

    //TESTING with 2> Treasures in deck
    printf("TESTING adventurerCardEffect() with two treasures in deck\n");
    testHandCount = 5;
    testHandPos = 4;
    testDiscardCount = 5;
    testDeckCount = 5;
    testPlayer = whoseTurn(&state);
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    state.deckCount[testPlayer] = testDeckCount;

    for(i = 0; i < testDeckCount; i++) {
        state.deck[testPlayer][i] = smithy;
    }
    state.deck[testPlayer][0] = gold;
    state.deck[testPlayer][1] = silver;
    state.hand[testPlayer][testHandPos] = adventurer;
    cardEffect(adventurer, 0, 0, 0, &state, testHandPos, &testBonus);
    if(state.handCount[testPlayer] == testHandCount+2) {
        printf("adventurerCardEffect(): PASS add two cards to hand\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL add two cards to hand\n");
    }
    if(state.hand[testPlayer][state.handCount[testPlayer]-1] == gold && state.hand[testPlayer][state.handCount[testPlayer]-2] == silver ) {
        printf("adventurerCardEffect(): PASS added proper treasure cards to hand\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL added proper treasure cards to hand\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount + testDeckCount - 2 + 1) {
        printf("adventurerCardEffect(): PASS discarded all proper cards\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL discarded all proper cards\n");
    }
    if(state.hand[testPlayer][testHandPos] != adventurer) {
        printf("adventurerCardEffect(): PASS discarded adventurer card from hand\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL discarded adventurer card from hand\n");
    }
    //TESTING with required shuffle
    printf("TESTING adventurerCardEffect() with a required shuffle\n");
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    state.deckCount[testPlayer] = testDeckCount;

    for(i = 0; i < testDeckCount; i++) {
        state.deck[testPlayer][i] = smithy;
    }
    state.deck[testPlayer][0] = gold;
    for(i = 0; i < testDiscardCount; i++) {
        state.discard[testPlayer][i] = smithy;
    }
    for(i = 0; i < testHandCount; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    state.discard[testPlayer][0] = silver;
    cardEffect(adventurer, 0, 0, 0, &state, testHandPos, &testBonus);
    if(state.hand[testPlayer][state.handCount[testPlayer]-1] == silver && state.hand[testPlayer][state.handCount[testPlayer]-2] == gold ) {
        printf("adventurerCardEffect(): PASS added proper treasure cards to hand\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL added proper treasure cards to hand\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount+testDeckCount-1) {
        printf("adventurerCardEffect(): PASS discarded proper amount of cards\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL discarded proper amount of cards\n");
    }
    //TESTING with less than 2 treasure cards
    printf("TESTING adventurerCardEffect() with less than 2 treasure cards\n");
    memset(&state, 23, sizeof(struct gameState));
    if(initializeGame(numPlayer, k, seed, &state) != 0) {
        printf("ERROR: initializeGame failed, exiting drawCard() tests\n");
        exit(1);
    }
    state.handCount[testPlayer] = testHandCount;
    state.discardCount[testPlayer] = testDiscardCount;
    state.deckCount[testPlayer] = testDeckCount;

    for(i = 0; i < MAX_DECK; i++) {
        state.deck[testPlayer][i] = smithy;
    }
    state.deck[testPlayer][0] = gold;
    for(i = 0; i < MAX_DECK; i++) {
        state.discard[testPlayer][i] = smithy;
    }
    for(i = 0; i < MAX_HAND; i++) {
        state.hand[testPlayer][i] = smithy;
    }
    cardEffect(adventurer, 0, 0, 0, &state, testHandPos, &testBonus);
    if(state.handCount[testPlayer] == testHandCount) {
        printf("adventurerCardEffect(): PASS adding 1 treasure card to hand and discarding adventurer\n");
    }
    else {
        printf("adventurerCardEffect(): FAIL adding 1 treasure card to hand and discarding adventurer\n");
    }
    if(state.discardCount[testPlayer] == testDiscardCount+testDeckCount) {
        printf("adventurerCardEffect(): PASS discarding correct cards after a shuffle with 1 treasure\n");
    }
    else {
        printf("adventruerCardEffect(): FAIL discarding correct cards after a shuffle with 1 treasure\n");
    }

}

int main(int argc, char *argv[]) {
    printf("TESTING adventurerCardEffect()\n\n");
    testAdventurerCardEffect();
    printf("\n");
    return 0;
}