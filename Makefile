LINKER = ld

CPARAMS = -std=gnu99 -O2 -Wall -Wextra

ASPARAMS = --32

LDPARAMS = -melf_i386

sources = $(wildcard src/*.c)

objects = $(sources:src/%.c:obj/%.o)

target = patate

bin/$(target): $(objects)
	$(LINKER) $(objects) $(LDPARAMS) -o $@
	
$(objects): obj/%.o : src/%.c
	gcc $(GPARAMS) -o $@ -c $<

($objects): obj/%.o: src/%.s 
	as $(ASPARAMS) -o $@ $<

all: $(target)

.PHONY: all clean

clean: 
	rm bin/$(target)
	rm obj/$(objects)
