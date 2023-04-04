#include "BFS.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BFS::BFS() {
	root = NULL;
}

BFS::BFS(int p[]) {
	root = CreateNode(p);
}

Node* BFS::CreateNode(int p[]) {
	Node* n = new Node;
	for (int i = 0; i < 9; i++) {
		n->puzzle[i] = p[i];
		if (p[i] == 0) {
			n->x = i;
		}
	}
	n->parent = NULL;
	return n;
}

void BFS::PrintBoard(Node* n) {
	cout << "------";
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << endl;
		cout << n->puzzle[i];
	}
	cout << endl;
	cout << "------" << endl;
}

bool BFS::SamePuzzle(int p1[], int p2[]) {
	bool Same=true;
	for (int i = 0; i < 9; i++) {
		if (p1[i] != p2[i]) {
			Same = false;
			break;
		}
	}
	return Same;
}

bool BFS::GoalFound(Node* n) {
	return SamePuzzle(n->puzzle, target);
}

void BFS::ExpandNode(Node* n) {
	MoveToLeft(n);
	MoveToRight(n);
	MoveToUp(n);
	MoveToDown(n);
}

void BFS::CopyPuzzle(int p1[], int p2[]) {
	for (int i = 0; i < 9; i++) {
		p1[i] = p2[i];
	}
}

void BFS::MoveToRight(Node* n) {

	if (n->x % col < col - 1)
	{
		int pc[9];
		CopyPuzzle(pc, n->puzzle);

		int temp = pc[n->x + 1];
		pc[n->x + 1] = pc[n->x];
		pc[n->x] = temp;

		if (n->parent!=NULL && SamePuzzle(pc, n->parent->puzzle)) {
			return;
		}
		Node* child = CreateNode(pc);
		child->parent = n;
		n->children.push_back(child);
	}
}

void BFS::MoveToLeft(Node* n) {
	if (n->x % col > 0)
	{
		int pc[9];
		CopyPuzzle(pc, n->puzzle);

		int temp = pc[n->x - 1];
		pc[n->x - 1] = pc[n->x];
		pc[n->x] = temp;
		
		if (n->parent != NULL && SamePuzzle(pc, n->parent->puzzle)) {
			return;
		}
		Node* child = CreateNode(pc);
		child->parent = n;
		n->children.push_back(child);
		
	}
}

void BFS::MoveToUp(Node* n) {
	if (n->x - col >= 0)
	{
		int pc[9];
		CopyPuzzle(pc, n->puzzle);
		int temp = pc[n->x - 3];
		pc[n->x - 3] = pc[n->x];
		pc[n->x] = temp;
		if (n->parent != NULL && SamePuzzle(pc, n->parent->puzzle)) {
			return;
		}
		Node* child = CreateNode(pc);
		child->parent = n;
		n->children.push_back(child);
	}
}

void BFS::MoveToDown(Node* n) {
	if (n->x + col < 9)
	{
		int pc[9];
		CopyPuzzle(pc, n->puzzle);
		int temp = pc[n->x + 3];
		pc[n->x + 3] = pc[n->x];
		pc[n->x] = temp;
		if (n->parent != NULL && SamePuzzle(pc, n->parent->puzzle)) {
			return;
		}
		Node* child = CreateNode(pc);
		child->parent = n;
		n->children.push_back(child);
	}
}

bool BFS::Contains(vector<Node*> v, Node* n) {
	for (int i = 0; i < v.size(); i++) {
		if (SamePuzzle(v[i]->puzzle, n->puzzle)) {
			return true;
		}
	}
	return false;
}

vector<Node*> BFS::PathToResult(Node* n) {
	vector<Node*> path;
	while (n != NULL) {
		path.push_back(n);
		n = n->parent;
	}
	return path;
}

vector<Node*> BFS::BFSearch(Node* n) {
	vector<Node*> queue;
	vector<Node*> visited;
	vector<Node*> result_path;
	queue.push_back(n);
	nodes = 0;
	while (queue.size() > 0) {
		Node* current = queue[0];			// 拿第一個
		queue.erase(queue.begin());         // 刪除第一個
		visited.push_back(current);
		if (GoalFound(current)) {
			Found = true;
			result_path = PathToResult(current);
			return result_path;
		}
		else {
			if (nodes++ > MAX_NODES)
			{
				Found = false;
				return visited;
			}
			ExpandNode(current);
			for (int i = 0; i < current->children.size(); i++) {
				if (!Contains(queue, current->children[i]) && !Contains(visited, current->children[i])) {
					queue.push_back(current->children[i]);
				}
				
			}
		}
	}
	return visited;
}	

vector<Node*> BFS::DFSearch(Node* n) {
	vector<Node*> stack;
	vector<Node*> visited;
	vector<Node*> result_path;
	stack.push_back(n);
	nodes = 0;
	while (stack.size() > 0) {
		Node* current = stack[stack.size()-1]; // 拿最後一個
		stack.pop_back();                      // 移除最後一個
		visited.push_back(current);
		if (GoalFound(current)) {
			Found = true;
			result_path = PathToResult(current);
			return result_path;
		}
		else {
			if (nodes++ > MAX_NODES)
			{
				Found = false;
				return visited;
			}
			ExpandNode(current);
			for (int i = 0; i < current->children.size(); i++) {
				if (!Contains(stack, current->children[i]) && !Contains(visited, current->children[i])) {
					stack.push_back(current->children[i]);
				}
			}
		}
	}
	return visited;
}

bool BFS::MahatanDistance(Node* n) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (n->puzzle[i] != 0) {
			int x = abs(i % 3 - n->puzzle[i] % 3);
			int y = abs(i / 3 - n->puzzle[i] / 3);
			sum += x + y;
		}
	}
	return sum;
}