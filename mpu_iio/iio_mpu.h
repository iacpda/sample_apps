/* IIO MPU functions
 *
 *  Copyright (c) 2016 Israel Cepeda
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include "sysfs_utils.h"

int mpu_get_dev_name(char *basedir, char *devname)
{
	return read_sysfs_string("name", basedir, devname);
}
