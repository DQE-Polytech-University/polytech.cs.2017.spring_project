SHELL = /bin/sh

PROJECT  := project_name

# ------------------
# External programs
# ------------------
CC  := gcc
RM  := rm -rf
DG  := doxygen

# --------------------
# Directories & Files
# --------------------
D_SRC    := ./src
D_TESTS  := $(D_SRC)/tests
D_DOC    := ./doc
D_UNITY  :=

ENTRY_POINT := $(D_SRC)/main.c

FILES_PROGR_C :=  $(filter-out $(ENTRY_POINT), $(wildcard $(D_SRC)/*.c))
FILES_TESTS_C :=  $(wildcard $(D_TESTS)/*.c) $(D_UNITY)/src/unity.c $(D_UNITY)/extras/fixture/src/unity_fixture.c

PROJECT_WITHOUT_TESTS := $(FILES_PROGR_C) $(ENTRY_POINT)
PROJECT_WITH_TESTS := $(FILES_TESTS_C) $(FILES_PROGR_C)

PROJECT_WITHOUT_TESTS_O  := $(PROJECT_WITHOUT_TESTS:.c=.o)
PROJECT_WITH_TESTS_O  := $(PROJECT_WITH_TESTS:.c=.o)

# ------------
# Flags
# ------------
CFLAGS  := -Wall
CFLAGS  += -std=c99
LFLAGS  :=

INCS := -I $(D_UNITY)/src -I $(D_UNITY)/extras/fixture/src

# ------------
# Targets
# ------------
default: $(PROJECT)

tests: test-$(PROJECT)

check: test-$(PROJECT)
	./test-$(PROJECT)

%.o: %.c
	$(CC) -c -I $(D_SRC) $(INCS) $(CFLAGS) $< -o $@

$(PROJECT): $(PROJECT_WITHOUT_TESTS_O)
	$(CC) -I $(D_SRC) $(LFLAGS) $(PROJECT_WITHOUT_TESTS_O) -o $@

test-$(PROJECT): $(PROJECT_WITH_TESTS_O)
	$(CC) -I $(D_SRC) $(LFLAGS) $(PROJECT_WITH_TESTS_O) -o $@

.phony: doxygen
doxygen:
	$(DG) $(D_DOC)/doxygen.config

.phony: html
html: doxygen

.phony: pdf
pdf: doxygen
	make -C $(D_DOC)/output/latex

.phony:	clean
clean:
	-$(RM) $(PROJECT_WITH_TESTS_O) $(PROJECT) test-$(PROJECT) $(D_DOC)/output
