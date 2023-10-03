#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
    int priority;
};

bool compareProcesses(const Process& a, const Process& b) {
    return a.priority < b.priority;
}

int main() {
    int number_of_process;
    cout << "Enter the number of processes: ";
    cin >> number_of_process;
    cout << "Enter information for " << number_of_process << " processes (arrival time, burst time, and priority)." << endl;

    vector<Process> process_info;
    int total_burst_time = 0;

    for (int i = 0; i < number_of_process; i++) {
        Process process;
        cout << "Enter " << i + 1 << "th process name: ";
        cin >> process.name;
        cout << "Enter " << i + 1 << "th arrival time: ";
        cin >> process.arrival_time;
        cout << "Enter " << i + 1 << "th burst time: ";
        cin >> process.burst_time;
        cout << "Enter " << i + 1 << "th priority: ";
        cin >> process.priority;
        total_burst_time += process.burst_time;
        process_info.push_back(process);
    }

    sort(process_info.begin(), process_info.end(), compareProcesses);

    cout << "Prc|Arrival T|Burst T|Wating T|TAT|Compilation T|Priority" << endl;

    vector<string> process_name(number_of_process);
    vector<int> arrival_time(number_of_process);
    vector<int> brust_time(number_of_process);
    vector<int> priority(number_of_process);

    for (int i = 0; i < number_of_process; i++) {
        process_name[i] = process_info[i].name;
        arrival_time[i] = process_info[i].arrival_time;
        brust_time[i] = process_info[i].burst_time;
        priority[i] = process_info[i].priority;
    }

    int total_waiting_time = 0;
    int total_turn_around_time = brust_time[0];
    int program_start = arrival_time[0];
    int program_finished = brust_time[0];

    for (int i = 0; i < number_of_process; i++) {
        if (i == 0) {
            cout << process_name[i] << "\t " << arrival_time[i] << "\t " << brust_time[i] << "\t "
                << arrival_time[i] << "\t " << brust_time[i] << "\t "
                << brust_time[i] << "\t " << priority[i] << endl;
        } else {
            program_finished += brust_time[i];
            program_start += brust_time[i - 1];
            cout << process_name[i] << "\t " << arrival_time[i] << "\t " << brust_time[i] << "\t "
                << program_finished - arrival_time[i] - brust_time[i] << "\t "
                << program_finished - arrival_time[i] << "\t " << program_finished << "\t " << priority[i] << endl;

            total_turn_around_time += (program_finished - arrival_time[i]);
            total_waiting_time += (program_start - arrival_time[i]);
        }
    }

    cout << "Average waiting time: " << static_cast<double>(total_waiting_time) / number_of_process << endl;
    cout << "Average turnaround time: " << static_cast<double>(total_turn_around_time) / number_of_process << endl;

    return 0;
}
