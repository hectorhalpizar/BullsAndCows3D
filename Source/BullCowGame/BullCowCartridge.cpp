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
    }
    else
    {

        if (HiddenWord == Input)
        {
            PrintLine(TEXT("Congratulations. YOU WIN!"));
            EndGame();
        }
        else
        {
            // PlayerStatus();
            if (Input.Len() != HiddenWord.Len()) {
                PrintLine(FString::Printf(TEXT("The hidden word has %i letters. YOU HAVE LOST."), HiddenWord.Len()));
            }
        }
    }

    // Validate if player´s lives are greater than zero
    // Let the player know that the Input is not valid
    // Decrease a life   
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = 5;
    bGameOver = false;
    PlayerStatus();
}

void UBullCowCartridge::PlayerStatus() {
    PrintLine(FString::Printf(TEXT("You have %i lives left."), Lives));
    PrintLine(TEXT("Please guess the word and type the Enter Key."));
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Pless the Enter Key to play Again."));
}
