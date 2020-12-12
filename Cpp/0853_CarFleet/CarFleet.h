// Joe
// 周漫
// 2020071823:14


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace car_fleet {
	struct Car {
		int position;
		double time;
		bool operator<(const Car car) const {
			return position < car.position;
		}
	};

	class Solution {
	public:		
		static int CarFleet(int target, vector<int>& position, vector<int>& speed) {
			int n = position.size();
			if (n < 1)
				return 0;
			vector<Car> cars(n);
			for (auto i = 0; i < n; ++i) {
				cars[i].position = position[i];
				cars[i].time = ((static_cast<double>(target) - position[i]) / speed[i]);
			}
			sort(cars.begin(), cars.end());
			auto t1 = cars[n-1].time;
			auto ans = 1;
			for (int i = n - 1; i > 0; --i) {
				auto t2 = cars[i-1].time;
				if (t2 <= t1) {
					t2 = t1;
				}
				else {
					ans += 1;
				}
				t1 = t2;
			}
			return ans;
		}
	};
}
