#define BOOST_TEST_MODULE BANASHRI
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include<bits/stdc++.h>
using namespace std;

class Employee {
    string name;
    public:
    void setName (string name) {
        this->name = name;
    }
    string getName () {
        return this->name;
    }
};

int fun(){
    static int i=0;
    //int i = 0;
    i++;
    return i;
}

BOOST_AUTO_TEST_SUITE(BANASHRI)

BOOST_AUTO_TEST_CASE(test1){
    int v = 10;
    BOOST_TEST(v==10); // True
}

BOOST_AUTO_TEST_CASE(test2){
    Employee emp;
    emp.setName("Banashri");
    BOOST_CHECK(emp.getName()=="Banashri"); // True
    BOOST_CHECK_EQUAL(emp.getName(), "BanashriK"); // False
}

BOOST_AUTO_TEST_CASE(test3){
    for (int j=1; j<5; j++){
        BOOST_TEST(fun()==j); // True when static declaration is on in fun(); otherwise False
    }
}

BOOST_AUTO_TEST_SUITE_END();
