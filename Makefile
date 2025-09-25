LINKER = ld

CPARAMS = -m32 -std=gnu99 -O2 -Wall -Wextra 

ASPARAMS = --32

LDPARAMS = -melf_i386

sources = $(wildcard src/*.c) $(wildcard src/*.s)

objects = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c)) $(patsubst src/%.s,obj/%.o,$(wildcard src/*.s))
target = patate

bin/$(target): src/linker.ld $(objects)
	mkdir -p bin
	$(LINKER) $(LDPARAMS) -T $< -o $@ $(objects) 
	
obj/%.o : src/%.c
	gcc $(CPARAMS) -o $@ -c $<

obj/%.o: src/%.s 
	as $(ASPARAMS) -o $@ $<

all: bin/$(target)

.PHONY: all clean

clean: 
	rm -f bin/$(target)
	rm -f $(objects)
