#!/usr/bin/env bash

set -x

set -e
set -o pipefail

#./a.out | true

#VAR=`./a.out | true`
# g++ -std=c++20 LRU.cpp -o LRU && ./LRU
if [[ $(exe/LRU | grep "a") == "abc" ]]; then
	echo "OK"
    echo "Integration test is OK"
else
	echo "NOT OK"
	exit 1
fi

if [[ $(echo "abc" | grep -oE "[abq]+") == "abc" ]]; then
	echo "OK"
    echo "Integration test is OK"
else
	echo "NOT OK"
	exit 1
fi


