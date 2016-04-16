/* SYSFS Utils functions
 *
 *  Copyright (c) 2016 Israel Cepeda
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IIODEVS "/sys/bus/iio/devices/"
#define DEVFS IIODEVS "iio:device%d"

int read_sysfs_string(char *filename, char *basedir, char *value)
{
	FILE *sysfsfp;
	char *fpath;
	int ret = 0;

	fpath = malloc(strlen(basedir) + strlen(filename) + 2);
	if (!fpath) {
		printf("Failed to allocate memory\n");
		return -ENOMEM;
	}

	sprintf(fpath, "%s/%s", basedir, filename);
	sysfsfp = fopen(fpath, "r");
	if (!sysfsfp) {
		ret = -errno;
		goto err_free;
	}
	fscanf(sysfsfp, "%s", value);
	fclose(sysfsfp);

err_free:
	free(fpath);
	return ret;
}

int write_sysfs_string(char *filename, char *basedir, char *value)
{
	FILE *sysfsfp;
	char *fpath;
	int ret = 0;

	fpath = malloc(strlen(basedir) + strlen(filename) + 2);
	if (!fpath) {
		printf("Failed to allocate memory\n");
		return -ENOMEM;
	}

	sprintf(fpath, "%s/%s", basedir, filename);
	sysfsfp = fopen(fpath, "w");
	if (!sysfsfp) {
		ret = -errno;
		goto err_free;
	}
	fprintf(sysfsfp, "%s", value);
	fclose(sysfsfp);

err_free:
	free(fpath);
	return ret;
}
