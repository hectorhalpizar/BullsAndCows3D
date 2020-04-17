// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull and Cows"));

    InitGame();
    // The Game lets the Player know how many Lives has left.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // Validate if Player´s Input is a valid isogram.
    if (bGameOver) {
        ClearScreen();
        InitGame();
        return;
    }
    
    ProcessGuess(Input);
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PlayerStatus();
}

void UBullCowCartridge::PlayerStatus() {
    PrintLine(FString::Printf(TEXT("You have %i %s left."), Lives, (Lives == 1 ? TEXT("life") : TEXT("lives"))));
    PrintLine(TEXT("Please guess the word and press Enter."));
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Pless the Enter Key to play Again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Input) {
    if (HiddenWord == Input && IsIsogram(Input))
    {
        PrintLine(TEXT("Congratulations. YOU WIN!"));
        EndGame();

        return;
    }
    
    if (Input.Len() != HiddenWord.Len()) {
        PrintLine(FString::Printf(TEXT("The hidden word has %i letters."), HiddenWord.Len()));
    }
    else {
        PrintLine(FString::Printf(TEXT("That´s not the word to guess.")));
    }

    if (--Lives > 0)
    {
        PlayerStatus();
    }
    else {
        PrintLine(TEXT("GAME OVER. YOU LOSE!"));
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Input) const {

    // Extract every letter from the Input

    // Check if that letter has already being 
    // is already marked as registrated
        // If it has...
            // return as false
        // if it hasn´t maked
            // Check the next input letter

    return true;
}
