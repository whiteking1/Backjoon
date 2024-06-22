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

        // ù ��° ���� �� ��° ���� ��ġ�� ���� �� �Է�
        for (int i = 0; i < N; ++i) {
            cin >> first_zone[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> second_zone[i];
        }

        // �� �������� Ŀ�� ������ ������ ������ �ִ� ���� �� ���
        vector<int> cover_first(N);
        vector<int> cover_second(N);

        cover_first[0] = second_zone[0];
        cover_second[0] = first_zone[0];

        for (int i = 1; i < N; ++i) {
            cover_first[i] = max(cover_first[i - 1], second_zone[i]);
            cover_second[i] = max(cover_second[i - 1], first_zone[i]);
        }

        // �ּ� Ư�� �Ҵ� �� ���
        int min_special_forces = 0;

        for (int i = 0; i < N; ++i) {
            // ���� ������ Ŀ���ϱ� ���� �ּ� Ư�� �Ҵ� ��
            int needed_for_current = max(first_zone[i], second_zone[i]);

            // ������ ���� �߿��� ���� ���� Ư�� �Ҵ� ��
            int min_needed_from_neighbors = 0;
            if (i > 0) {
                min_needed_from_neighbors = max(cover_first[i - 1], cover_second[i - 1]);
            }

            // ���� ������ �ϳ��� �Ҵ�� Ŀ���� �� �ִ��� Ȯ��
            if (needed_for_current <= W) {
                min_special_forces++;
            }
            else {
                // ������ ������ ���ļ� �ϳ��� �Ҵ�� Ŀ���� �� �ִ��� Ȯ��
                int combined_cover = max(needed_for_current, min_needed_from_neighbors);
                if (combined_cover <= W) {
                    min_special_forces++;
                }
                else {
                    // ���� ������ ������ ���� ��θ� ���� Ŀ���ؾ� ��
                    min_special_forces += 2;
                }
            }
        }

        // ��� ���
        cout << min_special_forces << "\n";
    }

    return 0;
}