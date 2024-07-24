#pragma once
#include "utils.h"

namespace sdds {

	//This holds difficulty levels
	enum Difficulty {
		EASY = 1,
		MEDIUM = 2,
		HARD = 3
	};

	Difficulty getLevel(int level);
	//int selectedQ = 4;

	class TriviaGame {
		int totalScore;
		int fails;
		int wins;
		string name = "";
		Difficulty Level = EASY;
		unordered_map<string, unordered_map<int, QuesAns*>>& qA;

		

	public:

		//TriviaGame constructs TriviaGame objects
		TriviaGame(int totalScore, int fails, int wins, unordered_map<string, unordered_map<int, QuesAns*>>& qA);

		//startGame starts the game and handles the entire gaming process from start to end, utilizing various functions
		//eventually returning the total score of the game
		int startGame(string name, int level);

		//This gets a random question, while returning the correct answer simultaneuously
		string getQuestion();

		//This verifies the correcteness of the user's answer,. while returning the correct answer
		void getVerifyAnswer(string correctAns);


	};

}