#include<iostream>
using namespace std;

void quicksort(int a[], int beg, int end)
{
    int pivot, x, i, temp;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2];
    a[(beg+end)/2]=a[end];
    a[end]=temp;
    
    pivot=a[end];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i]<=pivot)
        {
            temp=a[x];
            a[x]=a[i];
            a[i]=temp;
            x++;
        }
    }
    temp=a[end];
    a[end]=a[x];
    a[x]=temp;
    quicksort(a, beg, x-1);
    quicksort(a, x+1, end);
}

int main(){
	int n, x=0, sum=0;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	quicksort(arr, 0, n-1);
	sum-=arr[n-1];
	if(n<3)
		cout<<"0";
	else{
		for(int i=n-1; i>=2; i--){
			if(arr[i]<sum){
				x=1;
				cout<<i+1;
				break;
			}		
			sum-=arr[i-1];	
		}
		if(x==0)
			cout<<"0";
	}
}