cmake_minimum_required(VERSION 3.24)			# требуемая версия CMake

# название проекта my_project и его версия
project(numeric_integration VERSION 1.5)

# настройки компилятора
# set(CMAKE_CXX_COMPILER "g++-12")         		# имя компилятора (можно указать полный путь)
set(CMAKE_C_STANDARD 23)               		# версия стандарта языка
# set(CMAKE_CXX_STANDARD_REQUIRED True)  		# включает проверку: задана ли явно версия стандарта языка
add_compile_options(-O2)                 		# другие опции компиляции: второй уровень оптимизации кода




# папка для сохранения исполняемого файла: bin
# стоит указать, чтобы отделить от служебных файлов генерируемых CMake
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# add_executable -- цель -- создание исполняемого файла
add_executable(                         
  ${PROJECT_NAME}                        # имя файла = имя проекта
  calculus.c
  main.c                                 # Список файлов исходного кода через пробел
)


# Линкуем с математической библиотекой libm
target_link_libraries(${PROJECT_NAME}
    PRIVATE m
)

# cmake -B ./build .
# cmake --build ./build 

