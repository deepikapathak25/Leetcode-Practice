class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        /*
        // Linear search
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==target){
            count++;
            }
        }
        return count;
        */
        
        //Binary Search
        int s=0, e=arr.size()-1;
        int first=-1;
        int last=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==arr[mid]){
                first=mid;
                e=mid-1;
            }else if(arr[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }

        s=0, e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==arr[mid]){
                last=mid;
                s=mid+1;
            }else if(arr[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        if (first == -1 || last == -1) return 0;
        int count=last-first+1;
        return count;
    }
};
