class Solution {
  public:
  
    bool isValid(vector<int>&arr, int n, int m, int maxAllowedPages){
        int student =1, pages=0;
        for(int i=0;i<n;i++){
            if(arr[i]>maxAllowedPages){
                return false;
            }
            if(pages+arr[i]<=maxAllowedPages){
                pages+=arr[i];
            }else{
                student++;
                pages=arr[i];
            }
        }
        
        return student>m?false:true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n){
            return -1;
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int ans=-1;
        int s=0;
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};