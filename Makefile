SRC = $(wildcard *.c)
EXE = $(SRC:.c=)
TARGETS := $(addprefix build/,$(EXE))

build: $(TARGETS)

build/%: %.c
	mkdir -p build
	gcc $< -o build/$*

clean:
	rm -rf build/
