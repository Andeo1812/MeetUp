.PHONY: all tesing build rebuild check test memtest_general clean test_dataclass test_parsing test_database test_handler test_routing coverage_test_dataclass coverage_test_parsing coverage_test_database coverage_test_handler coverage_test_routing memtest_dataclass memtest_parsing memtest_database memtest_handler memtest_routing

all: check build test_context memtest_context test_parsing memtest_parsing test_database test_handling test_business_logic

TARGET = HttpServer

TEST_CONTEXT = ./build/tests/gtest_context
TEST_PARSING = ./build/tests/gtest_parsing
TEST_DATABASE = ./build/tests/gtest_database
TEST_HANDLING = ./build/tests/gtest_handling
TEST_ROUTING = ./build/tests/gtest_routing
TEST_BUSINESS_LOGIC = ./build/tests/gtest_business_logic

TARGET_COVERAGE = [456789]
COVERAGE_CONTEXT = build/project/context/CMakeFiles/Context.dir/src
COVERAGE_CONTEXT_1 = build/tests/CMakeFiles/gtest_context.dir/unit_tests
COVERAGE_PARSING = build/tests/CMakeFiles/gtest_parsing.dir/unit_tests
COVERAGE_DATABASE = build/tests/CMakeFiles/gtest_database.dir/unit_tests
COVERAGE_HANDLING = build/tests/CMakeFiles/gtest_handling.dir/unit_tests
COVERAGE_ROUTING = build/tests/CMakeFiles/gtest_routing.dir/unit_tests

test_business_logic:
	./run_build.sh
	${TEST_BUSINESS_LOGIC}

test:
	./run_build.sh
	${TEST_CONTEXT}
	${TEST_PARSING}
	${TEST_HANDLING}
	${TEST_DATABASE}
	${TEST_ROUTING}
	${TEST_BUSINESS_LOGIC}

clean:
	rm -rf build coverage-report valgrind.log test.log coverage.info

check:
	./run_linters.sh

build:
	./run_build.sh

rebuild: clean build

test_context:
	./run_build.sh
	${TEST_CONTEXT}

test_parsing:
	./run_build.sh
	${TEST_PARSING}

test_database:
	./run_build.sh
	${TEST_DATABASE}

test_handling:
	./run_build.sh
	${TEST_HANDLING}

test_routing:
	./run_build.sh
	${TEST_ROUTING}

coverage_test_context:
	./run_build.sh
	${TEST_CONTEXT}
	./run_coverage.sh ${COVERAGE_CONTEXT} ${TARGET_COVERAGE}

coverage_test_parsing:
	./run_build.sh
	${TEST_PARSING}
	./run_coverage.sh ${COVERAGE_PARSING} ${TARGET_COVERAGE}

coverage_test_database:
	./run_build.sh
	${TEST_DATABASE}
	./run_coverage.sh ${COVERAGE_DATABASE} ${TARGET_COVERAGE}

coverage_test_handing:
	./run_build.sh
	${TEST_HANDLING}
	./run_coverage.sh ${COVERAGE_HANDLING} ${TARGET_COVERAGE}

coverage_test_routing:
	./run_build.sh
	${TEST_ROUTING}
	./run_coverage.sh ${COVERAGE_ROUTING} ${TARGET_COVERAGE}

memtest_context:
	./run_build.sh
	./run_memtest.sh ${TEST_CONTEXT}

memtest_parsing:
	./run_build.sh
	./run_memtest.sh ${TEST_PARSING}

memtest_database:
	./run_build.sh
	./run_memtest.sh ${TEST_DATABASE}

memtest_handling:
	./run_build.sh
	./run_memtest.sh ${TEST_HANDLING}

memtest_routing:
	./run_build.sh
	./run_memtest.sh ${TEST_ROUTING}




