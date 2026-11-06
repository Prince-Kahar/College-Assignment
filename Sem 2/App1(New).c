#include <stdlib.h>
#include <stdio.h>

// Global delcaration for file pointer
FILE *fp, *fp1;

struct student
{
    char f_name[50], l_name[50];
    int roll_number;
    float marks[3], total, percentage;
} s;

void input();
void display();
int validate(int r);
void search();
void update();
void delete();
void topper();

int main()
{
    system("clear");
    int choice;
    do
    {

        // Taking Input for Choice

        printf("1. Add Student Record \n2. Display all students \n3. Search Student by roll number");
        printf("\n4. Update marks of student \n5. Delete a student \n6. See Topper \n7. Exit");
        printf("\nEnter the number of choice: ");
        scanf("%d", &choice);

        system("clear");
        switch (choice)
        {
        case 1:
            input();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            update();
            break;

        case 5:
            delete();
            break;

        case 6:
            topper();
            break;
        case 7:
            printf("Exiting....\n");
            break;
        default:
            printf("Invalid Choice");
            system("clear");
            break;
        }

    } while (choice != 7);
}

// Taking input for student Detials
void input()
{
    int n, t = 1, r;
    printf("Enter the number of students you want to enter detail: ");
    scanf("%d", &n);
    system("clear");

    fp = fopen("Student_details.txt", "a");
    for (int i = 0; i < n; i++)
    {
        s.total = 0;
        s.percentage = 0;
        system("clear");
        printf("----- Enter details of student %d -----\n", i + 1);

        printf("Enter First name: ");
        scanf("%s", s.f_name);

        printf("Enter Last name: ");
        scanf("%s", s.l_name);

        getchar();
        if (fp != NULL)
        {
            do
            {
                if (t == 1)
                {
                    fclose(fp);
                }
                printf("Enter Roll No: ");
                scanf("%d", &s.roll_number);
                t = validate(s.roll_number);
                if (t == 0)
                    printf("Duplicate Roll No, Enter new Roll No\n");
            } while (t == 0);
        }
        fp = fopen("Student_details.txt", "a");

        printf("Enter marks of 3 subjects by giving space: ");
        scanf("%f %f %f", &s.marks[0], &s.marks[1], &s.marks[2]);

        s.total = s.marks[0] + s.marks[1] + s.marks[2];
        s.percentage = s.total / 3;
        fprintf(fp, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], s.marks[2], s.total, s.percentage);
    }
    fclose(fp);
    system("clear");
}

// Function to Display the Details of students

void display()
{
    fp = fopen("Student_details.txt", "r");
    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
    {
        printf("Roll No: %d", s.roll_number);
        printf("\nName: %s %s", s.f_name, s.l_name);
        printf("\nSub1: %.2f\nSub2: %.2f\nSub3: %.2f", s.marks[0], s.marks[1], s.marks[2]);
        printf("\nTotal:  %.2f", s.total);
        printf("\nPercentage: %.2f", s.percentage);
        printf("\n\n");
    }
    fclose(fp);
}

// Function to validate roll number

int validate(int r)
{
    struct student t;
    int f = 1;

    fp = fopen("Student_details.txt", "r");

    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &t.roll_number, t.f_name, t.l_name, &t.marks[0], &t.marks[1], &t.marks[2], &t.total, &t.percentage)) != EOF)
    {
        if (r == t.roll_number)
        {
            f = 0;
            fclose(fp);
            return 0;
        }
    }

    if (f)
    {
        fclose(fp);
        return 1;
    }
}

// Function to Search Student Detail by Roll number

void search()
{
    int n, f = 0;
    printf("Enter Roll No: ");
    scanf("%d", &n);
    fp = fopen("Student_details.txt", "r");
    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
    {
        if (n == s.roll_number)
        {
            f = 1;
            printf("Roll No: %d", s.roll_number);
            printf("\nName: %s %s", s.f_name, s.l_name);
            printf("\nSub1: %.2f\nSub2: %.2f\nSub3: %.2f", s.marks[0], s.marks[1], s.marks[2]);
            printf("\nTotal:  %.2f", s.total);
            printf("\nPercentage: %.2f", s.percentage);
            printf("\n\n");
        }
    }
    if (f == 0)
    {
        printf("\n**** No Data Found of Student with roll Number %d ****\n\n", n);
    }
    fclose(fp);
}

// Function to update marks

