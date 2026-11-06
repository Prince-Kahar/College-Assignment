/*
C APPLICATION PROJECT

🎓 “Student Management System (File + DMA Based)”

⸻

🎯 Objective

Develop a menu-driven application in C that:
	•	Uses Structure
	•	Uses Pointers
	•	Uses Dynamic Memory Allocation
	•	Uses File Handling
	•	Uses User Defined Functions
	•	Covers real-world logic

⸻

📌 Features to Implement

🔹 1. Add Student Record
	•	Input:
	•	Roll No
	•	Name
	•	Marks (3 subjects)
	•	Calculate:
	•	Total
	•	Percentage

⸻

🔹 2. Display All Students
	•	Read data from file
	•	Display in tabular format

⸻

🔹 3. Search Student
	•	Search by:
	•	Roll No
	•	Display full details

⸻

🔹 4. Update Student
	•	Modify marks
	•	Recalculate total & percentage

⸻

🔹 5. Delete Student
	•	Remove record from file

⸻

🔹 6. Display Topper
	•	Student with highest percentage

⸻

🔹 7. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *FileName = ("student.txt");
const char *TempFileName = ("studentCopy.txt");

FILE *fp, *fp1;
typedef struct
{
    char FirstName[50];
    char LastName[50];
} Name;
typedef struct
{
    float Total;
    float Percentage;
} Result;
typedef struct
{
    int roll_no;
    Name name;
    float Marks[3];
    Result result;
} Student;

int CheckRollNo(int roll_no);
void calculate(Student *s);
void input();
void display();
void search();
void update();
void delete();
void DisplayTopper();
void operations();

int main()
{
    operations();
    return 0;
}

int CheckRollNo(int roll_no)
{
    fp = fopen(FileName, "r");
    char line[500];

    while (fgets(line, sizeof(line), fp))
    {

        int i = 0;

        // skip spaces
        while (line[i] == ' ' || line[i] == '\t')
            i++;

        if (line[i] != '\n')
            continue;

        int temp_roll_no = 0;
        i += 2; // skip "| "

        while (line[i] >= '0' && line[i] <= '9')
        {
            temp_roll_no = temp_roll_no * 10 + (line[i] - '0');
            i++;
        }

        if (temp_roll_no == roll_no)
        {
            fclose(fp);
            return 1; // exists
        }
    }

    fclose(fp);
    return 0; // not exists
}

void calculate(Student *s)
{
    s->result.Total = s->Marks[0] + s->Marks[1] + s->Marks[2];
    s->result.Percentage = (s->result.Total / 3.0);
}

void input()
{
    int exists, no_of_students;

    printf("Enter the number of students you want to enter detail: ");
    scanf("%d", &no_of_students);
    Student *s = malloc(no_of_students * sizeof(Student));

    for (int i = 0; i < no_of_students; i++)
    {
        printf("\nEnter Student %d Details:\n", i + 1);
        do
        {
            printf("Enter Roll No: ");

            int result = scanf("%d", &s[i].roll_no);

            if (result != 1)
            {
                printf("Error! Invalid input! Enter number only.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                exists = 1;

                continue;
            }

            exists = CheckRollNo(s[i].roll_no);
            if (exists)
                printf("Roll no already exists! Try again.\n");
        } while (exists);

        printf("Enter First Name: ");
        scanf("%s", s[i].name.FirstName);

        printf("Enter Last Name: ");
        scanf("%s", s[i].name.LastName);
        for (int j = 0; j < 3; j++)
        {
            printf("Enter %d Subject Marks: ", j + 1);
            scanf("%f", &s[i].Marks[j]);
            if (s[i].Marks[j] > 100 || s[i].Marks[j] < 0)
            {
                printf("Error! Invalid Marks. Enter Marks Less Than or Equal 100\n");
                j--;
            }
        }
        calculate(&s[i]);

        fp = fopen(FileName, "a+");

        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            fprintf(fp, "-----------------------------------------------------------------------------------------------------\n");
            fprintf(fp, "| RollNo | First Name     | Last Name      | Subject1  | Subject2  | Subject3  | Total  | Percentage |\n");
            fprintf(fp, "------------------------------------------------------------------------------------------------------\n");
        }
        fprintf(
            fp,
            "| %-6d | %-14s | %-14s | %-9.0f | %-9.0f | %-9.0f | %-6.0f | %-10.2f |\n",
            s[i].roll_no,
            s[i].name.FirstName,
            s[i].name.LastName,
            s[i].Marks[0],
            s[i].Marks[1],
            s[i].Marks[2],
            s[i].result.Total,
            s[i].result.Percentage);

        fclose(fp);
    }

    free(s);
}

void display()
{
    fp = fopen(FileName, "r");

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) <= 0)
    {
        printf("File is empty\n");
        fclose(fp);
        return;
    }
    rewind(fp);

    int ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
}

void search()
{
    int roll_no, found = 0;
    fp = fopen(FileName, "r");
    Student s;

    printf("Enter roll no to search: ");
    scanf("%d", &roll_no);

    while (1)
    {
        int result = fscanf(
            fp,
            "| %d | %s | %s | %f | %f | %f | %f | %f |",
            &s.roll_no,
            s.name.FirstName,
            s.name.LastName,
            &s.Marks[0],
            &s.Marks[1],
            &s.Marks[2],
            &s.result.Total,
            &s.result.Percentage);

        if (result == EOF)
            break;

        if (result != 8)
        {
            fscanf(fp, "%*[^\n]\n"); // skip invalid line
            continue;
        }
        if (s.roll_no == roll_no)
        {
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("| RollNo | First Name     | Last Name      | Subject1  | Subject2  | Subject3  | Total  | Percentage |\n");
            printf("------------------------------------------------------------------------------------------------------\n");
            printf(
                "| %-6d | %-14s | %-14s | %-9.0f | %-9.0f | %-9.0f | %-6.0f | %-10.2f |\n",
                s.roll_no,
                s.name.FirstName,
                s.name.LastName,
                s.Marks[0],
                s.Marks[1],
                s.Marks[2],
                s.result.Total,
                s.result.Percentage);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student details Not Found...\n");
    fclose(fp);
}

void update()
{
    int roll_no, found = 0;
    printf("Enter Roll No to Update: ");
    scanf("%d", &roll_no);
    FILE *fp = fopen(FileName, "r");
    FILE *fp1 = fopen(TempFileName, "w");

    Student s;
    while (fscanf(
               fp,
               "| %d | %s | %s | %f | %f | %f | %f | %f |",
               &s.roll_no,
               s.name.FirstName,
               s.name.LastName,
               &s.Marks[0],
               &s.Marks[1],
               &s.Marks[2],
               &s.result.Total,
               &s.result.Percentage) == 8)
    {
        if (s.roll_no == roll_no)
        {
            found = 1;
            printf("Found...\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("| RollNo | First Name     | Last Name      | Subject1  | Subject2  | Subject3  | Total  | Percentage |\n");
            printf("------------------------------------------------------------------------------------------------------\n");
            printf(
                "| %-6d | %-14s | %-14s | %-9.0f | %-9.0f | %-9.0f | %-6.0f | %-10.2f |\n",
                s.roll_no,
                s.name.FirstName,
                s.name.LastName,
                s.Marks[0],
                s.Marks[1],
                s.Marks[2],
                s.result.Total,
                s.result.Percentage);
            int choice;
            char ch;

            do
            {
                system("clear");
                printf("Which is wish you to update: \n");
                printf("1. Roll No\n");
                printf("2. First Name\n");
                printf("3. Last Name\n");
                printf("4. Subject Marks\n");

                printf("Choose Number Between 1 to 4: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:

                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    printf("Which Subject Student Details Update: \n");
                    printf("A. First Subject\n");
                    printf("B. Second Subject\n");
                    printf("C. Third Subject\n");
                    printf("D. First & Second Subject\n");
                    printf("E. First & Third Subject\n");
                    printf("F. Second & Third Subject\n");
                    printf("G. All Subject\n");
                    printf("H. None Of These\n");

                    printf("Choose one optin between A to H: \n");
                    char char_choice;
                    scanf(" %c", &char_choice);

                    switch (char_choice)
                    {
                    case 'A':
                    case 'a':
                        break;

                    case 'B':
                    case 'b':
                        break;

                    case 'C':
                    case 'c':
                        break;

                    case 'D':
                    case 'd':
                        break;

                    case 'E':
                    case 'e':
                        break;

                    case 'F':
                    case 'f':
                        break;

                    case 'G':
                    case 'g':
                        break;

                    case 'H':
                    case 'h':
                        break;

                    default:
                        printf("Error! You Have Chooce Invalid Character\n");
                    }
                    break;

                default:
                    printf("Error! You Have Chooce Invalid Number\n");
                }

                printf("\nDo You Want To Wish to Update More Details (Y/n): ");
                scanf(" %c", &ch);
            } while (ch == 'y' || ch == 'Y');
        }
        if (!found)
            printf("Student details Not Found...\n");
        fclose(fp);
    }
}

void delete()
{
    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");
    Student s;
    int roll_no, found = 0;

    printf("Enter Roll No to Delete: ");
    scanf("%d", &roll_no);

    while (1)
    {
        int result = fscanf(
            fp,
            "| %d | %s | %s | %f | %f | %f | %f | %f |",
            &s.roll_no,
            s.name.FirstName,
            s.name.LastName,
            &s.Marks[0],
            &s.Marks[1],
            &s.Marks[2],
            &s.result.Total,
            &s.result.Percentage);

        if (result == EOF)
            break;

        if (result != 8)
        {
            char str[500];
            fgets(str, sizeof(str), fp);
            fputs(str, fp1);
            continue; // exit loop after copying remainder
        }

        if (s.roll_no != roll_no)
        {
            fprintf(
                fp1,
                "| %-6d | %-14s | %-14s | %-9.0f | %-9.0f | %-9.0f | %-6.0f | %-10.2f |\n",
                s.roll_no,
                s.name.FirstName,
                s.name.LastName,
                s.Marks[0],
                s.Marks[1],
                s.Marks[2],
                s.result.Total,
                s.result.Percentage);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(fp1);

    remove(FileName);
    rename(TempFileName, FileName);

    if (found)
        printf("Record Deleted Successfully\n");
    else
        printf("Record Not Found\n");
}

void DisplayTopper()
{
    FILE *fp = fopen(FileName, "r");
    Student s, topper;
    float max = -1.00;

    while (1)
    {
        int result = fscanf(
            fp,
            "| %d | %s | %s | %f | %f | %f | %f | %f |",
            &s.roll_no,
            s.name.FirstName,
            s.name.LastName,
            &s.Marks[0],
            &s.Marks[1],
            &s.Marks[2],
            &s.result.Total,
            &s.result.Percentage);

        if (result == EOF)
            break;

        if (result != 8)
        {
            fscanf(fp, "%*[^\n]\n");
            continue;
        }

        if (s.result.Percentage > max)
        {
            max = s.result.Percentage;
            topper = s;
        }
    }

    if (max != -1.0)
        printf("\nTopper: %s %s with %.2f%%\n", topper.name.FirstName, topper.name.LastName, topper.result.Percentage);

    fclose(fp);
}

void operations()
{
    int choice;
    char ch;
    do
    {
        system("clear");
        printf("-----Student Management System-----\n");
        printf("1. Add Stusent Record\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. delete Student\n");
        printf("6. Display Topper\n");
        printf("7. Exit\n");

        printf("Choose Number Between 1 to 7: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear");
            input();
            break;

        case 2:
            system("clear");
            display();
            break;

        case 3:
            system("clear");
            search();
            break;

        case 4:
            system("clear");
            update();
            break;

        case 5:
            system("clear");
            delete();
            break;

        case 6:
            system("clear");
            DisplayTopper();
            break;

        case 7:
            system("clear");
            printf("Exiting...\n");
            exit(0);
        default:
            system("clear");
            printf("Error! You Have Chooce Invalid Number\n");
        }
        printf("\nDo You Want To Contiue (Y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
