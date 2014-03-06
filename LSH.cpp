// This program reads in two sets of features and return the Jaccard similarity between the two sets

// Questions to solve
// 1. how to use a general input data type, that is how to use template

#include <FeatureSets.h>
#include <NgramExtractor.h>
#include <iostream>

using namespace::std;

int main()
{
	string s1, s2;
	int k;
	double sim;

	cout << "Welcome!" << endl;
	cout << "Please input the first file name: ";
	cin >> s1;
	cout << endl;
	//check whether the file name is valid
	cout << "Please input the second file name: ";
	cin >> s2;
	cout << endl;
	//check whether the file name is valid
	cout << "Please input the number of grams: ";
	cin >> k;

	if (k < 0)
	{
		Error("wrong number.");
		return 0;
	}
	NgramExtractor ex1(s1, k);
	NgramExtractor ex2(s2, k);
	set <T> s1 = ex1.extract();
	set <T> s2 = ex2.extract();

	FeatureSets fs(s1, s2);
	sim = fs.minhash();
	cout << "The similarity between these two documents are: " << sim << endl;

	return 0;
}

void Error(string s)
{
	cout << "Error: " << s << endl;
}