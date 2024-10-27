#!/bin/bash

# Define or override the output file for the report
output_file="system_report.txt"
echo "System Report - $(date)" > "$output_file"

# Function to add a section header to the report
add_section() {
    echo -e "\n=== $1 ===" >> "$output_file"
}

# Hostname and User Information
add_section "Hostname and User Information"
echo "Hostname: $(hostname)" >> "$output_file"
echo "Current User: $(whoami)" >> "$output_file"

# System Information
add_section "System Information"
uname -a >> "$output_file"

# CPU Information
add_section "CPU Information"
lscpu >> "$output_file"

# Memory Information
add_section "Memory Information"
free -h >> "$output_file"

# Disk Usage Information
add_section "Disk Usage"
df -h >> "$output_file"

# Notify the user where the report is saved
echo "Report generated: $output_file"