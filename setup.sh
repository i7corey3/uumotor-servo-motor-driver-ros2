#!/bin/bash

case $1 in
    -h)
    printf "This script is used to install any and all dependencies required for this ros2 package\n"
    ;;
    *)
        sudo apt install libserial-dev
    ;;
esac