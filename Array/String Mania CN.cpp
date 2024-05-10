/* Rohit love strings. But he has many strings with him, and he is confused about which one he loves more. So he decided to come up with a scoring system for the strings. The scoring system took two strings as input, let's call them ‘STR1’ and ‘STR2’ of length ‘N’ and length ‘M’ respectively.

The system will return ‘1’ if ‘STR1’ is better than ‘STR2’.

The system will return ‘0’ if ‘STR1’ is the same as ‘STR2’.

The system will return ‘-1’ if ‘STR2’ is better than ‘STR1’.

To decide which string is better he followed the below steps.

Let’s suppose there exists a index ‘i’ such that ‘0’ <= ‘i’ < ‘min(N,M)’ and for all ‘j<i’, ‘STR1[j]’ is equal to ‘STR2[j]’, and ‘STR1[i] != STR2[i]’.

Then if ‘STR1[i]>STR2[i]’, ‘STR1’ is better otherwise if ‘STR2[i]>STR1[i]’, ‘STR2’ is better,

And if there doesn’t exist any such ‘i’ then if ‘N>M’, ‘STR1’ is better,

And if ‘N<M’, ‘STR2’ is better, and if ‘N’ is equal to ‘M’, both strings are the same.

But Rohit has so many strings, so he doesn’t have time to go through all strings, So being his friend can you help him automate this process?.
  */
#include <bits/stdc++.h>
int stringMania(int n, int m, string str1, string str2) 
{
    int len=min(n,m);
    for(int i=0;i<len;i++){
        if(str1[i]!=str2[i]){
            if(str1[i]>str2[i]){
                return 1;
            }else if(str2[i]>str1[i]){
                return -1;
            }
        }
    }
    if(n==m){
        return 0;
    }
    if(n>m){
        return 1;
    }
    return -1;
}
