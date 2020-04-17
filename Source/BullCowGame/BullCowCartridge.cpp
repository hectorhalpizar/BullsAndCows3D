// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull and Cows\nPress the Enter Key to continue"));

    HiddenWord = TEXT("cake"); // Set Hidden Word

    // Set Player´s Lives to 5.
    // The Game lets the Player know how many Lives has left.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    // Validate if Player´s Input is a valid isogram.

    if (HiddenWord == Input)
        PrintLine(TEXT("Congratulations. YOU WIN!"));
    else
        PrintLine(TEXT("Bummer. YOU LOSE!"));

    // Validate if player´s lives are greater than zero
    // Let the player know that the Input is not valid
    // Decrease a life   
}