#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
	const int limit = 1000000000;
	int n, m;
	

	cin >> n >> m;

	vector<pair<string, vector<pair<int, string>>>> v;
	map<string, int> cost;

	string s1,s2;
	int c1;
	for(int i=0; i<n; i++){
		cin >> s1 >> c1;
		cost[s1] = c1;
	}

	for(int i=0; i<m; i++){
		string tmp = "";
		cin >> tmp;

		size_t prev =0 , cur;

		cur = tmp.find('=');
		s1 = tmp.substr(prev, cur-prev);
		prev = cur+1;

		vector<pair<int, string>> _v;
		while(1){
			cur = tmp.find('+', prev);
			if(cur == string::npos)
				cur = tmp.size();
			s2 = tmp.substr(prev, cur-prev);
			c1= s2[0] - '0';
			s2 = s2.substr(1);
			prev = cur+1;

			if(cost.find(s2) == cost.end()){
				cost[s2] = -1;	
			}
			_v.push_back(make_pair(c1,s2));

			if(cur == tmp.size())
					break;
		}
			
		if(cost.find(s1) == cost.end()){
			cost[s1] = -1;
		}
		v.push_back(make_pair(s1,_v));
	}

	bool flag =true;
	while(flag){
		flag = false;
		for(int i=0; i<v.size(); i++){
			long long sum = 0;
			string name = v[i].first;
			for(int j=0; j<v[i].second.size(); j++){
				int cnt = v[i].second[j].first;
				string x = v[i].second[j].second;
				if(cost[x] != -1){
					sum += cnt * (long long)cost[x];
					if(sum > limit)
						sum = limit + 1;
				}
				else{
					sum = -1;
					break;
				}
			}
			if(sum > 0){
				if(cost[name] == -1 || cost[name] > sum){
					cost[name] = sum;
					flag =true;
				}
			}
		}
	}

	if(cost.find("LOVE") == cost.end())
		cout << "-1" << endl;
	else
		cout << cost["LOVE"] << endl;

	return 0;
}