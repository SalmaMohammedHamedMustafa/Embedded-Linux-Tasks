#!/bin/bash

choice=$(echo -e "Logout\nReboot\nShutdown" | rofi -dmenu -p "Select an action:")

if [ "$choice" = "Logout" ]; then
    # Logout
    pkill -KILL -u "$USER"
elif [ "$choice" = "Reboot" ]; then
    # Reboot
    sudo reboot
elif [ "$choice" = "Shutdown" ]; then
    # Shutdown
    sudo shutdown -h now
else
    echo "Invalid choice"
fi