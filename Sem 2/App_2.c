/*
💻 APP 2:

🏦 Bank Account Management System

⸻

🎯 Objective

Create a menu-driven banking system using:
	•	Structure
	•	File handling
	•	Functions
	•	Pointers
	•	Dynamic memory

⸻

📌 Features

🔹 1. Create Account
	•	Account No
	•	Name
	•	Initial Balance

🔹 2. Deposit Money
	•	Add amount to balance

🔹 3. Withdraw Money
	•	Check minimum balance condition

🔹 4. Display Account Details

🔹 5. Search Account

🔹 6. Delete Account

🔹 7. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float initial_balance = 2000.00f;

const char *FileName = ("bank.txt");
const char *TempFileName = ("bankCopy.txt");

FILE *fp, *fp1;

typedef struct
{
    char FirstName[50];
    char LastName[50];
} Name;
typedef struct
{
    long long int Account_no;
    Name name;
    float balance;
} Account;

int CheckAccountNo(long long int acc_no);
int AccountExistsInFile(long long int acc_no);
int CaseInsensitiveCompare(char str1[], char str2[]);

void input();
void deposit();
void withdraw();
void display();
void search();
void delete();
void check_balance();
void update_account();
void transfer_money();
void operations();

int main()
{
    operations();
    return 0;
}

int CheckAccountNo(long long int acc_no)
{
    if (acc_no >= 100000000LL && acc_no <= 999999999999999999LL)
        return 0;

    return 1;
}

int AccountExistsInFile(long long int acc_no)
{
    Account ac;

    char line[1000];

    fp = fopen(FileName, "r");
    if (fp == NULL)
        return 0;

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            fclose(fp);
            return 0;
        }
    }
    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == acc_no)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int CaseInsensitiveCompare(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        char c1 = str1[i];
        char c2 = str2[i];

        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 + 32;

        if (c2 >= 'A' && c2 <= 'Z')
            c2 = c2 + 32;

        if (c1 != c2)
            return 0;

        i++;
    }

    return str1[i] == '\0' && str2[i] == '\0';
}

void input()
{
    char line[1000];
    int exists, no_of_accounts;

    printf("+----------------------------------------------------------+\n");
    printf("|                ADD ACCOUNT HOLDER NUMBER                 |\n");
    printf("+----------------------------------------------------------+\n");
    printf("Enter the number of account you want to create detail: ");
    scanf("%d", &no_of_accounts);

    if (no_of_accounts <= 0)
    {
        printf("Invalid number of accounts.\n");
        return;
    }

    Account *ac = malloc(no_of_accounts * sizeof(Account));

    printf("\n+----------------------------------------------------------+\n");
    printf("|                   ENTER ACCOUNT DETAILS                    |\n");
    printf("+------------------------------------------------------------+\n");

    for (int i = 0; i < no_of_accounts; i++)
    {
        printf("Account No: %d\n", i + 1);

        do
        {
            int duplicate = 0;

            printf("Enter Account No: ");
            if (scanf("%lld", &ac[i].Account_no) != 1)
            {
                printf("Invalid input. Please enter a numeric account number.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                exists = 1;
                continue;
            }

            exists = CheckAccountNo(ac[i].Account_no);

            if (exists == 1)
            {
                printf("Invalid account number. Enter a number with 9 to 18 Digits.\n");
                continue;
            }

            for (int k = 0; k < i; k++)
            {
                if (ac[k].Account_no == ac[i].Account_no)
                {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate && AccountExistsInFile(ac[i].Account_no))
                duplicate = 1;

            if (duplicate)
            {
                exists = 1;
                printf("Account Number already exists! Try again.\n");
            }
            else
            {
                exists = 0;
            }

        } while (exists);

        printf("Enter First Name: ");
        scanf("%49s", ac[i].name.FirstName);

        printf("Enter Last Name: ");
        scanf("%49s", ac[i].name.LastName);

        while (1)
        {
            printf("Enter Opening Balance ( minimum 2000 ): ");
            if (scanf("%f", &ac[i].balance) != 1)
            {
                printf("Invalid input. Please enter a numeric balance.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue;
            }

            if (ac[i].balance < initial_balance)
            {
                printf("Invalid balance. Opening balance must be at least 2000.\n");
                continue;
            }

            break;
        }

        printf("\n");
    }

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    int data = 0, line_no = 0;
    if (fp != NULL)
    {
        while (fgets(line, sizeof(line), fp))
        {
            line_no++;
            data = 1;

            if (line_no <= 3)
            {
                fputs(line, fp1);
                continue;
            }

            if (strcmp(line, "-------------------------------------------------------------------------------------------------\n") == 0)
                continue;

            if (line[0] == '\n')
                continue;

            fputs(line, fp1);
        }
        fclose(fp);
    }
    if (!data)
    {
        fprintf(fp1, "-------------------------------------------------------------------------------------------------\n");
        fprintf(fp1, "| Account No            | First Name            | Last Name             | Balance               |\n");
        fprintf(fp1, "-------------------------------------------------------------------------------------------------\n");
    }
    for (int i = 0; i < no_of_accounts; i++)
    {
        fprintf(
            fp1,
            "| %-21lld | %-21s | %-21s | %-21.2f |\n",
            ac[i].Account_no,
            ac[i].name.FirstName,
            ac[i].name.LastName,
            ac[i].balance);
    }
    fprintf(fp1, "-------------------------------------------------------------------------------------------------\n");
    fclose(fp1);

    remove(FileName);

    if (rename(TempFileName, FileName) != 0)
    {
        printf("File to create account.\n");
        free(ac);
        return;
    }

    printf("Account record added successfully.\n");
    free(ac);
}

void deposit()
{
    long long int ac_no;
    float amount_deposit, current_balance;
    int found = 0;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");

    printf("Enter Account Number: ");
    if (scanf("%lld", &ac_no) != 1)
    {
        printf("Invalid account number.\n");
        fclose(fp);
        return;
    }

    if (CheckAccountNo(ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        return;
    }

    if (AccountExistsInFile(ac_no))
        found = 1;

    if (found)
    {
        printf("Account Number already exists! Try again.\n");
    }
    else
    {
        printf("Account Number not exists! Try again.\n");
        return;
    }

    do
    {
        printf("Enter Amount To Deposit: ");
        if (scanf("%f", &amount_deposit) != 1)
        {
            printf("Invalid amount.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            amount_deposit = -1;
        }
        else if (amount_deposit <= 0)
        {
            printf("Amount must be greater than 0.\n");
        }

    } while (amount_deposit <= 0);

    current_balance = ac.balance + amount_deposit;

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) != NULL)
            fputs(line, fp1);
    }

    while (fscanf(
               fp,
               "| %lld | %49s | %49s | %f |\n",
               &ac.Account_no,
               ac.name.FirstName,
               ac.name.LastName,
               &ac.balance) == 4)
    {
        if (ac.Account_no == ac_no)
        {
            ac.balance += amount_deposit;
        }

        fprintf(fp1,
                "| %-21lld | %-21s | %-21s | %-21.2f |\n",
                ac.Account_no,
                ac.name.FirstName,
                ac.name.LastName,
                ac.balance);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        fputs(line, fp1);

    fclose(fp);
    fclose(fp1);

    if (remove(FileName) != 0 || rename(TempFileName, FileName) != 0)
    {
        printf("Failed to update file.\n");
        return;
    }

    printf("Amount deposited successfully.\n");

    printf("Current Balance: %.2f\n", current_balance);
}

void withdraw()
{
    long long int ac_no;
    float amount_withdraw, remaining_balance;
    int found = 0, exists;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");

    printf("Enter Account Number: ");
    if (scanf("%lld", &ac_no) != 1)
    {
        printf("Invalid account number.\n");
        fclose(fp);
        return;
    }

    if (CheckAccountNo(ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        return;
    }

    if (AccountExistsInFile(ac_no))
        found = 1;

    if (found)
    {
        printf("Account Number already exists! Try again.\n");
    }
    else
    {
        printf("Account Number not exists! Try again.\n");
        return;
    }

    do
    {
        printf("Enter Amount To Withdraw: ");
        if (scanf("%f", &amount_withdraw) != 1)
        {
            printf("Invalid amount.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            amount_withdraw = -1;
        }

        else if (amount_withdraw <= 0)
        {
            printf("Amount must be greater than 0.\n");
        }

    } while (amount_withdraw <= 0);

    remaining_balance = ac.balance - amount_withdraw;

    if (remaining_balance < 2000)
    {
        printf("Insufficient balance. Minimum 2000 balance must remain.\n");
        return;
    }

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) != NULL)
            fputs(line, fp1);
    }

    while (fscanf(
               fp,
               "| %lld | %49s | %49s | %f |\n",
               &ac.Account_no,
               ac.name.FirstName,
               ac.name.LastName,
               &ac.balance) == 4)
    {
        if (ac.Account_no == ac_no)
        {
            ac.balance -= amount_withdraw;
        }

        fprintf(fp1,
                "| %-21lld | %-21s | %-21s | %-21.2f |\n",
                ac.Account_no,
                ac.name.FirstName,
                ac.name.LastName,
                ac.balance);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        fputs(line, fp1);

    fclose(fp);
    fclose(fp1);

    if (remove(FileName) != 0 || rename(TempFileName, FileName) != 0)
    {
        printf("Failed to update file.\n");
        return;
    }

    printf("Amount withdrawn successfully.\n");
    printf("Remaining Balance: %.2f\n", remaining_balance);
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

    printf("+-----------------------------------------------------------------------------------------------+\n");
    printf("|                                  ACCOUNT DETAILS DISPLAY                                      |\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    printf("\nAccount details displayed successfully.\n");

    fclose(fp);
}

void search()
{
    int found = 0, choice, exists;
    char line[1000];
    long long int ac_no;
    char FirstName[50], LastName[50];

    Account ac;

    fp = fopen(FileName, "r");

    printf("+----------------------------------------------------------+\n");
    printf("|                       SEARCH MENU                        |\n");
    printf("+----------------------------------------------------------+\n");
    printf("|  1. Search BY Account Number                             |\n");
    printf("|  2. Search By First Name                                 |\n");
    printf("|  3. Search By Last Name                                  |\n");
    printf("+----------------------------------------------------------+\n");
    printf("|  Choose Number Between 1 to 3:                           |\n");
    printf("+----------------------------------------------------------+\n");

    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice.\n");
        fclose(fp);
        return;
    }

    switch (choice)
    {
    case 1:
        system("clear");
        do
        {
            printf("Enter Account Number To Search: ");
            if (scanf("%lld", &ac_no) != 1)
            {
                printf("Invalid input. Please enter a numeric account number.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                exists = 1;
                continue;
            }

            exists = CheckAccountNo(ac_no);

            if (exists == 1)
            {
                printf("Invalid account number. Enter a number with 9 to 18 Digits.\n");
            }

        } while (exists);
        break;

    case 2:
        system("clear");
        printf("Enter First Name To Search: ");
        scanf("%49s", FirstName);
        break;

    case 3:
        system("clear");
        printf("Enter Last Name To Search: ");
        scanf("%49s", LastName);
        break;

    default:
        printf("Invalid search choice.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            printf("Invalid file format.\n");
            fclose(fp);
            return;
        }
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        switch (choice)
        {
        case 1:
            if (ac.Account_no == ac_no)
            {
                found = 1;

                printf("+-----------------------------------------------------------------------------------------------+\n");
                printf("|                                  ACCOUNT FOUND                                                |\n");
                printf("+-----------------------------------------------------------------------------------------------+\n");
                printf("| Account No            | First Name            | Last Name             | Balance               |\n");
                printf("+-----------------------------------------------------------------------------------------------+\n");
                printf("| %-21lld | %-21s | %-21s | %-21.2f |\n",
                       ac.Account_no,
                       ac.name.FirstName,
                       ac.name.LastName,
                       ac.balance);
                printf("+-----------------------------------------------------------------------------------------------+\n");

                fclose(fp);
                return;
            }
            break;

        case 2:
            if (CaseInsensitiveCompare(ac.name.FirstName, FirstName))
            {
                if (!found)
                {
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                    printf("|                                  ACCOUNT FOUND                                                |\n");
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                    printf("| Account No            | First Name            | Last Name             | Balance               |\n");
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                }

                found = 1;

                printf("| %-21lld | %-21s | %-21s | %-21.2f |\n",
                       ac.Account_no,
                       ac.name.FirstName,
                       ac.name.LastName,
                       ac.balance);
            }
            break;

        case 3:
            if (CaseInsensitiveCompare(ac.name.LastName, LastName))
            {
                if (!found)
                {
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                    printf("|                                  ACCOUNT FOUND                                                |\n");
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                    printf("| Account No            | First Name            | Last Name             | Balance               |\n");
                    printf("+-----------------------------------------------------------------------------------------------+\n");
                }

                found = 1;

                printf("| %-21lld | %-21s | %-21s | %-21.2f |\n",
                       ac.Account_no,
                       ac.name.FirstName,
                       ac.name.LastName,
                       ac.balance);
            }
            break;
        }
    }

    if (found && (choice == 2 || choice == 3))
    {
        printf("+-----------------------------------------------------------------------------------------------+\n");
    }
    else if (!found)
    {
        printf("No matching account found.\n");
    }

    fclose(fp);
}

void delete()
{
    long long int ac_no;
    int found = 0;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    printf("Enter Account Number To Delete: ");
    if (scanf("%lld", &ac_no) != 1)
    {
        printf("Invalid account number.\n");
        fclose(fp);
        fclose(fp1);
        return;
    }

    if (CheckAccountNo(ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        fclose(fp1);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) != NULL)
            fputs(line, fp1);
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == ac_no)
        {
            found = 1;
            continue;
        }

        fprintf(fp1,
                "| %-21lld | %-21s | %-21s | %-21.2f |\n",
                ac.Account_no,
                ac.name.FirstName,
                ac.name.LastName,
                ac.balance);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        fputs(line, fp1);

    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        remove(TempFileName);
        printf("Account number does not exist.\n");
        return;
    }

    if (remove(FileName) != 0 || rename(TempFileName, FileName) != 0)
    {
        printf("Failed to update file.\n");
        return;
    }

    printf("Account deleted successfully.\n");
}

void check_balance()
{
    long long int ac_no;
    int found = 0;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");

    printf("Enter Account Number: ");
    if (scanf("%lld", &ac_no) != 1)
    {
        printf("Invalid account number.\n");
        fclose(fp);
        return;
    }

    if (CheckAccountNo(ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            printf("Invalid file format.\n");
            fclose(fp);
            return;
        }
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == ac_no)
        {
            found = 1;
            printf("Account Number : %lld\n", ac.Account_no);
            printf("Account Holder : %s %s\n", ac.name.FirstName, ac.name.LastName);
            printf("Current Balance: %.2f\n", ac.balance);
            break;
        }
    }

    if (!found)
        printf("Account number does not exist.\n");

    fclose(fp);
}

void update_account()
{
    long long int ac_no;
    int found = 0, choice;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    printf("Enter Account Number to Update: ");
    if (scanf("%lld", &ac_no) != 1)
    {
        printf("Invalid account number.\n");
        fclose(fp);
        fclose(fp1);
        return;
    }

    if (CheckAccountNo(ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        fclose(fp1);
        return;
    }

    system("clear");

    printf("+-----------------------------------------------------------+\n");
    printf("|                What do you want to update?                |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Update First Name                                      |\n");
    printf("| 2. Update Last Name                                       |\n");
    printf("| 3. Update Both Names                                      |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Choose Number 1 or 2 or 3:                               |\n");
    printf("+-----------------------------------------------------------+\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) != NULL)
            fputs(line, fp1);
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == ac_no)
        {
            found = 1;

            switch (choice)
            {
            case 1:
                printf("Enter New First Name: ");
                scanf("%49s", ac.name.FirstName);
                break;

            case 2:
                printf("Enter New Last Name: ");
                scanf("%49s", ac.name.LastName);
                break;

            case 3:
                printf("Enter New First Name: ");
                scanf("%49s", ac.name.FirstName);

                printf("Enter New Last Name: ");
                scanf("%49s", ac.name.LastName);
                break;

            default:
                printf("Invalid update choice.\n");
                fclose(fp);
                fclose(fp1);
                remove(TempFileName);
                return;
            }
        }

        fprintf(fp1,
                "| %-21lld | %-21s | %-21s | %-21.2f |\n",
                ac.Account_no,
                ac.name.FirstName,
                ac.name.LastName,
                ac.balance);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        fputs(line, fp1);

    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        remove(TempFileName);
        printf("Account number does not exist.\n");
        return;
    }

    if (remove(FileName) != 0 || rename(TempFileName, FileName) != 0)
    {
        printf("Failed to update file.\n");
        return;
    }

    printf("Account details updated successfully.\n");
}

void transfer_money()
{
    long long int sender_ac_no, receiver_ac_no;
    float amount, sender_balance = 0;
    int sender_found = 0, receiver_found = 0;
    char line[1000];

    Account ac;

    fp = fopen(FileName, "r");

    printf("Enter Sender Account Number: ");
    if (scanf("%lld", &sender_ac_no) != 1)
    {
        printf("Invalid sender account number.\n");
        fclose(fp);
        return;
    }

    if (CheckAccountNo(sender_ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        return;
    }

    printf("Enter Receiver Account Number: ");
    if (scanf("%lld", &receiver_ac_no) != 1)
    {
        printf("Invalid receiver account number.\n");
        fclose(fp);
        return;
    }

    if (sender_ac_no == receiver_ac_no)
    {
        printf("Sender and receiver account numbers cannot be the same.\n");
        fclose(fp);
        return;
    }

    if (CheckAccountNo(receiver_ac_no) == 1)
    {
        printf("Invalid account number. Enter a number with 9 to 18 digits.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) == NULL)
        {
            printf("Invalid file format.\n");
            fclose(fp);
            return;
        }
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == sender_ac_no)
        {
            sender_found = 1;
            sender_balance = ac.balance;
        }

        if (ac.Account_no == receiver_ac_no)
        {
            receiver_found = 1;
        }
    }

    fclose(fp);

    if (!sender_found)
    {
        printf("Sender account number does not exist.\n");
        return;
    }

    if (!receiver_found)
    {
        printf("Receiver account number does not exist.\n");
        return;
    }

    do
    {
        printf("Enter Amount to Transfer: ");
        if (scanf("%f", &amount) != 1)
        {
            printf("Invalid amount.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            amount = -1;
        }

        else if (amount <= 0)
        {
            printf("Amount must be greater than 0.\n");
        }

    } while (amount <= 0);

    if (sender_balance - amount < 2000)
    {
        printf("Insufficient balance. Minimum 2000 balance must remain.\n");
        return;
    }

    fp = fopen(FileName, "r");
    fp1 = fopen(TempFileName, "w");

    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp) != NULL)
            fputs(line, fp1);
    }

    while (fscanf(fp,
                  "| %lld | %49s | %49s | %f |\n",
                  &ac.Account_no,
                  ac.name.FirstName,
                  ac.name.LastName,
                  &ac.balance) == 4)
    {
        if (ac.Account_no == sender_ac_no)
            ac.balance -= amount;
        else if (ac.Account_no == receiver_ac_no)
            ac.balance += amount;

        fprintf(fp1,
                "| %-21lld | %-21s | %-21s | %-21.2f |\n",
                ac.Account_no,
                ac.name.FirstName,
                ac.name.LastName,
                ac.balance);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        fputs(line, fp1);

    fclose(fp);
    fclose(fp1);

    if (remove(FileName) != 0 || rename(TempFileName, FileName) != 0)
    {
        printf("Failed to update file.\n");
        return;
    }

    printf("Amount transferred successfully.\n");
}

void operations()
{
    int choice;
    char ch;

    do
    {
        system("clear");
        printf("+-----------------------------------------------------------+\n");
        printf("|                  BANK MANAGEMENT SYSTEM                   |\n");
        printf("+-------------------------- MENU ---------------------------+\n");
        printf("|  1. Create Account                                        |\n");
        printf("|  2. Deposit Money                                         |\n");
        printf("|  3. Withdraw Money                                        |\n");
        printf("|  4. Display Account Details                               |\n");
        printf("|  5. Search Account                                        |\n");
        printf("|  6. Delete Account                                        |\n");
        printf("|  7. Check Balance                                         |\n");
        printf("|  8. Update Account Details                                |\n");
        printf("|  9. Transfer Money                                        |\n");
        printf("| 10. Exit                                                  |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("|  Choose Number Between 1 to 7:                            |\n");
        printf("+-----------------------------------------------------------+\n");

        printf("Enter your Choise: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            system("clear");
            input();
            break;

        case 2:
            system("clear");
            deposit();
            break;

        case 3:
            system("clear");
            withdraw();
            break;

        case 4:
            system("clear");
            display();
            break;

        case 5:
            system("clear");
            search();
            break;

        case 6:
            system("clear");
            delete();
            break;

        case 7:
            system("clear");
            check_balance();
            break;

        case 8:
            system("clear");
            update_account();
            break;

        case 9:
            system("clear");
            transfer_money();
            break;

        case 10:
            system("clear");
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
        printf("\nDo You Want To Contiue (Y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
