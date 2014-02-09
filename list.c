#include <linux/module.h>

struct entry {
	struct list_head list;
} first, second;

static int probe(void);

static __init int probe(void)
{

	INIT_LIST_HEAD(&first.list);
	list_add(&second.list, &first.list);
	list_add(&second.list, &first.list);
	list_del(&second.list);
	list_del(&first.list);
	list_del(&first.list);

	return -ENODEV;
}

module_init (probe);

MODULE_DESCRIPTION("Botched linked list");
MODULE_AUTHOR("Lubomir Rintel");
MODULE_LICENSE("GPL");
