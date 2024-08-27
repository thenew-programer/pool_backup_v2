#!/bin/sh

find . -type f -name "*.sh" | tr -d '/' | cut -d'.' -f2
