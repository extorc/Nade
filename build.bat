cmake --build c:/dev/Nade/build --config Debug --target Sandbox -j 6 --
pushd .
cd build/Debug
Sandbox
popd