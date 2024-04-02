#include <iostream>
#include <vector>
using namespace :: std;


class Graph{
public:
    Graph(int dim): 
        dim(dim), 
        nodes(dim * dim){
        graph = vector<vector<int>>(nodes, vector<int>(nodes, 0));
        colours = vector<char>(nodes, 'X');
    }

    void printBoard(void){
        for (int i = 0; i < dim; i++){
            for (int k = 0; k < i; k++){
                cout << '\t';
            }
            for (int j = 0; j < dim; j++){
                cout << colours[dim * i + j] << '\t';
            }
            cout << endl;
        }
    }

private:
    int nodes, dim;
    vector<vector<int>> graph;
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

    Graph graph = Graph(dim);
    graph.printBoard();

    int i, j;
    while (true){
        cout << "Enter the coordinates of your next move:" << endl;
        cin >> i >> j;
    }

    return 0;
}
