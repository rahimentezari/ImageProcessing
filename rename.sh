#!/bin/bash   

i=1
find -type f -iname "*.jpg" | while read x; do
    mv "${x}" "$(printf "%05d" ${i}).jpg"
    i=$((i+1))
done
