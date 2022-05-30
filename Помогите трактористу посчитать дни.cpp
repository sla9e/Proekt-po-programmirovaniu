#include <iostream>
#include <string>
#include <ctime>

using namespace std;



int Date( int D, int M, int Y ){ // Вычисление дня недели
    int a, y, m, R;             //
    a = ( 14 - M ) / 12;        //
    y = Y - a;                  //
    m = M + 12 * a - 2;         //
    R = 7000 + ( D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 );//
    return R % 7;//
}
int Vesok(int M, int Y){
    int f = 28 + (M + (M / 8))%2 + 2%M + 2*(1 / M); //дней в месяце
    if ((Y % 4 == 0) && (M == 2)){ // Проверка на весокосный год
        f = f + 1;
    }
    return f;
}
int Otdih(int DATA, int proverka, int kolvo){
    int holidays = 0;
    kolvo += 1;
    for(int q = 0; q <= kolvo; q++){
    if (DATA == proverka){
        holidays += 1;
        DATA += 1;
    }
    if (DATA > 7){
        DATA = 1;
    }
    else{
        DATA += 1;
    }
}
return holidays;
}

int main(){
cout << "Программа для вычисления количества рабочих дней\n";
int M, Y, M1, Y1; //Переменные день, месяц и год
int D, D1 = 1; // День по умолчанию = 1
cout << "Введите дату(пример: 05 02 2022)\n";
cin >> D >> M >> Y; // Ввод даты
cout << "Введите вторую дату(пример: 05 02 2022)\n";
cin >> D1 >> M1 >> Y1; // Ввод второй даты
int DATA = Date(D, M, Y);


int day;
int kolvo = 0;
//for(int i = M; i < M1; i++){
    //cout << Vesok(i, Y) << "\n";
if (Y != Y1){
    while(Y != Y1){
        for(int j = M; j <= 12; j++){
            kolvo += Vesok(j, Y);
        }
        M = 1;
        Y += 1;
    }
}
kolvo -= (D - D1);
if (M != M1){
    while(M != M1){
        for(int j = M; j < M1; j++){
            kolvo += Vesok(j, Y);
            M += 1;
        }
    }
}
//cout << "\nKolvo: " << kolvo << "\nDATA: " << DATA << "\n"; проверка для отладки

int proverka;
string var;
int holidays = 0;
while(var != "старт"){
    var = "";
    cout << "Введите выходной (пн вт ср чт пт сб вс через ENTER, для выхода введите старт): ";
    cin >> var;
    if(var == "пн"){
        holidays += Otdih(DATA, 1, kolvo);
    }
    else if(var == "вт"){
        holidays += Otdih(DATA, 2, kolvo);
    }
    else if(var == "ср"){
        holidays += Otdih(DATA, 3, kolvo);
    }
    else if(var == "чт"){
        holidays += Otdih(DATA, 4, kolvo);
    }
    else if(var == "пт"){
        holidays += Otdih(DATA, 5, kolvo);
    }
    else if(var == "сб"){
        holidays += Otdih(DATA, 6, kolvo);
    }
    else if(var == "вс"){
        holidays += Otdih(DATA, 7, kolvo);
    }
    else if(var == "старт"){
        cout << "Вычисляю результат...\n";
        exit;
    }
    else{
        cout << "Вы ввели неправильное значение!\nПопробуйте снова\n";
    }
    
}
cout << "Итого выходных: " << holidays;
cout << "\nИтого рабочих дней: " << kolvo - holidays + 1;
cout << "\nВремя работы = " << clock()/10000.0 << endl;
return 0;
}




