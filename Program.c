#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 10

// ------------------ Structures ------------------
typedef struct {
    char code[10];
    char name[30];
    float marks;
} Course;

typedef struct {
    char id[10];
    char name[30];
    char email[30];
    char phone[15];
    int courseCount;
    Course courses[MAX_COURSES];
} Student;

// ------------------ Globals ------------------
Student students[MAX_STUDENTS];
int studentCount = 0;

// ------------------ Function Declarations ------------------
void AddStudent();
void ShowAllStudents();
void SearchStudent();
void EditStudent();
void DeleteStudent();
void DeleteAllStudents();
void SaveToFile();
void LoadFromFile();
void SortStudentsByID();
void SortStudentsByName();
void ExportToCSV();
float CalculateGPA(Student s);

// ------------------ Main ------------------
int main() {
    int choice;
    LoadFromFile(); // Load saved data on startup

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student (ID/Name/Email)\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Delete All Students\n");
        printf("7. Sort Students by ID\n");
        printf("8. Sort Students by Name\n");
        printf("9. Save Data\n");
        printf("10. Export to CSV\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: AddStudent(); break;
            case 2: ShowAllStudents(); break;
            case 3: SearchStudent(); break;
            case 4: EditStudent(); break;
            case 5: DeleteStudent(); break;
            case 6: DeleteAllStudents(); break;
            case 7: SortStudentsByID(); break;
            case 8: SortStudentsByName(); break;
            case 9: SaveToFile(); break;
            case 10: ExportToCSV(); break;
            case 0: SaveToFile(); printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// ------------------ Functions ------------------
void AddStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }
    Student s;
    printf("Enter ID: "); scanf("%s", s.id);
    printf("Enter Name: "); scanf(" %[^\n]", s.name);
    printf("Enter Email: "); scanf("%s", s.email);
    printf("Enter Phone: "); scanf("%s", s.phone);

    printf("Enter number of courses (max %d): ", MAX_COURSES);
    scanf("%d", &s.courseCount);
    for (int i = 0; i < s.courseCount; i++) {
        printf("Course %d Code: ", i+1); scanf("%s", s.courses[i].code);
        printf("Course %d Name: ", i+1); scanf(" %[^\n]", s.courses[i].name);
        printf("Course %d Marks: ", i+1); scanf("%f", &s.courses[i].marks);
    }
    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

void ShowAllStudents() {
    if (studentCount == 0) {
        printf("No students found!\n");
        return;
    }
    printf("\n%-10s %-20s %-20s %-15s %-10s\n", "ID", "Name", "Email", "Phone", "GPA");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-20s %-20s %-15s %.2f\n",
            students[i].id, students[i].name, students[i].email, students[i].phone, CalculateGPA(students[i]));
    }
}

void SearchStudent() {
    char query[30];
    printf("Enter ID/Name/Email to search: ");
    scanf(" %[^\n]", query);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, query) == 0 ||
            strcasecmp(students[i].name, query) == 0 ||
            strcasecmp(students[i].email, query) == 0) {
            
            printf("\nFound Student:\n");
            printf("ID: %s\nName: %s\nEmail: %s\nPhone: %s\nGPA: %.2f\n",
                students[i].id, students[i].name, students[i].email, students[i].phone, CalculateGPA(students[i]));
            return;
        }
    }
    printf("No student found!\n");
}

void EditStudent() {
    char id[10];
    printf("Enter student ID to edit: ");
    scanf("%s", id);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Editing %s...\n", students[i].name);
            printf("Enter New Name: "); scanf(" %[^\n]", students[i].name);
            printf("Enter New Email: "); scanf("%s", students[i].email);
            printf("Enter New Phone: "); scanf("%s", students[i].phone);
            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void DeleteStudent() {
    char id[10];
    printf("Enter student ID to delete: ");
    scanf("%s", id);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void DeleteAllStudents() {
    studentCount = 0;
    printf("All students deleted!\n");
}

void SaveToFile() {
    FILE *fp = fopen("students.dat", "wb");
    if (!fp) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(&studentCount, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), studentCount, fp);
    fclose(fp);
    printf("Data saved successfully!\n");
}

void LoadFromFile() {
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) return;
    fread(&studentCount, sizeof(int), 1, fp);
    fread(students, sizeof(Student), studentCount, fp);
    fclose(fp);
}

void SortStudentsByID() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (strcmp(students[i].id, students[j].id) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sorted by ID!\n");
}

void SortStudentsByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (strcasecmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sorted by Name!\n");
}

void ExportToCSV() {
    FILE *fp = fopen("students.csv", "w");
    if (!fp) {
        printf("Error exporting file!\n");
        return;
    }
    fprintf(fp, "ID,Name,Email,Phone,GPA\n");
    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%s,%s,%s,%s,%.2f\n",
            students[i].id, students[i].name, students[i].email, students[i].phone, CalculateGPA(students[i]));
    }
    fclose(fp);
    printf("Exported to students.csv successfully!\n");
}

float CalculateGPA(Student s) {
    if (s.courseCount == 0) return 0.0;
    float total = 0;
    for (int i = 0; i < s.courseCount; i++) {
        total += s.courses[i].marks;
    }
    return total / s.courseCount / 25; // Convert marks (0-100) to GPA (0-4)
}
