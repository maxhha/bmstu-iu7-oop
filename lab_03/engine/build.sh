clear
mkdir -p build
(cd build; emcmake cmake -DCMAKE_BUILD_TYPE=Debug .. && emmake make -j8)