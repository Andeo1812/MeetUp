#!/usr/bin/env bash

set -e
./build/tests/test_server

lcov -t build/tests/test_server -o coverage.info -c -d build/project/
genhtml -o build/report/ coverage.info
