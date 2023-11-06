#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX_NUMBER_CANDIDATES 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX_NUMBER_CANDIDATES];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void determine_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_NUMBER_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_NUMBER_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    string winner_name = determine_winner();
    printf("%s\n", winner_name);
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
string determine_winner(void)
{
    string winner_name;

    int winner_votes = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner_votes)
        {
            winner_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner_votes)
        {
            winner_name = candidates[i].name
        }
    }
    return winner_name;
}
