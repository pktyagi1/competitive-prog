#include <bits/stdc++.h>
using namespace std;
class Trie{
private:
	int words,prefixes;
	Trie *edges[27];

public:
	Trie()
{
		words=0;
prefixes=0;
for (int var = 0; var < 26; ++var) {
edges[var]=NULL;
}}

void addWords(string word)
{
if(word.length()==0)
	words+=1;
else{
	prefixes+=1;
	int k=word[0]-'a';
	if(!edges[k])
	{
		edges[k]=new Trie();


	}
	edges[k]->addWords(word.substr(1));
}
}
int countWords(string word)
{
if(word.length()==0)
	return words;

else{
	int k=word[0]-'a';
	if(!edges[k])
		return 0;
	return edges[k]->countWords(word.substr(1));
}


}
int countPrefixes(string word)
{
if(word.length()==0)
	return prefixes;

else{
	int k=word[0]-'a';
	if(!edges[k])
		return 0;
	return edges[k]->countPrefixes(word.substr(1));
}


}
};


