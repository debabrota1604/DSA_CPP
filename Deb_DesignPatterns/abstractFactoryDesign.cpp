#include<bits/stdc++.h>
using namespace std;


// Button Interface-------------------------------------------------
class ButtonIntf{
    public:
    virtual void press()=0;
};

class MacButton: public ButtonIntf{
    public:
    void press(){
        cout << "Mac button pressed\n";
    }
};
class WinButton: public ButtonIntf{
    public:
    void press(){
        cout << "Win button pressed\n";
    }
};


// Textbox Interface-------------------------------------------------
class TextboxIntf{
    public:
    virtual void show()=0;
};

class MacTextbox: public TextboxIntf{
    public:
    void show(){
        cout << "This is output from Mac Textbox" << endl;
    }
};
class WinTextbox: public TextboxIntf{
    public:
    void show(){
        cout << "This is output from Win Textbox" << endl;
    }
};


// Factory Interface-------------------------------------------------
class FactoryIntf{
    public:
    virtual ButtonIntf* createButton()=0;
    virtual TextboxIntf* createTextbox()=0;
};

class MacFactory: public FactoryIntf{
    public:
    ButtonIntf* createButton(){
        return new MacButton();
    }

    TextboxIntf* createTextbox(){
        return new MacTextbox();
    }
};

class WinFactory: public FactoryIntf{
    public:
    ButtonIntf* createButton(){
        return new WinButton();
    }

    TextboxIntf* createTextbox(){
        return new WinTextbox();
    }
};


// New Abstract Factory Interface------------------------------------
class AbstractFactory: public FactoryIntf{
    public:
    static FactoryIntf* createFactory(string osType){
        if(osType == "Mac") return new MacFactory;
        else if (osType == "Win") return new WinFactory;

        else return new WinFactory; // default case
    }
};


int main(){
    cout << "Enter OS type: ";
    string osType;
    cin >> osType;

    FactoryIntf* factory = AbstractFactory::createFactory(osType);
    ButtonIntf* button = factory->createButton();
    button->press();


    TextboxIntf* textbox = factory->createTextbox();
    textbox->show();


    return 0;
}