@rmdir /q /s build
@mkdir build
@pushd build
@cmake -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake ..
@popd