#include <iostream>
using namespace std;

int main() {
    int n = 5, r = 3;

    int alloc[5][3] = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};
    int max[5][3] = {{7,5,3}, {3,2,2}, {9,0,2}, {4,2,2}, {5,3,3}};
    int total[3] = {10,5,7};

    int avail[3], need[5][3];
    bool done[5] = {0};

    // Calculate Available
    for(int j = 0; j < r; j++){
        int sum = 0;
        for(int i = 0; i < n; i++) sum += alloc[i][j];
        avail[j] = total[j] - sum;
    }

    // Calculate Need
    for(int i = 0; i < n; i++)
        for(int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
//
    // Find Safe Sequence
    cout << "Safe Sequence: ";
    int count = 0;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(done[i]) continue;

            bool ok = true;
            for(int j = 0; j < r; j++)
                if(need[i][j] > avail[j]) ok = false;

            if(ok){
                if(count > 0) cout << " -> ";
                cout << "P" << i;
                for(int j = 0; j < r; j++) avail[j] += alloc[i][j];
                done[i] = true;
                count++;
            }
        }
    }

    return 0;
}

