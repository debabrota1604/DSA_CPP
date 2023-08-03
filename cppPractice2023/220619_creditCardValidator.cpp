#include<iostream>
using namespace std;

bool isNumberOnly(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]<'0' || s[i]>'9') return false;
	}
	return true;
}

string cardType(string inp){
	if(inp.size()==16 && inp[0]=='5' && (inp[1] >='1' && inp[1] <= '5')){ //prefix 51-55
		return "MasterCard";
	}
	else if(inp.size()==15 && inp[0] =='3' && (inp[1] =='4' || inp[1] =='7')){ //prefix 34 or 37
		return "American Express";
	}
	else if(inp.size()==14 && inp[0] =='3' && inp[1] =='0' && inp[2] >='0' && inp[2] <='5'){ //prefix 300-305
		return "Diners Club Carte Blanche";
	}
	else if(inp.size()==14 && inp[0] =='3' && inp[1] =='6'){ //prefix 36
		return "Diners Club International";
	}
	else if(inp.size()==16 && inp[0] =='5' && (inp[1] =='4' || inp[1] =='5')){ //prefix 54-55
		return "Diners Club US and Canada";
	}
	return "-1";
}

int main(){
	string s= "3723153752975208";
	int num=0;
	cout << "current number: " << stoi(s) << endl;
	cin >> num;
	cout << "addition Result: " << stoi(s) + num << endl;



	return 0;
}
