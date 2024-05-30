
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hmap1(26, 0);
        vector<int> hmap2(26, 0);
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) {
            return false;
        }
        
        for (int i = 0; i < n1; ++i) {
            hmap1[s1[i] - 'a']++;
            hmap2[s2[i] - 'a']++;
        }
        
        int i = n1;
        int a = 0;
        while (i < n2) {
            if (hmap1 == hmap2) {
                return true;
            }
            hmap2[s2[a] - 'a']--; // Decrease the count of the character going out of the window
            hmap2[s2[i] - 'a']++; // Increase the count of the new character in the window
            a++;
            i++;
        }
        
        // Check the last window
        if (hmap1 == hmap2) {
            return true;
        }
        
        return false;
    }
};
