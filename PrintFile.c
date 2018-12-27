/* Упражнение 7-5. Напишите программу печати набора файлов, которая начинает каждый
новый файл с новой страницы и печатает для каждого файла
заголовок и счетчик текущих страниц

 Допустим на странице 24 строки (стандартный размер терминала GNOME)

Project Set programs arguments для передачи параметров программе в Code::Blocks
ВНИМАНИЕ bash вводит utf кодировка программа работает с ACSII которые совпадают только
в латинских буквах*/
#include <stdio.h>

char *myfgets(char *s,int n, register FILE *IOP);
void PrintFile(char *ARGV,register FILE *fp);
void main(int ARGC,char *ARGV[])
{
    char sear[100];
    int c;
    FILE *fp;

    if(ARGC ==1) // не заданы имена файлов
        fprintf(stdout,"\nFile not specified.\n");
    else while(--ARGC>0)
    {
            if ((fp=fopen(*++ARGV,"r"))== NULL)
                    {
                        fprintf(stderr,"cat: cant open %s\n",*ARGV);
                        break;
                    }
            else
            {
                PrintFile(*ARGV,fp);
                fclose(fp);
            }
    }
}
void PrintFile(char *ARGV,register FILE *fp)
{
    register int k;
    int str=0; // номер страницы
    int c=0; //код нажатой клавиши
    char *s[350];
    for(k=0;k<24;k++) fprintf(stdout,"\n");
    k=0;
    while (myfgets(s,350,fp)!=NULL && c!=0x18) // считывает построчно из файла
        { // 0x18 нажата комбинация Ctrl+x;
            if(k==0) // 24 строки в файле
            {
                k++;
                fprintf(stdout,"\nFile: %s; Page : %d\n ",ARGV,str);
                fprintf(stdout,"Continue :Enter; Ctrl+x: exit\n ");
            }
            fputs(s,stdout); // вывод строки
            k++;
            if(k==23)
            {
                k=0;
                c=fgetc(stdin);
            }
        }
    if(c==0x18) exit(0); // выход из программы
    getc(stdin);
}
char *myfgets(char *s,int n, register FILE *IOP)
{ // функиця читает строки из файла
    register int c;
    register char *cs;
    cs = s;
    while(--n>0 && (c=getc(IOP))!=EOF)
    if((*cs++=c)=='\n') // записываем значение по адресу и сравниваем
        break;
    *cs='\0';
    return((c==EOF && cs==s)? NULL : s ); // возврашает NULL если конец файла
}
