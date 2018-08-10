#include <iostream>
using namespace std;

int main(){
	char str[24];
	int arr[10], b[10];
	int x, i, j, k, l, y;
	int d, m=0, h, min;
	for(int i=0; i<10; i++){
		arr[i]=0;
		b[i]=0;
	}
	cin>>str;
	for(int i=0; i<23; i+=2){
		x=(int)str[i]-48;
		//cout<<x<<" ";
		arr[x]++;
		b[x]++;
	}
	
	for(i=12; i>=1; i--){
		for(j=31; j>=1; j--){
			for(k=23; k>=0; k--){
				for(l=59; l>=0; l--){

					for(y=0; y<10; y++)
						arr[y]=b[y];

					if((arr[i%10]>0 && arr[i/10]>0) || (i%10==i/10 && arr[i/10]>1) || (i<10 && arr[0]>1)){
						if(i>10){
							arr[i%10]--;
							arr[i/10]--;
						}
						else{
							arr[i]--;
							arr[0]--;
						}
						//cout<<"a"<<endl;
						//cout<<"j="<<j;

						if((arr[j%10]>0 && arr[j/10]>0) || (j%10==j/10 && arr[j/10]>1) || (j<10 && arr[0]>1)){
							if(j==31){
								if(m!=2 || m!=4 || m!=6 || m!=9 || m!=11){
									arr[3]--;
									arr[1]--;
								}
							}
							else if(j==30 && m!=2){
								arr[3]--;
								arr[0]--;
							}
							else if(j==29 && m!=2){
								arr[2]--;
								arr[9]--;
							}
							if(j>10){
								arr[j%10]--;
								arr[j/10]--;
							}
							else{
								arr[j]--;
								arr[0]--;
							}
							//cout<<"b";

							if((arr[k%10]>0 && arr[k/10]>0) || (k%10==k/10 && arr[k/10]>1) || (k<10 && arr[0]>1)){
								if(k>10){
									arr[k%10]--;
									arr[k/10]--;
								}
								else{
									arr[k]--;
									arr[0]--;
								}

								//cout<<"c";

								if((arr[l%10]>0 && arr[l/10]>0) || (l%10==l/10 && arr[l/10]>1) || (l<10 && arr[0]>1)){
									if(l>10){
										arr[l%10]--;
										arr[l/10]--;
									}
									else{
										arr[l]--;
										arr[0]--;
									}
									m=i;
									d=j;
									h=k;
									min=l;
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	cout<<m<<" "<<d<<" "<<h<<" "<<min<<endl;

	if(m==0){
		cout<<"0";
	}
	else{
		if(m<10)
			cout<<"0"<<m<<"/";
		else cout<<m<<"/";
		if(d<10)
			cout<<"0"<<d<<" ";
		else cout<<d<<" ";
		if(h<10)
			cout<<"0"<<h<<":";
		else cout<<h<<":";
		if(min<10)
			cout<<"0"<<min;
		else cout<<min;
	}

}