#include <linux/module.h>

static int probe(void);

static __init int probe(void)
{
	while (1);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("An infinite loop");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
