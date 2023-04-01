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

void BFS::AddNodePrivate(int p[], Node* Ptr) {

}

void BFS::AddNode(int p[]) {
	AddNodePrivate(p, root);
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

bool BFS::GoalFound(int p[]) {
	return SamePuzzle(p, target);
}

void BFS::ExpandNode(Node* n) {
	int x = 0;
	for (int i = 0; i < 9; i++) {
		if (n->puzzle[i] == 0) {
			x = i;
			break;
		}
	}
	MoveToLeft(n, x);
}

void BFS::MoveToRight(int p[], int i) {
	if (i % col < col - 1)
	{
		int pc[9];
		CopyPuzzle(pc, p);

		int temp = pc[i + 1];
		pc[i + 1] = pc[i];
		pc[i] = temp;

		Node* child = new Node(pc);
		children.push_back(child);
		child->parent = this;
	}
}

void BFS::MoveToLeft(int p[], int i) {
	if (i % col > 0)
	{
		int pc[9];
		CopyPuzzle(pc, p);

		int temp = pc[i - 1];
		pc[i - 1] = pc[i];
		pc[i] = temp;

		Node* child = new Node(pc);
		children.push_back(child);
		child->parent = this;
	}
}

void BFS::MoveToUp(int p[], int i) {
	if (i - col >= 0)
	{
		int pc[9];
		CopyPuzzle(pc, p);

		int temp = pc[i - 3];
		pc[i - 3] = pc[i];
		pc[i] = temp;

		Node* child = new Node(pc);
		children.push_back(child);
		child->parent = this;
	}
}

void BFS::MoveToDown(int p[], int i) {
	if (i + col < 9)
	{
		int pc[9];
		CopyPuzzle(pc, p);

		int temp = pc[i + 3];
		pc[i + 3] = pc[i];
		pc[i] = temp;

		Node* child = new Node(pc);
		children.push_back(child);
		child->parent = this;
	}
}
