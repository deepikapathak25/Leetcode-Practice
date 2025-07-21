int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	/*
	//Brute force
	int ans=n;
	for(int i=0;i<n;i++){
		if(arr[i]>x){
			ans=i;
			break;
		}
	}
	return ans;
	*/

	//Binary search
	int ans=n;
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(arr[mid]>x){
			ans=mid;
			e = mid-1;	
		}else {
			s = mid+1;
		}
	}
	return ans;
}