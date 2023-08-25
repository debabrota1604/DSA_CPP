#include<iostream>
using namespace std;


class A{
	string s;
	public:
	A(string s): s(s);
	string operator+(A obj){
		return this->s + obj.s;
	}	
}	

int main(){
	A a("ABC") , b ("D");
	cout << a+b << endl;
	
	return 0;
}



void rightShift(vector<int>& inp){
	int buffer, lastVal = inp[inp.size()-1];
	for(int iter = 0; iter<inp.size(); iter++){
		buffer = inp[iter];
		inp[iter] = lastval;
		lastVal = buffer;
	}
}

int insertNodeNth(Node *head, int pos, int data){
	if(pos !=0 && head ==nullptr) return -1;
	else{
		int len=0;
		//compute list length
		
		if(pos ==0){			
			Node *newNode = Node(data);
			newNode->next = head;
			head = newNode;
			return 0;
		}
		if(len < pos-1) return -1;
		else if(len == pos-1){
			Node *iter = head;
			// iterate iter to n-1'th node.
			
			Node *newNode = Node(data);
			iter->next = newNode;
		}
		else{// insert in the middle
			
			Node *iter = head;
			// iterate iter to n-1'th node.
		
			Node *newNode = Node(data);
			newNode->next = iter->next;
			iter->next = newNode;
		}		
	}
	return 0;
}
