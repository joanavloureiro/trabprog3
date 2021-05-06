
// #include <time.h>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <cstring>
// using namespace std;


// int calcularIdade(struct tm *data, struct tm *dataNascimento) {
//     int idade = data->tm_year - dataNascimento->tm_year;

//     /*
//      * Verifica as condições para determinar se já fez aniversário.
//      * Caso não tenha feito ainda, decrementamos a idade para compensar.
//      */
//     if (data->tm_mon < dataNascimento->tm_mon)
//         idade -= 1;
//     else if (data->tm_mon == dataNascimento->tm_mon)
//         if (data->tm_mday < dataNascimento->tm_mday)
//             idade -= 1;

//     return idade;
// } 


// int main (){

//     struct tm data = stringToTm("05/05/2021");

//     struct tm dataNascimento = stringToTm("07/05/2001");

//     int idade = calcularIdade(&data, &dataNascimento);

//     printf("Você tem %i anos de idade. \n", idade);


//   return 0;
// }