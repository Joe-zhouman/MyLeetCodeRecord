// Joe
// 周漫
// 2020071923:35


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace filter_restaurants {
	struct Restaurant {
		int id;
		int rating;

		Restaurant(const int id0, const int rating0): id(id0),
		                                              rating(rating0) {}

		bool operator<(const Restaurant restaurant) const {
			return rating == restaurant.rating ? id < restaurant.id : rating < restaurant.rating;
		}
	};

	class Solution {
	public:
		vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice,
		                              int maxDistance) {
			vector<Restaurant> restaurants_list;
			vector<int> ans;
			for (auto rests : restaurants) {
				if (veganFriendly <= rests[2] &&
				    rests[3] <= maxPrice &&
				    rests[4] <= maxDistance) {
					restaurants_list.emplace_back(Restaurant(rests[0], rests[1]));
				}

			}
			sort(restaurants_list.rbegin(), restaurants_list.rend());
			ans.reserve(restaurants_list.size());
			for (auto value : restaurants_list) {
				ans.push_back(value.id);
			}
			return ans;
		}
	};
}
