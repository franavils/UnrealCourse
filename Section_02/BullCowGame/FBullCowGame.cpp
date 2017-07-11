#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
	
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "tuturuasdasd";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[j] == MyHiddenWord[i])
			{
				if (i == j) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::CheckGuessValidity(std::string) const
{
	return false;
}
