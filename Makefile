obj-m += hello.o
obj-m += null.o
obj-m += bigstack.o
obj-m += stackovf.o
obj-m += memleak.o
obj-m += uafree.o
obj-m += stall.o
obj-m += reversed.o
obj-m += dead.o
obj-m += unlocked.o
obj-m += doublefree.o
obj-m += list.o
obj-m += uninit.o

.PHONY: modules clean
modules clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(PWD) $@
