vector<int> inp = {0, 0, 0};
vector<vector<int>> inp2d (3, inp);

inp.push_back(1); //{ 0,0,0,1}



bool fun(int x){
    while(x > 0 && x%3 ==0) x /= 3;
    if(x ==1) return true;
    else return false;
}



class A{
    int i;
    public:
    virtual void f(){ cout << "In A\n"; }
};
class B: public A{
    public:
    void f() { cout << "In B\n"; }
};
class C: public A{
    public:
    void f() { cout << "In C\n"; }
};
int main(){
    B b;
    C c;
    A *ptr = &b;
    ptr->f(); // prints In B 
    ptr = &c;
    ptr->f(); // prints In C 
    
    return 0;
}


void strcpy_t(char *s, char *d){
    int len=0;
    char *temp = *s;
    while(*temp != '\0'){ 
        temp++;
        len++;
    }
    d = (char *) malloc(sizeof(char) * (len+1));
    for(int iter=0; iter<=len; iter++){
        d[iter] = s[iter];
    }
}
int main(){
    char *s = " hello",*d;
    strcpy_t(s,d);
    
    free(d);
}
    



Questions------------------------------------

bool fun(int x)
{
  //return true if x is power of 3 (1,3,9,27...)
}

void strcpy_t(char *s, char *d)
{
 //implement this.
}

int mian()
{
 char *s = " hello";
 //call strcpy_t
}

string s = "this is string"
s="string is this"
