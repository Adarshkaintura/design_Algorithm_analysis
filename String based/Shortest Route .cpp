/*  Problem statement

You want to visit your friend’s house who lives at some location in an infinite grid. You are initially at the origin of the infinite grid and can move only in four directions (i.e East, West, North, South).

For Example, If you are at cell (X, Y) then you can move to East i.e at cell (X+1, Y), or West i.e at cell (X-1, Y), or North i.e at cell (X, Y+1), or South i.e at cell (X, Y-1).

Your friend gives you a string ‘STR’ of length ‘N’ that represents the route to his house from the origin. The string ‘STR’ has only four different characters, i.e ‘E’, ‘W’, ‘N’, ‘S’. which represent direction East, West, North, South, respectively.

You find out that the route given by your friend is very long, and a shorter route is also possible. Your task is to find the smallest route to reach your friend’s house. See the example for better clarity.

Note:

1. There can be more than one shortest route, you should return the one which is lexicographically smallest among them.
*/
#include <bits/stdc++.h> 
string findShortestRoute(string &str) 
{

	int ewcount=0;
	int sncount=0;
	for(int i=0;i<str.size();i++){
          if(str[i]=='S'){
			  sncount--;
		  } 
		  if(str[i]=='N'){
			  sncount++;
		  }
		  if(str[i]=='E'){
			  ewcount++;
		  }
		  if(str[i]=='W'){
			  ewcount--;
		  }
		  
	}
	string ans="";
	int sn=abs(sncount);
	int ew=abs(ewcount);
	for(int i=0;i<sn;i++){
      if(sncount>0){
		  ans+='N';
	  }else{
		  ans+='S';
	  }
	}
	for(int i=0;i<ew;i++){
		if(ewcount>0){
			ans+='E';
		}else{
			ans+='W';
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}
