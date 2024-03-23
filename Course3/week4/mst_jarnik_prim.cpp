#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
using namespace :: std;


class Graph{
public:
    Graph(string filename): graph(), nodes(0){
        ifstream graph_file(filename);
        istream_iterator<string> start(graph_file), end;
        vector<string> graph_components(start, end);
        generateGraph(graph_components);
    }

    void generateGraph(vector<string> graph_components) {
        nodes = stoi(graph_components[0]);

        for (int i=1; i<=(graph_components.size()-1)/3; i++){
            ...
        }
    }

private:
    int nodes;
    vector<vector<double>> graph;
};



int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Need inputfile.\n\n");
        exit(1);
    }

    string filename = string(argv[1]);

    Graph g = Graph(filename);

    return 0;
}
