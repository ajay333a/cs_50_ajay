import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    data_base = []
    with open(sys.argv[1], "r") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            data_base.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    subsequences = list(data_base[0].keys())[1: ]  # assinging sequences to a list

    results = {}

    for subsequence in subsequences:
        results[subsequence] = longest_match(sequence, subsequence)  # adding the SRT to the dict

    # Check database for matching profiles
    for person in data_base:
        matcho = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == results[subsequence]:  # Checking for matches in database
                matcho += 1

        if matcho == len(subsequences):
            print(person["name"])
            return

    print("No match")



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
