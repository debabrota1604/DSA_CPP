//This program aims to find the maximum number of elements producing exact sum as provided

// Can be solved using 1D memoization table

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& tempRes, vector<int>& inp, int index, int targetSum){
	if(targetSum ==0){
		res.emplace_back(tempRes);
	}
	for(int iter=index; iter<inp.size(); iter++){
		if(iter>index && inp[iter] == inp[iter-1]) continue;

		if(targetSum - inp[iter] >=0){
			tempRes.emplace_back(inp[iter]);
			dfs(res, tempRes, inp, iter, targetSum - inp[iter]);
			tempRes.pop_back();
		}
	}
}

int getMaxSize(vector<int> inp, int targetSum){
	vector<vector<int>> res;
	vector<int> temp;
	dfs(res, temp, inp, 0, targetSum);
	return res.size();
}

int main(){
	vector<int> inp {2,2,3,5,10};
	int target= 10;

	cout << "Max number of combinations with exact sum: " << getMaxSize(inp, target) << endl;


	return 0;

}
