#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
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
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool ballot_cast = false;
    int n = candidate_count;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // checking if vote and name are same
        {
            ballot_cast = true;
            candidates[i].votes++;
        }
    }
    return ballot_cast; //returning ballot
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int n = candidate_count;

    int max_votes = 0; //declaring max votes

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes > max_votes) // looping through evey candidates vote and assigning it to max votes
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name); //printing winner name;
        }
    }
}