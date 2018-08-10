#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[6]={2, 3, 5, 7, 11, 13};
    int arr2[6];
    int j=0, res=0, multi=1;
    for(int i=0; i<6; i++){
        if(n%arr[i]==0 && n!=0){
            arr2[j]=arr[i];
            multi*=arr2[j];
            j++;
        }
    }

    int s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;

    for(int i=1; i<=j; i++){
    	if(i==1){
    		for(int k=0; k<j; k++){
    			s1=s1+n/(arr2[k]);
    		}
    	}
    	if(i==2){
    		for(int k=0; k<j-1; k++){
    			for(int l=k+1; l<j; l++){
    				s2=s2+(n/(arr2[k]*arr2[l]));
    			}
    		}
    	}
    	if(i==3){
    		for(int k=0; k<j-2; k++){
    			for(int l=k+1; l<j-1; l++){
    				for(int m=l+1; m<j; m++){
    					s3=s3+(n/(arr2[k]*arr2[l]*arr2[m]));
    				}
    			}
    		}
    	}
    	if(i==4){
    		for(int k=0; k<j-3; k++){
    			for(int l=k+1; l<j-2; l++){
    				for(int m=l+1; m<j-1; m++){
    					for(int o=m+1; o<j; o++){
    						s4=s4+(n/(arr2[k]*arr2[l]*arr2[m]*arr2[o]));
    					}
    				}
    			}
    		}
    	}
    	if(i==5){
    		for(int k=0; k<j-4; k++){
    			for(int l=k+1; l<j-3; l++){
    				for(int m=l+1; m<j-2; m++){
    					for(int o=m+1; o<j-1; o++){
    						for(int p=o+1; p<j; p++){
    							s5=s5+(n/(arr2[k]*arr2[l]*arr2[m]*arr2[o]*arr2[p]));
    						}
    					}
    				}
    			}
    		}
    	}
    	if(i==6)
    		s6=n/multi;
    }

    res=n-(s1-s2+s3-s4+s5-s6);
    cout<<res;
}