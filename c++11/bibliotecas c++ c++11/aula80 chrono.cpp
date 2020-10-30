#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;


int main (){
//---------------------------------------------------
    seconds s(60);
    minutes m=duration_cast<minutes>(s);//duration_cast vai converter o segundos em mim ou qual outro tipo
        cout << m.count() << endl;
//---------------------------------------------------
    using chrono::system_clock;
    duration<int,ratio<60*60*24>> umdia(1);

    system_clock::time_point hoje=system_clock::now();//time_point determina um ponto no tempo
    system_clock::time_point amanha=hoje + umdia;
    system_clock::time_point ontem=hoje - umdia;

    time_t t;
    t=system_clock::to_time_t(hoje);
        cout << "hoje: " << ctime(&t) << "\n";//precisa do include ctime para formato padrao

    t=system_clock::to_time_t(amanha);
        cout << "hoje: " << ctime(&t) << "\n";

    t=system_clock::to_time_t(ontem);
        cout << "hoje: " << ctime(&t) << "\n";
//---------------------------------------------------
    //tempo de processamento
    steady_clock::time_point t1= steady_clock::now();
    for (int i = 0; i < 15000; i++){
        cout << "*";
    }
    steady_clock::time_point t2= steady_clock::now();
    //duration<float> tempo= duration_cast<duration<float>>(t2-t1);
    duration<double> tempo= duration_cast<duration<double>>(t2-t1);
        cout << "tempo: " << tempo.count() << " s" << endl;
//---------------------------------------------------
//---------------------------------------------------

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
//===================================================

    system ("pause");
    return 0;
}
