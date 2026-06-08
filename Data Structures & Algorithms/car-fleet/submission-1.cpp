class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        /*
            keep track of count of fleets
            eachh fleet is a time that a car can make, if a car cannot catch up to the nearest fleet
            it becomes its own fleet


            4 1 0 7   2 2 1 1

            time[i] = (target - position[i]) / speed[i]

                    
        2   4.5      3     3
            * *     *     *
            0 1 2 3 4 5 6 7 8 9 10

            starting from most ahead car -> calculate time
            walk backwards and determine time for each car, checking if time <= next closest fleet
            because cars cannot go ahead

            sort cars position and speed in descending order -> will let us walk backward
            calculate time for car[i] 

            use stack to keep track of closest fleet:
            if time <= top of stack, we will join that fleet, otherwise a new fleet will be created
        */

        int n = position.size();
        vector<pair<int, int>> pos_speed;
        stack<double> fleet_times;

        for (int i = 0; i < n; i++)
        {
            pos_speed.emplace_back(position[i], speed[i]);
        }

        sort(pos_speed.begin(), pos_speed.end(), greater<pair<int, int>>());

        for (const auto &[pos, speed] : pos_speed)
        {   
            double time = (target - pos) / static_cast<double>(speed);
            if (!fleet_times.empty())
            {
                if (time > fleet_times.top())
                {
                    cout << time << endl;
                    fleet_times.push(time);
                }
            }
            else
            {
                fleet_times.push(time);
            }
        }

        return fleet_times.size();
    }
};
