#include <stdio.h>
#include <stdlib.h>

// Function to write a sentence to "data.txt"
void writeSentence() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char sentence[101];
    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);
    
    fprintf(file, "%s", sentence);
    fclose(file);
    printf("Sentence written to data.txt\n");
}

// Function to read the content from "data.txt"
void readContent() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ch;
    printf("Content of data.txt:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

// Function to append a sentence to "data.txt"
void appendSentence() {
    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    char sentence[101];
    printf("Enter a sentence to append (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);
    
    fprintf(file, "%s", sentence);
    fclose(file);
    printf("Sentence appended to data.txt\n");
}

int main() {
    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Write a sentence to file\n");
        printf("2. Read content from file\n");
        printf("3. Append a sentence to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer after scanf

        switch (choice) {
            case 1:
                writeSentence();
                break;
            case 2:
                readContent();
                break;
            case 3:
                appendSentence();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}