#include <cmath>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <vector>
using namespace :: std;

enum Direction {
    East,
    West,
    North,
    South
};

inline int random_number(int n)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(0, n - 1);
    int r = distr(eng);
    return r;
}


class Graph{
public:
    Graph(int nodes): 
        nodes(nodes), 
        dim(sqrt(nodes + 1)), 
        graph(nodes, vector<int>(nodes, 0)){}

    void update_edges(int i, int j){
        graph[dim * i + j][dim * i + j] = 1;

        // neighbour 1
        if (i - 1 >= 0 && graph[dim*(i - 1) + j][dim*(i - 1) + j] == 1){
            graph[dim*(i - 1) + j][dim * i + j] = graph[dim * i + j][dim*(i - 1) + j] = 1;
        }

        // neighbour 2
        if (i - 1 >= 0 && j + 1 < dim && graph[dim*(i - 1) + j + 1][dim*(i - 1) + j + 1] == 1){
            graph[dim*(i - 1) + j + 1][dim * i + j] = graph[dim * i + j][dim*(i - 1) + j + 1] = 1;
        }

        // neighbour 3
        if (j - 1 >= 0 && graph[dim * i + j - 1][dim * i + j - 1] == 1){
            graph[dim * i + j - 1][dim * i + j] = graph[dim * i + j][dim * i + j - 1] = 1;
        }

        // neighbour 4
        if (j + 1 < dim && graph[dim * i + j + 1][dim * i + j + 1] == 1){
            graph[dim * i + j + 1][dim * i + j] = graph[dim * i + j][dim * i + j + 1] = 1;
        }

        // neighbour 5
        if (i + 1 < dim && graph[dim*(i + 1) + j][dim*(i + 1) + j] == 1){
            graph[dim*(i + 1) + j][dim * i + j] = graph[dim * i + j][dim*(i + 1) + j] = 1;
        }

        // neighbour 6
        if (i + 1 < dim && j - 1 >= 0 && graph[dim*(i + 1) + j - 1][dim*(i + 1) + j - 1] == 1){
            graph[dim*(i + 1) + j - 1][dim * i + j] = graph[dim * i + j][dim*(i + 1) + j - 1] = 1;
        }
    }

    vector<int> get_connections(int node){
        // this method checks all of the connections for a given node using breadth-first-search.
        
        vector<int> connections(nodes, 0);
        queue<int> q;
    
        q.push(node);
        connections[nodes] = 1;

        int cur;
        while (!q.empty()){
            cur = q.front();
            q.pop();
            for (int i=0; i<nodes; i++){
                if (i != cur && graph[cur][i] == 1 && connections[i] == 0){
                    connections[i] = 1;
                    q.push(i);
                }
            }
        }
        return connections;
    }

    bool check_connection(vector<int>& connections, Direction direction) {
        for (int k = 0; k < dim; k++) {
            int index;
            switch (direction) {
                case East:
                    index = dim*k + dim-1;
                    break;
                case West:
                    index = dim*k;
                    break;
                case North:
                    index = k; // Equivalent to 0 + k
                    break;
                case South:
                    index = dim*(dim-1) + k;
                    break;
            }
            if (connections[index] == 1) {
                return true;
            }
        }
        return false;
    }
    
    bool has_bridge(void){
        vector<int> connections, extremes;
        
        for (int i=0; i<dim; i++){
            if (graph[dim*i][dim*i] == 1){extremes.push_back(dim*i);}
            if (graph[dim*(i+1)-1][dim*(i+1)-1] == 1){extremes.push_back(dim*(i+1)-1);}
        }
        for (int j=1; j<dim-1; j++){
            if (graph[j][j] == 1){extremes.push_back(j);}
            if (graph[dim*(dim-1) + j][dim*(dim-1) + j] == 1){extremes.push_back(dim*(dim-1) + j);}
        }

        for (auto node = extremes.begin(); node != extremes.end(); node++){
            int i = *node / dim, j = *node % dim;
            connections = get_connections(*node);

            // check if this current extreme node is connected to another appropriate extreme node.
            
            if (i==0 && j==0){ 
                if (check_connection(connections, East) || check_connection(connections, South)){return true;}
            }

            if (i==0 && j==dim-1){
                if (check_connection(connections, West) || check_connection(connections, South)){return true;}
            }

            if (i==dim-1 && j==0){
                if (check_connection(connections, East) || check_connection(connections, North)){return true;}
            }

            if (i==dim-1 && j==dim-1){
                if (check_connection(connections, West) || check_connection(connections, North)){return true;}
            }

            if (i==0){
                if (check_connection(connections, South)){return true;}
            }

            if (i==dim-1){
                if (check_connection(connections, North)){return true;}
            }

            if (j==0){
                if (check_connection(connections, East)){return true;}
            }

            if (j==dim-1){
                if (check_connection(connections, West)){return true;}
            }
        }
        return false;
    }

private:
    int nodes, dim;
    vector<vector<int>> graph;
};



