#include <iostream>
#include <vector>

using namespace std;

int main() {
    int processes, resources;
    cout << "Number of processes: ";
    cin >> processes;
    cout << "Number of resources: ";
    cin >> resources;

    vector<int> max_resources(resources);
    cout << "Maximum resources: ";
    for (int i = 0; i < resources; i++) {
        cin >> max_resources[i];
    }

    cout << "\n-- Allocated resources for each process --" << endl;
    vector<vector<int>> currently_allocated(processes, vector<int>(resources));
    for (int i = 0; i < processes; i++) {
        cout << "Process " << i + 1 << " : ";
        for (int j = 0; j < resources; j++) {
            cin >> currently_allocated[i][j];
        }
    }

    cout << "\n-- Maximum resources for each process --" << endl;
    vector<vector<int>> max_need(processes, vector<int>(resources));
    for (int i = 0; i < processes; i++) {
        cout << "Process " << i + 1 << " : ";
        for (int j = 0; j < resources; j++) {
            cin >> max_need[i][j];
        }
    }

    vector<int> allocated(resources, 0);
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            allocated[j] += currently_allocated[i][j];
        }
    }

    cout << "\nTotal allocated resources: ";
    for (int i = 0; i < resources; i++) {
        cout << allocated[i] << " ";
    }
    cout << endl;

    vector<int> available(resources);
    for (int i = 0; i < resources; i++) {
        available[i] = max_resources[i] - allocated[i];
    }

    cout << "Total available resources: ";
    for (int i = 0; i < resources; i++) {
        cout << available[i] << " ";
    }
    cout << "\n";

    vector<bool> running(processes, true);
    int count = processes;

    while (count != 0) {
        bool safe = false;
        for (int i = 0; i < processes; i++) {
            if (running[i]) {
                bool executing = true;
                for (int j = 0; j < resources; j++) {
                    if (max_need[i][j] - currently_allocated[i][j] > available[j]) {
                        executing = false;
                        break;
                    }
                }
                if (executing) {
                    cout << "Process " << i + 1 << " is executing" << endl;
                    running[i] = false;
                    count--;
                    safe = true;
                    for (int j = 0; j < resources; j++) {
                        available[j] += currently_allocated[i][j];
                    }
                    break;
                }
            }
        }

        if (!safe) {
            cout << "The processes are in an unsafe state." << endl;
            break;
        }

        cout << "The process is in a safe state." << endl;
        cout << "Available resources: ";
        for (int i = 0; i < resources; i++) {
            cout << available[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
