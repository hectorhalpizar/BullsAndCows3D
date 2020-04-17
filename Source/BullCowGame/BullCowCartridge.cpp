// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull and Cows"));

    InitGame();

    // The Game lets the Player know how many Lives has left.
    PlayerStatus();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Validate if Player´s Input is a valid isogram.

    PlayerStatus();

    if (HiddenWord == Input)
        PrintLine(TEXT("Congratulations. YOU WIN!"));
    else
    {
        if (Input.Len() != HiddenWord.Len()) {
            PrintLine(FString::Printf(TEXT("The hidden word has %i letters"), HiddenWord.Len()));
        }
    }
    // Validate if player´s lives are greater than zero
    // Let the player know that the Input is not valid
    // Decrease a life   
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = 5;
}

void UBullCowCartridge::PlayerStatus() {
    PrintLine(FString::Printf(TEXT("You have %i lives left."), Lives));

    PrintLine(TEXT("Please guess the word and type the Enter Key."));
}