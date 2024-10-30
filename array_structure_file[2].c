#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    FILE *file;
    struct Student students[5];
    struct Student readStudents[5];

    // Input data for 5 students
    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    // Write to file using fwrite()
    file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(students, sizeof(struct Student), 5, file);
    fclose(file);

    // Read from file and display
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fread(readStudents, sizeof(struct Student), 5, file);
    fclose(file);

    printf("Data read from students.dat:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Marks: %d\n", readStudents[i].name, readStudents[i].marks);
    }

    return 0;
}