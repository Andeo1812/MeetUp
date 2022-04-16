.PHONY: all tesing build rebuild check test memtest_general clean test_dataclass test_parsing test_database test_handler test_routing coverage_test_dataclass coverage_test_parsing coverage_test_database coverage_test_handler coverage_test_routing memtest_dataclass memtest_parsing memtest_database memtest_handler memtest_routing

all: clean check build

TARGET = HttpServer

IP = 127.0.0.1

PORT = 8080

clean:
	rm -rf build coverage-report valgrind.log test.log coverage.info

check:
	./run_linters.sh

build:
	./run_build.sh

rebuild: clean build

launch:
	./build/project/$(TARGET) $(IP) $(PORT)

test_dataclass:
	./run_build.sh
	${TEST_DATACLASS}

test_parsing:
	./run_build.sh
	${TEST_PARSING}

test_database:
	./run_build.sh
	${TEST_DATABASE}

test_handler:
	./run_build.sh
	${TEST_HANDLER}

test_routing:
	./run_build.sh
	${TEST_ROUTING}

coverage_test_dataclass:
	./run_build.sh
	${TEST_DATACLASS}
	./run_coverage.sh ${GTEST_DATACLASS_COVERAGE} ${TARGET_COVERAGE}

coverage_test_parsing:
	./run_build.sh
	${TEST_PARSING}
	./run_coverage.sh ${GTEST_PARSING_COVERAGE} ${TARGET_COVERAGE}

coverage_test_database:
	./run_build.sh
	${TEST_DATABASE}
	./run_coverage.sh ${GTEST_DATABASE_COVERAGE} ${TARGET_COVERAGE}

coverage_test_handler:
	./run_build.sh
	${TEST_HANDLER}
	./run_coverage.sh ${GTEST_HANDLER_COVERAGE} ${TARGET_COVERAGE}

coverage_test_routing:
	./run_build.sh
	${TEST_ROUTING}
	./run_coverage.sh ${GTEST_ROUTING_COVERAGE} ${TARGET_COVERAGE}

memtest_dataclass:
	./run_build.sh
	./run_memtest.sh ${TEST_DATACLASS}

memtest_parsing:
	./run_build.sh
	${TEST_PARSING}
	./run_memtest.sh ${TEST_PARSING}

memtest_database:
	./run_build.sh
	${TEST_DATABASE}
	./run_memtest.sh ${TEST_DATABASE}

memtest_handler:
	./run_build.sh
	./run_memtest.sh ${TEST_HANDLER}

memtest_routing:
	./run_build.sh
	./run_memtest.sh ${TEST_ROUTING}




