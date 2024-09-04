#!/bin/bash

cat /etc/passwd | grep -v "^#" | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | sed -n $FT_LINE1,$(echo $FT_LINE2)p | tr '\n' ', ' | sed 's/,$/./' | tr -d '\n'
