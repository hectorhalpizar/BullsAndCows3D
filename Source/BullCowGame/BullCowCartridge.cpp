// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
#include "Math/UnrealMathUtility.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull and Cows"));

    ValidIsograms = GetValidWords(Isograms);
    
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
    HiddenWord = ValidIsograms[FMath::RandRange(0, ValidIsograms.Num())];
    PrintLine(FString::Printf(TEXT("WORD %s SELECTED."), *HiddenWord));
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
        int Cows, Bulls;
        GetBullsCows(Input, Cows, Bulls);
        PrintLine(FString::Printf(TEXT("You have [%i] Cows and [%i] Bulls"), Cows, Bulls));
    }
    else {
        PrintLine(TEXT("GAME OVER. YOU LOSE!"));
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Input) const {

    // Extract every letter from the Input
    
    // Check if that letter has already being 
    for (int32 Index = 0; Index < Input.Len() - 1; Index++)
    {
        for (int32 Comparison = Index + 1;
            Comparison < Input.Len(); Comparison++) {

            if (Input[Index] == Input[Comparison]) {
                return false;
            }
            // is already marked as registrated
            // If it has...
                // return as false
            // if it hasn´t maked
                // Check the next input letter
        }
    }

    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString> & IsogramList) const {
    TArray <FString> Result;

    for (FString IsogramWord : IsogramList) {
        if (IsogramWord.Len() >= 8 && IsogramWord.Len() <= 10) {
            Result.Emplace(IsogramWord);
        }
    }
    return Result;
}

void UBullCowCartridge::GetBullsCows(const FString& Input, int32& BullCount, int32& CowCount) {
    BullCount = 0;
    CowCount = 0;

    for (int32 InputIndex = 0; InputIndex < Input.Len(); InputIndex++) {
        if (Input[InputIndex] == HiddenWord[InputIndex]) {
            BullCount++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++) {
            if (Input[InputIndex] == HiddenWord[HiddenIndex]) {
                CowCount ++;
                break;
            }
        }
    }
}
