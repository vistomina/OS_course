#!/bin/bash
size ex2 | awk  '{print $1, $2, $3}' > ex1.txt

