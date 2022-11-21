#include <bits/stdc++.h>
#include <cwchar>
using namespace std;

struct DFSResult {
	map<char,int> discovery;
	map<char, int> finish;
	map<char, char> parent;
};

struct node {
	char data;
	struct node *next;
};

class Searching {

	map<char, int> status;
	map<char, char> parent;
	map<char, int> discovery;
	map<char, int> finish;
	map<char, vector<char>> adjlist;
	int dfstime;
	
	void DFSVisit(char u);
	public: 
		Searching(map<char, vector<char>> adjlist) {
			this->adjlist = adjlist;
			dfstime = 0;
		}

		DFSResult DFS();
};

void Searching::DFSVisit(char u) {
	status[u] = 1;
	dfstime++;
	discovery[u] = dfstime;
	for (auto v : adjlist[u]) {
		if (status[v] == 0) {
			parent[v] = u;
			DFSVisit(v);
		}
	}
	status[u] = 2;
	dfstime++;
	finish[u] = dfstime;
}

DFSResult Searching::DFS() {
	dfstime = 0;

	for (auto [v,_] : adjlist) {
		status[v] = 0;
	}

	for (auto [v,_] : adjlist) {
		if (status[v] == 0) {
			DFSVisit(v);
		}
	}
	
	DFSResult r;
	r.discovery = discovery;
	r.finish = finish;
	r.parent = parent;
	return r;

}

struct node* topsort(map<char, vector<char>>& adjlist) {
	Searching s(adjlist);
	DFSResult d = s.DFS();
	map<char, int> finish = d.finish;
	
	struct node* n = NULL;
	vector<int> times;
	for (auto [_,f] : finish) {
		times.push_back(f);
	}
	map<int, char> revfinish;
	for (auto [u,t] : finish) {
		revfinish[t] = u;
	}
	sort(times.begin(), times.end());
	for (auto t : times) {
		char u = revfinish[t];
		struct node *x = new node;
		x->data = u;
		x->next = n;
		n = x;
	}
	return n;
}

int main(void) {

	map<char,vector<char>> adjlist;
	adjlist['s'] = {'r','w'};
	adjlist['r'] = {'v','s'};
	adjlist['w'] = {'s','t','x'};
	adjlist['x'] = {'w','t','u','y'};
	adjlist['t'] = {'w','u','x'};
	adjlist['y'] = {'x','u'};
	adjlist['u'] = {'x','t','y'};
	adjlist['v'] = {'r'}; 

	struct node *h = topsort(adjlist);
	while (h != NULL) {
		cout << h->data << " ";
		h = h->next;
	}
	cout << endl;
	
	return 0;

}
