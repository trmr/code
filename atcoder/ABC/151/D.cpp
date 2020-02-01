#include <iostream>
#include <queue>


using namespace std;

#define REP(x, y) for(int (x) = 0; (x) < (y); (x)++)

const int MAX_H = 20, MAX_W = 20;
const int INF = -1;

char maze[MAX_H][MAX_W];
int h, w;
int sx, sy;
int gx, gy;

int d[MAX_H][MAX_W];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {

    queue<pair<int, int>> que;
    int max_d = 0;

    REP(i, h){
        REP(j, w) {
            d[i][j] = INF;
        }
    }

    que.push(pair<int, int>(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        pair<int, int> p = que.front();
        que.pop();

        REP(i, 4){
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if (0<=nx && nx < h && 0 <= ny && ny < w && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(pair<int, int>(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    REP(i, h){
        REP(j, w) {
            if (max_d < d[i][j]) {
                max_d = d[i][j];
            }
        }
    }
    return max_d;


}


int main() {
    cin >> h >> w;
    REP(i, h) {
        REP(j, w) {
            cin >> maze[i][j];
        }
    }

    int max_d = 0;

    REP(i, h) {
        REP(j, w) {
            if (maze[i][j] == '#') continue;
            sx = i, sy = j;
            int d = bfs();
            if (max_d < d){
                max_d = d;
            }
        }
    }
    cout << max_d << endl;
    return 0;
}