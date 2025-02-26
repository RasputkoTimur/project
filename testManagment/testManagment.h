#pragma once
#include <string>
using namespace std;
class testManagment
{
private:
	void addCategorty(Category category);
	void addQuestion(Question question);
	void exportTest(Test test);
	void addTest(Test test);
	void importTest(Test Test);
	void addAnswer(Answer answer, Category category);
	void setCorrectAnswer(Answer correctAnswer, Category category);
	void exportCategory(Category category);
	void importCategory(Category category);
};

