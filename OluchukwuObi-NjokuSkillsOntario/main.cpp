//Author: Oluchukwu Obi-Njoku
//Date: 6th May,  2024


#include <algorithm>
#include "utils.h"
#include "TriviaGame.h"

using namespace sdds;



int main() {

	unordered_map<string, unordered_map<int, QuesAns*>> qA;

	string playerName;
	string difficulty;
	
	welcomeMessage(playerName, difficulty);

	TriviaGame Game(0, 0, 0, qA);
	Game.startGame(playerName, stoi(difficulty));
	//cout << playerName << difficulty << endl;

	
	
	
	
	//readTriviaFile("trivia.csv", qA);


	/*for (int i = 0; i < qA["hard"].size(); i++) {
		cout << generateRandoms(int(qA["hard"].size())) << endl;
	}*/

	/*if (qA.size()) {
		for (const auto& data : qA) {
			cout << " Difficulty : " << data.first << " : ";
			for (const auto& item : data.second) {
				cout << "Question: " << item.first << '\n' << *item.second;
			}
		}
	}

	if (qA.size()) {
		for (const auto& data : qA) {
			for (const auto& item : data.second) {
				delete item.second;
			}
		}
	}*/

	return 0;
}