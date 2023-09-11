//Queation: https://www.codechef.com/problems/WEIGHTBL
//Level:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int w1,w2,x1,x2,m;
	    cin>>w1>>w2>>x1>>x2>>m;
	    int min=x1*m;
	    int max=x2*m;
	    if(w2<=(max+w1) && w2>=(min+w1)){
	        cout<<1<<endl;
	    }
	    else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}