echo "Compilando projeto..."
cmake -S . -B build -G "Ninja" # generate the ninja files so you can call it
cmake --build build # use this to use the generated files or call `cd build && ninja`

echo "Build concluído!"