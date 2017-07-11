#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuessBack();
bool AskToPlayAgain();
FText Guess = "";

FBullCowGame BCGame;


int main() 
{
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);				
	return 0;	
}

void PrintIntro()
{
	// Introduce the game
	int32 HiddenWordLenght = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << HiddenWordLenght << " letter isogram I'm thinking of?" << std::endl;
}
void PlayGame() 
{
	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 i = 1; i <= MaxTries; i++)
	{
		GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
 		PrintGuessBack();
		std::cout << std::endl;
	}

	//TODO summarise game
}

FText GetGuess() 
{
	// Get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry <<". Guess the word: ";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuessBack()
{
	// Repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y')  || (Response[0] == 'Y');

	return false;
}
