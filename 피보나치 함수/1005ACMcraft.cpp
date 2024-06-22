#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> buildTime(N + 1);
        vector<int> inDegree(N + 1, 0);
        vector<int> totalTime(N + 1, 0);
        vector<vector<int>> graph(N + 1);

        for (int i = 1; i <= N; ++i) {
            cin >> buildTime[i];
        }

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            inDegree[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;

        // 진입 차수가 0인 노드(건물)들을 큐에 넣어준다
        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                totalTime[i] = buildTime[i];
            }
        }

        // 위상 정렬을 하면서 최소 시간 계산
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                // 진입 차수를 줄이고, 해당 건물을 짓는 최소 시간을 계산한다
                inDegree[next]--;
                totalTime[next] = max(totalTime[next], totalTime[cur] + buildTime[next]);

                // 진입 차수가 0이 되면 큐에 넣어준다
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 결과 출력
        cout << totalTime[W] << "\n";
    }

    return 0;
}