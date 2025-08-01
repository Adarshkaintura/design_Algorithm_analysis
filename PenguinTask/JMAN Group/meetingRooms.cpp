//question- /* Problem Description
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

 

Where:

 

    A[i][0] = start time of the ith meeting.
    A[i][1] = end time of the ith meeting.

 

Find the minimum number of conference rooms required so that all meetings can be done.

Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

 


Problem Constraints

1 <= N <= 105

 

0 <= A[i][0] < A[i][1] <= 2 * 109

 


Input Format

The only argument given is the matrix A.


Output Format

Return the minimum number of conference rooms required so that all meetings can be done.


Example Input

Input 1:

 A = [      [0, 30]        0-------------------------------------30
            [5, 10]           5-------10
            [15, 20]                         15--------20
     ]

Input 2:

 A =  [     [1, 18]      1-------------------------------18
            [18, 23]                                     18---------23
            [15, 29]                            15-------------------------------29
            [4, 15]            4----------------15
            [2, 11]        2----------------11
            [5, 13]              5-------------13
      ]



Example Output

Output 1:

 2

Output 2:

 4
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startTimes, endTimes;

        for (const auto& interval : intervals) {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int rooms = 0, endPtr = 0;

        for (int i = 0; i < startTimes.size(); ++i) {
            if (startTimes[i] < endTimes[endPtr]) {
            
                rooms++;
            } else {
                endPtr++;
            }
        }

        return rooms;
    }
};
