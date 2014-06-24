export FREEDRENO_LIBS="-L$PWD/../install/usr/lib -ldrm -ldrm_freedreno"
export FREEDRENO_CFLAGS="-I$PWD/../install/usr/include -I$PWD/../install/usr/include/libdrm -I$PWD/../install/usr/include/freedreno"
rm -rf ./build_freedreno
mkdir -p ./build_freedreno
cd ./build_freedreno
CC=gcc-4.8 CXX=g++-4.8 ../configure --with-gallium-drivers=freedreno --with-dri-drivers= --disable-dri3 \
--enable-shared-glapi=no --prefix=$PWD
make -j4
