/*
Define a structure called cricket that will describe the following information:
        player name
        team name
        betting average
Using cricket, declare an array player with 50 elements and write a program to read the information about all the 50 players and print a team-wise list containing names of players with their batting average.
*/

#include <stdio.h>
#include <string.h>
#define N 50 

struct cricket
{
    char player_name[30], team_name[30];
    float betting_average;
}player[5]; // Using 5 for testing, change to 50 for final version

int main()
{
    int i, j;
    int printed[5] = {0}; // to track printed teams

    /* Input details */
    for (i = 0; i < 5; i++)
    {
        printf("\nEnter details of player %d\n", i + 1);

        printf("Player name: ");
        scanf("%[^\n]s", player[i].player_name);
        getchar();

        printf("Team name: ");
        scanf("%[^\n]s", player[i].team_name);

        printf("Batting average: ");
        scanf("%f", &player[i].betting_average);
        getchar();
    }

    printf("\nTEAM WISE PLAYER LIST\n");
    for (i = 0; i < 5; i++)
    {
        // Skip, If this player’s team is already printed
        if (printed[i] == 1)
            continue;

        printf("\nTeam: %s\n", player[i].team_name);
        printf("----------------------------\n");
        printf("%-15s %-15s\n", "Player", "Average");

        for (j = 0; j < 5; j++)
            if (strcmp(player[i].team_name, player[j].team_name) == 0)
            {
                printf("%-15s %-15.2f\n", player[j].player_name, player[j].betting_average);
                printed[j] = 1;
            }
    }

    return 0;
}