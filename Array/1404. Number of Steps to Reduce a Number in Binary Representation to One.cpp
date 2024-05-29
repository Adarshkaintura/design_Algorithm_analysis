//my approach 30 test case passed out of 80 
class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        long long num=0;
          for (int i = 0; i < n; i++) {
            num += (s[i] - '0') * pow(2, n - 1 - i);
        }
        int steps=0;
        while(num!=1){
           if(num%2==0){
            num=num/2;
           }else{
            num += 1;
           }
           steps++;
        }
        return steps;
    }
};

// let see the optimized
class Solution {
public:
   
   void addone(string& s){
    int n=s.length();
    int i=n-1;
    while(i>=0 && s[i]!='0'){
        s[i]='0';
        i--;
    }
    if(i<0){
        s = '1'+s;
    }else{
        s[i]='1';
    }
   }
    int numSteps(string s) {
        int steps=0;
        while(s.length()>1){
            int n=s.length();
            if(s[n-1]=='1'){
                addone(s);
                
            }else{
               s.pop_back();
            }
            steps++;
        }
        return steps;
    }
};
