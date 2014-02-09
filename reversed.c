#include <linux/module.h>
#include <linux/mutex.h>

static struct mutex first, second;

static void one(void);
static void two(void);
static int probe(void);

static void one(void)
{
	mutex_lock(&first);
	mutex_lock(&second);
	mutex_unlock(&first);
	mutex_unlock(&second);
}

static void two(void)
{
	mutex_lock(&second);
	mutex_lock(&first);
	mutex_unlock(&first);
	mutex_unlock(&second);
}

static __init int probe(void)
{
	mutex_init(&first);
	mutex_init(&second);

	one();
	two();

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Reversed locking");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
