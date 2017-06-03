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
#endif /*__MEMDEV_H*/