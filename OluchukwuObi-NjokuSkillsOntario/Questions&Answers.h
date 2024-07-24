#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//This class holds a question and the answers to it
//along with functions which permit access to the data within
namespace sdds {

	class QuesAns {
		string qCategory;
		string question;
		string correctAns;
		vector<string> ans;

	public:

		//Construct the QuesAns class
		QuesAns(string category, string question, string correctAns, vector<string> ans);

		//This displays the question
		void displayQuestion();

		//This returns the correct answer
		string getCorrectAnswer();

		//This outputs the private data
		friend ostream& operator<<(ostream& os, const QuesAns& qa) {
			os << " Category : " << qa.qCategory << " \n" << " Question : " << qa.question << " \n" << " Correct Answer : " << qa.correctAns << " \n" << " All Answers : ";

			for (const auto& eachAns : qa.ans) {
				os << eachAns << " ";
			}
			os << endl;
			return os;
		}
	};

}
