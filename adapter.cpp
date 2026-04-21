#include<iostream>
using namespace std;

// Inbuilt Graph Library which expects xml data
class Graph {
    public:

        Graph() {

        }

        // it expects XML
        virtual void showGraph(string data) {
            cout << data << endl;
        }
};

// 3rd Graph Library which works with JSON data
class AnalyticsLibrary {
    public:

        AnalyticsLibrary() {

        }

        // It expects JSON
        void renderGraph(string data) {
            cout << data << endl;
        }
};

// Adapter Class which is responsible for calling AnalyticsLibrary method
class AnalyticsAdapter: public Graph {

    private:
        AnalyticsLibrary* analyticsLibrary;

    public:

        AnalyticsAdapter() {
            this->analyticsLibrary = new AnalyticsLibrary();
        }


        void showGraph(string xmlData) override {
            // convert xml to json
            string jsonData =  xmlData + "to JSON";
            this->analyticsLibrary->renderGraph(jsonData);
        }
};

class Stock {
    private:
        string xmlData;
    public:
        void setData(string data) {
            this->xmlData = data;
        }
        void showGraph(Graph* library) {
            library->showGraph(this->xmlData);
        }
};

int main() {
    string stockData = "XML";
    Stock* stock = new Stock();
    stock->setData(stockData);

    Graph* graph = new Graph();

    // "XML";
    stock->showGraph(graph);

    AnalyticsAdapter* analyticsAdapter = new AnalyticsAdapter();

    // "XML to JSON";
    stock->showGraph(analyticsAdapter);

    return 0;
}