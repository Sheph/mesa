rm -rf ./build_llvm
mkdir -p ./build_llvm
cd ./build_llvm
../configure --with-gallium-drivers=swrast --with-dri-drivers= --disable-dri3 \
--disable-opengl --disable-egl --disable-dri --enable-gallium-llvm --enable-shared-glapi=no --enable-gallium-tests --prefix=$PWD
make -j4
