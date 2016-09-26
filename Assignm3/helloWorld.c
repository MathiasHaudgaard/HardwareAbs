#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
static int initWorld(void)
{
 printk(KERN_ALERT "Hello earth!\n");
 return 0;
}
static void exitWorld(void)
{
 printk(KERN_ALERT "Goodbye\n");
}
module_init(initWorld);
module_exit(exitWorld);
