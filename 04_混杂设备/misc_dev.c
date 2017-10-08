#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <mach/gpio.h>

//定义命令
#define DEV_CMD_1		_IOW('h',0x01,unsigned long)		
#define DEV_CMD_1		_IOW('h',0x02,unsigned long)		

int dev_state = 0;

int dev_open(struct inode *inode,struct file *filp )  
{
	if(dev_state == 0)
	{
		dev_state =  1;
		printk("Open file suc!\n");
		return 0;
	}
	else
	{
		printk("The file has opened!\n");
		return -1;
	}
}

int dev_release(struct inode *inode,struct file *filp )
{
	if(dev_state == 1)
	{
		dev_state =  0;
		printk("close file suc!\n");
		return 0;
	}
	else
	{
		printk("The file has closed!\n");
		return -1;
	}
}

static ssize_t dev_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	int ret =0;
	
	return 0;
}

int dev_ioctl(struct inode *inode,struct file *filp,unsigned int cmd,unsigned long arg)
{
	switch(cmd)
	{
	case DEV_CMD_1: printk("dev cmd 1!\n");
		break;
	case DEV_CMD_2:printk("dev cmd 1\n");
		break;
	default :printk("Error command!\n");
	}
	return 0;
}

const struct file_operations dev_fop =
{
	.owner = THIS_MODULE,
	.open  = led_open,
	.ioctl = led_ioctl,
	.release = led_release,
};

struct miscdevice misc =
{
	.minor = 30,
	.fops = &led_fop,
	.name = "msic_test"
};

static int __init dev_init(void)
{
	int ret;

	printk("----- misc test init-----\n");

	/**
	*  混杂设备主设备号就是10，通过次设备号来区分 
	*/
	ret = misc_register(&misc);					//向内核注册设备号
	if(ret < 0)
	{
		printk("Register Error!\n");
		return ret;
	}

	return 0;
}

static void __exit dev_exit(void)
{
	misc_deregister(&misc);
	open_state = 0;
	printk("test End\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
