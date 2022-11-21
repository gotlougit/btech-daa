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

int main(void) {

	map<char, vector<char>> adjlist;
	adjlist['a'] = {'b','h'};
	adjlist['b'] = {'a','c','h'};
	adjlist['h'] = {'a','b','i','g'};
	adjlist['i'] = {'h','g','c'};
	adjlist['c'] = {'f','b','d','i'};
	adjlist['d'] = {'c','f','e'};
	adjlist['e'] = {'f','d'};
	adjlist['f'] = {'c','d','g','e'};
	adjlist['g'] = {'i','f','h'};
	
	map<pair<char,char>, int> weights;
	for (auto [u,_] : adjlist) {
		for (auto v: adjlist[u]) {
			pair<char,char> t;
			t.first = u;
			t.second = v;
			int s = weights.size();
			weights[t] = s+1;
		}
	}

	map<char, struct node *> mapping;
	vector<struct node *> disjointsets;
	for (auto [u,_] : adjlist) {
		mapping[u] = MakeSet(u);
		disjointsets.push_back(mapping[u]);
	}
	
	//TODO: sort

	vector<pair<char,char>> A;
	for (auto [x,_] : weights) {
		auto [u,v] = x;
		if (FindSet(mapping[u]) != FindSet(mapping[v])) {
			A.push_back(x);
			Union(disjointsets, mapping[u], mapping[v]);
		}
	}

	for (auto x : A) {
		cout << x.first << " " << x.second << endl;	
	}

	return 0;
}
