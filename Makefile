all: mpu spi

clean: mpu_clean spi_clean

mpu:
	cd mpu_iio && make

spi:
	cd spi_tools && make

mpu_clean:
	cd mpu_iio && make clean

spi_clean:
	cd spi_tools && make clean
