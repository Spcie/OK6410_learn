Linux ioctl实现学习
参考OK6410资料
运行环境
Ubuntu 16.04.2 LTS
内核版本:4.4.0

上传日期:2017.6.11
该驱动程序在字符设备模块例程基础上开发，实现ioctl函数功能
由于应用程序需要包含驱动头文件memdev.h。因此直接将memdev.h拷贝到测试应用程序目录下

默认采用124的主设备号

驱动程序实例中编译后得到memdev.ko文件，使用insmod将memdev加载

使用命令:cat /proc/devices可以查看设备号

在/dev下使用命令:mknod memdev c 124 0 创建设备文件

编译提供的测试应用程序并运行即可观察现象
