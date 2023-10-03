#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
};

bool compareProcesses(const Process& a, const Process& b) {
    return (a.arrival_time + a.burst_time) < (b.arrival_time + b.burst_time);
}

int main() {
    int number_of_process;
    cout << "Enter the number of process: ";
    cin >> number_of_process;
    cout << "Enter " << number_of_process << " processes arrival time and burst time." << endl;

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
        total_burst_time += process.burst_time;
        process_info.push_back(process);
    }

    sort(process_info.begin(), process_info.end(), compareProcesses);

    cout << "Prog. Name \t Arrival Time \t Burst Time \t Start \t Waiting \t TAT \t Finish" << endl;
    int total_waiting_time = 0;
    int total_turnaround_time = process_info[0].burst_time;
    int program_start = process_info[0].arrival_time;
    int program_finished = process_info[0].burst_time;

    for (int i = 0; i < number_of_process; i++) {
        if (i == 0) {
            cout << process_info[i].name << "\t " << process_info[i].arrival_time << "\t " << process_info[i].burst_time << "\t "
                << program_start << "\t " << process_info[i].arrival_time << "\t " << process_info[i].burst_time << "\t "
                << process_info[i].burst_time << endl;
        } else {
            program_finished += process_info[i].burst_time;
            program_start += process_info[i - 1].burst_time;
            cout << process_info[i].name << "\t " << process_info[i].arrival_time << "\t " << process_info[i].burst_time << "\t "
                << program_start << "\t " << program_finished - process_info[i].arrival_time - process_info[i].burst_time << "\t "
                << program_finished - process_info[i].arrival_time << "\t " << program_finished << endl;

            total_turnaround_time += (program_finished - process_info[i].arrival_time);
            total_waiting_time += (program_start - process_info[i].arrival_time);
        }
    }

    cout << "Average waiting time " << static_cast<double>(total_waiting_time) / number_of_process << endl;
    cout << "Average turnaround time " << static_cast<double>(total_turnaround_time) / number_of_process << endl;

    return 0;
}