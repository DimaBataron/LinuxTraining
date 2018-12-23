#Создание динамической бибилиотеки
binary: main.o libworld.so
	gcc -o binary main.o -L .-lworld -Wl,-rpath,.
#Wl,option,optargs,... Расшифровываю: передать линковщику (-Wl) 
#опцию option с аргументами optargs.
# Бибилиотека из текущего каталога -rpath
main.o: main.c
	gcc -c main.c
libworld.so: h_world.o g_world.o #компоненты
	 gcc -shared -o libworld.so h_world.o g_world.o
 #из объектных файлов делаем дин.библ
h_world.o: h_world.c
	gcc -c -fPIC h_world.c #создаем объектный файл
# -fPIC объектные файлы, полученные в результате компиляции должны содержать позиционно-независимый код  
g_world.o: g_world.c
	gcc -c -fPIC g_world.c
clean:
	rm -f *.o *.a binary *.so
