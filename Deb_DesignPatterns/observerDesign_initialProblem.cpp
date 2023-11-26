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
    virtual void analyseJsonData(){
        cout << "Analyzing " << jsonData << endl;
    }
};

int main(){
    XML_Data* xmlObj = new XML_Data("Sample XML Data");

    //...
    //convert the XML data into JSON data somehow
    //...

    DataAnalyticsTool* tool = new DataAnalyticsTool("Converted JSON Data");
    tool->analyseJsonData();
    return 0;

}