windres -i icon.rc -o icon-out.o

cmake -G "MinGW Makefiles" .

cmake --build .
