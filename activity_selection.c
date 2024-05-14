#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int finish;
} Activity;
int compare(const void *a, const void *b) {
    return ((Activity *)a)->start - ((Activity *)b)->start;
}
int main() {
    int max_activities = 100;
    Activity activity[max_activities];
    int num_activities;
    printf("Enter the number of activities: ");
    scanf("%d", &num_activities);
    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < num_activities; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activity[i].start, &activity[i].finish);
    }
    qsort(activity, num_activities, sizeof(Activity), compare);
    printf("Following activities are selected: ");
    printf("%d ", 1);
    int last_selected = 0;
    for (int j = 1; j < num_activities; j++) {
        if (activity[j].start >= activity[last_selected].finish) {
            printf("%d ", j + 1);
            last_selected = j;
        }
    }
    return 0;
}
