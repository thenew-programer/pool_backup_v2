#!/bin/bash

cat /etc/passwd | grep -v "^#" | awk 'NR != 1 {print $0}' | cut -d':' -f1 | rev | sort -r | sed -n $FT_LINE1\,$FT_LINE2'p' | tr '\n' ',' | sed 's/,$/./' | sed 's/,/, /g' | tr -d '\n'
