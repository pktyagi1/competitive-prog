#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
class Word{
public:
	vector<string> getSyllable(string str)
	{
	 vector<string> syl;
	 string actual=str.substr(0,1);
    string vowel="aeiou";
	 FOR(i,1,str.size())
	 {
	 char c=str[i];
	 if(vowel.find(actual[actual.size()-1])!=string::npos && vowel.find(c)==string::npos)
	 {
		 syl.push_back(actual);
		 actual="";
	 }
actual+=c;
	 }
syl.push_back(actual);
return syl;
	}
	Word(string str):word(str){
		sortsylable=syllable=getSyllable(str);
		sort(sortsylable.begin(),sortsylable.end());

	}
	string word;
	vector<string> syllable;
	vector<string> sortsylable;
bool operator<(const Word& rhs) const
{
if(sortsylable==rhs.sortsylable)
	return syllable<rhs.syllable;
return sortsylable<rhs.sortsylable;
}

};

class SyllableSorting {

	public: vector<string> sortWords(vector<string> words) {
   vector<Word> wordList;
   FOR(i,0,words.size())
   {
	   wordList.push_back(Word(words[i]));
   }
sort(wordList.begin(),wordList.end());
   FOR(i,0,words.size())
   {

	   words[i]=wordList[i].word;
   }
		return words;
	}

};
