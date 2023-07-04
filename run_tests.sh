#!/bin/bash

if [ "$#" -eq 0 ]; then
    dirs=$(ls -d tests*/ | tr '\n' ',' | sed 's/,$//')
    echo "Directories to Test: ${dirs}"
else
    dirs="$@"
    echo "Directories to Test: ${dirs}"
fi

IFS=',' read -ra test_dirs <<< "$dirs"

declare -A dir_statistics

echo
echo "Running Tests..."
echo "----------------"

for dir in "${test_dirs[@]}"; do
  dir=${dir%/}  # Remove trailing slash from directory name
  if [ ! -d "$dir" ]; then
    echo "Directory '$dir' does not exist."
    continue
  fi

  for file in $(ls $dir/ | grep in | cut -d"." -f1); do
    ./hw5 < $dir/${file}.in > $dir/${file}.lli
done