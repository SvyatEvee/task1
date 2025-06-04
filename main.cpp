#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("data_prog_contest_problem_1.txt");

    if (!ifs.is_open()) {
        cout << "File was not opened" << endl;
        return 0;
    }

    vector<pair<int, int>> segments;

    unsigned segments_number = 0;

    //Считываем данные о количестве отрезков
    ifs >> segments_number;

    // Если отрезков нету, то возвращаем 0
    if(segments_number == 0){
        cout << 0 << endl;
        return 0;
    }

    // Считываем данные о отрезках из файла и записываем их в вектор
    for (unsigned i = 0; i < segments_number; ++i) {
        pair<int, int> segment;
        ifs >> segment.first >> segment.second;
        segments.push_back(segment);
    }

    ifs.close();

    // Cортируем отрезки по возрастанию координаты правого конца
    sort(segments.begin(), segments.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

    unsigned point_counter = 1;
    pair<int, int> current_segment = segments.front();

    // Если координата левого конца следующего отрезка больше координаты правого конца текущего отрезка, то они не пересекаются, нужно добавить точку
    for (unsigned i = 1; i < segments_number; ++i) {
        if (segments[i].first > current_segment.second) {
            point_counter++;
            current_segment = segments[i];
        }
    }

    cout << point_counter << endl;
    return 0;
}
