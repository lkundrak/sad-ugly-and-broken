#include <linux/module.h>

int probe(void);

int probe()
{
	printk(KERN_INFO "YOLO World!\n");
	return -ENODEV;
}

module_init (probe);
