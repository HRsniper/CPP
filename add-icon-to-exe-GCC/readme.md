# Adicionando um ícone a um arquivo executável compilado pelo GCC

Como todos sabemos, os arquivos compilados pela linha de comando `gcc/g++` no (_MinGW_ ou _TMD-GCC_) não possuem ícones por padrão.

## Então, como devo adicionar um ícone a ele?

1.  primeiro prepare um arquivo de ícone `.ico`. e em seguida, crie um documento de texto com nome `icon.rc` no mesmo diretório do arquivo `.ico` e escreva nele:

    - ```cpp
        1 ICON "icon.ico"
      ```

2.  Em seguida, use `windres` para vincular o arquivo `.rc`, e a extensão do arquivo de saída para o link `.o`:

    - ```ps1
        windres -i icon.rc -o icon-out.o
      ```

3.  Finalmente, use `g++` para compilar seu programa e o arquivo de link do ícone para ser vinculado juntos:
    - ```ps1
        g++ main.cpp icon-out.o -o main.exe
      ```

**Agora seu executável possui um ícone.**

---

## Compilando aplicativos de 32 ou 64 bits

O `gcc/g++` pode compilar aplicativos de 32 ou 64 bits com os parâmetros `-m32` e `-m64`.
os arquivos vinculados acima usando `windres` também são divididos em 32 ou 64 bits.

Em circunstâncias normais, a arquitetura do arquivo de ícone que vinculamos diretamente segue nosso sistema. se você for um sistema windows de 64 bits, o arquivo vinculado `xxx.o` também será de 64 bits (_é o mesmo quando compilado sem o parâmetro -m para `gcc/g++` siga a arquitetura do sistema_).

Mas se estivermos compilando o arquivo executável de uma arquitetura especifica, também precisamos especificar a arquitetura ao vincular o ícone, caso contrário, ocorrerá um erro durante a compilação conjunta final.

**Se quiser compilar um programa de 32 bits:**

1. use o link de ícone `windres` e adicione o parâmetro `-F` à linha de comando para vincular a arquitetura de 32 bits:

   - ```ps1
      windres -i ico.rc -o ico32.o -F pe-i386
     ```

2. em seguida, compile junto ao seu programa (_usando o parâmetro `-m32` para especificar um programa de 32 bits_):

   - ```ps1
      g++ -m32 main.cpp ico32.o -o main32.exe
     ```

**Se quiser compilar um programa de 64 bits:**

1.  use o link de ícone `windres` e adicione o parâmetro `-F` à linha de comando para vincular a arquitetura de 64 bits:

    - ```ps1
        windres -i ico.rc -o ico64.o -F pe-x86-64
      ```

2.  em seguida, compile junto ao seu programa (_usando o parâmetro `-m64` para especificar um programa de 64 bits_):

    - ```ps1
        g++ -m64 main.cpp ico64.o -o main64.exe
      ```

**O EFEITO É O MESMO**
