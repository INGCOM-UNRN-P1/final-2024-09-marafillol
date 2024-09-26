# Robot de revisión 🤖

Este es un programa que ve que hay en el repositorio, compila y ejecuta
algunos chequeos adicionales.

Esto _no_ es la corrección, es una ayuda a la misma.


## Repositorio
**branch/revision:** main, cf591c1
,
Informe creado el jue 26 sep 2024 15:13:10 -03

### Archivos contenidos
```total 12K
drwxrwxr-x 2 mrtin mrtin 4,0K sep 26 15:13 output
-rw-rw-r-- 1 mrtin mrtin  202 sep 26 15:13 README.md
-rw-rw-r-- 1 mrtin mrtin 3,9K sep 26 15:13 remover_duplicados.c

```
## Analisis
### sobre `final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c

#### gcc -Wall -Wextra

```

```

 [0]

#### cppcheck

```
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:9:0: information: Include file: <stdio.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSystem]
#include <stdio.h>
^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:10:0: information: Include file: <stdlib.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSystem]
#include <stdlib.h>
^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:11:0: information: Include file: <ctype.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSystem]
#include <ctype.h>
^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:12:0: information: Include file: <string.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSystem]
#include <string.h>
^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:122:26: style: Parameter 'argv' can be declared as const array [constParameter]
int main(int argc, char* argv[]) {
                         ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:27:13: information: found a cast [findcasts-cast]
    return *(unsigned char*)entrada - *(unsigned char*)salida;
            ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:33:21: information: found a cast [findcasts-cast]
        if (isalpha((unsigned char)*cadenaOriginal)) {
                    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:34:39: information: found a cast [findcasts-cast]
            *cadenaLimpia++ = tolower((unsigned char)*cadenaOriginal);
                                      ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:75:29: information: found a cast [findcasts-cast]
    Palabra* nuevaPalabra = (Palabra*)malloc(sizeof(Palabra));
                            ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:51:5: error: Regla 8: La función 'esDuplicado' tiene multiples return ({return_count}). [chequeos-retornos]
int esDuplicado(Palabra* primer_palabra, const char* cadenaOriginal) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:122:5: error: Regla 8: La función 'main' tiene multiples return ({return_count}). [chequeos-retornos]
int main(int argc, char* argv[]) {
    ^

```

 [0]

#### splint

