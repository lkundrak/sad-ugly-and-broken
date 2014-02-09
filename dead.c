#include <linux/module.h>
#include <linux/mutex.h>

static int probe(void);

static __init int probe(void)
{
	struct mutex lock;

	mutex_init(&lock);
	mutex_lock(&lock);
	mutex_lock(&lock);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Locking a lock we own");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
