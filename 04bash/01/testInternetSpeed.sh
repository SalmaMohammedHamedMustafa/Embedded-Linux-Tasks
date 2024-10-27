#!/bin/bash

# Check if speedtest-cli is installed
if ! command -v speedtest-cli >/dev/null 2>&1; then
    rofi -e "speedtest-cli is not installed. Please install it using your package manager."
    exit 1
fi

# Run the speed test and capture the results
speedtest_result=$(speedtest-cli)

# Prepare the output with a close option
output="Speed Test Results:\n$speedtest_result\n\nPress Enter to close."

# Print the results using rofi
echo -e "$output" | rofi -dmenu -p "Speed Test Results" -no-fixed-size