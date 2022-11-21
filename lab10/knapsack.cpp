#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

pair<float,float> addClass(float cost, float weight) {
	pair<float,float> element;
	element.first = cost;
	element.second = weight;
	return element;
}

void strategy1(vector<pair<float,float>>& objects, int wt) {
	
}

void strategy2(vector<pair<float,float>>& objects, int wt) {
	
}

void strategy3(vector<pair<float,float>>& objects, int wt) {
	map<float, int> correspondingWt;
	float profit = 0;
	for (int i = 0; i < objects.size(); i++) {
		float perwt = objects[i].first / objects[i].second;
		correspondingWt[-1 * perwt] = i;
	}
	for (auto [pw,index] : correspondingWt) {
		if (objects[index].second > wt) {
			profit += wt * pw * -1;
			wt = 0;
			break;
		} else {
			wt -= objects[index].second;
			profit += objects[index].first;
		}
	}
	cout << "Profit from strategy 3: " << profit << endl;
}

int main(void) {
	vector<pair<float,float>> objects;
	objects.push_back(addClass(25,18));
	objects.push_back(addClass(24,15));
	objects.push_back(addClass(15,10));
	strategy3(objects, 20);
}
