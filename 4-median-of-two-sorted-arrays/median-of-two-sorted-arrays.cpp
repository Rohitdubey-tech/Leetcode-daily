class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> Combined(nums1.size()+nums2.size());
    for(int i=0; i<(nums1.size()); i++)
    {
        Combined[i]=nums1[i];
    }    
    for(int i=nums1.size(); i<(nums1.size()+nums2.size()); i++)
    {
        Combined[i]=nums2[i-nums1.size()];
    }
    std::sort(Combined.begin(), Combined.end());
    if((nums1.size()+nums2.size())%2==1)
    {
        return Combined[((nums1.size()+nums2.size()-1)/2)];
    }
    else
    {
        int size = Combined.size();
        return ((Combined[(size+1)/2]+Combined[(size-1)/2])/2.0);
    }
    }
};