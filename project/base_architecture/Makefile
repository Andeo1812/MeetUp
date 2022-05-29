all: run_server


COVERAGE_SERVER = build/tests/CMakeFiles/test_server.dir/unit_tests
# Run Server
run_server:
	./run_build.sh
	./../../build/project/base_architecture/server 127.0.0.1 8000 send

# Run integration tests
integrate_tests:
	./run_build.sh
	./../../build/tests/test_server
