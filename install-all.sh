#!/bin/bash
sudo apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc
sudo apt-add-repository 'deb https://repos.codelite.org/ubuntu/ bionic universe'
sudo apt update
sudo apt install libsfml-dev \
	g++ cmake \
	libglu-dev \
	libxi-dev \
	freeglut3-dev \
	p7zip-full \
	unzip \
	codelite \
	wxcrafter \
	zlib1g-dev \
	zlib1g \
	libpugixml-dev \
	libpugixml1v5

cd ~
wget https://github.com/edoren/STP/archive/master.zip
unzip master.zip
cd STP-master
mkdir build
cd build
cmake ..
make
sudo make install

cd ~
wget https://github.com/erincatto/Box2D/archive/v2.3.1.zip
unzip v2.3.1.zip
cd Box2D-2.3.1/Box2D/Build
cmake -DBOX2D_VERSION=2.3.1 \
	-DBOX2D_INSTALL=ON \
	-DBOX2D_INSTALL_DOC=ON \
	-DBOX2D_BUILD_SHARED=ON \
	-DBOX2D_BUILD_STATIC=ON \
	-DBOX2D_BUILD_EXAMPLES=OFF \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_VERBOSE_MAKEFILE=ON \
	..
make
make preinstall
sudo cmake -DCMAKE_INSTALL_PREFIX=/usr/local -P cmake_install.cmake