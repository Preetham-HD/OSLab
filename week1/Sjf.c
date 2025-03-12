#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Non preemptive

void sjfSort(int at[], int bt[], int n) {
   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (bt[j] > bt[j + 1]) {
                swap(&bt[j], &bt[j + 1]);         
                swap(&at[j], &at[j + 1]);
            }
        }
    }
}

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

    sjfSort(at, bt, n);

    calcTime(at, bt, tat, ct, rt, wt, n);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }
}
/*
output:
Enter the number of processes: 3

Enter the arrival and burst time of each of the processes:
P1 Arrival time: 0
P1 Burst time: 2
P2 Arrival time: 3
P2 Burst time: 4
P3 Arrival time: 5
P3 Burst time: 8

Process AT      BT      CT      TAT     WT      RT
P1      0       2       2       2       0       0
P2      3       4       7       4       0       0
P3      5       8       15      10      2       2
*/
