#include <iostream>
#include <vector>
#include <limits>
#include <random>
using namespace :: std;

// References --  this code implements dijkstra's algo as explained in this video:
// dijkstras algo explained: https://www.youtube.com/watch?v=bZkzH5x0SKU

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
                    cout << graph[i][j] << "\t";
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

    void remove_visited(vector<int>& neighbours, vector<double>& distances) {
        for (size_t i=0; i<neighbours.size(); i++){
            int cur = neighbours[i];
            if (visited[cur] == 1){
                neighbours[i] = -1;
                distances[i] = -1;
            }
        }
    }

    void add_distances(double minDist, vector<double>& distances) {
        for (size_t i=0; i<distances.size(); i++){
            if (distances[i] != -1){
                distances[i] += minDist;
            }
        }
    }

    void update_distances(int prev, vector<int>& neighbours, vector<double>& distances) {
        for (size_t i=0; i<neighbours.size(); i++){
            if (neighbours[i] != -1 && distances[i] < shortest_distance[neighbours[i]]){
                shortest_distance[neighbours[i]] = distances[i];
                previous_node[neighbours[i]] = prev;
            }
        }
    }

    void update_visits(int prev) {
        visited[prev] = 1;
        unvisited[prev] = 0;
    }

    void update_trackers(int& prev, double& minDist, vector<int>& neighbours) {
        double curMinDist = numeric_limits<double>::infinity();
        int curMinNeighbour = -1;

        for (size_t i=0; i<neighbours.size(); i++){
            if (neighbours[i] != -1 && shortest_distance[neighbours[i]] < curMinDist){
                curMinDist = shortest_distance[neighbours[i]];
                curMinNeighbour = neighbours[i];
            }
        }
        prev = curMinNeighbour;
        minDist = curMinDist;
    }

    bool no_connections(vector<int>& neighbours) {
        for (size_t i=0; i<neighbours.size(); i++){
            if (neighbours[i] > -1){
                return false;
            }
        }
        return true;
    }

    void print_path(int source, int destination) {
        cout << "Path = ";
        int nxt = destination;
        while (nxt != source){
            cout << nxt << " <- ";
            nxt = previous_node[nxt];
        }
        cout << source << endl;
    }

    void path(int source, int destination) {
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
            remove_visited(neighbours, distances);

            if (no_connections(neighbours)){
                cout << "NO SOLUTION!" << endl;
                break;
            }

            // step 2: add minDist to neighbouring distances
            add_distances(minDist, distances);

            // step 3: update shortest_distance IF distances from step 2 are lower and update previous_node
            update_distances(prev, neighbours, distances);

            // step 4: updated visited and unvisited.
            update_visits(prev);

            // step5: update prev and minDist based on minimal distances obtained in step 2
            update_trackers(prev, minDist, neighbours);

            if (prev == destination){
                print_path(source, destination);
                break;
            }
        }
        cout << "MinCost = " << shortest_distance[destination] << endl;  
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
    double density;
    double range[2] = {1.0, 10.0};

    // density = 20%
    density = 0.2;

    Graph g1 = Graph(nodes);
    g1.generateGraph(density, range);
    // g.printGraph();
    ShortestPath sp1 = ShortestPath(g1, nodes);
    sp1.path(0, 49);

    // density = 40%
    density = 0.4;

    Graph g2 = Graph(nodes);
    g2.generateGraph(density, range);
    // g.printGraph();
    ShortestPath sp2 = ShortestPath(g2, nodes);
    sp2.path(0, 49);

    return 0;
}