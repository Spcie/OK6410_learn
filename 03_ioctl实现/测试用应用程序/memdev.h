#ifndef __MEMDEV_H
#define __MEMDEV_H

#ifndef MEMDEV_MAJOR
#define MEMDEV_MAJOR 124
#endif

#ifndef MEMDEV_NR_DEVS
#define MEMDEV_NR_DEVS 2
#endif

#ifndef MEMDEV_SIZE
#define MEMDEV_SIZE 4096
#endif

/*mem设备描述结构体*/
struct mem_dev
{
	char *data;
	unsigned long size;
};

/*定义幻数*/
#define MEMDEV_IOC_MAGIC 'x'

/*定义命令*/
#define MEMDEV_IOCPRINT _IO(MEMDEV_IOC_MAGIC,1)
#define MEMDEV_IOCGETDATA _IOR(MEMDEV_IOC_MAGIC,2,int)
#define MEMDEV_IOCSETDATA _IOW(MEMDEV_IOC_MAGIC,3,int)

#define MEMDEV_IOC_MAXNR 3

#endif /*__MEMDEV_H*/