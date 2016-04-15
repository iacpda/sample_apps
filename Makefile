mpu:
	cd mpu_iio && make

mpu_clean:
	cd mpu_iio && make clean

clean: mpu_clean

all: mpu
