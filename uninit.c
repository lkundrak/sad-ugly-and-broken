#include <linux/module.h>
#include <linux/slab.h>

static int probe(void);

static __init int probe(void)
{
	int *yolo = kmalloc(sizeof(int), GFP_KERNEL);
	printk("Nuf: 0x%08x\n", *yolo);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Read from uninitialized memory");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
