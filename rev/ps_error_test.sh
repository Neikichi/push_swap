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
# USAGE: check_error "arguments" test_id mode
# mode can be "single" or "multi"
check_error() {
    ARG="$1"
    TEST_ID="$2"
    MODE="$3"
    EXPECTED_MESSAGE="Error"

    # Run the command
    if [ "$MODE" = "single" ]; then
        ./push_swap "$ARG" > "$LOG_FILE" 2>&1
    else
        ./push_swap $ARG > "$LOG_FILE" 2>&1
    fi

    # Read the actual output
    ACTUAL_OUTPUT=$(cat "$LOG_FILE")

    # Check the output
    if [ -s "$LOG_FILE" ]; then
        if grep -qx "${EXPECTED_MESSAGE}" "$LOG_FILE"; then
            # It's an error as expected
            printf "${GREEN}Test $TEST_ID: [OK] ARG: '$ARG'${DEF_COLOR}\n"
        else
            # Unexpected output (KO)
            printf "${RED}Test $TEST_ID: [KO] Unexpected output for ARG: '$ARG'${DEF_COLOR}\n"
            printf "Expected: ${GREEN}${EXPECTED_MESSAGE}${DEF_COLOR}\n"
            printf "Actual: ${RED}${ACTUAL_OUTPUT}${DEF_COLOR}\n"
            printf "Debug Information:\n"
            printf "Mode: $MODE\n"
            printf "ARG length: ${#ARG}\n"
            printf "Output (hex):\n"
            hexdump -C "$LOG_FILE"
        fi
    else
        # No output (KO)
        printf "${RED}Test $TEST_ID: [KO] No output for ARG: '$ARG'${DEF_COLOR}\n"
        printf "Expected: ${GREEN}${EXPECTED_MESSAGE}${DEF_COLOR}\n"
        printf "Actual: (No output)\n"
        printf "Debug Information:\n"
        printf "Mode: $MODE\n"
        printf "ARG length: ${#ARG}\n"
        printf "Output (hex):\n"
        hexdump -C "$LOG_FILE"
    fi
}
# Test cases
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
    "42 -2 10 11 0 90 45 500 -200 e" "1 \"2 3\" 4 \"5\""
)

additional_cases=(
    "42 42.0" "-42.5 43" "42+42" "42-" "-+42" "2147483647 2147483647"
    "-2147483648 -2147483648" " " "99999999999999999999" 
    "-99999999999999999999999999" "1e10" "4.2e+1" "00 000 0000" 
    "2147483648" "-2147483649"
)

printf "\n${GREEN}Testing with the whole argument as a single argument:${DEF_COLOR}\n"
for i in "${!test_cases[@]}"; do
    # Test as a single argument
    check_error "${test_cases[$i]}" $((i + 1)) "single"
done

for i in "${!additional_cases[@]}"; do
    check_error "${additional_cases[$i]}" $((i + ${#test_cases[@]} + 1)) "single"
done

printf "\n${GREEN}Testing with the argument split into multiple arguments:${DEF_COLOR}\n"
for i in "${!test_cases[@]}"; do
    # Test as multiple arguments
    check_error "${test_cases[$i]}" $((i + 1)) "multi"
done

for i in "${!additional_cases[@]}"; do
    check_error "${additional_cases[$i]}" $((i + ${#test_cases[@]} + 1)) "multi"
done

printf "\n${GREEN}Error checking script completed.${DEF_COLOR}\n"

