#include <linux/module.h>

static int probe(void);

static __init int probe(void)
{
	int *pointer = NULL;
	return *pointer;
}

module_init (probe);

MODULE_DESCRIPTION("Triggers a NULL dereference");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
