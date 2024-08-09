//no space but time is still O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       int n=n1+n2;
       int idx2=n/2;
       int idx1=idx2-1;
       int cnt=0;
       int i=0,j=0;
       int ind1el=-1,ind2el=-1;
       while(i<n1 && j<n2 ){
        if(nums1[i]<nums2[j]){ 
            if(cnt==idx1) ind1el=nums1[i];
            if(cnt==idx2) ind2el=nums1[i];  
           i++;
        }else{
            if(cnt==idx1) ind1el=nums2[j];
            if(cnt==idx2) ind2el=nums2[j]; 
            j++;
        }
          cnt++;
       }
       while(i<n1){
         if(cnt==idx1) ind1el=nums1[i];
            if(cnt==idx2) ind2el=nums1[i];  
           i++;
           cnt++;
       }
       while(j<n2){
        if(cnt==idx1) ind1el=nums2[j];
            if(cnt==idx2) ind2el=nums2[j]; 
            j++;
            cnt++;
       }
       if(n%2==1){
        return (double)ind2el;
       }
       return (double)(ind1el+ind2el)/2.0;
    }
};
//optimized
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       if(n1>n2){
        return findMedianSortedArrays(nums2,nums1);
       }
       int l=0;
       int h=n1;
       int left=(n1+n2+1)/2;
       int n=n1+n2;
       while(l<=h){
        int mid1=(l+h)/2;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1<n1)r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(mid1-1 >= 0) l1=nums1[mid1-1];
        if(mid2-1 >= 0) l2=nums2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1){
                 return (double)max(l1,l2);
            }
            return (double)(max(l1,l2)+min(r1,r2))/2.0;

        }
        else if(l1>r2){
            h=mid1-1;
        }
        else{
            l=mid1+1;
        }


       }
       return 0;
    }
};
