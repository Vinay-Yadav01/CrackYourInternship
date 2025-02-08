class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pair<int, string>>> cuisineRating;
    unordered_map<string, string> food_cuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodRating[foods[i]] = ratings[i];
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating = foodRating[food];
        foodRating[food] = newRating;
        cuisineRating[cuisine].erase({-oldRating, food});
        cuisineRating[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return (*cuisineRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */