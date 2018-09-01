#include<bits/stdc++.h>

using namespace std;

char board[8][8];
vector< pair<int, int> > freechunks;

bool paint(char boa[8][8], int h, int w){
	for(int i = -7; i < 8; ++i){
		int nowh = h + i;
		if(0 <= nowh && nowh < 8 && boa[nowh][w] != 'Q'){
			boa[nowh][w] = '#';
		}
	}
	for(int i = -7; i < 8; ++i){
		int noww = w + i;
		if(0 <= noww && noww < 8 && boa[h][noww] != 'Q'){
			boa[h][noww] = '#';
		}
	}
	for(int i = -7; i < 8; ++i){
		int nowh = h + i, noww = w + i;
		if(0 <= noww && noww < 8 && 0 <= nowh && nowh < 8 && boa[nowh][noww] != 'Q'){
			boa[nowh][noww] = '#';
		}
	}
	for(int i = -7; i < 8; ++i){
		int nowh = h - i, noww = w + i;
		if(0 <= noww && noww < 8 && 0 <= nowh && nowh < 8 && boa[nowh][noww] != 'Q'){
			boa[nowh][noww] = '#';
		}
	}
}

bool check(char boa[8][8], int h, int w){
	for(int i = -7; i < 8; ++i){
		int nowh = h + i;
		if(0 <= nowh && nowh < 8 && boa[nowh][w] == 'Q'){
			if(nowh == h) continue;
			return false;
		}
	}
	for(int i = -7; i < 8; ++i){
		int noww = w + i;
		if(0 <= noww && noww < 8 && boa[h][noww] == 'Q'){
			if(noww == w) continue;
			return false;
		}
	}
	for(int i = -7; i < 8; ++i){
		int nowh = h + i, noww = w + i;
		if(0 <= noww && noww < 8 && 0 <= nowh && nowh < 8 && boa[nowh][noww] == 'Q'){
			if(nowh == h && noww == w) continue;
			return false;
		}
	}
	for(int i = -7; i < 8; ++i){
		int nowh = h + i, noww = w - i;
		if(0 <= noww && noww < 8 && 0 <= nowh && nowh < 8 && boa[nowh][noww] == 'Q'){
			if(nowh == h && noww == w) continue;
			return false;
		}
	}
	return true;
}

bool isqueen(char boa[8][8]){
	int count = 0;
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(boa[i][j] == 'Q') count++;
		}
	}
	return count == 8;
}

void pushbackfreechunks(){
	freechunks.clear();
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == '.') freechunks.push_back(make_pair(i, j));
		}
	}
}

void show(char boa[8][8]){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(boa[i][j] == '#') boa[i][j] = '.';
			cout << boa[i][j];
		}
		cout << endl;
	}
}

void copyarray(char boa1[8][8], char boa2[8][8]){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			boa2[i][j] = boa1[i][j];
		}
	}
}
	
int main(){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == 'Q' && !check(board, i, j)){
				cout << "No Answer" << endl;
				return 0;
			}
		}
	}
	
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == 'Q') paint(board, i, j);
		}
	}
	
	pushbackfreechunks();
	char boardbuf[8][8];
	bitset<64> bits;
	for(int i = 0; i < pow(2, freechunks.size()); ++i){
		copyarray(board, boardbuf);
		for(int i = 0; i < 8; ++i){
			for(int j = 0; j < 8; ++j){
				if(boardbuf[i][j] == 'Q' && check(boardbuf, i, j)){
					paint(boardbuf, i, j);
				}
			}
		}
		bits = i;
		for(int j = 0; j < freechunks.size(); ++j){
			pushbackfreechunks();
			if(bits[j] == 1 && check(boardbuf, freechunks[j].first, freechunks[j].second)){
				boardbuf[freechunks[j].first][freechunks[j].second] = 'Q';
				paint(boardbuf, freechunks[j].first, freechunks[j].second);
			}
			if(isqueen(boardbuf)){
				show(boardbuf);
				return 0;
			}
		}
	}
	cout << "No Answer" << endl;
}