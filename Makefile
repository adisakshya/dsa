# Path
BASE = C++

# Default target
.DEFAULT_GOAL := help

# Targets

help :
	@echo "algorithms 	: Run algorithms."

check:
	test -n "$(target)" || (echo "target-type not provided" ; exit 1)

algorithms: check
	+$(MAKE) -C $(BASE)/$@ $(target) file=$(file)