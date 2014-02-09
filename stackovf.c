#include <linux/module.h>

static void overflow(int);

static void overflow(int n)
{
	char memory[4];
	memset(memory, 0, n);
}

static __init int probe(void)
{
	overflow(64);
	overflow(64);
	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Causes a stack overflow");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
