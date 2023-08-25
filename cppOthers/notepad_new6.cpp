
		
		
void swapStrings(char **s1, char **s2){
	char *temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}


int main(){
	char *p = "Hi", *p1 = "Hello";
	swapStrings (&p, &p1);
}



void reverse(char **s, int size){
	if(size >= 0){
		reverse(s
		
		

int main(){
	char *p = "Hello", res = "\0";
	int size = 5;
	reverse(&p, size);
}
H-e-l-l-o-\0
H


void reverseStr(string s, int index){
	if(index >=0){
		return  to_string(s[index]) + reverseStr(s, index-1);
	}
	else return "";
}

int main(){
	string s = "Hello";
	reverseStr(s,s.size()-1);
	
	

	
"Hello" ,4 : "o" + "lleh" = "olleH"
"Hello" ,3 : "l" + "leH" = "lleH"
"Hello" ,2 : "l" + "eH" = leH
"Hello" ,1 : "e" + "H" = "eH"
"Hello" ,0 : "H" + ""
"Hello" ,-1: RETURN






class A{
	static int a;
	int b;
}
int main(){
	A obj;
	cout << sizeof(obj) << endl;
}




