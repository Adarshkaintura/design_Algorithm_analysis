#include <bits/stdc++.h> 
int findnext(vector<int>& vis,int i,int n){
	while(vis[i]!=0){
		i++;
		i%=n;
		if(i==0){
           i=n;
		}
	}
	return i;
}
vector<int> theOrder(int n)
{
	vector<int>ans;
	vector<int>vis(n+1,0);
	int c=0;
	int i=1;
	while(c<n){
		i=findnext(vis,i,n);
		i++;
		i%=n;
		if(i==0){
			i=n;
		}
		i=findnext(vis,i,n);
		ans.push_back(i);
		vis[i]=1;
		c++;
	}
	return ans;
}
