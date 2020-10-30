#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    fstream arquivo;
    string linha;
    char linha_b[255];

/*
    arquivo.open("texto.txt",fstream::in|fstream::out|fstream::app);

    //in - input (leitura) posiciona no inicio
    //out - output (escrita)
    //binary - modo binario
    //ate - abre para escrita e posiciona no final
    //app -append - abre para escrita sem deletar o conteudo autal e posiciona no final ,cria o arquivo se ele nao existir
    //trunc -truncate - abra para escrita e remove o conteudo atual antes de abrir

    if (arquivo.is_open()){
        arquivo << "HRsniper" << "\n" << "aula100" << "\n";
    }else{
        cout << "nao encontrado" << endl;
    }

    arquivo.close();
*/
///////////////////////////////////////////////////////////////////////////////////////////
cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////
/*
    arquivo.open("texto.txt",fstream::in);
    if (arquivo.is_open()){
        while (getline(arquivo,linha))
        {
            cout << linha << "\n";
        }
    }else{
        cout << "nao encontrado" << endl;
    }

    arquivo.close();
*/
///////////////////////////////////////////////////////////////////////////////////////////
cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////
/*
    //write - escreve no arquivo

    arquivo.open("texto.txt",fstream::out|fstream::app);
    if (arquivo.is_open()){
       arquivo.write("write escreveu",14);
    }else{
        cout << "nao encontrado" << endl;
    }

    arquivo.close();

cout << endl;

    arquivo.open("texto.txt",fstream::in);

    while (getline(arquivo,linha))
        {
            cout << linha << "\n";
        }

    arquivo.close
*/
///////////////////////////////////////////////////////////////////////////////////////////
cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////
/*
    //read - le o arquivo

    arquivo.open("texto.txt",fstream::in);
    arquivo.read(linha_b,255);
    cout << linha_b << endl;

    arquivo.close
*/
///////////////////////////////////////////////////////////////////////////////////////////
cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////
/*
    //tellp - retorna a posiçao do ponteiro dentro do stream
    //seekp - define a posiçao do ponteiro dentro da stream

//arquivos de bancos de dados

    long pos;

    arquivo.open("texto.txt",fstream::out);
    arquivo.write("HR sniper",9);

    pos=arquivo.tellp();//posiçao 9
    cout << pos << "\n";

    arquivo.seekp(pos-6);//posiçao 3
    pos=arquivo.tellp();//posiçao 3
    cout << pos << endl;

    arquivo.write("chaytec",8);

    arquivo.close();
*/
///////////////////////////////////////////////////////////////////////////////////////////
cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////

    // constantes para difinir a posiçao sa stram
    //beg - apartir do iniciio
    //cur - apartir da posiçao atual
    //end - apartir do final

    long pos2;

    arquivo.open("texto.txt",fstream::out);
    arquivo.write("HR sniper",9);

    pos2=arquivo.tellp();//pos2içao 9
    cout << pos2 << "\n";

    arquivo.seekp(arquivo.beg+3);//pos2içao 3
    pos2=arquivo.tellp();//pos2içao 3
    cout << pos2 << endl;

    arquivo.write("chaytec",8);

    arquivo.close();


	system("pause");
	return 0;
}
