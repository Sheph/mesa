rm -rf ./build_llvm
mkdir -p ./build_llvm
cd ./build_llvm
../configure --with-gallium-drivers=swrast --with-dri-drivers=swrast --disable-dri3 \
--enable-gallium-llvm --enable-shared-glapi=no --enable-gallium-tests --prefix=$PWD
make -j4
mkdir -p $PWD/lib/dri
ln -s $PWD/lib/gallium/swrast_dri.so $PWD/lib/dri/swrast_dri.so
