#include <stdio.h>
#include <string.h>

// Global variables declaration (student information)
char choice;
char student_name[8][100] = {
    "Aarav Jung Kc", "Aananta Raj Khanal", "Dirasha Rajbhandari", "Kirtan Malakar",
    "Paruhangma Limbu", "Rubish Krishna Karmacharya", "Sangam Sunar", "Deep Singh Rawal"
};
long long student_phone[8] = {9090909090, 9191919191, 9292929292, 9393939393, 9494949494, 9595959595, 9696969696, 9797979797};
int student_roll[8] = {601, 602, 603, 604, 605, 606, 607, 608};

// Subject grades
int student_eng[8] = {40, 50, 40, 50, 40, 50, 40, 50};
int student_mp[8] = {40, 50, 40, 50, 40, 50, 40, 50};
int student_math[8] = {0, 50, 40, 50, 40, 50, 40, 50};
int student_c[8] = {0, 50, 40, 50, 40, 50, 40, 50};
int student_acc[8] = {40, 50, 40, 50, 40, 50, 40, 50};
double student_gpa;
int total;
double percentage;


// Function 
void marks(int i);

int main() {
    // Declaration
    char input_id[50];
    char input_password[50];
    char password[] = "1234";
    char id[] = "paruhangma";
    int count = 0;
    int input_roll; 
    int i;

    do {
        printf("Welcome to the student Portal \n");
        printf("Input id: \n");
        scanf("%s", input_id);
        printf("Input password: \n");
        scanf("%s", input_password);
        printf("\n");

        if (strcmp(input_id, id) == 0 && strcmp(input_password, password) == 0) {
            printf("Password and Id correct. Welcome !! \n");
            break;
        } else {
            printf("Incorrect id or password. Please try again later.\n");
            count++;
        }
    } while (count < 3);

    if (count == 3) {
        printf("Attempt has been blocked.\n");
        return 0;
    }

    printf("\n");
    printf("Current Record of BCA-2027. \n");
    printf("Student Records:\n");
    
    do{
    printf("Enter Roll no. of the student record to be viewed:\n");

    for (i = 0; i < 8; i++) {
        printf("%d. %d\n", i + 1, student_roll[i]);
    }
    scanf("%d", &input_roll);

    // Display student record on the basis of input_roll
    for (i = 0; i < 8; i++) {
        if (input_roll == student_roll[i]) {
            printf("Student Record of %d \n", input_roll);
            marks(i);
            break;
        }    
    }

    if (i == 8) {
        printf("\n Student with Roll Number %d not found.\n", input_roll);
    }
    
    printf("\n");
    printf("Press y to continue. \n");
    scanf(" %c",&choice);
    }
while(choice == 'y' || choice == 'Y');
    return 0;
}

void marks(int index) {
    printf("Name: %s\n", student_name[index]);
    printf("Phone: %lld\n", student_phone[index]);
    printf("Maths: %d\n", student_math[index]);
    printf("Microprocessor: %d\n", student_mp[index]);
    printf("English: %d\n", student_eng[index]);
    printf("C-Programming: %d\n", student_c[index]);
    printf("Account: %d\n", student_acc[index]);
    printf("\n");

    // Calculate total marks and percentage
    total = student_math[index] + student_mp[index] + student_eng[index] + student_c[index] + student_acc[index];
    percentage = (total / 500.0) * 100;

    printf("Total: %d\n", total);
    printf("Percentage: %.2lf%%\n", percentage);

    // Check for failures and set GPA
    int failed = 0;

    if (student_math[index] < 30) {
        printf("Failed in Mathematics\n");
        failed++;
    }
    if (student_mp[index] < 30) {
        printf("Failed in Microprocessor\n");
        failed++;
    }
    if (student_eng[index] < 30) {
        printf("Failed in English\n");
        failed++;
    }
    if (student_c[index] < 30) {
        printf("Failed in C-Programming\n");
        failed++;
    }
    if (student_acc[index] < 30) {
        printf("Failed in Account\n");
        failed++;
    }
    
    // GPA Calculation
    if (failed) {
        student_gpa = 0.0;
        printf("Total subjects failed: %d\n",failed);

    } else {
        if (percentage >= 90) {
            student_gpa = 4.0;
        } else if (percentage >= 70) {
            student_gpa = 3.0;
        } else if (percentage >= 50) {
            student_gpa = 2.0;
        } else if (percentage >= 40) {
            student_gpa = 1.0;
        } else {
            student_gpa = 0.0;
        }
    }

    printf("GPA: %.2f\n", student_gpa);
    
    if (!failed) {
        printf("Passed all subjects.\n");
    }
}
