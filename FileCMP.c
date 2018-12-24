/* Упражнение 7.3 Напишите программу сравнения двух файлов которая будет
печатать первую строку и позицию сивола где они различаются.

-----------------------------------------------------------------------------------
Project Set programs arguments для передачи параметров программе в Code::Blocks
ВНИМАНИЕ bash вводит utf кодировка программа работает с ACSII которые совпадают только
в латинских буквах*/
#include <stdio.h>
#include <string.h>

void filecmp(FILE *fp1,FILE *fp2 );
char *myfgets(char *s,int n, register FILE *IOP);

void main(int ARGC,char *ARGV[])
{
    FILE *fp1, *fp2;
    char *s;
    if(ARGC <3 ) // нет агрументов вызова
    {
        fprintf(stdout,"filecmp: many arguments");
    }
    else
    {
        if(ARGC>3)
        {
            fprintf(stdout,"filecmp: few arguments");
            exit(0);
        }
        if ((fp1=fopen(*++ARGV,"r")) == NULL)
                {
                    fprintf(stderr,"cat: cant open %s\n",*ARGV);
                    exit (0);
                }
        if ((fp2=fopen(*++ARGV,"r")) == NULL)
                {
                    fprintf(stderr,"cat: cant open %s\n",*ARGV);
                    exit (0);
                }
        filecmp(fp1,fp2);
    }
    getchar();
}
void filecmp(FILE *fp1,FILE *fp2 )
{
    char c1[300];
    char c2[300];
    register char *rc1 = c1;
    register char *rc2 = c2;
    register int i;
    int fl =0;
    while(myfgets(rc1,300,fp1)!=NULL)
    {
        myfgets(rc2,300,fp2);
        for(i=0;*(rc1+i)!='\0';i++)
        {
            if( *(rc1+i) != *(rc2+i))
            {
                fl =1 ;
                goto a;
            }
        }
    }
     a: if(fl==1)
     {
        fprintf(stdout,"nunmber sym %d, string :\n %s",i,c1);
     }

}

char *myfgets(char *s,int n, register FILE *IOP)
{
    register int c;
    register char *cs;
    cs = s;
    while(--n>0 && (c=getc(IOP))!=EOF)
    if((*cs++=c)=='\n') // записываем значение по адресу и сравниваем
        break;
    *cs='\0';
    return((c==EOF && cs==s)? NULL : s ); // возврашает NULL если конец файла
}