void update()
{
    system("clear");
    int n, c = 0, m, choice, s_no, s_no1;
    float m1, m2, m3, cm;

    struct student t;
    int f = 1;

    printf("Enter Roll Number: ");
    scanf("%d", &n);

    fp = fopen("Student_details.txt", "r");
    fp1 = fopen("Student_copy_details.txt", "w");

    while (fp, (fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &t.roll_number, t.f_name, t.l_name, &t.marks[0], &t.marks[1], &t.marks[2], &t.total, &t.percentage)) != EOF)
    {
        c++; // Counting , on which index data is there
        m = c;

        if (n == t.roll_number)
        {
            fclose(fp);
            c = 0;
            printf("1. Update marks of 1 subject \n2.Update marks of 2 subject \n3.Update marks of all subjects\n");

            printf("Enter Choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // Case to Update marks of 1 subject
                c = 0;
                printf("Enter the subject number to change marks: ");
                scanf("%d", &s_no);
                printf("\nEnter new marks of sub %d: ", s_no);
                scanf("%f", &cm);

                fp = fopen("Student_details.txt", "r");
                while (fp, (fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
                {
                    c++;
                    if (c == m)
                    {
                        if (s_no == 1) // Condition when to update marks of 1st subject
                        {
                            s.total = cm + s.marks[1] + s.marks[2];
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, cm, s.marks[1], s.marks[2], s.total, s.percentage);
                        }

                        else if (s_no == 2) // Condition when to update marks of 2nd subject
                        {
                            s.total = s.marks[0] + cm + s.marks[2];
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], cm, s.marks[2], s.total, s.percentage);
                        }

                        else // Condition when to update marks of 3rd subject
                        {
                            s.total = s.marks[0] + s.marks[1] + cm;
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], cm, s.total, s.percentage);
                        }
                    }

                    else
                    {
                        fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], s.marks[2], s.total, s.percentage);
                    }
                }
                fclose(fp);

                break;

            case 2: // Switch case to update marks for two subjects
                c = 0;
                printf("Enter the subject number by leaving space: ");
                scanf("%d %d", &s_no, &s_no1);
                printf("\nEnter new marks of sub %d: ", s_no);
                scanf("%f", &m1);
                printf("\nEnter new marks of sub %d: ", s_no1);
                scanf("%f", &m2);

                fp1 = fopen("Student_copy_details.txt", "w");
                fp = fopen("Student_details.txt", "r");
                while (fp, (fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
                {
                    c++;
                    if (c == m)
                    {
                        if (s_no == 1 && s_no1 == 2) // Condition when to update marks of 1st and 2nd subject
                        {
                            s.total = m1 + m2 + s.marks[2];
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, m1, m2, s.marks[2], s.total, s.percentage);
                        }

                        else if (s_no == 1 && s_no1 == 3) // Condition when to update marks of 1st and 3rd subject
                        {
                            s.total = m1 + s.marks[1] + m2;
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, m1, s.marks[1], m2, s.total, s.percentage);
                        }

                        else // Condition when to update marks of 2nd and 3rd subject
                        {
                            s.total = s.marks[0] + m1 + m2;
                            s.percentage = s.total / 3;
                            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], m1, m2, s.total, s.percentage);
                        }
                    }

                    else
                    {
                        fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], s.marks[2], s.total, s.percentage);
                    }
                }
                fclose(fp);

                break;

            case 3:
                c = 0;
                printf("\nEnter new marks of sub 1: ");
                scanf("%f", &m1);
                printf("\nEnter new marks of sub 2: ");
                scanf("%f", &m2);
                printf("\nEnter new marks of sub 3: ");
                scanf("%f", &m3);

                fp1 = fopen("Student_copy_details.txt", "w");
                fp = fopen("Student_details.txt", "r");
                while (fp, (fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
                {
                    c++;
                    if (c == m)
                    {
                        s.total = m1 + m3 + m2;
                        s.percentage = s.total / 3;
                        fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, m1, m2, m3, s.total, s.percentage);
                    }
                    else
                        fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], s.marks[2], s.total, s.percentage);
                }
            default:
                printf("\nInvalid choice\n");
                break;
            }
            rename("Student_copy_details.txt", "Student_details.txt");

            f = 1;
            break;
        }
        else
            f = 0;
    }

    if (f == 0)
    {
        printf("\n**** Roll No %d Does not exist *****\n\n", n);
    }
    fclose(fp1);
}

// Function to delete records

void delete()
{
    int n;
    fp = fopen("Student_details.txt", "r");
    fp1 = fopen("Student_copy_details.txt", "a");
    printf("Enter Roll No to Delete record: ");
    scanf("%d", &n);
    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
    {
        if (s.roll_number != n)
        {

            fprintf(fp1, "Roll No: %d \nName: %s %s\nSub 1: %.2f\nSub 2: %.2f\nSub 3: %.2f\nTotal: %.2f\nPercentage: %.2f\n\n", s.roll_number, s.f_name, s.l_name, s.marks[0], s.marks[1], s.marks[2], s.total, s.percentage);
        }
    }
    fclose(fp1);
    fclose(fp);
    rename("Student_copy_details.txt", "Student_details.txt");
}

// Function to find topper

void topper()
{
    float max=0;
    fp=fopen("Student_details.txt","r");
    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
    {
        if(s.percentage>max)
        max=s.percentage;
    }
    fclose(fp);
        fp = fopen("Student_details.txt", "r");
    while ((fscanf(fp, "Roll No: %d \nName: %s %s\nSub 1: %f\nSub 2: %f\nSub 3: %f\nTotal: %f\nPercentage: %f\n\n", &s.roll_number, s.f_name, s.l_name, &s.marks[0], &s.marks[1], &s.marks[2], &s.total, &s.percentage)) != EOF)
    {
        if(max==s.percentage){
        printf("Roll No: %d", s.roll_number);
        printf("\nName: %s %s", s.f_name, s.l_name);
        printf("\nSub1: %.2f\nSub2: %.2f\nSub3: %.2f", s.marks[0], s.marks[1], s.marks[2]);
        printf("\nTotal:  %.2f", s.total);
        printf("\nPercentage: %.2f", s.percentage);
        printf("\n\n");
        }
    }
    fclose(fp);

}