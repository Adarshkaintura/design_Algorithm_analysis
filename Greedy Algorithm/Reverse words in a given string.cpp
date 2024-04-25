//Brute force
class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverse(string& str,int i,int j){
        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string S) 
    { 
      int i=0;
      int j=S.length()-1;
      while(i<j){
          swap(S[i],S[j]);
          i++;
          j--;
      }
      j=0;
      for(i=0;i<S.length();i++){
          if(S[i]=='.'){
              reverse(S,j,i-1);
              j=i+1;
              
          }
      }
      reverse(S,j,i-1);
      return S;
    } 
};
//optimized
