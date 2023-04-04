#pragma once
#include <iostream>
#include <vector>

using namespace std;
#define MAX_NODES 1000000

struct Node {
		vector<Node*> children;
		Node* parent = NULL;
		int puzzle[9];
		int x = 0;
	};

class BFS
{
private:
	int target[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int col = 3;
	void MoveToLeft(Node* n);
	void MoveToRight(Node* n);
	void MoveToUp(Node* n);
	void MoveToDown(Node* n);
	void CopyPuzzle(int p1[], int p2[]);
public:
	Node* root;
	int Found = false;
	int nodes = 0;
	BFS();
	BFS(int p[]);
	Node* CreateNode(int p[]);
	void PrintBoard(Node* n);
	bool SamePuzzle(int p1[], int p2[]);
	bool GoalFound(Node* n);
	void ExpandNode(Node* n);
	vector<Node*> PathToResult(Node* n);
	bool Contains(vector<Node*> v, Node* n);
	vector<Node*> BFSearch(Node* n);
	vector<Node*> DFSearch(Node* n);
	bool MahatanDistance(Node* n);
};

