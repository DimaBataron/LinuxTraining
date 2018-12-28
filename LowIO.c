/* Упражнение 8-1 Перепишите программу cat из главы 7, используя функции
READ, WRITE, OPEN, CLOSE вместо их эквивалентов из стандартной библиотеки.


Project Set programs arguments для передачи параметров программе в Code::Blocks
ВНИМАНИЕ bash вводит utf кодировка программа работает с ACSII которые совпадают только
в латинских буквах*/
#include <stdio.h>

void main(int ARGC,char *ARGV[])
{
    FILE *fp;
    char *buf[512]; // для ввода байт
    int k=0; // количество фактически считанных симолов
    if(ARGC ==1)
    { // не заданы имена файлов
        fprintf(stdout,"\n Input con. Ctrl+D Exit\n");
        while ((k=fread(buf,1,512,stdin))!=0)  // сюда можно перенаправить поток
        {
            fwrite(buf,1,k,stdout);
        }
    }
    else while(--ARGC>0)
    {
            if ((fp=fopen(*++ARGV,"r"))== NULL)
                    {
                        fprintf(stderr,"cat: cant open %s\n",*ARGV);
                        break;
                    }
            else
            {
                while ((k=fread(buf,1,512,fp))!=0) // здесь при чтении из файла
                {
                    fwrite(buf,1,k,stdout);
                }
                fclose(fp);
            }
    }
}
