//iteratively
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        
        for(int i=0;i<nums.size();i++){
            int n = result.size();
            for(int j=0;j<n;j++){
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
            
        }
        return result;
    }
};


//recursively
class Solution {
public:
	void appendSet(vector<int>& nums,vector<vector<int>>& result,vector<int> curr,int index){
		result.push_back(curr);
		for(int i=index;i<nums.size();i++){
			vector<int> temp = curr;
			temp.push_back(nums[i]);
			appendSet(nums,result,temp,i+1);
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        appendSet(nums,result,curr,0);
        return result;
    }
};

//bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int total_num = pow(2,nums.size());
        vector<vector<int>> result(total_num,vector<int>());
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<total_num;j++){
                if((j>>i)&1){
                    result[j].push_back(nums[i]);
            
                }        
            }
        }
        return result;
    }
};
