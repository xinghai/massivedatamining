#include <iostream>
#include <string>
#include <set>
#include <stdlib.h>

using namespace::std;

class NgramExtractor
{
public:
	NgramExtractor(string s, int k):filename(s), numberofGrams(k){}
	~NgramExtractor();
	set<string> extract();

	/* data */
private:
	int numberofGrams;
	string filename;
};

set<string> NgramExtractor::extract()
{
	set<string> ss;
	fstream F;
	string buf;
	F.open(filename);
	string s;
	while((F>>buf))
	{
		for (int i = 0; i <= buf.size()-numberofGrams; i++)
		{
			s = buf.substr(i, numberofGrams);
			if (s[0] != ' ')
				ss.insert(s);
		}
	}
	return ss;
}