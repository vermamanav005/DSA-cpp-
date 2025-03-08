#include <bits/stdc++.h>
using namespace std;


int ncr(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++){
        ans=ans*(n-i);
        ans=ans/(r-i);
    }
    return ans;
    
}

int main() {
	// your code goes here
	int ans = ncr(4,0);
	cout<<ans;

}