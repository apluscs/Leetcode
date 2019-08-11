class Solution {
    public:
        int carFleet(int target, vector < int > & position, vector < int > & speed) {
            int N = speed.size(), res = 0;
            double timeFirst = -1; //time it takes first car in curr fleet to reach target
            map < int, int > cars; //sort as you go = faster
            for (int i = 0; i != N; i++) {
                cars[-position[i]] = speed[i]; //sort by position closest to target  
            }

            // for(auto car:cars) cout<<car.first<<", "<<car.second<<endl;
            // for(int i=0;i!=N;i++) cout<<cars[i][0]<<", "<<cars[i][1]<<endl;
            for (auto car: cars) {
                double curr = (target + car.first) / (double) car.second; //cuz negative val
                if (curr > timeFirst) {
                    res++; //tails behind curr fleet, leading a new fleet
                    timeFirst = curr;
                    // cout<<timeFirst<<'\t';
                }
            }
            return res;
        }
};

class SolutionSlow {
    public:
        int carFleet(int target, vector < int > & position, vector < int > & speed) {
            int N = speed.size(), res = 0;
            double timeFirst = -1; //time it takes first car in curr fleet to reach target
            vector < vector < int >> cars(N);
            for (int i = 0; i != N; i++) {
                cars[i].push_back(position[i]); //sort by position closest to target
                cars[i].push_back(speed[i]);
            }

            sort(cars.begin(), cars.end(), compareArr);
            // for(int i=0;i!=N;i++) cout<<cars[i][0]<<", "<<cars[i][1]<<endl;
            for (int i = 0; i != N; i++) {
                double curr = (target - cars[i][0]) / (double) cars[i][1];
                if (curr > timeFirst) {
                    res++; //tails behind curr fleet, leading a new fleet
                    timeFirst = curr;
                    // cout<<timeFirst<<'\t';
                }
            }
            return res;
        }

    static bool compareArr(vector < int > & car1, vector < int > & car2) {
        return car1[0] > car2[0];
    }
};
