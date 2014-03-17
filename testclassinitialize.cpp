#include <iostream>
#include <vector>

using namespace::std;

class testclassinitialize
{
public:
	testclassinitialize(vector<int>& oriv)
	{
		copyv = vector<int> (oriv.begin(), oriv.end());
	}

	void printv()
	{
		for(vector<int>::iterator it = copyv.begin(); it != copyv.end(); it++)
			cout << *it << "\t";
		cout << endl;
	}
	//~testclassinitialize();

private:
	vector<int> copyv;
};


int main()
{
	int arr[] = {1,2,3,4,5};
	vector<int> v(arr, arr+5);
	testclassinitialize t(v);
	t.printv();
	return 0;
}