#include <linux/module.h>
#include <linux/slab.h>

static int probe(void);

static __init int probe(void)
{
	void *yolo = kmalloc(2048, GFP_KERNEL);
	if (yolo == NULL)
		return -ENOMEM;
	kfree(yolo);
	kfree(yolo);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Double free");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
