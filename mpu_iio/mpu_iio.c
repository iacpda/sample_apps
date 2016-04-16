/* MPU IIO Basic app
 *
 *  Copyright (c) 2016 Israel Cepeda
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

#include "iio_mpu.h"

/* Tests */
bool test_accel = false;

/*
 * Main function
 */
int main(int argc, char **argv)
{
	char c, devfs[35], dev_name[10];
	int device = 0, ret = 0;

	while ((c = getopt(argc, argv, "d:a")) != -1) {
		switch (c) {
		case 'd':
			device = atoi(optarg);
			break;
		case 'a':
			test_accel = true;
			break;
		case '?':
		default:
			return -1;
		}
	}

	sprintf(devfs, DEVFS, device);
	printf("INFO: devfs=%s\n", devfs);

	ret = mpu_get_dev_name(devfs, dev_name);
	if (ret) {
		printf("ERROR: Device not found\n");
		return ret;
	}
	printf("INFO: device name=%s\n", dev_name);

	/* Power device */
	ret = mpu_set_dev_power(devfs, "1");
	if (ret) {
		printf("ERROR: Power enable failed\n");
		return ret;
	}
	printf("INFO: Power enabled\n");

	/* Accel */
	if (test_accel) {
		ret = mpu_set_dev_accel_enable(devfs, "1");
		if (ret) {
			printf("ERROR: Accel enable failed\n");
			return ret;
		}
		printf("INFO: Accel enabled\n");
	} else {
		ret = mpu_set_dev_accel_enable(devfs, "0");
		if (ret) {
			printf("ERROR: Accel disable failed\n");
			return ret;
		}
		printf("INFO: Accel disabled\n");
	}

	/* Buffer enable */
	ret = mpu_set_dev_buffer_enable(devfs, "1");
	if (ret) {
		printf("ERROR: Buffer enable failed\n");
		return ret;
	}
	printf("INFO: Buffer enabled\n");

	/* Master enable */
	ret = mpu_set_dev_master_enable(devfs, "1");
	if (ret) {
		printf("ERROR: Master enable failed\n");
		return ret;
	}
	printf("INFO: Master enabled\n");

	printf("INFO: ###################################\n");
	printf("INFO: # Hello, is all can do right now! #\n");
	printf("INFO: ###################################\n");

	/* Master disable */
	ret = mpu_set_dev_master_enable(devfs, "0");
	if (ret) {
		printf("ERROR: Master disable failed\n");
		return ret;
	}
	printf("INFO: Master disabled\n");

	/* Buffer disable */
	ret = mpu_set_dev_buffer_enable(devfs, "0");
	if (ret) {
		printf("ERROR: Buffer disable failed\n");
		return ret;
	}
	printf("INFO: Buffer disabled\n");

	/* Power off device */
	ret = mpu_set_dev_power(devfs, "0");
	if (ret) {
		printf("ERROR: Power disable failed\n");
		return ret;
	}
	printf("INFO: Power disabled\n");

	return ret;
}
