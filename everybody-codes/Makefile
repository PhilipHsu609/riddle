YEAR ?= $(shell date +%Y)
QUEST ?= 1

PUZ_DIR = $(YEAR)/Quest$(shell printf "%02d" $(QUEST))
TARGET = ec_$(YEAR)_q$(shell expr $(QUEST) + 0)
INPUT_FILES = part1.txt part2.txt part3.txt
TEMPLATE = quest.cpp
USAGE = [YEAR=XXXX] [QUEST=N]

include ../shared/make/Site.mk
