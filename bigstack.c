#include <linux/module.h>

struct big {
	char payload[1024];
};

static char callme(struct big, int);
static int probe(void);

static char callme(struct big one, int times)
{
	struct big two;
	if (times) {
		return callme(one, --times);
	} else {
		return two.payload[0] = '\0';
	}
}

static __init int probe(void)
{
	struct big one;
	callme(one, 32);
	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Consumes all stack space");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
