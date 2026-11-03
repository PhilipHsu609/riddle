YEAR ?= $(shell date +%Y)
DAY ?= 1

PUZ_DIR = $(YEAR)/Day$(shell printf "%02d" $(DAY))
TARGET = aoc_$(YEAR)_d$(shell expr $(DAY) + 0)
INPUT_FILES = input.txt example.txt
TEMPLATE = solve.cpp
USAGE = [YEAR=XXXX] [DAY=N]

include ../shared/make/Site.mk
