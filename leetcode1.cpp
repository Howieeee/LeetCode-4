class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int aSize = nums1.size(), bSize =nums2.size(); 
        int size = aSize + bSize; //計算最後排序完的Size
        int pA =0,pB=0; //用兩個pointer達到 O(m+n)
        double median = 0;
        
        for(int i=0;i<size;i++){
            
            if(pA != aSize && pB != bSize){
                if(nums1[pA] <= nums2[pB]){
                    ans.push_back(nums1[pA]);
                    pA +=1;
                }else if(nums2[pB] <= nums1[pA]){
                    ans.push_back(nums2[pB]);
                    pB +=1;
                }
            }else if(pA == aSize){
                ans.push_back(nums2[pB]);
                pB +=1;
            }else if(pB == bSize){
                ans.push_back(nums1[pA]);
                pA +=1;
            }
            
        }
        
        int idx = size/2; //還沒變成index
        idx -=1 ;//先變成index
        if(size%2 ==0){ // size是偶數 要 idx and idx+1  /2
            median = double((ans[idx] + ans[++idx]))/2;
            //cout << median;
            return median;
        }else{ //size是偶數 就是idx+1
            return double(ans[++idx]);
        }
    }
};
