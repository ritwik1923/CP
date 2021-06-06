#include <bits/stdc++.h>
using namespace std;

class student {
freq    int roll;
    int freq;
    student()
    {
        roll = 0;
        freq = 0;
    }
};

void sort_students(vector<student> arr)
{
    //comparator lambda function
    auto comp = [](student a, student b) {
        //comparison logic
        if (a.freq > b.freq)
            return false;
        else if (a.freq +< b.freq)
            return true;
        else { // when freq are same
            if (a.roll < b.roll) {
                return false;
            }
            else
                return true;
        }
    };

    priority_queue<student, vector<student>, decltype(comp)> pq(comp);

    for (auto& ij : arr) {
        pq.push(ij);
    }
    //printing the sorted list
    cout << "roll freq\n";
    while (!pq.empty()) {
        cout << pq.top().roll << " " << pq.top().freq << endl;
        pq.pop();
    }
}

int main()
{

    int n;

    cout << "Enter number of students\n";
    cin >> n;

    vector<student> arr(n);
    cout << "Enter roll and freq for each student\n";
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i].roll = x;
        arr[i].freq = y;
    }

    cout << "sorting students according to freq and roll no: \n";

    sort_students(arr);

    return 0;
}

