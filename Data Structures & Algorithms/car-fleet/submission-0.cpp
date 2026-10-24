class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // By sorting in descending order we can base calculations on the car that is in first place
        // Because the speed of that car will determine the speed of that fleet
        // if a car reaches the target before the car ahead then that means they become a fleet
        //  which merges with the fleet by popping it from the stack.
        sort(cars.rbegin(), cars.rend());

        vector<double> stack;
        for (auto& p : cars) {
            stack.push_back((double) (target - p.first) / p.second);
            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
                stack.pop_back();
            }
        }

        // remaining cars in the stack are individual fleets.
        return stack.size();
    }
};
