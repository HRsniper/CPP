#include <iostream>
#include <ctime>
#include <cmath>// para sqrt

using namespace std;

int n_primos(int n){
    int i,j;
    int freq=n-1;
    for (i=2; i<=n; ++i){
        for (j=sqrt(i);j>1; --j){
            if(i%j==0){
                --freq;
                break;
            }
        }
    }
    return freq;
}

int main (){
//---------------------------------------------------
    int primos;
    clock_t t1;// clock_t tipo de retorno para clock
    t1=clock();// tempo de procesamento
    primos=n_primos(90000);
    t1=clock()-t1;

    cout << "qtde primos: " << primos << endl;
    cout << "tempo:" << ((float)t1)/CLOCKS_PER_SEC  << "s" << endl;//coverteu tipo interio para float dividido por segundos
//---------------------------------------------------
    clock_t t2,t3,t4;// clock_t tipo de retorno para clock
    t2=clock();// tempo de procesamento
    primos=n_primos(80000);
    t3=clock();
    t4=difftime(t3,t2);//diferenca entra 2 clocks

    cout << "qtde primos: " << primos << endl;
    cout << "tempo:" << ((float)t4)/CLOCKS_PER_SEC  << "s" << endl;
//---------------------------------------------------
    time_t ti;
    time(&ti);
        cout << ti << " segundos desde 00:00 de 1 jan de 1970" << endl;
//---------------------------------------------------
    //dada padrao
    time_t ti1;
    struct tm* infot;
    time(&ti1);
    infot=localtime(&ti1);//localtime converte time_t para struct tm*
        cout << asctime(infot) << endl;// asctime converte struct tm* em string
    cout << infot->tm_yday << " dia do ano" << endl;//membros de struct tm*
//---------------------------------------------------
    //dada padrao ctime
    time_t ti2;
    time(&ti2);
    cout << ctime(&ti2) << endl;//ctime converte time_t em string nao precis da struct tm*
//---------------------------------------------------
    //dada padrao mudando o formato mes/dia/ano 12h-am/24h-pm
    time_t ti3;
    struct tm* infot1;
        char letra[80];
        char letra1[80];
    time(&ti3);
    infot1=localtime(&ti3);
    strftime(letra,80,"hora: %I:%M:%S pm - %Y",infot1);
        cout << letra << endl;

    strftime(letra1,80,"data: %D - %Y",infot1);
        cout << letra1 << endl;
//===================================================
/*
%a	Abbreviated weekday name *	Thu
%A	Full weekday name *	Thursday
%b	Abbreviated month name *	Aug
%B	Full month name *	August
%c	Date and time representation *	Thu Aug 23 14:55:02 2001
%C	Year divided by 100 and truncated to integer (00-99)	20
%d	Day of the month, zero-padded (01-31)	23
%D	Short MM/DD/YY date, equivalent to %m/%d/%y	08/23/01
%e	Day of the month, space-padded ( 1-31)	23
%F	Short YYYY-MM-DD date, equivalent to %Y-%m-%d	2001-08-23
%g	Week-based year, last two digits (00-99)	01
%G	Week-based year	2001
%h	Abbreviated month name * (same as %b)	Aug
%H	Hour in 24h format (00-23)	14
%I	Hour in 12h format (01-12)	02
%j	Day of the year (001-366)	235
%m	Month as a decimal number (01-12)	08
%M	Minute (00-59)	55
%n	New-line character ('\n')
%p	AM or PM designation	PM
%r	12-hour clock time *	02:55:02 pm
%R	24-hour HH:MM time, equivalent to %H:%M	14:55
%S	Second (00-61)	02
%t	Horizontal-tab character ('\t')
%T	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S	14:55:02
%u	ISO 8601 weekday as number with Monday as 1 (1-7)	4
%U	Week number with the first Sunday as the first day of week one (00-53)	33
%V	ISO 8601 week number (01-53)	34
%w	Weekday as a decimal number with Sunday as 0 (0-6)	4
%W	Week number with the first Monday as the first day of week one (00-53)	34
%x	Date representation *	08/23/01
%X	Time representation *	14:55:02
%y	Year, last two digits (00-99)	01
%Y	Year	2001
%z	ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100)
If timezone cannot be determined, no characters	+100
%Z	Timezone name or abbreviation *
If timezone cannot be determined, no characters	CDT
%%	A % sign	%
*/
//---------------------------------------------------

    system ("pause");
    return 0;
}
