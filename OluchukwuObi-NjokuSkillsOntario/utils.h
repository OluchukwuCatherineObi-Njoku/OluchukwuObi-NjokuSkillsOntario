#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Questions&Answers.h"

using namespace std;

namespace sdds {

	//It accepts the file name, handles reading the data in the file, 
	// and populates the unordered map with appropriate objects created with the data from the file. 
	void readTriviaFile(const char* fileName, unordered_map<string, unordered_map<int, QuesAns*>>& qA);
	
	string getQuoted(ifstream& fin);

	void updateValue(string& value, vector<string>& values);

	int generateRandoms(int n);

	void clearQuestionBank(unordered_map<string, unordered_map<int, QuesAns*>>& qA);

	void clearBuffer();

	int verifyDifficultyInput(string difficulty);

	void welcomeMessage(string& playerName, string& difficulty);

}