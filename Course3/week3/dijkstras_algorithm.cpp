#include <iostream>
#include <vector>
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
    
    void getSum() {
        double sm;
        for (int i=0; i<nodes; i++){
            for (int j=0; j<nodes; j++){
                sm += graph[i][j];
            }
        }
        cout << sm << endl;
    }
private:
    int nodes;
    vector<vector<double>> graph;
};


int main(void)
{
    int nodes = 50;
    double density = 0.4;
    double range[2] = {1.0, 10.0};

    Graph g=Graph(nodes);
    g.generateGraph(density, range);
    g.printGraph();
    g.getSum();
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


