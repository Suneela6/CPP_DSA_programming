//ninja is planning this 'N' days-long training schedule
//each day, he can perform any one of these three activities.
//(running,fighting practivce,learning new moves)
//each activity has some merit points on each day. as ninja has to improve all his skills,
//he can't do the same activity in two consecutive days.
//can you help ninja find out the maxmimum merit points ninja can earn
// you are given a 2d array of size N*3 "pomints" with the points
//correspondinh to each day and activity. your task is to calculate the maxn=imum number 
//of merit points that ninja can earn
#include <iostream>
#include <vector>
using namespace std;

int ninjaTrainingMemo(int day, int lastActivity, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (day == 0) {
        int maxPoints = 0;
        for (int i = 0; i < 3; i++) {
            if (i != lastActivity) maxPoints = max(maxPoints, points[0][i]);
        }
        return maxPoints;
    }

    if (dp[day][lastActivity] != -1) return dp[day][lastActivity];

    int maxPoints = 0;
    for (int i = 0; i < 3; i++) {
        if (i != lastActivity) {
            int activityPoints = points[day][i] + ninjaTrainingMemo(day - 1, i, points, dp);
            maxPoints = max(maxPoints, activityPoints);
        }
    }

    return dp[day][lastActivity] = maxPoints;
}

int main() {
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << "Maximum Merit Points (Memoization): " << ninjaTrainingMemo(n - 1, 3, points, dp) << endl;
    return 0;
}
