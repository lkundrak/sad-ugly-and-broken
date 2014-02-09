#include <linux/module.h>
#include <linux/mutex.h>

static int probe(void);

static __init int probe(void)
{
	struct mutex lock;

	mutex_init(&lock);
	mutex_unlock(&lock);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Unlocking an unlocked lock");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
