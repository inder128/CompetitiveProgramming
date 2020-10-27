#! /usr/bin/env bash
# to run :-
# ./start.bash <contestName>

set -e
set -u

for testdir in "$@"; do
    mkdir -p $testdir
    testfile=$testdir/A.cpp
    echo "create file '$testfile'"
    echo "" > $testfile

    testfile=$testdir/B.cpp
    echo "create file '$testfile'"
    echo "" > $testfile

    testfile=$testdir/C.cpp
    echo "create file '$testfile'"
    echo "" > $testfile

    testfile=$testdir/D.cpp
    echo "create file '$testfile'"
    echo "" > $testfile

    testfile=$testdir/E.cpp
    echo "create file '$testfile'"
    echo "" > $testfile
done