.PHONY: all tesing build rebuild check test memtest_general clean test_dataclass test_parsing test_database test_handler test_routing coverage_test_dataclass coverage_test_parsing coverage_test_database coverage_test_handler coverage_test_routing memtest_dataclass memtest_parsing memtest_database memtest_handler memtest_routing

all: check build test_context memtest_context test_parsing memtest_parsing test_database test_handling test_business_logic test_routing

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

BUILD = ./scripts/run_build.sh
MEMTEST = ./scripts/run_memtest.sh
TEST_COVERAGE = ./scripts/run_coverage.sh

# Run Server
run_server:
	${BUILD}
	./build/project/HttpServer 127.0.0.1 8000 project/base_architecture/send

# Run integration tests
integrate_tests:
	${BUILD}
	./build/tests/gtest_base_architecture

test_business_logic:
	${BUILD}
	${TEST_BUSINESS_LOGIC}

test:
	${BUILD}
	${TEST_CONTEXT}
	${TEST_PARSING}
	${TEST_HANDLING}
	${TEST_DATABASE}
	${TEST_ROUTING}
	${TEST_BUSINESS_LOGIC}

clean:
	rm -rf build coverage-report valgrind.log test.log coverage.info

check:
	./scripts/run_linters.sh

build:
	${BUILD}

rebuild: clean build

test_context:
	${BUILD}
	${TEST_CONTEXT}

test_parsing:
	${BUILD}
	${TEST_PARSING}

test_database:
	${BUILD}
	${TEST_DATABASE}

test_handling:
	${BUILD}
	${TEST_HANDLING}

test_routing:
	${BUILD}
	${TEST_ROUTING}

coverage_test_context:
	${BUILD}
	${TEST_CONTEXT}
	${TEST_COVERAGE} ${COVERAGE_CONTEXT} ${TARGET_COVERAGE}

coverage_test_parsing:
	${BUILD}
	${TEST_PARSING}
	${TEST_COVERAGE} ${COVERAGE_PARSING} ${TARGET_COVERAGE}

coverage_test_database:
	${BUILD}
	${TEST_DATABASE}
	${TEST_COVERAGE} ${COVERAGE_DATABASE} ${TARGET_COVERAGE}

coverage_test_handing:
	${BUILD}
	${TEST_HANDLING}
	${TEST_COVERAGE} ${COVERAGE_HANDLING} ${TARGET_COVERAGE}

coverage_test_routing:
	${BUILD}
	${TEST_ROUTING}
	${TEST_COVERAGE} ${COVERAGE_ROUTING} ${TARGET_COVERAGE}

memtest_context:
	${BUILD}
	${MEMTEST} ${TEST_CONTEXT}

memtest_parsing:
	${BUILD}
	${MEMTEST} ${TEST_PARSING}

memtest_database:
	${BUILD}
	${MEMTEST} ${TEST_DATABASE}

memtest_handling:
	${BUILD}
	${MEMTEST} ${TEST_HANDLING}

memtest_routing:
	${BUILD}
	${MEMTEST} ${TEST_ROUTING}




