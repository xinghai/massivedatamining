#include <set>
#include <string>

using namespace::std;

class dictionaryGenerator{
public:
	void dictionaryGenerator(int n): gramnum(n){}
	void generateDict();
	void addone();
private:
	int gramnum;
	set<string> s;
};

dictionaryGenerator::generateDict()
{
	string cur(gramnum, 'a');
	do
	{
		push(cur);
		addone(cur);
	} while (cur != "aaaa");
}

dictionaryGenerator::addone(string &str)
{
	int carrier = 1;
	for (int i = 0; i<s; i++)
	{
		a[i]+=carrier;
		carrier=0;
		if (a[i]>'z')
		{
			a[i] = 'a';
			carrier = 1;
		}
		else
			break;
	}
}

