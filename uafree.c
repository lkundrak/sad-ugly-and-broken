#include <linux/module.h>
#include <linux/slab.h>

static int probe(void);

static __init int probe(void)
{
	void *yolo = kmalloc(2048, GFP_KERNEL);
	if (yolo == NULL)
		return -ENOMEM;
	kfree(yolo);
	memset(yolo, '\0', 2048);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Use memory after free");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
