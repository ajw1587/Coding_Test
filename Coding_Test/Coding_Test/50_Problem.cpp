#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 4중 for문
int No50()
{
	system_clock::time_point start = system_clock::now();

    vector<vector<int>> map{ {3, 5, 1, 3, 1, 3, 2},
                            {1, 2, 1, 3, 1, 1, 2},
                            {1, 3, 1, 5, 1, 3, 4},
                            {5, 1, 1, 3, 1, 3, 2},
                            {3, 1, 1, 3, 1, 1, 2},
                            {1, 3, 1, 3, 1, 2, 2} };
    int h = 2, w = 3;
    int max = 0;
    int loc_h, loc_w;
    for (int i = 0; i <= map.size() - h; i++) { // h
        for (int j = 0; j <= map[0].size() - w; j++) { // w
            int sum = 0;
            for (int h_idx = i; h_idx < h + i; h_idx++) { // h
                for (int w_idx = j; w_idx < w + j; w_idx++) { // w
                    sum += map[h_idx][w_idx];
                }
            }
            if (sum > max) {
                max = sum;
                loc_h = i;
                loc_w = j;
            }
        }
    }

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No50();
//
//	return 0;
//}