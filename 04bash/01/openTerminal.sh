#!/bin/bash

# Define the list of directories to choose from
value=$(cat <<EOF
${HOME}/ARMWorkSpace
${HOME}/AVRWorkSpace
${HOME}/BareMetalTools
${HOME}/college
${HOME}/Desktop
${HOME}/Documents
${HOME}/Downloads
${HOME}/EmbeddedLinux
${HOME}/'Graduation Project Material'
${HOME}/'Graduation Projectreferences'
${HOME}/intern
${HOME}/literatureReview
${HOME}/ML
${HOME}/Music
${HOME}/nodejs
${HOME}/Pictures
${HOME}/ProblemSolving
${HOME}/Projects
${HOME}/Public
${HOME}/Qt
${HOME}/QtLearn
${HOME}/scripts
${HOME}/Siemens_5g_diploma
${HOME}/simulation.pdsprj
${HOME}/snap
${HOME}/STM32Cube
${HOME}/SwiftExam
${HOME}/Templates
${HOME}/untitled
${HOME}/Videos
EOF
)

# Use rofi in dmenu mode to select one of the directories
select=$(echo -e "$value" | rofi -dmenu -p "Choose a directory:")

# Check if a selection was made
if [ -n "$select" ]; then
    # Open the selected directory in a terminal
    gnome-terminal --working-directory="$select" &
else
    echo "No selection made."
fi
