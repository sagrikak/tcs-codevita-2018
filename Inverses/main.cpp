#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0, j=0, ans=0;
    int arr[6]={2, 3, 5, 7, 11, 13};
    int arr2[6];
    for(int i=0; i<6; i++){
        if(n%arr[i]==0){
            arr2[j]=arr[i];
            j++;
        }
    }
    for(int i=1; i<=n; i++){
        count=0;
        for(int k=0; k<j; k++){
            if(i%arr2[k]==0){
                count++;
                break;
            }
        }
        if(count==0)
            ans++;
    }
    cout<<ans;
    return 0;
}