/* Упражнение 7-4. Переделайте программу поиска заданной комбинации символов
из главы 5 таким образом, чтобы в качестве ввода использовался набор именованных файлов
или, если такие фацлы не указаны как аргументы, стандартный ввод.
Следует ли печатать имя файла при нахождении подходящей строки?

Project Set programs arguments для передачи параметров программе в Code::Blocks
ВНИМАНИЕ bash вводит utf кодировка программа работает с ACSII которые совпадают только
в латинских буквах*/
#include <stdio.h>

int search(char *sear);
int searchFILE(char *sear, char *dim);
int filesearch(FILE *fp,char *sear, char *ARGV);
char *myfgets(char *s,int n, register FILE *IOP);
void main(int ARGC,char *ARGV[])
{
    char sear[100];
    int c;
    FILE *fp;
s    fprintf(stdout,"Search poisk <100 characters :\n ");
    fgets(sear,100,stdin); //ввод строки для поиска

    if(ARGC ==1) // не заданы имена файлов
        {// поиск в тандартном вводе
            fprintf(stdout,"\nFile not specified,search stdin.\n");
            if((c=search(sear))==0) printf("Not found");
            else printf("Found, position %d",c);
        }
    else while(--ARGC>1)
    {
            if ((fp=fopen(*++ARGV,"r"))== NULL)
                    {
                        fprintf(stderr,"cat: cant open %s\n",*ARGV);
                        break;
                    }
            else
            {
                filesearch(fp,sear,*ARGV);
                fclose(fp);
            }
    }
    getchar();
}
int search(char *sear)
{ // функция поиска в стандарном вводе
    int sum;
    register int i=0,k=0;
    while((sum=getc(stdin))!=EOF)
    {
        k++;
        if(*(sear+i)==sum)
            {
            do
            {
                i++;
                k++;
                sum=getc(stdin);
            }
            while(*(sear+i)==sum && sum!=EOF);
            if(*(sear+i)=='\0') return k-i; // если такая последовательность найдена
            i=0;
            }
    }
    return 0;
}
int filesearch(FILE *fp,char *sear, char *ARGV)
{ // функция поиска подстроки в файле
    int str =0; // счетчик строк
    char Istr[350];
    while (myfgets(Istr,350,fp)!=NULL) // если прочитали строку
    {
        str++;
        if(searchFILE(sear,Istr)!=0) // ищем подстроку в прочитанной
        {
            fprintf(stdout,"String found, FILE NAME: %s ;str Number: %d",ARGV,str);
        }

    }
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
int searchFILE(char *sear, char *dim)
{
   int sum;
    register int i=0,k=0;
    while((sum = *(dim+k)) !='\0')
    {
        if(*(sear+i)==sum)
            {
            do
            {
                i++;
                k++;
                sum= *(dim+k);
            }
            while(*(sear+i)==sum && sum!='\0');
            if(*(sear+i)=='\n') return i; // если такая последовательность найдена
            i=0;
            }
            k++;
    }
    return 0;
}
