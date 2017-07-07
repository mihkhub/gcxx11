#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	for(int k = 0; k < 1024; ++k) v.insert(v.begin(), k);
	return 0;
}
