#include "TriviaGame.h"

namespace sdds {

	//This constructs the TriviaGame object
	TriviaGame::TriviaGame(int totalScore, int fails, int wins, unordered_map<string, unordered_map<int, QuesAns*>>& qA)
	: totalScore(totalScore), fails(fails), wins(wins), qA(qA){};

	//This determines the user's chosen level based on their input
	Difficulty getLevel(int level) {
		if (level == 1) return Difficulty::EASY;
		if (level == 2) return Difficulty::MEDIUM;
		if (level == 3) return Difficulty::HARD;
	};

	//This gets a random question for the user
	string TriviaGame::getQuestion() {
		int selectedQ = 0;
		string correctAns;
		if (this->Level == EASY) {
			while(((this->qA["easy"]).find(selectedQ)) == (this->qA["easy"]).end())
			 selectedQ = generateRandoms(this->qA["easy"].size());

			this->qA["easy"].at(selectedQ)->displayQuestion();
			correctAns = this->qA["easy"].at(selectedQ)->getCorrectAnswer();
			this->qA["easy"].erase(selectedQ);
			return correctAns;

		}
		else if (this->Level == MEDIUM) {
			while (((this->qA["medium"]).find(selectedQ)) == (this->qA["easy"]).end())
			selectedQ = generateRandoms(this->qA["medium"].size());


			this->qA["medium"].at(selectedQ)->displayQuestion();

			correctAns = this->qA["medium"].at(selectedQ)->getCorrectAnswer();
			this->qA["easy"].erase(selectedQ);
			return correctAns;
		}
		else {
			while (((this->qA["hard"]).find(selectedQ)) == (this->qA["hard"]).end())
			selectedQ = generateRandoms(this->qA["hard"].size());

			this->qA["hard"].at(selectedQ)->displayQuestion();

			correctAns = this->qA["hard"].at(selectedQ)->getCorrectAnswer();
			this->qA["easy"].erase(selectedQ);
			return correctAns;
		}


	};

	void TriviaGame::getVerifyAnswer(string correctAns) {

		string answer;

		cin >> answer;

		if (answer == "A" || answer == "B" || answer == "C" || answer == "D") {
			if (answer == "A") {
				cout << "Wonderful, your answer is correct" << endl;
				this->wins++;
				if (this->Level == EASY) this->totalScore += 1;
				else if (this->Level == MEDIUM) this->totalScore += 2;
				else if (this->Level == HARD) this->totalScore += 3;
			}
			else {
				cout << "Your answer is wrong, here is the correct one: "<< correctAns << endl;
				this->fails++;

			}
		}
		else {
			cout << "You failed to enter any of the available options, you fail this question" << endl;
			this->fails++;
		}


	}

	//This starts the game for the user
	int TriviaGame::startGame(string name, int level) {

		int i = 0;

		this->name = name;
		this->Level = getLevel(level);

		clearQuestionBank(this->qA);
		readTriviaFile("trivia.csv", this->qA);

		while (i != 15) {
			string answer = getQuestion();
			getVerifyAnswer(answer);
			i++;
		}

		cout << this->totalScore << endl;

		return 0;
	}
}