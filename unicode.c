#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
//#include <wchar.h>  // функции для работы с расширенными типами
//#include <wctype.h> // расширеные типы для символов
// си не подрерживает бибилиотеку iostream эта библиотека с++;

//принимает только таблиу asci

int main()
{

    int i;
    printf("Просмотр кодов символов в 16-ричном формате\n");
    printf("Для выхода нажать ctrl+x\n");
    do //UNICODE - для русских символов
    {
    fread(&i,2,1,stdin); // прочитать из входного потока 2 байта
    fwrite(&i,2,1,stdout); // что получли то и выведем
    printf(": %X   ",i);
    }
    while(i!=0x180A);

}
