class Solution {
public:
    char kthCharacter(int k) {
        vector<char> vec;
        char ch='a';
        vec.push_back(ch);
        while(vec.size()<k){
          int n=vec.size();
          for(int i=0;i<n;i++){
            ch=vec[i];
            if(ch!='z'){
               ch++;
            }else{
                ch='a';
            }

            vec.push_back(ch);
          }
        }
return vec[k-1];
    }
};
class Solution {
public:
    char kthCharacter(int k) {
        int x=__builtin_popcount(k-1);
        return 'a'+x;
    }
};
