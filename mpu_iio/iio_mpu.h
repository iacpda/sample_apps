/* IIO MPU functions
 *
 *  Copyright (c) 2016 Israel Cepeda
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include "sysfs_utils.h"

int mpu_get_dev_name(char *devdir, char *devname)
{
	return read_sysfs_string("name", devdir, devname);
}

int mpu_get_dev_power(char *devdir, char *enable)
{
	return read_sysfs_string("power_state", devdir, enable);
}

int mpu_set_dev_power(char *devdir, char *enable)
{
	return write_sysfs_string("power_state", devdir, enable);
}

int mpu_get_dev_buffer_enable(char *devdir, char *enable)
{
	return read_sysfs_string("buffer/enable", devdir, enable);
}

int mpu_set_dev_buffer_enable(char *devdir, char *enable)
{
	return write_sysfs_string("buffer/enable", devdir, enable);
}

int mpu_get_dev_master_enable(char *devdir, char *enable)
{
	return read_sysfs_string("master_enable", devdir, enable);
}

int mpu_set_dev_master_enable(char *devdir, char *enable)
{
	return write_sysfs_string("master_enable", devdir, enable);
}
