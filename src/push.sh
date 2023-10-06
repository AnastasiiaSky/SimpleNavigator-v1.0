#!/bin/bash

cd ..
if [[ $# = 1 ]] 
then 
# cd ..
    dev=$(git status | awk 'NR=='1'{print $3}')
    echo "$dev"
    git add .
    git commit -m "$(date +"%Y.%m.%d_%H:%M")_$1"
    git push origin $dev
    # cat "$(date +"%Y.%m.%d_%H:%M")"
else 
    echo "Введите коммит"
    
fi
