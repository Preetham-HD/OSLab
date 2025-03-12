#include <stdio.h>

void calcTime(int at[], int bt[], int tat[], int ct[], int rt[], int wt[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];
        }
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = time - at[i];
        time = ct[i];
    }
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tat[n], ct[n], rt[n], wt[n];

    printf("\nEnter the arrival and burst time of each of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d Arrival time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    calcTime(at, bt, tat, ct, rt, wt, n);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