```
Splint 3.1.2 --- 21 Feb 2021

< loading standard library /usr/share/splint/lib/standard.lcd .... >
< preprocessing >
< checking final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c >
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function compararCadenas)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:23:12:
    Left operand of && is non-boolean (char): *entrada && (*entrada == *salida)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:27:12:
    Return value type unsigned char does not match declared type int:
    *(unsigned char *)entrada - *(unsigned char *)salida
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function limpiarCadenaParaComparar)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:32:12:
    Test expression for while not boolean, type char: *cadenaOriginal
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function esDuplicado)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:54:47:
    Passed storage cadenaLimpiaOriginal not completely defined
    (*cadenaLimpiaOriginal is undefined):
    limpiarCadenaParaComparar (..., cadenaLimpiaOriginal)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:58:51:
    Passed storage cadenaLimpiaComparar not completely defined
    (*cadenaLimpiaComparar is undefined):
    limpiarCadenaParaComparar (..., cadenaLimpiaComparar)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function agregarPalabra)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:70:9:
    Test expression for if not boolean, type int:
    esDuplicado(*primer_palabra, cadenaOriginal)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:78:14:
    Argument to exit has implementation defined behavior: 1
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:81:18:
    Passed storage nuevaPalabra->cadena not completely defined
    (*(nuevaPalabra->cadena) is undefined):
    copiarCadena (nuevaPalabra->cadena, ...)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:82:5:
    Implicitly only storage nuevaPalabra->siguiente (type struct Palabra *) not
    released before assignment: nuevaPalabra->siguiente = NULL
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:93:2:
    Function returns with possibly null storage derivable from parameter
    *primer_palabra->siguiente
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:82:31
   : Storage *primer_palabra->siguiente may become null
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function liberarMemoria)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:117:14:
    Implicitly temp storage primer_palabra passed as only param (actual aliases
    primer_palabra): free (actual)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c: (in function main)
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:137:5:
    Return value (type int) ignored: fclose(archivoEn...
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:145:42:
    Null storage primer_palabra passed as non-null param:
    escribirArchivoSalida (..., primer_palabra)
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:123:3
   1: Storage primer_palabra becomes null
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:146:5:
    Return value (type int) ignored: fclose(archivoSa...
< checking macros /usr/include/ctype.h >
< global checks >
locale_t (/usr/include/x86_64-linux-gnu/bits/types/locale_t.h:24:20), 16 uses:
   /usr/include/ctype.h:251:36, 252:36, 253:36, 254:36, 255:36, 256:36, 257:36
      258:36, 259:36, 260:36, 261:37, 263:36, 267:42, 268:40, 271:42, 272:40
Palabra (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c
:19:3), 14 uses:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:51:24

      52:12, 69:28, 75:12, 75:37, 75:60, 87:16, 96:54, 104:56, 105:12, 113:28
      114:12, 116:16, 123:12
__isctype (/usr/include/ctype.h:88), 11 uses:
   /usr/include/ctype.h:189:22, 190:22, 191:22, 192:22, 193:22, 194:22, 195:22
      196:22, 197:22, 198:22, 199:23
__uint64_t (/usr/include/x86_64-linux-gnu/bits/types.h:48:34), 6 uses:
   /usr/include/x86_64-linux-gnu/bits/types.h:59:19, 145:21, 149:21, 158:21
      185:21, 189:21
__int64_t (/usr/include/x86_64-linux-gnu/bits/types.h:47:32), 5 uses:
   /usr/include/x86_64-linux-gnu/bits/types.h:58:18, 153:20, 163:20, 181:20
      223:20
__int32_t (/usr/include/x86_64-linux-gnu/bits/types.h:41:20), 3 uses:
   /usr/include/x86_64-linux-gnu/bits/types.h:56:18
   /usr/include/ctype.h:81:23, 83:23
limpiarCadenaParaComparar (final-2024-09-submissions/final-2024-09-marafillol/re
mover_duplicados.c:39:1), 2 uses:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:54:5
      58:9
isalpha (/usr/include/ctype.h:190), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:33:13
isblank (/usr/include/ctype.h:201), 1 use:
   /usr/include/ctype.h:130:12
isascii (/usr/include/ctype.h:225), 1 use:
   /usr/include/ctype.h:142:12
toascii (/usr/include/ctype.h:226), 1 use:
   /usr/include/ctype.h:146:12
_tolower (/usr/include/ctype.h:228), 1 use:
   /usr/include/ctype.h:151:12
_toupper (/usr/include/ctype.h:229), 1 use:
   /usr/include/ctype.h:150:12
isalnum_l (/usr/include/ctype.h:304), 1 use:
   /usr/include/ctype.h:251:12
isalpha_l (/usr/include/ctype.h:305), 1 use:
   /usr/include/ctype.h:252:12
iscntrl_l (/usr/include/ctype.h:306), 1 use:
   /usr/include/ctype.h:253:12
isdigit_l (/usr/include/ctype.h:307), 1 use:
   /usr/include/ctype.h:254:12
islower_l (/usr/include/ctype.h:308), 1 use:
   /usr/include/ctype.h:255:12
isgraph_l (/usr/include/ctype.h:309), 1 use:
   /usr/include/ctype.h:256:12
isprint_l (/usr/include/ctype.h:310), 1 use:
   /usr/include/ctype.h:257:12
ispunct_l (/usr/include/ctype.h:311), 1 use:
   /usr/include/ctype.h:258:12
isspace_l (/usr/include/ctype.h:312), 1 use:
   /usr/include/ctype.h:259:12
isupper_l (/usr/include/ctype.h:313), 1 use:
   /usr/include/ctype.h:260:12
isxdigit_l (/usr/include/ctype.h:314), 1 use:
   /usr/include/ctype.h:261:12
isblank_l (/usr/include/ctype.h:316), 1 use:
   /usr/include/ctype.h:263:12
__int8_t (/usr/include/x86_64-linux-gnu/bits/types.h:37:21), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:52:17
__uint8_t (/usr/include/x86_64-linux-gnu/bits/types.h:38:23), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:53:18
__int16_t (/usr/include/x86_64-linux-gnu/bits/types.h:39:26), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:54:18
__uint16_t (/usr/include/x86_64-linux-gnu/bits/types.h:40:28), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:55:19
__uint32_t (/usr/include/x86_64-linux-gnu/bits/types.h:42:22), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:57:19
__off64_t (/usr/include/x86_64-linux-gnu/bits/types.h:153:21), 1 use:
   /usr/include/x86_64-linux-gnu/bits/types.h:203:18
_ISupper (/usr/include/ctype.h:48:3), 1 use:
   /usr/include/ctype.h:198:37
_ISlower (/usr/include/ctype.h:49:3), 1 use:
   /usr/include/ctype.h:193:37
_ISalpha (/usr/include/ctype.h:50:3), 1 use:
   /usr/include/ctype.h:190:37
_ISdigit (/usr/include/ctype.h:51:3), 1 use:
   /usr/include/ctype.h:192:37
_ISxdigit (/usr/include/ctype.h:52:3), 1 use:
   /usr/include/ctype.h:199:38
_ISspace (/usr/include/ctype.h:53:3), 1 use:
   /usr/include/ctype.h:197:37
_ISprint (/usr/include/ctype.h:54:3), 1 use:
   /usr/include/ctype.h:195:37
_ISgraph (/usr/include/ctype.h:55:3), 1 use:
   /usr/include/ctype.h:194:37
_IScntrl (/usr/include/ctype.h:57:3), 1 use:
   /usr/include/ctype.h:191:37
_ISpunct (/usr/include/ctype.h:58:3), 1 use:
   /usr/include/ctype.h:196:37
_ISalnum (/usr/include/ctype.h:59:3), 1 use:
   /usr/include/ctype.h:189:37
__locale_t (/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:41:33), 1
use:
   /usr/include/x86_64-linux-gnu/bits/types/locale_t.h:24:19
compararCadenas (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:28:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:60:13
copiarCadena (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:48:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:81:5
esDuplicado (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:66:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:70:9
agregarPalabra (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:93:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:99:9
leerArchivoEntrada (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:101:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:136:5
escribirArchivoSalida (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:110:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:145:5
liberarMemoria (final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:120:1), 1 use:
   final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:148:5

Finished checking --- 14 code warnings
2128 source lines in 0.02 s.

```

 [1]

