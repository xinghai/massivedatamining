#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>

using namespace::std;

class FeatureSets
{
public:
	FeatureSets(set<T> &input1, set<T> &input2) s1 = input1, s2 = input2;
	~FeatureSets();

	double jaccardsim(set<T>& s1, set<T>& s2, vector<T>& featureset, int testrounds)
	{
		vector<bool> f1(featureset.size(), false);
		vector<bool> f2(featureset.size(), false);
		setfeaturevector(s1, s2, featureset, f1, f2);
		return minhash(f1, f2, f1.size(), testrounds);
	}

	void setfeaturevector(set<T>& s1, set<T>& s2, vector<T>& featureset, vector<bool> &f1, vector<bool> &f2)
	{
		for(int i = 0; i< featureset.size(); i++)
		{
			if (s1.find(featureset[i]) != s1.end())
				f1[i] = true;
			if (s2.find(featureset[i]) != s2.end())
				f2[i] = true;
		}
		return;
	}

	double minhash(vector<bool> &f1, vector<bool> &f2, int N, int testrounds)
	{
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
				if ((f1[idx] && !f2[idx]) || (f2[idx] && !f1[idx]))
					break;
				else if (f1[idx])
				{
					crash++;
					break;
				}
			}
		}
		return (double)crash/(double)testrounds;
	}

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
	set<T> s1, set<T> s2;
};
