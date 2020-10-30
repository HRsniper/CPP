// Protetores de cabeçalho / Header guards
/* A boa notícia é que podemos evitar o problema acima por meio de um mecanismo chamado proteção de cabeçalho (também chamada de proteção de inclusão ). Protetores de cabeçalho são diretivas de compilação condicional que assumem a seguinte forma: */
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
    // suas declarações (e certos tipos de definições) aqui
#endif

/* Quando este cabeçalho é incluído (#include), o pré-processador verifica se SOME_UNIQUE_NAME_HERE foi definido anteriormente. Se esta é a primeira vez que incluímos o cabeçalho, SOME_UNIQUE_NAME_HERE não terá sido definido. Consequentemente, #define SOME_UNIQUE_NAME_HERE e inclui o conteúdo do arquivo. Se o cabeçalho for incluído novamente no mesmo arquivo, SOME_UNIQUE_NAME_HERE já terá sido definido desde a primeira vez que o conteúdo do cabeçalho foi incluído, e o conteúdo do cabeçalho será ignorado (graças ao #ifndef). */

/* Todos os seus arquivos de cabeçalho devem ter protetores de cabeçalho neles. SOME_UNIQUE_NAME_HERE pode ser qualquer nome que você quiser, mas por convenção é definido como o nome do arquivo completo do arquivo de cabeçalho, digitado em maiúsculas, usando sublinhados para espaços ou pontuação. */