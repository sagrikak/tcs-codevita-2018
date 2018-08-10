#include<iostream>
using namespace std;

void quicksort(char a[], int beg, int end)
{
    char pivot, temp;
    int x, i;
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
	int n;
	cin>>n;
	char mat[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>mat[i][j];
	}

	int i=0, j=0, k;
	char arr[8];

	while(mat[i][j]!='D' && i<n && j<n){
		if(mat[i][j]=='A'){	

			if(mat[i+1][j] == 'R'){
				i++;
				mat[i][j]='V';
			}
			else if(mat[i][j+1] == 'R'){
				j++;
				mat[i][j]='V';
			}
			else if(mat[i+1][j+1] == 'R'){
				i++;
				j++;
				mat[i][j]='V';
			}
		}

		if(mat[i][j]=='V'){
			k=0;
			if((mat[i-1][j-1]=='L' || mat[i-1][j-1]=='S' || mat[i-1][j-1]=='T' || mat[i-1][j-1]=='W') && i-1>=0 && j-1>=0){
				arr[k]=mat[i-1][j-1];
				k++;
			}
			if((mat[i-1][j]=='L' || mat[i-1][j]=='S' || mat[i-1][j]=='T' || mat[i-1][j]=='W') && i-1>=0){
				arr[k]=mat[i-1][j];
				k++;
			}
			if((mat[i-1][j+1]=='L' || mat[i-1][j+1]=='S' || mat[i-1][j+1]=='T' || mat[i-1][j+1]=='W') && i-1>=0 && j+1<n){
				arr[k]=mat[i-1][j+1];
				k++;
			}
			if((mat[i][j-1]=='L' || mat[i][j-1]=='S' || mat[i][j-1]=='T' || mat[i][j-1]=='W') && j-1>=0){
				arr[k]=mat[i][j-1];
				k++;
			}
			if((mat[i][j+1]=='L' || mat[i][j+1]=='S' || mat[i][j+1]=='T' || mat[i][j+1]=='W') && j+1<n){
				arr[k]=mat[i][j+1];
				k++;
			}
			if((mat[i+1][j-1]=='L' || mat[i+1][j-1]=='S' || mat[i+1][j-1]=='T' || mat[i+1][j-1]=='W')&& i+1<n && j-1>=0){
				arr[k]=mat[i+1][j-1];
				k++;
			}
			if((mat[i+1][j]=='L' || mat[i+1][j]=='S' || mat[i+1][j]=='T' || mat[i+1][j]=='W') && i+1<n){
				arr[k]=mat[i+1][j];
				k++;
			}
			if((mat[i+1][j+1]=='L' || mat[i+1][j+1]=='S' || mat[i+1][j+1]=='T' || mat[i+1][j+1]=='W') && i+1<n && j+1<n){
				arr[k]=mat[i+1][j+1];
				k++;
			}
			if(k>0){
				quicksort(arr, 0, k-1);
				//cout<<k<<" ";
				for(int x=0; x<k; x++)
					cout<<arr[x]<<" ";
				cout<<endl;
			}
			else cout<<"NO HURDLES"<<endl;

			if((mat[i+1][j] == 'D' && i+1<n) || (mat[i+1][j-1]=='D' && i+1<n && j-1>=0) || (mat[i+1][j+1]=='D' && i+1<n && j+1<n) || (mat[i][j+1]=='D' && j+1<n) || (mat[i][j-1]=='D' && j-1>=0) || (mat[i-1][j]=='D' && i-1>=0) || (mat[i-1][j-1]=='D' && i-1>=0 && j-1>=0) || (mat[i-1][j+1]=='D' && i-1>=0 && j+1<n)){
				cout<<"DESTINATION";
				break;
			}

			if(mat[i+1][j] == 'R' && i+1<n){
				i++;
				mat[i][j]='V';
			}
			else if(mat[i][j+1] == 'R' && j+1<n){
				j++;
				mat[i][j]='V';
			}
			else if(mat[i+1][j+1] == 'R' && i+1<n && j+1<n){
				i++;
				j++;
				mat[i][j]='V';
			}
			else if(mat[i+1][j-1] == 'R' && i+1<n && j-1>=0){
				i++;
				j--;
				mat[i][j]='V';
			}
			else if(mat[i][j-1] == 'R' && j-1>=0){
				j--;
				mat[i][j]='V';
			}
			else if(mat[i-1][j-1] == 'R' && i-1>=0 && j-1>=0){
				i--;
				j--;
				mat[i][j]='V';
			}
			else if(mat[i-1][j] == 'R' && i-1>=0){
				i--;
				mat[i][j]='V';
			}
			else if(mat[i-1][j+1] == 'R' && i-1>=0 && j+1<n){
				i--;
				j++;
				mat[i][j]='V';
			}

		}
	}
}