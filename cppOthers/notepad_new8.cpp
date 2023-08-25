
int max(vector<int> inp){
	int res = inp[0];
	for(int iter=1; iter<inp.size(); iter++){
		if(res>inp[iter]) res = inp[iter];
	}
	return res;
}

[ 5, 1 ,6]
