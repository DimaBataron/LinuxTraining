/* Пример Cтандартная программа cat для конкатенации файлов
Project Set programs arguments для передачи параметров программе в Code::Blocks
ВНИМАНИЕ bash вводит utf кодировка программа работает с ACSII которые совпадают только
в латинских буквах*/
#include <stdio.h>

void filecopy(FILE *fp);

void main(int ARGC,char *ARGV[])
{
    FILE *fp;
    if(ARGC ==1) // нет агрументов вызова
        filecopy(stdin); // копировать стандартный вход.
    else while(--ARGC>0)
    {
            if ((fp=fopen(*++ARGV,"r"))== NULL)
                    {
                        fprintf(stderr,"cat: cant open %s\n",*ARGV);
                        break;
                    }
            else
            {
                filecopy(fp);
                fclose(fp);
            }
    }
}
void filecopy(FILE *fp)
{
    int c;
    while ((c=getc(fp))!=EOF)
    putc(c,stdout); // посимвольный вывод с входного потока в выходной
}
