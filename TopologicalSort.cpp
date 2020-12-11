#include <iostream>
#include <vector>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 
you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should
also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        graph = vector<vector<int>>(numCourses);

        for(const auto& p : prerequisites)
            graph[p.first].push_back(p.second);

        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);

        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, v)) return false;

        return true;
    }

private:
    vector<vector<int>> graph;
    bool dfs(int cur, vector<int>& v) {
        if(v[cur] == 1) return true;
        if(v[cur] == 2) return false;

        v[cur] = 1;

        for(const int t : graph[cur])
            if(dfs(t, v)) return true;

        v[cur] = 2;

        return false;
    }
};

int main() {
    int numCourses = 8;
    vector<pair<int, int>> prerequisites = {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}};
    bool x = Solution().canFinish(numCourses, prerequisites);
    cout << x << endl;

    return 0;
}

