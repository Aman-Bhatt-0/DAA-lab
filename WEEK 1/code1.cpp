#include <iostream>
#include <vector>
using namespace std;
class search
{
public:
  int linear_search (vector < int >ar, int key)
  {
	for (int i = 0; i < ar.size (); i++)
	  {
		if (ar[i] == key)
		  {
			cout << "present " << i + 1;
			cout << ar.size ();
			return i + 1;
		  }
	  }
	cout << "Not present ";
	return 0;
  }
};

int
main ()
{
  int n;
  cin >> n;
  search ob[n];
  vector < int >ar;
  int a;
  for (int i = 0; i < n; i++)
	{
	  int siz;
	  cin >> siz;
	  for (int j = 0; j < siz; j++)
		{
		  cin >> a;
		  ar.push_back (a);
		}
	  int key;
	  cin >> key;
	  ob[i].linear_search (ar, key);
	  ar.clear ();
	}
  return 0;
}
