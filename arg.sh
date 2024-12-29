#!/bin/bash

# Colors for output
DEF_COLOR='\033[0;39m'

# Text Colors
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

# Bright Text Colors
BRIGHT_BLACK='\033[1;90m'
BRIGHT_RED='\033[1;91m'
BRIGHT_GREEN='\033[1;92m'
BRIGHT_YELLOW='\033[1;93m'
BRIGHT_BLUE='\033[1;94m'
BRIGHT_MAGENTA='\033[1;95m'
BRIGHT_CYAN='\033[1;96m'
BRIGHT_WHITE='\033[1;97m'

# Background Colors
BG_BLACK='\033[40m'
BG_RED='\033[41m'
BG_GREEN='\033[42m'
BG_YELLOW='\033[43m'
BG_BLUE='\033[44m'
BG_MAGENTA='\033[45m'
BG_CYAN='\033[46m'
BG_WHITE='\033[47m'

# Formatting
RESET='\033[0m'
BOLD='\033[1m'
DIM='\033[2m'
ITALIC='\033[3m'
UNDERLINE='\033[4m'
BLINK='\033[5m'
REVERSE='\033[7m'
HIDDEN='\033[8m'

# Path to the push_swap program
FILE=$PWD/push_swap
FILE2=$PWD/psiter

SIZE=100

printf "${YELLOW}Generating a random permutation of numbers from 1 to $SIZE.${DEF_COLOR}\n"
PERMUTATION=$(seq 1 ${SIZE} | shuf | tr '\n' ' ')
echo "${CYAN}$PERMUTATION${DEF_COLOR}"

ARG=$PERMUTATION

# Count number of arguments in ARG
ARG_COUNT=$(echo "$ARG" | wc -w)

printf "${GREEN}Running both QS and ITER with size of $ARG_COUNT.${DEF_COLOR}\n"

# Run push_swap and count lines
./push_swap "$ARG" > outqs.txt
LINE_COUNT_QS=$(wc -l < outqs.txt)

# Run psiter and count lines
./psiter "$ARG" > outiter.txt
LINE_COUNT_ITER=$(wc -l < outiter.txt)

# Define thresholds
if [ "$ARG_COUNT" -le 3 ]; then
	MAX_LINES=3
elif [ "$ARG_COUNT" -le 5 ]; then
	MAX_LINES=12
elif [ "$ARG_COUNT" -le 100 ]; then
  MAX_LINES=700
elif [ "$ARG_COUNT" -le 500 ]; then
  MAX_LINES=5500
else
  MAX_LINES=0  # Default case if thresholds are not defined
fi

# Check QS line count
if [ "$LINE_COUNT_QS" -gt "$MAX_LINES" ]; then
  printf "${RED}QS: Exceeded max moves ($LINE_COUNT_QS / $MAX_LINES).${DEF_COLOR}\n"
else
  printf "${GREEN}QS: OK ($LINE_COUNT_QS / $MAX_LINES).${DEF_COLOR}\n"
fi

# Check ITER line count
if [ "$LINE_COUNT_ITER" -gt "$MAX_LINES" ]; then
  printf "${RED}ITER: Exceeded max moves ($LINE_COUNT_ITER / $MAX_LINES).${DEF_COLOR}\n"
else
  printf "${GREEN}ITER: OK ($LINE_COUNT_ITER / $MAX_LINES).${DEF_COLOR}\n"
fi

printf "${GREEN}Done.${DEF_COLOR}\n"
