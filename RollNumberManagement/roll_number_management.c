#include <stdio.h>
#define max 5

int n = 0, i;

struct STUD {
    char stud_name[20];
    int roll_num;
    float per_marks;
};

void Read_data(struct STUD s[max]) {
    printf("Enter how many students (max %d)? ", max);
    scanf("%d", &n);

    if (n > max) {
        printf("Number of students exceeds the maximum limit. Setting to max (%d).\n", max);
        n = max; // Adjust n to max if it exceeds
    } else if (n <= 0) {
        printf("Invalid number of students. Exiting.\n");
        return;
    }

    printf("\nEnter student details:\n");
    printf("Student name\tRoll Num\tPercentage Marks\n");
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].stud_name);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll_num);
        printf("Percentage Marks: ");
        scanf("%f", &s[i].per_marks);

        // Validate percentage marks
        if (s[i].per_marks < 0 || s[i].per_marks > 100) {
            printf("Invalid percentage! Please re-enter details for this student.\n");
            i--; // Retry this student
        }
    }
}

void Displaydata(struct STUD s[], int count) {
    printf("\nStudent Details (Score > 85):\n");
    printf("Stud Name\tRoll Num\tPercentage Marks\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-15s %-10d %.2f\n", s[i].stud_name, s[i].roll_num, s[i].per_marks);
    }
}

void calculate(struct STUD s[max]) {
    struct STUD high_scorers[max];
    int count = 0;

    for (i = 0; i < n; i++) {
        if (s[i].per_marks > 85) {
            high_scorers[count] = s[i]; // Store the high scorer
            count++;
        }
    }

    // Display the details of students who scored more than 85
    if (count > 0) {
        Displaydata(high_scorers, count);
    } else {
        printf("\nNo students scored more than 85.\n");
    }
}

int main() {
    struct STUD s[max];
    Read_data(s);
    if (n > 0) { // Proceed only if students were entered
        calculate(s);
    }
    return 0;
}
