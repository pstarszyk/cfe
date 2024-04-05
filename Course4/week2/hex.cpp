#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace :: std;


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
        colours(nodes, '.'){
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

    void update_board(int i, int j, char c){
        if (c == 'B'){player_graph.update_edges(i, j);}
        else {computer_graph.update_edges(i, j);}
    }

    void computer_move(void){
        vector<int> open_nodes;
        for (int i=0; i<nodes; i++){
            if (colours[i] == '.'){open_nodes.push_back(i);}
        }

        // Generate random available node.
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0, open_nodes.size() - 1);
        int index = distr(eng);
        int node = open_nodes[index];

        update_colours(node / dim, node % dim, computer_colour); 
        update_board(node / dim, node % dim, computer_colour);
    }

    void move(int i, int j){
        if (!is_legal(i, j)){
            cout << "ILLEGAL MOVE!" << endl;
            return;
        }
        update_colours(i, j, player_colour);
        update_board(i, j, player_colour);
        computer_move(); 
        draw_board();
    }

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
        cout << "Enter the dimension of the board that you want to play on (7 or 11):" << endl;
        cin >> dim;
        if (dim == 7 || dim == 11){
            break;
        }
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
    }

    return 0;
}
