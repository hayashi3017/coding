#include <bits/stdc++.h>
using namespace std ;


int main() {
	int S;
	cin >> S;

	vector<vector<string>> table(S, vector<string>(S));
	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			cin >> table.at(i).at(j);
		}
	}
	
	vector<vector<int>> hole(S, vector<int>(S, 0));

	int N;
	cin >> N;

	vector<string> words(N);
	for(int i=0; i<N; i++){
		cin >> words.at(i);
	}

	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			for(int k=0; k<N; k++){
				if(table.at(i).at(j) == words.at(k)){
					hole.at(i).at(j) = 1;
				}
			}
		}
	}
	string output;
	int verticalHoleNum, horizontalHoleNum, rightDiagonalHoleNum=0, leftDiagonalHoleNum=0;
	int answer = 0;

	// 縦でそろう
	for(int i=0; i<S; i++){
		verticalHoleNum = 0;
		for(int j=0; j<S; j++){
			if(hole.at(j).at(i) == 0){
				break;
			}else{
				verticalHoleNum++;
				if(verticalHoleNum == S){
					answer = 1;
				}
			}
		}
	}


	// 横でそろう
	
	for(int i=0; i<S; i++){
		horizontalHoleNum = 0;
		for(int j=0; j<S; j++){
			if(hole.at(i).at(j) == 0){
				break;
			}else{
				horizontalHoleNum++;
				if(horizontalHoleNum == S){
					answer = 1;
				}
			}
		}
	}


	// 斜めでそろう
	
	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			if(i==j){
				if(hole.at(i).at(j) == 0){
					break;
				}else{
					rightDiagonalHoleNum++;
					if(rightDiagonalHoleNum == S){
						answer = 1;
					}
				}
			}
		}
	}

	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
				if(i+j == S-1){
					if(hole.at(i).at(j) == 0){
						break;
					}else{
						leftDiagonalHoleNum++;
						if(leftDiagonalHoleNum == S){
							answer = 1;
						}
					}
				}
			}
	}

	if(answer == 1){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}

}
