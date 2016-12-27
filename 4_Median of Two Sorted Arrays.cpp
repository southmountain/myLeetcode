class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if((m+n)%2==0)
        {
            int k=(m+n)/2;
            return (findKthValue(nums1.begin(),m,nums2.begin(),n,k)+
            findKthValue(nums1.begin(),m,nums2.begin(),n,k+1))/2;
        }else
        {
            int k=(m+n)/2+1;
            return findKthValue(nums1.begin(),m,nums2.begin(),n,k);
        }
        
    }
private:
    //假设m<n，
    double findKthValue(vector<int>::iterator A,int m,vector<int>::iterator B,int n,int k)
    {
        if(m>n)return findKthValue(B,n,A,m,k);
        if(m==0)return *(B+k-1);
        if(k==1)return min(*A,*B);
        
        int ia=min(k/2,m),ib=k-ia;
        if(*(A+ia-1)<*(B+ib-1))
        return findKthValue(A+ia,m-ia,B,n,ib);
        else if(*(A+ia-1)>*(B+ib-1))
        return findKthValue(A,m,B+ib,n-ib,ia);
        else
        return *(A+ia-1);
    }
};