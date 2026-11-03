# Shared make rules for a site. Include from <site>/Makefile after defining:
#   PUZ_DIR      puzzle directory relative to the site (recursive `=`)
#   TARGET       CMake target name of the puzzle      (recursive `=`)
#   INPUT_FILES  files created next to the solution by `add`
#   TEMPLATE     file in templates/ used for C++ `add`
#   USAGE        extra help text
ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
LANGUAGE ?= cpp

CMAKE_FLAGS := -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang

ifeq ($(LANGUAGE),rust)
BIN = $(TARGET)_rs
else
BIN = $(TARGET)
endif

.PHONY: all config build add run clean help

help:
	@echo "Usage: make [all|add|run|clean] $(USAGE) [LANGUAGE=cpp|rust]"

all: build

config:
	cmake $(CMAKE_FLAGS) -S . -B build

build: config
	cmake --build build

add:
	@mkdir -p $(PUZ_DIR)
	@cd $(PUZ_DIR) && touch $(INPUT_FILES)
	@if [ "$(LANGUAGE)" = "rust" ]; then \
		cp -n $(ROOT)/templates/solve.rs $(PUZ_DIR)/solve.rs; \
	else \
		cp -n $(ROOT)/templates/$(TEMPLATE) $(PUZ_DIR)/solve.cpp; \
	fi
	@echo "Created $(PUZ_DIR)"

run:
	@test -d $(PUZ_DIR) || { echo "No such puzzle: $(PUZ_DIR)"; exit 1; }
	@test -f build/Makefile || cmake $(CMAKE_FLAGS) -S . -B build >/dev/null
	@cmake --build build --target $(BIN)
	@echo "" && cd $(PUZ_DIR) && $(CURDIR)/bin/$(BIN)

clean:
	rm -rf bin build
