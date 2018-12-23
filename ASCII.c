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
    // ASCI
        while((i=getchar())!=0x18)
            {
                //printf("%c:",i);
                printf("%X",i);
            }
            return 0;
}
