#include <iostream>
#include <ctime>

using namespace std;

char Gammirovanie(char a, char gamma)
{

    char a_gamm = a ^ gamma;
    return a_gamm;
}

char Cyclicheskiy_sdvig(char a_gamm)
{
    char maska = a_gamm << 3;
    a_gamm = a_gamm >> 5;
    char a_result = maska | a_gamm;
    return a_result;
}

char Obr_cyclicheskiy_sdvig(char a_result)
{
    char new_maska = a_result >> 3;
    char a_middle = a_result << 5;
    char a_pre_gamm = a_middle | new_maska;
    return a_pre_gamm;
}

char Obr_gammirovanie(char a_pre_gamm, char gamma) {
    char a_end = a_pre_gamm ^ gamma;
    return a_end;
}

int main()
{
    srand(time(0));
    int gamma = rand() % 96 + 32;
    char a;
    cout << "Введите а" << endl;
    cin >> a;
    cout << endl << "результат гаммирования " << Gammirovanie(a,  gamma);
    cout << endl << "результат циклицеского сдвига " << Cyclicheskiy_sdvig(Gammirovanie( a,  gamma));
    cout << endl << "результат обратного циклицеского сдвига " << Obr_cyclicheskiy_sdvig(Cyclicheskiy_sdvig(Gammirovanie( a, gamma)));
    cout << endl << "результат обратного гаммирования " << Obr_gammirovanie(Obr_cyclicheskiy_sdvig(Cyclicheskiy_sdvig(Gammirovanie( a, gamma))), gamma);
    return 0;
}