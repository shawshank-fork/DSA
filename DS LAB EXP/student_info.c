#include <stdio.h>

// Define a structure to store student information
struct Student {
    int rollno;
    char name[50];
    char gender[10];
    int marks;
};

int main() {
    // Create an instance of the structure
    struct Student student;

    // Pointer to the structure
    struct Student *ptr = &student;

    // Input student information
    printf("Enter roll no: ");
    scanf("%d", &ptr->rollno);

    printf("Enter name: ");
    scanf("%s", ptr->name);

    printf("Enter gender: ");
    scanf("%s", ptr->gender);

    printf("Enter marks: ");
    scanf("%d", &ptr->marks);

    // Display student information
    printf("Rollno.-%d\n, Name-%s\n, Gender-%s\n, Marks-%d\n", ptr->rollno, ptr->name, ptr->gender, ptr->marks);

    return 0;
}
