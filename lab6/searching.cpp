#include <bits/stdc++.h>
#include <cwchar>
using namespace std;

struct BFSResult {
	map<char,int> distance;
	map<char,char> parent;
};

struct DFSResult {
	map<char,int> discovery;
	map<char, int> finish;
	map<char, char> parent;
};

class Searching {

	map<char, int> status;
	map<char, int> distance;
	map<char, char> parent;
	map<char, int> discovery;
	map<char, int> finish;
	map<char, vector<char>> adjlist;
	int dfstime;
	
	void DFSVisit(char u);
	void reset();
	public: 
		Searching(map<char, vector<char>> adjlist) {
			this->adjlist = adjlist;
			dfstime = 0;
		}

		BFSResult BFS(char source);
		DFSResult DFS();
};

void Searching::reset() {
	map<char, int> empty;
	map<char, char> empty2;
	status = empty;
	distance = empty;
	parent = empty2;
	discovery = empty;
	finish = empty;
}

BFSResult Searching::BFS(char source) {
	reset();

	for (auto [v,_] : adjlist) {
		if (v != source) {
			status[v] = 0;
			distance[v] = INT_MAX;
		}
	}

	status[source] = 1;
	distance[source] = 0;

	queue<char> q;
	q.push(source);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adjlist[u]) {
			if (status[v] == 0) {
				status[v] = 1;
				distance[v] = distance[u] + 1;
				parent[v] = u;
				q.push(v);
			}
		}
		status[u] = 2;
	}
	BFSResult r;
	r.distance = distance;
	r.parent = parent;
	return r;
}

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
	reset();
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

	Searching s(adjlist);

	BFSResult bfsresult = s.BFS('s');
	DFSResult dfsresult = s.DFS();

	cout << "V: ";
	for (auto [v,_] : bfsresult.parent) {
		cout << v << " ";
	}
	cout << endl;
	
	cout << "D: ";
	for (auto [v, _] : bfsresult.distance) {
		cout << bfsresult.distance[v] << " ";
	}
	cout << endl;

	cout << "P: ";
	for (auto [v,_] : bfsresult.parent) {
		cout << bfsresult.parent[v] << " ";
	}
	cout << endl;

	cout << "-------" << endl;
	
	cout << "V: ";
	for (auto [v,_] : dfsresult.parent) {
		cout << v << " ";
	}
	cout << endl;

	cout << "D: ";
	for (auto [v,_] : dfsresult.discovery) {
			cout << dfsresult.discovery[v] << " ";
	}
	cout << endl;
	
	cout << "F: ";
	for (auto [v,_] : dfsresult.finish) {
		cout << dfsresult.finish[v] << " ";
	}
	cout << endl;

	cout << "P: ";
	for (auto [v,_] : dfsresult.parent) {
		cout << dfsresult.parent[v] << " ";
	}
	cout << endl;
	
	return 0;

}
