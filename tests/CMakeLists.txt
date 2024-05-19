# Collect all the test source files
file(GLOB TEST_SOURCES "*.cpp")

# Create a test executable
add_executable(tests ${TEST_SOURCES})

# Add the tests
add_test(NAME tests COMMAND tests)
