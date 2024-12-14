#!/bin/bash

# Colors for output
DEF_COLOR='\033[0;39m'
RED='\033[1;91m'
GREEN='\033[1;92m'

# Path to the push_swap program
FILE=$PWD/push_swap
LOG_FILE=test_log.txt

# Check if the push_swap program exists
if [ ! -f "$FILE" ]; then
    printf "${RED}ERROR: push_swap program not found at $FILE ${DEF_COLOR}\n"
    exit 1
fi

# Clean up log file after execution
trap "rm -f $LOG_FILE" EXIT

# Function to test error handling
check_error() {
    ARG="$1"
    TEST_ID="$2"
    EXPECTED_MESSAGE="Error"

    # Debug: Print the command being executed and argument length
    printf "Debug: Running command: ./push_swap \"$ARG\"\n"
    printf "Debug: ARG length: ${#ARG}\n"

    # Handle empty string explicitly
    if [ -z "$ARG" ]; then
        ./push_swap "" > "$LOG_FILE" 2>&1
    else
        ./push_swap $ARG > "$LOG_FILE" 2>&1
    fi

    # Read the actual output
    ACTUAL_OUTPUT=$(cat "$LOG_FILE")

    # Debug: Print output as hex
    printf "Output (hex):\n"
    hexdump -C "$LOG_FILE"

    # Check the output
    if [ -s "$LOG_FILE" ]; then
        if grep -qx "${EXPECTED_MESSAGE}" "$LOG_FILE"; then
            printf "${GREEN}Test $TEST_ID: [OK] ${DEF_COLOR}\n"
        else
            printf "${RED}Test $TEST_ID: [KO] Unexpected output. ${DEF_COLOR}\n"
            printf "Expected: ${GREEN}${EXPECTED_MESSAGE}${DEF_COLOR}\n"
            printf "Actual: ${RED}${ACTUAL_OUTPUT}${DEF_COLOR}\n"
        fi
    else
        printf "${RED}Test $TEST_ID: [KO] No output for error. ${DEF_COLOR}\n"
        printf "Expected: ${GREEN}${EXPECTED_MESSAGE}${DEF_COLOR}\n"
        printf "Actual: (No output)\n"
    fi
}

# Original test cases for error checking
test_cases=(
    "a" "111a11" "hello world" "" "0 0" "111-1 2 -3"
    "-3 -2 -2" "\n" "-2147483649" "-2147483650" "2147483648"
    "8 008 12" "10 -1 -2 -3 -4 -5 -6 90 99 10" "1 +1 -1"
    "3333-3333 1 4" "111a111 -4 3" "111111 -4 3 03"
    "2147483649" "2147483647+1" "0 1 2 3 4 5 0" "3 +3"
    "3+3" "42 42" "42 -42 -42 " "4222-4222" "99999999999999999999999999"
    "-99999999999999999999999999" "0 -0 1 -1" "0 +0 1 -1"
    "111+111 -4 3" "-" "+" "--123 1 321" "++123 1 321"
    "0000000000000000000000009 000000000000000000000009" "00000001 1 9 3"
    "00000003 003 9 1" "--21345" "1 01" "-000 -0000"
    "-00042 -000042" "42 a 41" "42 41 40 45 101 x 202 -1 224 3"
    "42 -2 10 11 0 90 45 500 -200 e"
)

# Additional edge cases
additional_cases=(
    "42 42.0" "-42.5 43" "42+42" "42-" "-+42" "2147483647 2147483647"
    "-2147483648 -2147483648" " " "99999999999999999999" 
    "-99999999999999999999999999" "1e10" "4.2e+1" "00 000 0000" 
    "+0001 -0002" "2147483648" "-2147483649"
)

# Run all test cases with the whole argument as a single quoted string
printf "\n${GREEN}Testing with the whole argument as a single quoted string:${DEF_COLOR}\n"
for i in "${!test_cases[@]}"; do
    check_error "\"${test_cases[$i]}\"" $((i + 1))
done

# Run additional cases with the whole argument as a single quoted string
for i in "${!additional_cases[@]}"; do
    check_error "\"${additional_cases[$i]}\"" $((i + ${#test_cases[@]} + 1))
done

# Run all test cases with the argument split into individual values
printf "\n${GREEN}Testing with the argument split into individual values:${DEF_COLOR}\n"
for i in "${!test_cases[@]}"; do
    check_error "${test_cases[$i]}" $((i + 1))
done

# Run additional cases with the argument split into individual values
for i in "${!additional_cases[@]}"; do
    check_error "${additional_cases[$i]}" $((i + ${#test_cases[@]} + 1))
done

printf "\n${GREEN}Error checking script completed.${DEF_COLOR}\n"

