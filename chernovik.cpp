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
    char maska = 0;
    for (int i = 0; i < 5; i++)
    {
        maska << 5;
        maska += 1;
    }
    char b = a_gamm & maska;
    b << (8 - 5);
    a_gamm  >> 5;
    return a_gamm | b;
}

char Obr_cyclicheskiy_sdvig(char a_result)
{
    char new_maska = 0;
    for (int i = 0; i < 5; i++)
    {
        new_maska >> 5;
        new_maska += 1;
    }
    char b1 = a_result & new_maska;
    b1 >> (8 - 5);
    a_result  << 5;
    return a_result | b1;
}

char Obr_gammirovanie(char a_pre_gamm, char gamma) {
    char a_end = a_pre_gamm ^ gamma;
    return a_end;
}

int main()
{
    srand(time(0));
    int gamma = rand() % 128;
    char vvod[256];
    cout << "Введите фразу" << endl;
    cin.getline (vvod,256);
    int n =0;
    for (int i=0;vvod[i]!='\0';i++)
        n++;
    char fraza[n];
    for(int i =0; i < n; i++ )
        fraza[i] = vvod[i];
    cout << endl << "результат гаммирования: ";
    for(int i = 0; i < sizeof(fraza); i++)
    {
        char a = fraza[i];
        cout << Gammirovanie(a, gamma);
    }
    cout << endl << "результат циклицеского сдвига: ";
    for(int i = 0; i < sizeof(fraza); i++) {
        char a = fraza[i];
        cout << Cyclicheskiy_sdvig(Gammirovanie(a, gamma));
    }
    cout << endl << "результат обратного циклицеского сдвига: ";
    for(int i = 0; i < sizeof(fraza); i++) {
        char a = fraza[i];
        cout << Obr_cyclicheskiy_sdvig(Cyclicheskiy_sdvig(Gammirovanie(a, gamma)));
    }
    cout << endl << "результат обратного гаммирования: ";
    for(int i = 0; i < sizeof(fraza); i++) {
        char a = fraza[i];
        cout << Obr_gammirovanie(Obr_cyclicheskiy_sdvig(Cyclicheskiy_sdvig(Gammirovanie(a, gamma))), gamma);
    }
    return 0;
}
