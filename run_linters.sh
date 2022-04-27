#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}

main="project/main.cpp"

Context_hpp="project/context/include/*"
Context_cpp="project/context/src/*"
Context_path_hpp="project/context/include/"

Database_hpp="project/database/PostgreSQL/include/* project/database/include/virtual/*  project/database/include/impl/*"
Database_cpp="project/database/PostgreSQL/src/*"
Database_path_hpp="project/database/"

Sum_hpp="${Context_hpp} ${Database_hpp}"
Sum_cpp="${Context_cpp} ${Database_cpp} ${main}"
Sum_path_hpp="${Context_path_hpp} ${Database_path_hpp}"

print_header "RUN cppcheck"
check_log "cppcheck project --enable=all --inconclusive --error-exitcode=1 -I project --suppress=missingIncludeSystem" "\(information\)"

print_header "RUN clang-tidy"
check_log "clang-tidy ${Sum_cpp} ${Sum_hpp} -warnings-as-errors=*  -- -x c++ --std=c++20 -I ${Sum_path_hpp}" "Error (?:reading|while processing)"

print_header "RUN cpplint"
check_log "cpplint --extensions=cpp project/general/include/* project/pattern/imperative_model/include/* project/general/src/* project/pattern/imperative_model/src/*" "Can't open for reading"

print_header "SUCCESS"
