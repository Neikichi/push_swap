#!/bin/bash

# Colors for output
DEF_COLOR='\033[0;39m'
RED='\033[1;91m'
GREEN='\033[1;92m'

# Generate all permutations of 5 digits (1 to 5)
permutations=$(perl -e 'use Algorithm::Permute; my $p = Algorithm::Permute->new([1..5]); while (my @res = $p->next) { print join(" ", @res), "\n"; }')

# Initialize a counter
counter=1

# Iterate over each permutation and run push_swap
echo "Testing all permutations of 5 digits:"
while read -r perm; do
    echo "Test $counter: ./push_swap $perm"
    ./push_swap $perm

    # Capture the output and count lines
    output=$(./push_swap $perm)
    output_count=$(echo "$output" | wc -l)

    # Determine pass/fail status
    if [ "$output_count" -gt 12 ]; then
        status="${RED}FAIL${DEF_COLOR}"
    else
        status="${GREEN}PASS${DEF_COLOR}"
    fi

    # Print the result
    echo -e "Output count: $output_count [$status]"

    counter=$((counter + 1))
done <<< "$permutations"


# #!/bin/bash
#
# # Generate all permutations of 5 digits (1 to 5)
# permutations=$(perl -e 'use Algorithm::Permute; my $p = Algorithm::Permute->new([1..5]); while (my @res = $p->next) { print join(" ", @res), "\n"; }')
#
# # Initialize a counter
# counter=1
#
# # Iterate over each permutation and run push_swap
# echo "Testing all permutations of 5 digits:"
# while read -r perm; do
#     echo -n "Test $counter: ./push_swap $perm - " # Print the test number and permutation
#
#     # Capture the output and count lines
#     output=$(./push_swap $perm)
#     output_count=$(echo "$output" | wc -l)
#
#     # Determine pass/fail status
#     if [ "$output_count" -gt 12 ]; then
#         status="FAIL"
#     else
#         status="PASS"
#     fi
#
#     # Print the result
#     echo "Output count: $output_count [$status]"
#
#     counter=$((counter + 1))
# done <<< "$permutations"

