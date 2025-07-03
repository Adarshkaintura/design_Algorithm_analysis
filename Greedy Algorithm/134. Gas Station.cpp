//brute O(n^2);
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int cst=0;
        int gs=0;
        for(int i=0;i<n;i++){
            gs=0;
           int idx=i;
           int j=idx;
           while(1){
            gs +=gas[j];
           cst=cost[j];
            if(gs-cst>=0){
                 gs=gs-cst;
                j=(j+1)%n;
                if(j==idx){
                    return idx;
                }   
            }else{
                break;
            }

           }
        }
return -1;
    }
};
//optimized
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0,sumc=0;
        for(int i=0;i<cost.size();i++){
            sumg+=gas[i];
            sumc+=cost[i];
        }
        if(sumg<sumc){
            return -1;
        }
        int result=0;
        int total=0;
        for(int i=0;i<cost.size();i++){
           total+=gas[i]-cost[i];
           if(total<0){
            result=i+1;
           total=0;
           }
        }
        return result;
    }
};
