#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "library.h"

using namespace std;

void create_number(vector<string> &code, int a, int r){
        code.push_back(concatStringInt("ZERO ", r));
	vector < int > number;
        while(a!=0){
                if(a&1 == 1)
                        number.push_back( 1 );
                else
                        number.push_back( 0 );
                a>>=1;
        }
        for( int i=number.size() - 1 ; i>=0 ; i-- ){
                if(i!=number.size() - 1)
	 		code.push_back(concatStringInt("SHL ", r));
                if(number[i]==1)
                        code.push_back(concatStringInt("INC ", r));
        }
}

string concatStringInt(string s, int i){
	ostringstream oss;
	oss << s << i;
	return oss.str();
}

int numbSub(int a, int b){
	 return (a>b) ? a-b : 0; 
}

int isPrefix(string pattern, string text){
	for(int i=0 ; i<pattern.size() ; i++)
		if(pattern[i] != text[i])
			return 0;
	return 1;
}

string getLastWord(string tekst){
	string word = "";
	for(int i=tekst.size()-1 ; tekst[i]!=' ' ; i--)
		word += tekst[i];
	string ret = "";
	for(int i=word.size()-1 ; i>=0 ; i--)
		ret += word[i];
	return ret;
}

string replaceLastWord(string tekst, string rep){
	int i = 0;
	for(i=tekst.size()-1 ; tekst[i]!=' ' && i>0 ; i--);
	tekst = tekst.substr(0,i+1);
	tekst += rep;
	return tekst;
}
