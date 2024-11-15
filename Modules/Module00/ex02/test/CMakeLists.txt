
#cmake -S . -B build       # Configura o projeto e cria arquivos de construção no #diretório "build"
#cmake --build build       # Compila o projeto
#cd build                  # Entra no diretório de construção
#./convert up "example string"  # Executa o programa com argumentos de exemplo


cmake_minimum_required(VERSION 3.10)
project(StringConverterTestProject)

# Define o padrão de C++
set(CMAKE_CXX_STANDARD 17)

# Adiciona o executável com o nome "convert", buscando os arquivos em src
add_executable(convert_test main_test.cpp ../src/StringConverter.cpp StringConverterTest.cpp)

# Inclui o diretório de cabeçalhos
target_include_directories(convert_test PRIVATE ../include)

enable_testing()
add_test(NAME ConvertTest COMMAND convert_test)