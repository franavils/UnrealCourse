#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuessBack();
bool AskToPlayAgain();
string Guess = "";


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
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
}
void PlayGame() 
{
	constexpr int LIMIT_OF_TURNS = 5;
	for (int i = 1; i <= LIMIT_OF_TURNS; i++)
	{
		GetGuess();
		PrintGuessBack();
		cout << endl;
	}
}

string GetGuess() 
{
	// Get a guess from the player
	cout << "Guess the word: ";
	getline(cin, Guess);
	return Guess;
}

void PrintGuessBack()
{
	// Repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;	
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? (y/n)";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y')  || (Response[0] == 'Y');

	return false;
}