#### clang

```

```

 [0]

#### clang-tidy

```
29 warnings generated.
56 warnings and 1 error generated.
Error while processing /home/mrtin/dev/pi/dredd/final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c.
error: error reading 'pic' [clang-diagnostic-error]
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:14:1: warning: replace macro with enum [modernize-macro-to-enum]
#define MAX_CARACTERES 100
^~~~~~~~
                       =
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:14:9: warning: macro 'MAX_CARACTERES' defines an integral constant; prefer an enum instead [modernize-macro-to-enum]
#define MAX_CARACTERES 100
        ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:34:31: warning: narrowing conversion from 'int' to signed type 'char' is implementation-defined [cppcoreguidelines-narrowing-conversions]
            *cadenaLimpia++ = tolower((unsigned char)*cadenaOriginal);
                              ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:43:12: warning: variable 'i' is not initialized [cppcoreguidelines-init-variables]
    size_t i;
           ^
             = 0
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:12: warning: Call to function 'fscanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'fscanf_s' in case of C11 [clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling]
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
           ^~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:12: note: Call to function 'fscanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'fscanf_s' in case of C11
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
           ^~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:141:9: warning: Potential leak of memory pointed to by 'primer_palabra' [clang-analyzer-unix.Malloc]
        fprintf(stderr, "Error al abrir el archivo de salida: %s\n", argv[2]);
        ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:125:9: note: Assuming 'argc' is equal to 3
    if (argc != 3) {
        ^~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:125:5: note: Taking false branch
    if (argc != 3) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:131:9: note: Assuming 'archivoEntrada' is not equal to NULL
    if (archivoEntrada == NULL) {
        ^~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:131:5: note: Taking false branch
    if (archivoEntrada == NULL) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:136:5: note: Calling 'leerArchivoEntrada'
    leerArchivoEntrada(archivoEntrada, &primer_palabra);
    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:12: note: Assuming the condition is true
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:5: note: Loop condition is true.  Entering loop body
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:99:9: note: Calling 'agregarPalabra'
        agregarPalabra(primer_palabra, cadena);
        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:70:5: note: Taking false branch
    if (esDuplicado(*primer_palabra, cadenaOriginal)) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:75:39: note: Memory is allocated
    Palabra* nuevaPalabra = (Palabra*)malloc(sizeof(Palabra)); 
                                      ^~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:76:9: note: Assuming 'nuevaPalabra' is not equal to NULL
    if (nuevaPalabra == NULL) {
        ^~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:76:5: note: Taking false branch
    if (nuevaPalabra == NULL) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:84:5: note: Taking true branch
    if (*primer_palabra == NULL) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:99:9: note: Returned allocated memory via 1st parameter
        agregarPalabra(primer_palabra, cadena);
        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:12: note: Assuming the condition is false
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:98:5: note: Loop condition is false. Execution continues on line 98
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:136:5: note: Returned allocated memory via 2nd parameter
    leerArchivoEntrada(archivoEntrada, &primer_palabra);
    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:140:9: note: Assuming 'archivoSalida' is equal to NULL
    if (archivoSalida == NULL) {
        ^~~~~~~~~~~~~~~~~~~~~
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:140:5: note: Taking true branch
    if (archivoSalida == NULL) {
    ^
final-2024-09-submissions/final-2024-09-marafillol/remover_duplicados.c:141:9: note: Potential leak of memory pointed to by 'primer_palabra'
        fprintf(stderr, "Error al abrir el archivo de salida: %s\n", argv[2]);
        ^
Suppressed 46 warnings (46 in non-user code).
Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
Found compiler error(s).

```

 [1]

# Importante
_Este informe solo es una ayuda a quien corregirá_
