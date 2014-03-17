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
	FeatureSets(set<string> &input1, set<string> &input2, int k, set<string>& allfeatures):s1(input1), s2(input2), testrounds(k)
	{
		featureset = vector<string>(allfeatures.begin(), allfeatures.end());
		N = featureset.size();
	}

	~FeatureSets(){};
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
	set<string> s1, s2;
	vector<string> featureset;
	int testrounds;
	int N;
};

double FeatureSets::minhash()
{
	vector<int> randperm(N, 0);
	double crash = 0;
	for (int i = 0; i < N; i++)
		randperm[i] = i;
	//randmix(randperm, N);
	for (int i = 0; i < testrounds; i++)
	{
		for (int j = 0; j < N; j++)
		{
			swap(randperm[j],randperm[j+randgen(N-j)]);
			int idx = randperm[j];
			string pivot = featureset[idx];
			bool flag1 = (find(s1.begin(), s1.end(), pivot) == s1.end())? false:true;
			bool flag2 = (find(s2.begin(), s2.end(), pivot) == s2.end())? false:true;
			if ((flag1 && !flag2) || (flag2 && !flag1))
				break;
			else if (flag1 && flag2)
			{
				crash++;
				break;
			}
		}
	}
	return (double)crash/(double)testrounds;
}
