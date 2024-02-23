#include <iostream> 
#include<vector>

using namespace std;
class Main{
    public:
    int countPair(vector<int> arr,int k)
    {
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(abs(arr[i]-arr[j])==k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    int t;
    cout<<"ENter Test Case"<<endl;
    cin>>t;
    Main ob[t];
    for(int i=0;i<t;i++)
    {
        int n;
        cout<<"Enter size of vector";
        cin>>n;
        vector<int> arr;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            arr.push_back(a);
        }
        int k;
        cout<<"Enter value of k";
        cin>>k;
        cout<<ob[i].countPair(arr,k);
        arr.clear();

    }
}
