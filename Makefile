LINKER = ld

CPARAMS = -std=gnu99 -O2 -Wall -Wextra -nostdlib -fno-builtin #-32 

ASPARAMS = #--32

LDPARAMS = #-melf_i386

sources = $(wildcard src/*.c) $(wildcard src/*.s)

objects = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c)) $(patsubst src/%.s,obj/%.o,$(wildcard src/*.s))
target = patate

all: patate.iso

bin/$(target): src/linker.ld $(objects)
	mkdir -p bin
	$(LINKER) $(LDPARAMS) -T $< -o $@ $(objects) 
	
obj/%.o : src/%.c
	mkdir -p obj
	gcc $(CPARAMS) -o $@ -c $<

obj/%.o: src/%.s 
	mkdir -p obj
	as $(ASPARAMS) -o $@ $<

patate.iso: bin/patate
	mkdir -p iso
	mkdir -p iso/boot
	mkdir -p iso/boot/grub
	cp $< iso/boot
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	#echo 'GRUB_TERMINAL_INPUT="console serial"' >> iso/boot/grub/grub.cfg
	#echo 'GRUB_GFXMODE=text' >> iso/boot/grub/grub.cfg
	#echo 'set pager=1' >> iso/boot/grub/grub.cfg
	#echo 'set deubg=all' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Patate Kernel" {' >> iso/boot/grub/grub.cfg
	echo ' multiboot /boot/patate' >> iso/boot/grub/grub.cfg
	echo ' boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

#launch VM containing the os ( only after having configurated it in virtual box ) 
run: patate.iso
	(killall VirtualBoxVM && sleep 1) || true
	VirtualBoxVM --startvm "patatekernel" &

.PHONY: all clean

clean: 
	rm -f patate.iso
	rm -f bin/$(target)
	rm -f $(objects)
