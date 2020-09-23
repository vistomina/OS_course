#include <stdio.h>

void swap (int* a, int* b, int * c, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
    temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

void sort (int* burst_time, int* arrival_time, int * g, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if ((arrival_time[j] > arrival_time[j + 1]) || (arrival_time[j] == arrival_time[j + 1] && burst_time[j] > burst_time[j + 1]))
                swap(burst_time, arrival_time, g, j, j + 1);
        }
    }
}

int main()
{
    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    printf("Please, enter numbers not in random order\n");
    int g[n], arrival_time[n], burst_time[n], waiting_time[n], turn_around_time[n], completion_time;
    float avgwt = 0, avgtat = 0;
 
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time of the process %d: ", i+1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time of the process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        g[i] = i + 1;
    }
    
    sort(burst_time, arrival_time, g, n);
 
    waiting_time[0] = 0;
    completion_time = 0;
    turn_around_time[0] = burst_time[0];
    
    for(int i = 1; i<n; i++) {
        waiting_time[i]=0;
        for(int j = 0; j < i; j++){
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i]-1;
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }

    for(int i = 0; i < n; i++){
        completion_time += burst_time[i];
        avgwt += waiting_time[i];
        avgtat += turn_around_time[i];
        printf("\nArrival time: %d", arrival_time[i]);
        printf("\nBurst time: %d", burst_time[i]);
        printf("\nCompletion time: %d", completion_time);
        printf("\nTurn around time: %d", turn_around_time[i]);
        printf("\nWaiting time: %d", waiting_time[i]);
        printf("\n\n");
    }
 
    printf("\n\nAverage Waiting Time: %f", avgwt/n);
    printf("\nAverage Turnaround Time: %f", avgtat/n);
 
    return 0;
}
