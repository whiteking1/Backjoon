#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, W;
        cin >> N >> W;

        vector<int> first_zone(N);
        vector<int> second_zone(N);

        // 첫 번째 원과 두 번째 원에 배치된 적의 수 입력
        for (int i = 0; i < N; ++i) {
            cin >> first_zone[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> second_zone[i];
        }

        // 각 구역에서 커버 가능한 인접한 구역의 최대 적의 수 계산
        vector<int> cover_first(N);
        vector<int> cover_second(N);

        cover_first[0] = second_zone[0];
        cover_second[0] = first_zone[0];

        for (int i = 1; i < N; ++i) {
            cover_first[i] = max(cover_first[i - 1], second_zone[i]);
            cover_second[i] = max(cover_second[i - 1], first_zone[i]);
        }

        // 최소 특수 소대 수 계산
        int min_special_forces = 0;

        for (int i = 0; i < N; ++i) {
            // 현재 구역을 커버하기 위한 최소 특수 소대 수
            int needed_for_current = max(first_zone[i], second_zone[i]);

            // 인접한 구역 중에서 가장 적은 특수 소대 수
            int min_needed_from_neighbors = 0;
            if (i > 0) {
                min_needed_from_neighbors = max(cover_first[i - 1], cover_second[i - 1]);
            }

            // 현재 구역을 하나의 소대로 커버할 수 있는지 확인
            if (needed_for_current <= W) {
                min_special_forces++;
            }
            else {
                // 인접한 구역과 합쳐서 하나의 소대로 커버할 수 있는지 확인
                int combined_cover = max(needed_for_current, min_needed_from_neighbors);
                if (combined_cover <= W) {
                    min_special_forces++;
                }
                else {
                    // 현재 구역과 인접한 구역 모두를 따로 커버해야 함
                    min_special_forces += 2;
                }
            }
        }

        // 결과 출력
        cout << min_special_forces << "\n";
    }

    return 0;
}