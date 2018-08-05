#include<bits/stdc++.h>

using namespace std;

int N, K, L;
int p[100000] = {}, q[100000] = {}, r[100000] = {}, s[100000] = {};
int link_road[200000] = {}, link_rail[200000] = {};
int ans[200000] = {};

void dfs(int search, int isRail){
	if(isRail){
		for(int j = 0; j < K; ++j){
			if(p[j] == search){
				link_road[q[j]]++;
				dfs(q[j], 0);
			}else if(q[j] == search){
				link_road[p[j]]++;
				dfs(p[j], 0);
			}
		}
	}else{
		for(int j = 0; j < L; ++j){
			if(r[j] == search){
				link_rail[s[j]]++;
				dfs(s[j], 1);
			}else if(s[j] == search){
				link_rail[r[j]]++;
				dfs(r[j], 1);
			}
		}
	}
}

int main(){
	cin >> N >> K >> L;
	int p[K] = {}, q[K] = {}, r[L] = {}, s[L] = {};

	for(int i = 0; i < K; ++i){
		cin >> p[i] >> q[i];
	}
	for(int i = 0; i < L; ++i){
		cin >> r[i] >> s[i];
	}

	for(int i = 1; i <= N; ++i){
		for(int j = 0; j < K; ++j){
			if(p[j] == i){
				link_road[q[j]]++;
				dfs(p[j], 0);
			}else if(q[j] == i){
				link_road[p[j]]++;
				dfs(q[j], 0);
			}
		}
		for(int j = 0; j < L; ++j){
			if(r[j] == i){
				link_rail[s[j]]++;
				dfs(r[j], 0);
			}else if(s[j] == i){
				link_rail[r[j]]++;
				dfs(s[j], 0);
			}
		}

		for(int k = 0; k < N; ++k){
			if(!(link_road[k] && link_rail[k])) continue;
			if(link_road[k] == link_rail[k]) ans[i-1]++;
		}
		
		for(int k = 0; k < N; ++k){
			link_road[k] = link_rail[k] = 0;
		}
	}

	for(int i = 0; i < N; ++i){
		cout << ++ans[i] << " ";
	}
	cout << endl;
}
