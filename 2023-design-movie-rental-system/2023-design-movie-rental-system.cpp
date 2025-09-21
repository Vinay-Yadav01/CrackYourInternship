struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[2] != b[2])
            return a[2] < b[2]; // lower price first
        if (a[0] != b[0])
            return a[0] < b[0]; // lower shopID first
        return a[1] < b[1];     // lower movieID first
    }
};

class MovieRentingSystem {
    int size;
    unordered_map<int, set<pair<int, int>>>
        movieDetail; // For every movie -> sorted by {price, shopID}

    vector<unordered_map<int, int>>
        shopDetail; // Every shopID -> {movie, price}

    set<vector<int>, comp> rentedMovie; // {shop, movie, price}

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        size = n;
        shopDetail.resize(size);
        for (auto& entry : entries) {
            int shopID = entry[0];
            int movieID = entry[1];
            int price = entry[2];
            shopDetail[shopID][movieID] = price;
            movieDetail[movieID].insert({price, shopID});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto it_movie_offerings = movieDetail.find(movie);
        if (it_movie_offerings != movieDetail.end()) {
            for (auto& offering : it_movie_offerings->second) {
                if (ans.size() == 5) {
                    break;
                }
                ans.push_back(offering.second);
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int price = shopDetail[shop][movie];
        movieDetail[movie].erase({price, shop});
        rentedMovie.insert({shop, movie, price});
    }

    void drop(int shop, int movie) {
        int price = shopDetail[shop][movie];
        rentedMovie.erase({shop, movie, price});
        movieDetail[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (const auto& record : rentedMovie) {
            ans.push_back({record[0], record[1]});
            if (ans.size() == 5)
                break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */