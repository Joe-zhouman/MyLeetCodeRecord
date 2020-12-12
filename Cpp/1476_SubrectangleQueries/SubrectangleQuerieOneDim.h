#pragma once
#include <vector>;
using namespace std;

class SubrectangleQueriesOneDim {
	vector<int> _data = {};
	int _maxRow;
	int _maxCol;
public:
	SubrectangleQueriesOneDim(vector<vector<int>>& rectangle) {
		_maxRow = rectangle.size();
		_maxCol = rectangle[0].size();
		for (int i = 0; i < _maxRow; i++) {
			for (int j = 0; j < _maxCol; j++)
				_data.push_back(rectangle[i][j]);
		}
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; i++)
			for (int j = col1; j <= col2; j++)
				_data[i * _maxCol + j] = newValue;
	}

	int getValue(int row, int col) { return _data[row * _maxCol + col]; }
};
