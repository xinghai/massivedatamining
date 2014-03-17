#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <stdlib.h>

using namespace::std;

class NgramExtractor
{
public:
	NgramExtractor(string s, int k):filename(s), numberofGrams(k){}
	~NgramExtractor(){};
	set<string> extract(set<string>& allfeatures);

	/* data */
private:
	int numberofGrams;
	string filename;
};

set<string> NgramExtractor::extract(set<string>& allfeatures)
{
	set<string> ss;
	ifstream F(filename, ifstream::in);
	string buf;
	if (!F.is_open())
		cout << "Warning: file fails to open!" << endl;
	string s;
	while((F>>buf))
	{
		//cout <<buf << endl;
		if (buf.length() < numberofGrams)
			continue;
		for (int i = 0; i <= buf.size()-numberofGrams; i++)
		{
			s = buf.substr(i, numberofGrams);
			if (s[0] != ' ')
			{
				ss.insert(s);
				allfeatures.insert(s);
			}
		}
	}
	F.close();
	return ss;
}