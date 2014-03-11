#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace::std;

class FeatureSets
{
public:
	FeatureSets(set<string> &input1, set<string> &input2, vector<string>& fs, int k):s1(input1), s2(input2), featureset(fs), testrounds(k){}
	~FeatureSets();

	double jaccardsim();

	double minhash();

	int randgen(int max)  //generate a random interger from 0 to max-1
	{
		return (rand()%max);
	}

	void randperm(vector<int> &v, int N)
	{
		for (int i = 0; i < N; i++)
			swap(v[i], v[i+randgen(N-i)]);
	}

private:
	set<string> s1, set<string> s2;
	vector<string> featureset;
	int testrounds;
};

FeatureSets::jaccardsim()
{
	vector<bool> f1(featureset.size(), false);
	vector<bool> f2(featureset.size(), false);
	setfeaturevector(featureset, f1, f2);
	return minhash(testrounds);
}

double FeatureSets::minhash()
{
	int N = featuresets.size();
	vector<int> randperm(N, 0);
	double crash = 0;
	for (int i = 0; i < N; i++)
		randperm[i] = i;
	//randmix(randperm, N);
	for (int i = 0; i < testrounds; i++)
	{
		for (int j = 0; j <testrounds; j++)
		{
			swap(v[j],v[j+randgen(N-j)]);
			int idx = v[j];
			string pivot = featureset[idx];
			bool flag1 = (find(s1.begin(), s1.end(), pivot) == s1.end())? false:true;
			bool flag2 = (find(s2.begin(), s2.end(), pivot) == s2.end())? false:true;
			if ((flag1 && !flag2) || (flag2 && !flag1))
				break;
			else if (flag1)
			{
				crash++;
				break;
			}
		}
	}
	return (double)crash/(double)testrounds;
}
