
#include<iostream>

#include "Info_Quiz.h"

using namespace std;


Info_Quiz::Info_Quiz(){
	Q = nullptr; 
	nr_questions =0;

}

Info_Quiz::~Info_Quiz(){


}
bool Info_Quiz::full(){
	if(!empty()){
		if(nr_questions == max_questions) return true;	
	} return false;

}

bool Info_Quiz::empty(){
	if(Q == nullptr) return true;
	else return false; 
}

bool Info_Quiz::get_question(string in_quest, string right, string wrong){
	bool insertion = false; 
	if(!full() and !included(in_quest)){
	
		Quest *aux = new Quest;
		aux->Question = in_quest;
		aux->R_Answer = right;
		aux->F_Answer = wrong;
		insertion = true; 
		if(empty()){
			Q = aux;
			Q->left = Q;
			Q->right= Q;
			nr_questions=1;
		} else {
			Quest *Q_aux = Q->left;
			Q->left = aux; 
			aux->right = Q;
			Q_aux->right = aux; 
			aux->left = Q_aux;
			nr_questions+=1;
		}
	} 

	return insertion;
}

bool Info_Quiz::included(string in_quest){
	bool repeated = false;
	if(!empty()){
		Quest *Q_aux = Q; 

		do{
			if(in_quest == Q_aux->Question){
				repeated = true;
				break;	
			} 
		Q_aux = Q_aux->left;	
		}while(Q_aux != Q);
	}
	return repeated;
}


void Info_Quiz::get_csv(string filename, bool &insert, string sep = ";"){
	ifstream file; 
	file.open(filename);
	if(file.is_open()){
		string buff, qst, r_ans, w_ans;
		int pos_1, pos_2;
		while(getline(file, buff)){
			if(!full()){
				pos_1 = buff.find(sep);
				pos_2 = buff.rfind(sep);
				qst = buff.substr(0, pos_1-1) ;
				r_ans = buff.substr(pos_1, pos_2 - pos_1);
				w_ans = buff.substr(pos_2+1);
				insert = this->get_question(qst,r_ans,w_ans);
			} else	break;
		}

	}else {
		insert = false;
	}

}