class HexBoard{
public:
    HexBoard(int dim, char colour): 
        dim(dim), 
        player_colour(colour),
        nodes(dim * dim),
        player_graph(nodes),
        computer_graph(nodes),
        colours(nodes, '.'),
        player_status(false),
        computer_status(false){
        if (player_colour == 'B'){computer_colour = 'R';}
        else {computer_colour = 'B';}
    }

    void draw_board(void){
        cout << '\n' << endl;
        for (int i = 0; i < dim; i++) {
            // Print leading spaces for the row
            cout << string(i * 2, ' ');

            for (int j = 0; j < dim; j++) {
                if (j > 0){cout << " -- ";}
                cout << colours[i * dim + j];
            }
            cout << "\n";

            if (i < dim - 1) {
                cout << string(i * 2, ' '); // Adjust the leading spaces for slashes
                for (int k = 0; k < dim - 1; k++) {
                    cout << " \\ /";
                    if (k < dim - 2){cout << " ";}
                }
                cout << "  \\\n"; // Print the last slash at the end of each slash-row
            }
        }
        cout << '\n' << endl;
    }

    bool is_legal(int i, int j){
        int node = dim * i + j;
        if (colours[node] == '.'){return true;}
        return false;
    }

    void update_colours(int i, int j, char c){
        colours[dim * i + j] = c;
    }

    void update_board(int i, int j, char c, Graph& pgraph, Graph& cgraph){
        if (c == player_colour){pgraph.update_edges(i, j);}
        else {cgraph.update_edges(i, j);}
    }

    void computer_move(int i, int j){
        vector<int> open_nodes;
        for (int i=0; i<nodes; i++){
            if (colours[i] == '.'){open_nodes.push_back(i);}
        }

        // Generate random available node.
        int index = random_number(open_nodes.size());
        int node = open_nodes[index];

        update_colours(node / dim, node % dim, computer_colour); 
        update_board(node / dim, node % dim, computer_colour, player_graph, computer_graph);
    }

    void move(int i, int j){
        if (!is_legal(i, j)){
            cout << "ILLEGAL MOVE!" << endl;
            return;
        }
        update_colours(i, j, player_colour);
        update_board(i, j, player_colour, player_graph, computer_graph);
        if (player_graph.has_bridge()){
            player_status = true;
            draw_board();
            return;
        }
        computer_move(i, j); 
        if (computer_graph.has_bridge()){
            computer_status = true;
            draw_board();
            return;
        }
        draw_board();

    }

    bool player_status, computer_status;

private:
    int nodes, dim;
    char player_colour, computer_colour;
    Graph player_graph, computer_graph;
    vector<char> colours;
};


int main(void)
{

    int dim;
    while (true){
        cout << "Enter the dimension of the board that you want to play on:" << endl;
        cin >> dim;
        break;
    }

    char colour;
    while (true){
        cout << "Enter the colour you want to be (B or R):" << endl;
        cin >> colour;
        if (colour == 'B' || colour == 'R'){
            break;
        }
    }

    HexBoard hex = HexBoard(dim, colour);
    hex.draw_board();

    int i, j;
    while (true){
        cout << "Enter the coordinates of your next move:" << endl;
        cin >> i >> j;

        hex.move(i, j);
        if (hex.player_status){
            cout << "PLAYER WINS!!!" << endl;
            break;
        }
        if (hex.computer_status){
            cout << "COMPUTER WINS!!!" << endl;
            break;
        }
    }

    return 0;
}
