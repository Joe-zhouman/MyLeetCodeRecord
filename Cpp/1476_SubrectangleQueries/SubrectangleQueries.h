#pragma once
#include <vector>
using namespace std;

class SubrectangleQueries {
	vector<vector<int>> _data;
public:
	SubrectangleQueries(vector<vector<int>>& rectangle) { _data = rectangle; }

	void UpdateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; i++)
			for (int j = col1; j <= col2; j++)
				_data[i][j] = newValue;
	}

	int GetValue(int row, int col) { return _data[row][col]; }
};
