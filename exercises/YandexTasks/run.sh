#!/bin/bash

PROGRAM="./Easy_Growing_list"
MAX_ATTEMPTS=5000000

count=0
found=0

# Проверка существования программы
if [ ! -x "$PROGRAM" ]; then
    echo "Error: $PROGRAM not found or not executable"
    exit 1
fi

while [ $count -lt $MAX_ATTEMPTS ] && [ $found -eq 0 ]; do
    ((count++))

    output=$($PROGRAM 2>&1)

    if echo "$output" | grep -q "YES!"; then
        found=1
        echo ""
        echo "🎉 SUCCESS! 🎉"
        echo "Found 'YES!' on attempt #$count"
        echo "in the list: $output"
        echo "------------------------"
    fi
done

if [ $found -eq 0 ]; then
    echo ""
    echo "❌ Failed to find YES! after $MAX_ATTEMPTS attempts"
fi