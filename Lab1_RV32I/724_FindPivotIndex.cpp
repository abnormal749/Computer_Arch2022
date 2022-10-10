#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
	int leftSum=0,rightSum=0;
        for(int i=0; i<nums.size(); i++)
	    rightSum += nums[i];

	for(int i=0; i<nums.size(); i++){
	    rightSum -= nums[i];
	    if(leftSum == rightSum){
	        return i;
	    }else{
	        leftSum += nums[i];
	    }
	}

	return -1;
    }
};

int main(int arg, char* argv[]){
    vector<int> test1 = {1,7,3,6,5,6};
    //vector<int> test2 = {1,2,3};
    vector<int> test2 = {2,1,-1};

    Solution a;
    std::cout << a.pivotIndex(test2) << '\n';
    return 0;
}
