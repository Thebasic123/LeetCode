//very classic interview question
//many different versions

//1.
//hashMap method, with O(n) time and O(n) space
//works for general cases
int findDuplicate(vector<int>& nums){
	map<int,int> m;
	for(int i=0;i<nums.size();i++){
		map<int,int>::iterator it = m.find(nums[i]);
		if(it != m.end()){
			it->second++;
		}else{
			m.insert(std::make_pair(nums[i],1));
		}
	}
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		if(it->second > 1){
			return it->first;
		}
	}
	return -1;//no duplicate value
}

//2.
//sort method,with O(nlogn) time, and O(1) space
//works for general case
int findDuplicate(vector<int>& nums){
	sort(nums.begin(),nums.end());
	int curr = INT_MIN;//set to unused number
	for(int i=0;i<nums.size();i++){
		if(nums[i] == curr){
			return nums[i];
		}else{
			curr = nums[i];
		}
	}
	return -1;//no duplicate value
}

//3.
//loop through the given array, and the current number is n,
//we go to nth element, if nth element is positive, then we change 
//it to negative, if nth element is already negative, it means we visited
//this element before, since we have a dulicate, return n

//this algo only works for all numbers are positive integers, >=1
//this algo has time complexity O(n) and O(1) space complexity
//but this algo changes the input array
int findDuplicate(vector<int>& nums){
	for(int i=0;i<nums.size();i++){
		int index = abs(nums[i]);
		if(nums[index] > 0){
			nums[index] = -nums[index];
		}else{
			return index;
		}
	}
	return -1;
}

//4.
//this method uses binary search and pigeonhole priciple
//this only works for n+1 elements between 1-n range
//O(nlogn) time and O(1) time complexity
int findDuplicate(vector<int>& nums){
	int low = 1;
	int high = nums.size()-1;
	while(low < high){
		int mid = low+(high-low)/2;
		int count = 0;
		for(int i=0;i<nums.size();i++){
			if(nums[i]<=mid){
				count++;
			}
		}
		if(count<=mid){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low;
}
