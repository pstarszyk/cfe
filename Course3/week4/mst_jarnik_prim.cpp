#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
using namespace :: std;


// Define a custom comparator for the min heap
struct CompareTuple {
    bool operator()(const tuple<double, int, int>& a, const tuple<double, int, int>& b) const {
        // Min heap based on the first element of the tuple (double)
        return get<0>(a) > get<0>(b);
    }
};



class Graph{
public:
    Graph(string filename) {
        // Note: as long as you define the class member (under private or public like below), you can initialize them in the 
        // constructor body however you want, even though all of the vars are released when constructor returns.
        ifstream graph_file(filename);
        istream_iterator<string> start(graph_file), end;
        vector<string> graph_components(start, end);
        nodes = stoi(graph_components[0]);
        graph = vector<vector<double>>(nodes, vector<double>(nodes, 0.0));

        int k, j;
        double c;

        for (int i=0; i<(graph_components.size()-1)/3; i++){
            k = stoi(graph_components[3*i+1]);
            j = stoi(graph_components[3*i+2]);
            c = stod(graph_components[3*i+3]);
            graph[k][j] = graph[j][k] = c;
        }
    }

    void printGraph(void) {
        for (int i=0; i<nodes; i++){
            cout << endl;
            for (int j=0; j<nodes; j++){
                    cout << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }    

    void print_mst(void){
        for (int i=0; i<nodes; i++){
            for (int j=i+1; j<nodes; j++){
                if (graph[i][j] < 0){
                    cout << i << " <---> " << j << "\n";
                }
            }
        }
        cout << endl;
    }

    void get_mst(void) {
        vector<int> closed(nodes, 0); // define closed set
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, CompareTuple> minHeap; // define min heap
        int current_source = 0; // define current node - start at 0
        closed[0] = 1; // mark current_source as closed
        int closed_count = 1;
        int new_destinations; // keep track of how many destinations we can reach every iteration 
        double destination_cost;
        double minCost = 0.0; 

        while (true){

            // step 1: for each edge with cost>0 @ current_source, IF destination is not in closed set add to heap
            for (int i=current_source+1; i<nodes; i++){ // just need to traverse upper triangular part of graph matrix
                destination_cost = graph[current_source][i];
                if (destination_cost>0 && closed[i]==0){
                    minHeap.push(make_tuple(destination_cost, current_source, i));
                }
            } 

            // step 2: pop off heap. IF destination is not in closed, make current_source = destination and mark it closed. ELSE keep popping.  
            while (!minHeap.empty()){
                auto [cost, source, destination] = minHeap.top();
                minHeap.pop();
                if (closed[destination] == 0){
                    minCost += graph[source][destination];
                    graph[source][destination] = graph[destination][source] = -1.0;
                    current_source = destination;
                    closed_count++;
                    break;
                }
            }

            if (closed_count == nodes){ // break if all nodes in closed set -- we have a solution
                cout << "minCost = " << minCost << endl;
                print_mst();
                break;
            }

            if (minHeap.empty() && closed_count < nodes){ // disconnected tree -- we don't have a solution
                cout << "Disconnected tree -- NO SOLUTION!" << endl;
                break;
            }

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

    string filename = argv[1];

    Graph g = Graph(filename);
    g.get_mst();

    return 0;
}
