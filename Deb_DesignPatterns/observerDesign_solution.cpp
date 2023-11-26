#include<bits/stdc++.h>
using namespace std;


class XML_Data{
    string xmlData;
    public:
    XML_Data(string inputXML){
        xmlData = inputXML;
    }
    string getData(){ return xmlData; }
};

class DataAnalyticsTool{
    string jsonData;
    public:
    DataAnalyticsTool (string inputJson){
        jsonData = inputJson;
    }
    string getData(){ return jsonData; }
    virtual void analyseJsonData(){
        cout << "Analyzing JSON data..." << endl;
    }
};

// New class to convert XML to JSON
class Adapter: public DataAnalyticsTool{
    XML_Data* xmlObj;

    public:
    Adapter(XML_Data* inputXmlObj):DataAnalyticsTool("Converted " + inputXmlObj->getData()){
        xmlObj = inputXmlObj;
        cout << "Converting " << xmlObj->getData() << " into JSON data" << endl;
    }
    void analyseJsonData() override{
        cout << "Analyzing " << getData() << endl;
    }
};

int main(){
    XML_Data* xmlObj = new XML_Data("Sample XML Data");

    DataAnalyticsTool* tool = new Adapter(xmlObj);
    tool->analyseJsonData();


    return 0;
}