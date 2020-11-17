#! /usr/bin/env bash
# to run :-
# ./start.bash <contestName>

set -e
set -u

for testdir in "$@"; do
    mkdir -p $testdir
    touch $testdir/A.cpp
    touch $testdir/B.cpp
    touch $testdir/C.cpp
    touch $testdir/D.cpp
    touch $testdir/E.cpp  
done