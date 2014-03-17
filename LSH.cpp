// This program reads in two sets of features and return the Jaccard similarity between the two sets

// Questions to solve
// 1. how to use a general input data type, that is how to use template

#include "FeatureSets.h"
#include "NgramExtractor.h"
#include <iostream>

using namespace::std;

void Error(string s);

int main()
{
	string str1, str2;   //file names for comparison
	int k;   // number of grams
	double sim;
	set<string> allfeatures;

	cout << "Welcome!" << endl;
	cout << "Please input the first file name: ";
	cin >> str1;
	cout << endl;
	//check whether the file name is valid
	cout << "Please input the second file name: ";
	cin >> str2;
	cout << endl;
	//check whether the file name is valid
	cout << "Please input the number of grams: ";
	cin >> k;

	if (k < 0)
	{
		Error("wrong number.");
		return 0;
	}
	NgramExtractor ex1(str1, k);
	NgramExtractor ex2(str2, k);
	set <string> s1 = ex1.extract(allfeatures);
	set <string> s2 = ex2.extract(allfeatures);
	FeatureSets fs(s1, s2, 1000, allfeatures);
	sim = fs.minhash();
	cout << "The similarity between these two documents are: " << sim << endl;
	return 0;
}

void Error(string s)
{
	cout << "Error: " << s << endl;
}