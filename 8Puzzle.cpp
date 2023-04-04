#include <iostream>
#include "BFS.h"
using namespace std;

int main()
{
    int initPuzzle[9] = { 1, 2, 4, 3, 0, 5, 7, 6, 8 };
    //int initPuzzle[9] = { 1, 0, 2, 3, 4, 5, 6, 7, 8 };
    vector<Node*> result;
    
    BFS bfs(initPuzzle);
    bfs.PrintBoard(bfs.root);
    
    result=bfs.BFSearch(bfs.root);
    if (bfs.Found) {
        for (int i = result.size()-1; i >= 0; i--) {
            bfs.PrintBoard(result[i]);
        }
        cout << "Found the result, nodes checked=" << bfs.nodes << endl;
        cout << result.size() << endl;
        
	} else {
        cout << "No solution, nodes checked=" << bfs.nodes << endl;
    }
    
}
