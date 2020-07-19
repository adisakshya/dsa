# Compiler
CC = g++

# Compiler Directives
CFLAGS = -W -Wall -pedantic

# Paths
OUTPUT_DIR=outputs

# Default target
.DEFAULT_GOAL := help

# Targets

help :
	@echo "dynamic_programming 	: Run dynamic-programming algorithms."
	@echo "greedy 			: Run greedy algorithms."
	@echo "recursion 		: Run recursion algorithms."
	@echo "sorting 		: Run sorting algorithms."
	@echo "clean       		: Remove all generated output files."

check:
	test -n "$(file)" || (echo "filename not provided" ; exit 1)

.PHONY: dynamic_programming greedy recursion sorting clean

dynamic_programming greedy recursion sorting: check
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(file).o $@/$(file).cpp
	$(OUTPUT_DIR)/$(file).o

clean:
	rm -rf $(OUTPUT_DIR)/*.o