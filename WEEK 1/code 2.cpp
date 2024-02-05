#include <iostream>
#include <vector>
using namespace std;
class search
{
public:
  int binary_search (vector < int >ar, int key)
  {
	int lb=0;
	int ub=ar.size()-1;
	int mid;
	while(lb<ub)
	{
	    mid=(ub-lb)/2;
	    if(ar[mid]<key)
	        lb=mid+1;
	    else if(ar[mid]>key)
	        ub=mid-1;
	    else
	        return mid+1;
	}
	return 0;
  }
};

int main ()
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
	  cout<<ob[i].binary_search(ar, key);
	  
	  ar.clear ();
	}
  return 0;
}




