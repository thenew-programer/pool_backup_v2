#!/bin/bash

cat /etc/passwd | grep -v "#" | cut -d':' -f1 | rev
