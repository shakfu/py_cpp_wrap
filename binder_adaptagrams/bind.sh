NAME=adaptagrams
BINDER=../bin/binder

mkdir -p $NAME

$BINDER \
    --root-module $NAME \
    --prefix $PWD/$NAME \
    --bind dialect \
    --skip std \
    all_includes.hpp \
    -- -std=c++11 \
    -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/12.0.0/include \
    -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 \
    -I/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include \
    -I../include \
    $(python3 -m pybind11 --includes) \
    -DNDEBUG
