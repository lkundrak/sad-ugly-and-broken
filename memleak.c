#include <linux/module.h>
#include <linux/slab.h>

static void teardown(void);
static int probe(void);

static __exit void teardown(void)
{
}

static __init int probe(void)
{
	void *yolo = kmalloc(2048, GFP_KERNEL);
	if (yolo == NULL)
		return -ENOMEM;

	return 0;
}

module_exit (teardown);
module_init (probe);

MODULE_DESCRIPTION("Leaks memory");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
