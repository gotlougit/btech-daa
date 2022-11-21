#include <bits/stdc++.h>
using namespace std;

struct node {
	char data;
  	struct node *next;
  	struct node *prev;
};

struct node* MakeSet(char data) {
	struct node *n = new struct node;
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

struct node* FindSet(struct node* key) {
	while (key->prev != NULL) {
		key = key->prev;
	}
	return key;
}

void Union(vector<struct node*>& disjointsets, struct node* u, struct node* v) {
	struct node *x = FindSet(u);
	struct node *y = FindSet(v);
	while (x->next != NULL) {
		x = x->next;
	}
	x->next = y;
	y->prev = x;
	for (int i = 0; i < disjointsets.size(); i++) {
		if (y == disjointsets[i]) {
			disjointsets.erase(disjointsets.begin() + i);
			break;
		}
	}
}

vector<struct node *> ConnectedComponents(map<char, vector<char>>& adjlist, vector<pair<char,char>>& edges) {
	
	vector<struct node*> disjointsets;
	map<char, struct node*> mapping;

	//MakeSet() for every vertex and calculate edgelist
	for (auto [v,_] : adjlist) {
		struct node *n = mapping[v];
		if (!n) {
			n = MakeSet(v);
			disjointsets.push_back(n);
			mapping[v] = n;
		}
		for (auto u : adjlist[v]) {
			struct node *x = mapping[u];
			if (!x) {
				x = MakeSet(u);
				disjointsets.push_back(x);
				mapping[u] = x;
			}
			pair<char,char> t;
			t.first = v;
			t.second = u;
			edges.push_back(t);
		}

	}

	for (auto [u,v] : edges) {
		if (FindSet(mapping[u]) != FindSet(mapping[v])) {
			Union(disjointsets, mapping[u],mapping[v]);
		}
	}
	return disjointsets;
}


int main(void) {

	map<char, vector<char>> adjlist;
	adjlist['a'] = {'b','c'};
	adjlist['b'] = {'a','c','d'};
	adjlist['c'] = {'a','b'};
	adjlist['d'] = {'b'};

	adjlist['e'] = {'f','g'};
	adjlist['f'] = {'e'};
	adjlist['g'] = {'e'};
	
	adjlist['h'] = {'i'};
	adjlist['i'] = {'h'};
	
	adjlist['j'] = {' '};

	vector<pair<char,char>> edges;
	for (auto [u,_] : adjlist) {
		for (auto v: adjlist[u]) {
			pair<char,char> t;
			t.first = u;
			t.second = v;
			edges.push_back(t);
		}
	}
	vector<struct node*> disjointsets = ConnectedComponents(adjlist, edges);

	cout << "Connected components: " << endl;
	for (auto n : disjointsets) {
		while (n != NULL) {
			cout << n->data << " ";
			n = n->next;
		}
		cout << endl;
	}

	return 0;
}
