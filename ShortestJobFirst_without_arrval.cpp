#include <iostream>
using namespace std;

int main() {
	int P[100],BT[100],WT[100] = {0},TAT[100] = {0};
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;

	cout << "Enter number of process: ";
	cin >> n;

	cout << "Enter Burst Time:" << endl;

	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		cout << "P" << i + 1 << ": ";
		cin >> BT[i];
		P[i] = i+1;
	}

	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++){
           if (BT[i] > BT[j]){
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
			}
		}
	}

	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++){
            WT[i] += BT[j];
		}
		total += WT[i];
	}

	avg_wt = (float)total / n;
	total = 0;
	cout << "P	 BT	 WT	 TAT" << endl;

	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		TAT[i] = BT[i]+WT[i];
		total += TAT[i];
		cout << "P" << P[i] << "	 " << BT[i] << "	 " << WT[i] << "	 " << TAT[i] << endl;
	}

	avg_tat = (float)total / n;
	cout << "Average Waiting Time= " << avg_wt << endl;
	cout << "Average Turnaround Time= " << avg_tat << endl;
}

