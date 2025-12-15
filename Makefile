CC      := gcc
CFLAGS  := -Wall -Wextra -O0 -g
COVFLAGS:= -fprofile-arcs -ftest-coverage
INCLUDES:= -Isrc -Itest/unity

SRC     := src/calculator.c
TEST_NO_UNITY := test/test_calculator.c
TEST_UNITY    := test/test_calculator_unity.c
UNITY_SRC     := test/unity/unity.c

BIN     := test_calculator

GCOVR_HTML := coverage_gcovr.html
LCOV_INFO  := coverage.info
LCOV_HTML  := coverage_html

build-no-unity:
	$(CC) $(CFLAGS) $(COVFLAGS) \
	$(SRC) $(TEST_NO_UNITY) \
	-o $(BIN)

build-unity:
	$(CC) $(CFLAGS) $(COVFLAGS) \
	$(SRC) $(TEST_UNITY) $(UNITY_SRC) \
	$(INCLUDES) \
	-o $(BIN)

run:
	./$(BIN)

gcovr-line:
	gcovr --filter src/calculator.c --txt-metric line

gcovr-branch:
	gcovr --filter src/calculator.c --txt-metric branch

gcovr-decision:
	gcovr --filter src/calculator.c --txt-metric decision

gcovr-html:
	gcovr -r . \
	--exclude 'test/.*' \
	--html --html-details \
	-o $(GCOVR_HTML)

gcovr-html-open:
	xdg-open coverage_gcovr.html

gcovr-xml:
	gcovr -r . --xml -o coverage.xml

gcovr-json:
	gcovr -r . --json -o coverage.json

lcov-capture:
	lcov --capture --directory . --output-file $(LCOV_INFO)

lcov-list:
	lcov -l $(LCOV_INFO)

lcov-html:
	genhtml $(LCOV_INFO) \
	--branch-coverage \
	-o $(LCOV_HTML)

lcov-html-open:
	xdg-open coverage_html/index.html

lcov:
	lcov --rc lcov_branch_coverage=1 -c -d . -o $(LCOV_INFO)
	genhtml --branch-coverage $(LCOV_INFO) -o $(LCOV_HTML)


clean:
	@echo "Limpando build e cobertura..."
	@rm -f $(BIN)
	@find . -type f \( \
		-name "*.gcda" -o \
		-name "*.gcno" -o \
		-name "*.gcov" -o \
		-name "*.info" \
	\) -delete
	@rm -rf $(LCOV_HTML) $(GCOVR_HTML) coverage.xml coverage.json
	@rm -rf coverage_html
	@echo "Limpeza concluída"
