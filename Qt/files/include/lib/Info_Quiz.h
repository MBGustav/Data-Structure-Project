
#ifndef INFO_QUIZ_HPP
#define INFO_QUIZ_HPP


#include<iostream>
#include <string>
#include <fstream>

using namespace std;



struct Quest
{
	string Question;
	string R_Answer; 
	string F_Answer; 
	Quest *left; 
	Quest *right; 
};



class Info_Quiz
{
public:
	Info_Quiz();
	~Info_Quiz();
	bool get_question(string input_question, string Right, string wrong);
	bool empty();
	bool full();
	void get_csv(string filename, bool &insert, string sep);




private: 
	const int max_questions = 15;
	int nr_questions;

	Quest *Q;
	bool included(string input_question);
};



#endif /*INFO_QUIZ_HPP*/
