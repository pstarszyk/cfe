#include <iostream>
#include <vector>
#include <limits>
#include <random>
using namespace :: std;


double randomFloat(double range[]) {
    random_device rd; // Obtain a random number from hardware
    uniform_real_distribution<> distr(range[0], range[1]); // Define the range
    double rand = distr(rd); // Generate a random double within range
    return rand;
}


class Graph{
public:
    Graph(int nodes=1): nodes(nodes), graph(nodes, vector<double>(nodes, 0)){
        // constructor initializes a graph with no edges.
    }

    void generateGraph(double density, double range[]) {
        double prange[2] = {0.0, 1.0};
        for (int i=0; i<nodes; i++){
            for (int j=i+1; j<nodes; j++){
                double prob = randomFloat(prange);
                if (prob < density){
                    double distance = randomFloat(range);
                    graph[i][j] = graph[j][i] = distance;

                }
            }
        }
    }

    void printGraph() {
        for (int i=0; i<nodes; i++){
            cout << endl;
            for (int j=0; j<nodes; j++){
                    cout << " " << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    void get_neighbour_data(int node, vector<int>& neighbours, vector<double>& distances) {
        for (int i=0; i<nodes; i++){
            if (graph[node][i] > 0){
                neighbours.push_back(i);
                distances.push_back(graph[node][i]);
            }
        }
    }

private:
    int nodes;
    vector<vector<double>> graph;
};


class ShortestPath{
public:
    ShortestPath(Graph& graph, int nodes): graph(graph), nodes(nodes),
        nodes_list(vector<int>(nodes)),
        visited(vector<int>(nodes, 0)),
        unvisited(vector<int>(nodes, 1)),
        previous_node(vector<int>(nodes, -1)),
        shortest_distance(vector<double>(nodes, numeric_limits<double>::infinity())){
        iota(nodes_list.begin(), nodes_list.end(), 0);
    }

    int path(int source, int destination) {
        // initialize previous_node  withsource because that's where we're starting,
        // and shortest_distance with 0 because |source - source| = 0.
        previous_node[source] = source; 
        shortest_distance[source] = 0;

        // initialize previous visited node and minDist through that node.
        // initialize unvisited neighbours and their distances.
        int prev = source;
        double minDist = 0;
        vector<int> neighbours;
        vector<double> distances;

        while (true){
            // step 1: get unvisited connections of prev.
            neighbours.clear();
            distances.clear();
            graph.get_neighbour_data(prev, neighbours, distances);
            
        }  

        
        // for (size_t i = 0; i < neighbours.size(); ++i) {
        //     cout << neighbours[i] << " " << distances[i] << " ";
        // }
        // cout << endl;

        return 0;
    }

private:
    Graph graph;
    int nodes;
    vector<int> nodes_list;
    vector<int> previous_node;
    vector<int> visited;
    vector<int> unvisited;
    vector<double> shortest_distance;
};



int main(void)
{
    int nodes = 50;
    double density = 0.4;
    double range[2] = {1.0, 10.0};

    Graph g=Graph(nodes);
    g.generateGraph(density, range);
    // g.printGraph();
    // g.getSum();


    ShortestPath sp=ShortestPath(g, nodes);
    sp.path(2,7);

    return 0;
}

// References:
// dijkstras algo explained: https://www.youtube.com/watch?v=bZkzH5x0SKU

// Learnings:
// method calls - how similar they are to python. to invoke a method of an object you apply the same pattern: object.method(args)
// using vector enables you to declare arrays with non-static types -- the size does not need to be known at compile time with vector, whereas with native arrays it does.
//
//
//
//


