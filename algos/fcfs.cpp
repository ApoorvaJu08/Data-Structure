#include<iostream>
using namespace std;

// Function to find waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process would be zero
    wt[0] = 0;
    for(int i  = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];
}

// Function to calculate TAT
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate avg time
void findAvgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    // Display processes along with all details
    cout << "Processes " << " Burst Time " << " Waiting Time " << " Turn around Time\n";
    // Calculate total Wt and total TAT
    for(int i = 0; i < n; i++) 
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "  " << i+1 << "\t\t" << bt[i] << "\t   " << wt[i] << "\t\t  " << tat[i] << endl; 
    }
    cout << "Avg waiting time = " << (float)total_wt / (float)n;
    cout << "\nAvg turn around time = " << (float)total_tat / (float)n;
}

int main() {
    int processes[] = {1, 2, 3 };
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 5, 8};
    findAvgTime(processes, n, burst_time);
    return 0;
}