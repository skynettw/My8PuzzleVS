#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node {
		vector<Node*> children;
		Node* parent = NULL;
		int puzzle[9];
	};

class BFS
{
private:
	int target[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int x = 0;
	int col = 3;
	void AddNodePrivate(int p[], Node* Ptr);
public:
	Node* root;
	BFS();
	BFS(int p[]);
	Node* CreateNode(int p[]);
	void AddNode(int p[]);
	void PrintBoard(Node* n);
	bool SamePuzzle(int p1[], int p2[]);
	bool GoalFound(int p[]);
	void ExpandNode(Node* n);
	void MoveToLeft(int p[], int x);
	void MoveToRight(int p[], int x);
	void MoveToUp(int p[], int x);
	void MoveToDown(int p[], int x);
};

