class Solution {
public:
    int maxArea(vector<int>& height) {
        //Brute force
        int maxWater=0;
        vector<int> ans;

        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int width=j-i;
                int ht=min(height[i],height[j]);
                int area=width*ht;
                maxWater=max(area,maxWater);
            }
        }
        return maxWater;

        //Optimized Approach(2-Pointer)
        int maxWater=0;
        int n=height.size();
        int lp=0, rp=n-1;
        while(lp<rp){
            int ht=min(height[lp],height[rp]);
            int wd=rp-lp;
            int storage=ht*wd;
            maxWater=max(storage,maxWater);
            height[lp]<height[rp]?lp++:rp--;
        }
        return maxWater;
    }
};