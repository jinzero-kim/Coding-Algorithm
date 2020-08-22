
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x) 
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) 
		parent[b] = a;
	else 
		parent[a] = b;
}

bool isCycle(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) 
		return true;
	return false;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int main(void) {
	const int n = 7;

	vector<Edge> v;
	v.push_back(Edge(1, 2, 17));
	v.push_back(Edge(1, 3, 21));
	v.push_back(Edge(1, 4, 20));
	v.push_back(Edge(1, 6, 34));
	v.push_back(Edge(2, 6, 22));
	v.push_back(Edge(3, 4, 15));
	v.push_back(Edge(3, 5, 13));
	v.push_back(Edge(3, 6, 27));
	v.push_back(Edge(3, 7, 19));
	v.push_back(Edge(4, 5, 14));
	v.push_back(Edge(5, 7, 20));
	v.push_back(Edge(6, 7, 25));

	sort(v.begin(), v.end());

	int parent[n];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
 	}
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isCycle(parent, v[i].node[0]-1, v[i].node[1]-1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
		}
	}

	printf("%d\n", sum);

	return 0;
}