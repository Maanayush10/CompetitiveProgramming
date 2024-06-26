/*

Implementing Dijkstra Algorithm
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

*/
//shout out to Raj Vikramaditya
//using priority q
// prority queue stores the distance and node as a min heap
//the top element is taken out and the current node's distance is added to the prev node's distance and checked with the entry in the distance arr
//if it is less the entry is updated otherwise, we just proceed forward
// presence of INT_MAX shows node not reachable
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>distance(V, INT_MAX);
        pq.push({S, 0});
        distance[S]=0;
        while(!pq.empty())
        {
            int node= pq.top().first;
            int prevDis= pq.top().second;
            pq.pop();
            for(auto it: adj[node])
            {
                int dist= it[1]+prevDis;
                if(dist<distance[it[0]])
                {
                    distance[it[0]]= dist;
                    pq.push({it[0], dist});
                }
            }
        }
        for(int i=0; i<distance.size(); i++)
        {
            if(distance[i]==INT_MAX)
            {
                distance[i]=-1;
            }
        }
        return distance;
    }
};
