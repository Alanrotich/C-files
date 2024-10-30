#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int marks, n;

    file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);
        fprintf(file, "Name: %s, Marks: %d\n", name, marks);
    }

    fclose(file);
    printf("Data appended to students.txt\n");
    return 0;
}