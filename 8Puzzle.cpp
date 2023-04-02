#include <iostream>
#include "BFS.h"
using namespace std;

int main()
{
    int initPuzzle[9] = { 1, 2, 4, 3, 0, 5, 7, 6, 8 };
    vector<Node*> result;
    
    BFS bfs(initPuzzle);
    bfs.PrintBoard(bfs.root);
    
    result=bfs.BFSearch(bfs.root);
    if (bfs.Found) {
        cout << "Found the result, depth=" << bfs.depth << endl;
        cout << result.size() << endl;
        for (int i = result.size()-1; i >= 0; i--) {
            bfs.PrintBoard(result[i]);
        }
        
	} else {
        cout << "No solution, depth=" << bfs.depth << endl;
    }
    
}
