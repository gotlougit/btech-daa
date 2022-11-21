#include <bits/stdc++.h>

using namespace std;

pair<string, pair<float,float>> addClass(string classname, float start, float end) {
	pair<float, float> timing;
	timing.first = start;
	timing.second = end;
	pair<string, pair<float, float>> element;
	element.first = classname;
	element.second = timing;
	return element;
}

int main(void) {
	
	vector<pair<string, pair<float, float>>> fullschedule;
	fullschedule.push_back(addClass("Art",9,10));
	fullschedule.push_back(addClass("English",9.5,10.5));
	fullschedule.push_back(addClass("Math",10,11));
	fullschedule.push_back(addClass("CS",10.5,11.5));
	fullschedule.push_back(addClass("Music",11,12));
	vector<pair<string, pair<float, float>>> classschedule;	
	int i = 1;
	int end = fullschedule[0].second.second;
	classschedule.push_back(fullschedule[0]);
	while (i < fullschedule.size()) {
		if (fullschedule[i].second.first == end) {
			end = fullschedule[i].second.second;
			classschedule.push_back(fullschedule[i]);
		}
		i++;
	}
	cout << "Classname" << " | " << "Start" << " | " << "End" << endl;
	for (auto c : classschedule) {
		cout << c.first << " | " << c.second.first << " | " << c.second.second << endl;
	}
	return 0;

}
