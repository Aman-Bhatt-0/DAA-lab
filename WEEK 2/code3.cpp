#include <iostream>
#include <vector>
using namespace std;
class indices
{
public :
   int triplets(vector <int> &arr,int key)
    {
        int i=0,j=0,c=0;
        vector <int>ans(3,-1);
        for(int k=arr.size()-1;k>=0;k--)
        {
            i=0;
            j=k-1;
            while(i<j)
            {
                if(key==abs(arr[j]-arr[i]))
                {
                    c++;
                }
                else if(arr[k]>abs(arr[i]-arr[j]))
                    i++;
                else
                    j--;
            }
        }
        return c;
    }
};
int main()
{
    int n;
    cout<<"enter n:";
    cin >> n;
    indices ob[n];
    vector < int >ar;
    int a;
    for (int i = 0; i < n; i++)
	{
	  int siz;
	  cout<<"enter size";
	  cin >> siz;
	  for (int j = 0; j < siz; j++)
		{
		    cout<<"enter num";
            cin >> a;
            ar.push_back (a);
		}
		int key;
		cout<<"enter key";
		cin>>key;
	    cout<<ob[i].triplets(ar,key);
        ar.clear ();
	}
  return 0;
}

