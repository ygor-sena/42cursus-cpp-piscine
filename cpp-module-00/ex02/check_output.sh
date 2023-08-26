#!/bin/bash

./account > my_output.log
diff my_output.log 19920104_091532.log

if [ $? -eq 0 ]; then
    exit 0
else
    exit 1
fi