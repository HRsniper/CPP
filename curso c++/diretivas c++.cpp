// pré-processador
// Elas são processadas antes da compilação do código propriamente dito. 
// De uma maneira geral elas instruem o compilador de algumas ações que devem ser feitas com o código.
// Portanto, o pré-processador modifica o programa fonte, que ainda não estaria pronto para ser entregue ao compilador.
// Todas as diretivas de compilação são iniciadas pelo caractere # (sharp).
// As diretivas podem ser colocadas em qualquer parte do programa, mas não podem ser colocadas na mesma linha que outra diretiva ou instrução.

// As principais diretivas de compilação são:

#define
    /* A diretiva #define tem duas utilidades. Uma delas é apenas definir um símbolo que pode ser testado mais tarde. Outra é definir uma constante ou ainda uma macro com parâmetros.
    As três maneiras de usar a diretiva são: */
    #define nome_do_símbolo
    #define nome_da_constante valor_da_constante
    #define nome_da_macro(parâmetros) expressão_de_substituição

#elif
    /* A diretiva #elif serve para implementar uma estrutura do tipo if (condição) {...} else if (condição) {...}.
    Sua forma geral é: */
    #if expressão_1 
        código
    #elif expressão_2 
        código
    #elif expressão_3 
        código
        ...
    #elif expressão_n 
        código
    #endif 

#else
    /* A diretiva #else funciona como na estrutura de bloco if (condição) {...} else {...}: */
    #if expressão  /* ou #ifndef expressão */
        código /* será executado se a expressão for verdadeira */
    #else
        código /* será executado se a expressão for falsa */
    #endif 

#endif
    /* Todas as diretivas de compilação condicional, como #if e #ifdef, devem corresponder a uma diretiva de fechamento #endif antes do final do arquivo. Caso contrário, uma mensagem de erro será gerada. 
    sua sintaxe é:*/
    #if expressão  /* ou #ifndef expressão */
        código
    #endif 

#error
    /* A diretiva #error emite uma mensagem de erro especificada pelo usuário no momento da compilação e, em seguida, encerra a compilação.
    Sintaxe */
    #error cadeia de caracteres de token-String

#if
    /* A sequência de declarações será compilada apenas se a expressão fornecida for verdadeira.
    É muito importante ressaltar que a expressão fornecida não pode conter nenhuma variável, apenas valores constantes e símbolos do pré-processador.
    sua sintaxe é: */
    #if expressão
        código
        ...
    #endif 

#ifdef
#ifndef
    /* O pré-processador também tem estruturas condicionais. No entanto, como as diretivas são processadas 
        antes de tudo, só podemos usar como condições expressões que envolvam constantes e símbolos do pré-processador.
    As diretivas #ifdef e #ifndef têm o mesmo efeito que a diretiva #if quando ela é usada com o operador definido.
    Você pode usar as diretivas #ifdef e #ifndef em #if qualquer lugar que possam ser usadas.
    Suas sintaxes são: */
    #ifdef nome_do_símbolo    #ifndef nome_do_símbolo
        código                    código
        ...                       ...
    #endif                    #endif
    /* O código entre as duas diretivas só será compilado se o símbolo (ou constante) nome_do_símbolo
        já tiver sido definido. Há também a estrutura ifndef, que executa o código se o símbolo não tiver sido definido.
        Lembre que o símbolo deve ter sido definido através da diretiva #define. */


#import
    /* Usado para incorporar informações de uma biblioteca de tipos. O conteúdo da biblioteca de tipos é convertido em classes C ++, principalmente descrevendo as interfaces COM. */
    // Sintaxe
    #import "nome do arquivo" [atributos]
    #import <nome do arquivo> [atributos]

    // Parâmetros
        /* nome do arquivo */
    /* Especifica a biblioteca de tipos a ser importada. O nome do arquivo pode ser um dos seguintes tipos:
        * O nome de um arquivo que contém uma biblioteca de tipos, como um arquivo .olb, .tlb ou .dll. A palavra-chave, file:, pode preceder cada nome de arquivo. */
    /* * O progid de um controle na biblioteca de tipos. A palavra-chave, progid:, pode preceder cada progid. Por exemplo:
        #import "progid: my.prog.id.1.5" */
    /* Para obter mais informações sobre progids, consulte Especificando o ID de localização e o número da versão aqui:
    https://docs.microsoft.com/pt-br/cpp/preprocessor/hash-import-directive-cpp?view=vs-2019#_predir_the_23import_directive_specifyingthelocalizationidandversionnumber */

#include
    /* A diretiva #include diz ao pré-processador para incluir naquele ponto um arquivo especificado.
    Sua sintaxe é: */
    #include "nome_do_arquivo"
        /* ou */
    #include <nome_do_arquivo>

#line
    /* A diretiva #line informa ao pré-processador para definir os valores relatados do compilador para o número de linha e o nome de arquivo para um determinado número de linha e nome de arquivo.
    O compilador usa o número de linha e o nome de arquivo opcional para fazer referência aos erros que encontra durante a compilação. */
    // Sintaxe
    #line sequência de dígitos ["nome do arquivo"]

        /* Os exemplos a seguir ilustram #lineas macros __LINE__e __FILE__. */
        /* 
        printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
        #line 88
            printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
        #line 90 "hello.cpp"
            printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
            printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );

        Resultado
        This code is on line 87, in file diretivas c++.cpp
        This code is on line 88, in file diretivas c++.cpp
        This code is on line 90, in file hello.cpp
        This code is on line 91, in file hello.cpp
        */

#pragma
    /* Esta diretiva é uma diretiva de propósito especial e é usada para ativar ou desativar alguns recursos. Este tipo de diretivas são específicas do compilador, ou seja, variam de compilador para compilador.  */
    /* As diretivas pragma especificam recursos de compilador específicos do computador ou do sistema operacional.  */
    // Sintaxe
    #pragma cadeia de caracteres de token #pragma
    __pragma ( cadeia de caracteres de token )

    alloc_text, auto_inline, bss_seg, check_stack, code_seg, comment, component, conform1, const_seg, data_seg, deprecated, 
    detect_mismatch, fenv_access, float_control, fp_contract, function, hdrstop, include_alias, init_seg1, inline_depth, inline_recursion, 
    intrinsic, loop1, make_public, managed, message, omp, once, optimize, pack, pointers_to_members1, pop_macro, push_macro, region,, endregion, runtime_checks, section, setlocale, strict_gs_check, unmanaged, vtordisp1, warning.
    /* acesse: https://docs.microsoft.com/pt-br/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=vs-2019
    para ver todos os pragmas */

#undef
    /* A diretiva #undef remove a definição atual do identificador. Consequentemente, ocorrências subsequentes do identificador são ignoradas pelo pré-processador. 
    Sua sintaxe é:  */
    #undef nome_da_macro

#using
    /* Importa metadados para um programa compilado com /CLR.
    Sintaxe */
    #using arquivo [ as_friend ]
        Parâmetros
    /* arquivo
        Um arquivo MSIL (Microsoft Intermediate Language) .dll, .exe, .netmodule ou .obj. Por exemplo: */
        #using <MyComponent.dll>
        #using "MyComponent.dll"
    /* as_friend
        Especifica que todos os tipos no arquivo estão acessíveis. Para obter mais informações, consulte Friend Assemblies (C++). https://docs.microsoft.com/pt-br/cpp/dotnet/friend-assemblies-cpp?view=vs-2019 */