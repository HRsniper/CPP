#include <iostream>
#include <cmath>//math.h

#define PI 3.14159265

double radTOgra(int a){//radianus para graus
    return a*PI/180;
}

using namespace std;

int main(){

    //Sin , Cos , Tan - Seno , Cosseno , Tangente
    int ang=45;

    cout << "Seno de " << ang << "....: " << sin(ang*PI/180) << endl;// (ang*PI/180) converter radianus em graus
    cout << "Cesseno de " << ang << ".: " << cos(ang*PI/180) << endl;
    cout << "Tangente de " << ang << ": " << tan(ang*PI/180) << endl;

cout << endl;

    //asin , acos , atan - Arco do Seno , Arco do Cosseno , Arco da Tangente

    cout << "Arco do Seno de " << ang << "....: " << asin(radTOgra(ang)) << endl;
    cout << "Arco do Cesseno de " << ang << ".: " << acos(radTOgra(ang)) << endl;
    cout << "Arco do Tangente de " << ang << ": " << atan(radTOgra(ang)) << endl;

cout << endl;

    //atan2 - calcula o arco da tangente usndo dois parametros representados de x e y
    double x=-10.0;
    double y=10.0;

    cout << "Arco Tangente de X=-10 e Y=10 : " << atan2(x,y)*180/PI << endl;

cout << endl;

    //exp - funçao exponemcial
    double x2=10;

    cout << "Valor exponencial de " << x2 << ": " << exp(x2) << endl;

cout << endl;

    //log - retorna o logaritmo natural de um numero
    double x3=10;

    cout << "Logaritmo natural de " << x3 << ": " << log(x3) << endl;

cout << endl;

    //pow - calcula a potencia de um numero base elevado a um expoente
    double x4=10;

    cout << "10 elevado a 2: " << pow(x4,2) << endl;

cout << endl;

    //sqrt - calcula a raiz quadrada de um numero
    double x5=9;

    cout << "Rai quadrada de 9: " << sqrt(x5) << endl;

cout << endl;

    //cbrt - calculo a raiz cubica de um numero
    double x6=27;

    cout << "Raiz cubica de 27: " << cbrt(x6) << endl;

cout << endl;

    //hypot - retorna a hipotenusa (lado maior de um triangulo retangulo)
    double cat1=3, cat2=4;

    cout << "Catetos: " << cat1 << " , " << cat2 << " , Hipotenusa: " << hypot(cat1,cat2) << endl;

    //o quadrado da hipotenusa é igual a soma dos quadrados dos catetos
    cout << "Catetos: " << cat1 << " , " << cat2 << " , Hipotenusa: " << sqrt(pow(cat2,2)+pow(cat1,2)) << endl;

cout << endl;

    //ceil - arredonda para cima retornando o numero inteiro mais proximo
    double a=2.2,b=3.8,c=-2.7,d=-1.2;

    cout << a << " = " << ceil(a) << endl;
    cout << b << " = " << ceil(b) << endl;
    cout << c << " = " << ceil(c) << endl;
    cout << d << " = " << ceil(d) << endl;

cout << endl;

    //floor - arredonda para baixo retornando o numero inteiro mais proximo

    cout << a << " = " << ceil(a) << endl;
    cout << b << " = " << ceil(b) << endl;
    cout << c << " = " << ceil(c) << endl;
    cout << d << " = " << ceil(d) << endl;

cout << endl;

    //round - arrendonda para cima ou para baixo , conforme a regra padrao(5.6=5.5 // 5.4=5.0)
    //rint - trabalha quase do mesmo jeito
    double g=5.6,h=5.4;

    cout << g << " = " << round(g) << " // " << h << " = " << round(h) << endl;

    cout << g << " = " << rint(g) << " // " << h << " = " << rint(h) << endl;

cout << endl;

    //fmod - retorna o resto de divisao em float
    double e=5.7,f=2;

    cout << fmod(e,f) << endl;

cout << endl;


    //fdim - retorna a diferença sempre positivos entre dois numeros
    double i=15,j=9;

    cout << fdim(i,j) << endl;

cout << endl;

    //fmax - retorna o maior valor dentre os dois
    //fmin - retorna o menor valor dentre os dois

    cout << fmax(i,j) << endl;
    cout << fmin(i,j) << endl;

cout << endl;

    //abs ou fabs - arrdonda o valor absoluta de numerais
    double k=-15,l=-9;

    cout << k << " = " << abs(k) << " // " << l << " = " << abs(l) << endl;

    cout << k << " = " << fabs(k) << " // " << l << " = " << fabs(l) << endl;

	system("pause");
	return 0;
}
