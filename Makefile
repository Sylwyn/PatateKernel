LINKER = ld

CPARAMS = -std=gnu99 -O2 -Wall -Wextra

ASPARAMS = --32

LDPARAMS = -melf_i386

sources = $(wildcard src/*.c) $(wildcard src/*.s)

objects = $(sources:src/%.c=obj/%.o) $(sources:src/%.s=obj/%.o)

target = patate

bin/$(target): src/linker.ld $(objects)
	echo $(objects)
	$(LINKER) $(LDPARAMS) -T $< -o $@ $(objects)
	
obj/%.o : src/%.c
	gcc $(GPARAMS) -o $@ -c $<

obj/%.o: src/%.s 
	as $(ASPARAMS) -o $@ $<

all: bin/$(target)

.PHONY: all clean

clean: 
	rm -f bin/$(target)
	rm -f obj/$(objects)
