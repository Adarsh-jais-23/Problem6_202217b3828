#include <stdio.h>
#include <stdlib.h> // For exit() function

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float awt = 0, att = 0;

    // Initialize all arrays
    for (i = 0; i < 10; i++) {
        a[i] = 0; 
        b[i] = 0; 
        w[i] = 0; 
        g[i] = 0; 
    }

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of processes. Please enter a number between 1 and 10.\n");
        return 1;
    }
    
    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    printf("\nEnter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Calculate completion times
    g[0] = a[0] + b[0]; // First process completion time
    for (i = 1; i < n; i++) {
        g[i] = (a[i] > g[i-1]) ? a[i] + b[i] : g[i-1] + b[i];
    }
    
    // Calculate waiting times and turnaround times
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i]; // Waiting time
        t[i] = g[i] - a[i]; // Turnaround time
        awt += w[i]; // Accumulate total waiting time
        att += t[i]; // Accumulate total turnaround time
    }
    
    awt /= n; // Average waiting time
    att /= n; // Average turnaround time
    
    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    
    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
    
    return 0;
}

