#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, qt;
    int count = 0;
    int sq = 0;
    int bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0;
    float atat = 0;

    system("cls");  // Note: system("cls") is Windows-specific; consider using system("clear") for Unix-like systems

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter quantum time: ");
    scanf("%d", &qt);

    while (1) {
        int allProcessesComplete = 1;  // Flag to check if all processes have completed

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                allProcessesComplete = 0;  // Set the flag to false as there are still processes remaining

                if (rem_bt[i] > qt) {
                    // If remaining burst time is greater than quantum time
                    sq += qt;
                    rem_bt[i] -= qt;
                } else {
                    // If remaining burst time is less than or equal to quantum time
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                }

                tat[i] = sq;  // Set turnaround time for the current process
                wt[i] = tat[i] - bt[i];  // Set waiting time for the current process
            }
        }

        if (allProcessesComplete)
            break;  // Exit the loop if all processes have completed
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    // Print the results
    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }

    printf("\naverage waiting time: %f\n", awt);
    printf("average turnaround time: %f\n", atat);

    return 0;
}
