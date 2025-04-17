#include <bits/stdc++.h> 
string rotateString(int n,string s,int i){
	reverse(s.begin()+i,s.end());
	reverse(s.begin(),s.end());
	reverse(s.begin()+(n-i),s.end());
	return s;
}
int minimumRotations(int n, string s)
{
	if(n==1){
		return 1;

	}
	for(int i=1;i<n;i++){
	string str=rotateString(n,s,n-i);
	if(str==s){
		return i;
	}

}
	return n;
}
