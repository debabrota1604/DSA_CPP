
Class MySingletonClass{
	private:
		MySingletonClass();
		static MySingletonClass* objPtr;
	public:
		static MySingletonClass* getInstance()
};


MySingletonClass :: static MySingletonClass* getInstance(){
	if(objPtr == nullptr){ 
		objPtr = new MySingletonClass ();
	}
	Return objPtr;
}


Int main(){
	MySingletonClass::




You have 15 Rs with you. You go to a shop and the shopkeeper tells you the price is 1 Rs per soft drink. He also tells you that you can get a soft drink in return of 3 bottles. How many maximum soft drinks you can drink?

15SD + 15EB = 15SD + 5SD + 5EB = 20SD + 1SD + 1EB + 2EB = 22 SD + 1EB.


Money = 15RS
returnValue = 3
Price = 1;

Int Maxdrink(int money, int returnValue){
	Int SD=money,EB=money;
	while(EB >= returnValue){
		Int Free = EB/returnValue;
		SD +=Free;
		EB = EB%returnValue +Free;
}
	Return SD;
}
Struct Node{
	Int data;
	Node *prev, *next; //points to the prev & next node
};



Merge Two Sorted Link List, 1st in descending order and 2nd is in ascending order
List1:  8->4
List2: 1->5->7

Result 1->4->5->7->8

Node* reverseList(Node* head){
	if(head == nullptr) return nullptr;
	Else if(head->next == nullptr) return head;
	Node *temp = reverseList(node->next);
	temp->next = node;
	node->next = temp;
Return head;
}
Node* mergeList(Node* node1, Node* node2){
	//Step1: Reverse 1st List to ascending order
	Node1 = reverseList(node1);

	//Step2: Merge two ascending sorted lists to a new list
	Node *temp1 = node1, *temp2=node2, *head, *temp3, *node;
	while(temp1 && temp2){
		if(temp1->data < temp2->data){
			node = new Node();
			node->data = temp1->data;
			temp1 = temp1->next;
}
		Else{
			node = new Node();
			node->data = temp2->data;
			temp2 = temp2->next;
}
if(temp3 != nullptr){
temp3->next = node;
temp3 = temp3->next;
}
Else temp3 = node;
if(head == nullptr){ head = temp3;}
}
while(temp1 != nullptr){
	node = new Node();
		node->data = temp1->data;
		temp1 = temp1->next;
temp3->next = node;
temp3 = temp3->next;

if(head == nullptr){ head = temp3;}
}
while(temp2 != nullptr){
	node = new Node();
		node->data = temp2->data;
		temp2 = temp2->next;
temp3->next = node;
temp3 = temp3->next;

if(head == nullptr){ head = temp3;}
}
	return head;		

}

