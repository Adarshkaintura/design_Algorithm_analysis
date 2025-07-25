class Solution {
public:
vector<int> splitString(string s,char dm){
    vector<int> ans;
    int start=0;
    int end=s.find(dm,start);
    while(end!=string::npos){
        string temp=s.substr(start,end-start);
        ans.push_back(stoi(temp));
        start=end+1;
        end=s.find(dm,start);

        
    }
    string temp=s.substr(start,end-start);
    ans.push_back(stoi(temp));
    return ans;
}
    int compareVersion(string version1, string version2) {
        vector<int>v1=splitString(version1,'.');
        vector<int>v2=splitString(version2,'.');

        int val1,val2;
        for(int i=0;i<max(v1.size(),v2.size());i++){
            val1=i<v1.size()?v1[i]:0;
            val2=i<v2.size()?v2[i]:0;
            if(val1<val2) return -1;
            else if(val1>val2) return 1;
        }
        return 0;

    }
};
