#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// ������ �� �����
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
// ��Ƴ�...?

// Ax + By + E = 0
// Cx + Dy + F = 0
// cross_x = (BF - ED) / (AD - BC)
// cross_y = (EC - AF) / (AD - BC)
//vector<double> get_dot(vector<int> dot1, vector<int> dot2)
vector<double> get_dot(double A, double B, double E, double C, double D, double F)
{
    //double A = dot1[0], B = dot1[1], E = dot1[2];
    //double C = dot2[0], D = dot2[1], F = dot2[2];
    vector<double> cross_dot;

    // ������ ���
    if (A * D - B * C == 0) return cross_dot;

    // �������� �ִ� ���
    double cross_x = (B * F - E * D) / (A * D - B * C);
    double cross_y = (E * C - A * F) / (A * D - B * C);
    cross_dot.push_back(cross_x);
    cross_dot.push_back(cross_y);

    return cross_dot;
}

int No()
{
    system_clock::time_point start = system_clock::now();

    vector<string> answer;
    vector<vector<int>> line =
    { {2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12} };

    // ���� ������ ã���ֱ�
    long long max_x = -9223372036854775807, max_y = -9223372036854775807;
    long long min_x = 9223372036854775807, min_y = 9223372036854775807;
    vector<vector<long long>> cross_dots;
    for (int i = 0; i < line.size() - 1; i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            //vector<double> cross_dot = get_dot(
            //    line[i][0], line[i][1], line[i][2],
            //    line[j][0], line[j][1], line[j][2]
            //);
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];

            vector<long long> cross_dot;
            long long cross_x = B * F - E * D;
            long long cross_y = E * C - A * F;
            long long mod = A * D - B * C;

            // �������� ���ٸ�
            if (mod == 0) continue;
            // ������ �ƴϸ�
            //if (!is_integer(cross_dot[0]) || !is_integer(cross_dot[1])) continue;
            if (cross_x % mod || cross_y % mod) continue;
            cross_dot.push_back(cross_x / mod);
            cross_dot.push_back(cross_y / mod);

            // x, y�� �ּ�, �ִ밪 �����ֱ�
            max_x = (max_x < cross_dot[0]) ? cross_dot[0] : max_x;
            min_x = (min_x > cross_dot[0]) ? cross_dot[0] : min_x;
            max_y = (max_y < cross_dot[1]) ? cross_dot[1] : max_y;
            min_y = (min_y > cross_dot[1]) ? cross_dot[1] : min_y;

            cross_dots.push_back(cross_dot);
        }
    }

    // cross_dots (0, 0) �������� �ٲ��ֱ�
    for (int i = 0; i < cross_dots.size(); i++)
    {
        cross_dots[i][0] -= min_x;
        cross_dots[i][1] -= min_y;
        //cross_dots[i][0] = cross_dots[i][0] + min_y;
        //cross_dots[i][1] = cross_dots[i][1] - min_x;
    }
    max_x -= min_x;
    min_x -= min_x;
    max_y -= min_y;
    min_y -= min_y;

    // answer ������ֱ�
    string tmp;
    for (int i = 0; i <= max_x; i++)
    {
        tmp += ".";
    }
    for (int i = 0; i <= max_y; i++)
    {
        answer.push_back(tmp);
    }

    for (int i = 0; i < cross_dots.size(); i++)
    {
        long long x = cross_dots[i][1];
        long long y = cross_dots[i][0];
        answer[x][y] = '*';
    }

    reverse(answer.begin(), answer.end());

    system_clock::time_point end = system_clock::now();
    microseconds micro = duration_cast<microseconds>(end - start);
    cout << "�ҿ� �ð� : " << micro.count() << endl;
    return 0;
}

int main()
{
    No();

    return 0;
}