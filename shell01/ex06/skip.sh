#!/bin/sh

ls -l . | awk 'NR % 2 {print $0}'
