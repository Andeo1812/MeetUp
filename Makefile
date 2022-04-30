.PHONY: all tesing build rebuild check test memtest_general clean test_dataclass test_parsing test_database test_handler test_routing coverage_test_dataclass coverage_test_parsing coverage_test_database coverage_test_handler coverage_test_routing memtest_dataclass memtest_parsing memtest_database memtest_handler memtest_routing

all: clean check build

TARGET = HttpServer

TEST_CONTEXT =
TEST_PARSING =
TEST_DATABASE =
TEST_HANDLING=
TEST_ROUTING =

clean:
	rm -rf build coverage-report valgrind.log test.log coverage.info

check:
	./run_linters.sh

build:
	./run_build.sh

rebuild: clean build

launch:
	./build/project/$(TARGET) $(IP) $(PORT)

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
	./run_coverage.sh ${GTEST_DATACLASS_COVERAGE} ${TARGET_COVERAGE}

coverage_test_parsing:
	./run_build.sh
	${TEST_PARSING}
	./run_coverage.sh ${GTEST_PARSING_COVERAGE} ${TARGET_COVERAGE}

coverage_test_database:
	./run_build.sh
	${TEST_DATABASE}
	./run_coverage.sh ${GTEST_DATABASE_COVERAGE} ${TARGET_COVERAGE}

coverage_test_handing:
	./run_build.sh
	${TEST_HANDLING}
	./run_coverage.sh ${GTEST_HANDLER_COVERAGE} ${TARGET_COVERAGE}

coverage_test_routing:
	./run_build.sh
	${TEST_ROUTING}
	./run_coverage.sh ${GTEST_ROUTING_COVERAGE} ${TARGET_COVERAGE}

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




