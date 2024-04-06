<script src="https://gist.github.com/romjanxr/cfcdc5e015a9811c6c40f71753d64949.js"></script>
graph.cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 101;

vector<int> adj[N];
int visited[N];

int bfs(int src){
    int count = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        count++;
        for(int child : adj[parent]){
            if(visited[child] == false){
                q.push(child);
                visited[child] = true;
            }
        }
    }
    return count;
}
int cnt = 0;
void dfs(int src){
    cnt++;
    visited[src] = true;
    for(int child : adj[src]){
        if(!visited[child])
            dfs(child);
    }
}

int main(){
    int node, edge;
    cin >> node >> edge;
    while(edge--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= node; i++ ){
        if(!visited[i])
        {
            // int sz = bfs(i);
            // if(sz > 1)
            cnt = 0;
            dfs(i);
            if(cnt > 1)
                count++;
        }
    }
    cout << count << endl;
}

/* 
8 5
1 2
1 3
4 5
6 7
8 8
 */
Labyrinth.cpp
/*
########
#.A#...#
####.#B#
#......#
########
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int n, m;
int maze[N][N];
int visited[N][N];

int dx[4] ={0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int x, int y){
    return !visited[x][y] && maze[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(pair<int, int> src){
    queue<pair<int, int>> q;

    q.push(src);
    visited[src.first][src.second] = true;

    while(!q.empty()){
        auto parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(validate(new_x, new_y))
            {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }
    }
}

int main()
{
    
    pair<int, int> src, dst;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                maze[i][j] = -1;
            if(s[j] == 'A') src = {i, j};
            if(s[j] == 'B') dst = {i, j};
        }
    }
    bfs(src);

    if(visited[dst.first][dst.second] == true) cout << "YES" << endl;
    else cout << "NO" << endl;
}

