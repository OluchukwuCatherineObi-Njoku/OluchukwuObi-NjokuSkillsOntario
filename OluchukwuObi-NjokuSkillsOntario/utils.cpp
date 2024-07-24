#include "utils.h"

namespace sdds {


	//welcomeMessage creates a message which welcomes and requests playerName and difficulty level
	void welcomeMessage(string& playerName, string& difficulty) {

		cout << "Hello! Welcome to our Trivia Game.\n Can we have your name?  ";
		cin >> playerName;

		cout << "\n\nThanks for giving us a name.\nNow, what difficulty level would you like ?" << endl;
		cout << "EASY - 1\nMEDIUM - 2\nHARD - 3\n";

		cin >> difficulty;

		while (verifyDifficultyInput(difficulty) == 0) {
			cout << "EASY - 1 \n MEDIUM - 2 \n HARD - 3 \n";

			cin >> difficulty;
			//clearBuffer();
		}

		
	}


	//Verifies if input given when diffiulty is requested, is correct
	int verifyDifficultyInput(string difficulty){
		if (difficulty == "1" || difficulty == "2" || difficulty == "3") {
			cout << "Perfect, your game has begun" << endl;
			return stoi(difficulty);
		}
		else {
			cout << "Your entered value matches none of our options. Re-enter" << endl;
			return 0;
		}
	}

	//clearBuffer clears the buffer 
	void clearBuffer() {
		cin.clear();
		cin.ignore(INT_MAX);
	}

	// generateRandoms accepts an int as an argument, generates a random number based off of 
	//the int as its limit, and returns the generated random number
	int generateRandoms(int n) {
		int rnd_number = (rand() * (RAND_MAX + 1) + rand()) % n;
		return rnd_number;
	}

	//getQuoted accepts a reference to the opened file that is to be read, 
	//reads the string that is within quotes
	//and returns the string
	string getQuoted(ifstream& fin) {
		char ch;
		string quotedVal = "";
		getline(fin, quotedVal, '?');
		fin.get(ch);
		return quotedVal;
	}

	//updateValue accepts 2 arguments, a string and a vector, and 
	//based on set conditions, updates the vector with the value in the string data type
	void updateValue(string& value, vector<string>& values) {
		if (value.length()) {
			values.push_back(value);
			value.clear();
		}
	}

	//clearQuestionBank accepts the unordered_map which holds all the questions,
	//and handle deallocating all memory which is pointed to, and 
	//deleting all the data in the map
	void clearQuestionBank(unordered_map<string, unordered_map<int, QuesAns*>>& qA) {
		if (qA.size()) {
			for (const auto& data : qA) {
				for (const auto& item : data.second) {
					delete item.second;
				}
			}
			qA.clear();
		}
		
	}

	//readTriviaFile accepts a file name and a 2d unordered_map as parameters,
	//then it reads the file with the file name, creates QuesAns objects, which it uses to 
	//populate the unoredered map, then it returns nothing

	void readTriviaFile(const char* fileName, unordered_map<string, unordered_map<int, QuesAns*>>& qA){

		unordered_map<int, QuesAns*> hardQA = {};
		unordered_map<int, QuesAns*> mediumQA = {};
		unordered_map<int, QuesAns*> easyQA = {};

		
		ifstream fin(fileName);

		if (fin.is_open()) {

			char ch;
			string value = "";
			vector <string> values = {};


			getline(fin, value);
			value.clear();
			while (fin.peek() != EOF && fin.get(ch)) {

				if (ch != '\n') {

					if (ch != ',') {
						if (values.size() == 2) {
							if (ch != int(34)) value = ch;
							value += getQuoted(fin);
							updateValue(value, values);
						}
						else {
							value += ch;
						}
					
						
					}
					else {
						updateValue(value, values);
					}

				}
				else {
					updateValue(value, values);
					QuesAns * QuAns = new QuesAns(values[1], values[2], values[3], { values[3], values[4], values[5], values[6] });
					if (values[0] == "hard") {
						hardQA[int(hardQA.size())] = QuAns;
					} 
					else if (values[0] == "medium") {
						mediumQA[int(mediumQA.size())] = QuAns;
					} 
					else {
						easyQA[int(easyQA.size())] = QuAns;
					}

					values.clear();
					value.clear();
				}
				
			}
			qA["hard"] = hardQA;
			qA["medium"] = mediumQA;
			qA["easy"] = easyQA;
			fin.close();
		}
		else {
			cout << "File unable to open" << endl;
			fin.clear();
		}

	}
}