#include "Questions&Answers.h"

namespace sdds {

	//QuesAns instantiates the variables within its class
	QuesAns::QuesAns(string category, string question, string correctAns, vector<string> ans) {
		this->qCategory = category;
		this->question = question;
		this->correctAns = correctAns;
		this->ans = ans;
	}

	void QuesAns::displayQuestion() {
		cout << this->qCategory << endl;
		cout << this->question << endl;

		cout << "Select an answer" << endl;
		cout << "A - " << ans[0] << endl;
		cout << "B - " << ans[1] << endl;
		cout << "C - " << ans[2] << endl;
		cout << "D - " << ans[3] << endl;
	}

	string QuesAns::getCorrectAnswer() {
		return this->correctAns;
	}
}
