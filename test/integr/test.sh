#!/usr/bin/env bash

set -x
# if something will be wrong, exception shell stops
# set -e

path="./tmp/exe/LRU"
output=$($path 1 "test/data/test1.txt")
if [[ $output == "-1" ]]; then
	echo "OK: Integration test 1 passed"
else
	echo "FAIL: Integration test 1 failed"
fi

output=$($path 1 "test/data/test2.txt")
if [[ $output == "-1" ]]; then
	echo "OK: Integration test 2 passed"
else
	echo "FAIL: Integration test 2 failed"
fi
