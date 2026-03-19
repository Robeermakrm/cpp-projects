#include <iostream>
#include <windows.h>
using namespace std;

char arr[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char possion;
char player='x';
int x=0;
int o=0;


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void show()
{
    cout<<"\n\n THE DEVOLPER THISE GAME IS (ROBEER MAKRM)\n";
    cout<<"\n\n\t\t\t___________________"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  ";
    for(int j=0;j<3;j++){
        if(arr[0][j]=='x') setColor(12);
        else if(arr[0][j]=='o') setColor(9);
        else setColor(7);
        cout << arr[0][j];
        setColor(7);
        cout << "  |  ";
    }
    cout << endl << "\t\t\t|_____|_____|_____|"<<endl;

    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  ";
    for(int j=0;j<3;j++){
        if(arr[1][j]=='x') setColor(12);
        else if(arr[1][j]=='o') setColor(9);
        else setColor(7);
        cout << arr[1][j];
        setColor(7);
        cout << "  |  ";
    }
    cout << endl << "\t\t\t|_____|_____|_____|"<<endl;

    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  ";
    for(int j=0;j<3;j++){
        if(arr[2][j]=='x') setColor(12);
        else if(arr[2][j]=='o') setColor(9);
        else setColor(7);
        cout << arr[2][j];
        setColor(7);
        cout << "  |  ";
    }
    cout << endl << "\t\t\t|_____|_____|_____|"<<endl;
}


void play()
{
    cout<<"Please enter position (1-9) and the first play is (X): ";
    cin>>possion;
    bool valid = false;
    for(int i=0; i<3; i++)
    {
        for (int g=0; g<3; g++)
        {
            if(possion==arr[i][g])
            {
                arr[i][g]=player;
                valid = true;
            }
        }
    }
    if(!valid)
    {
        cout << "Invalid move! Try again.\n";
        play();
    }

    if (player=='x') player='o';
    else player='x';
}


char winner()
{
    int teest=0;
    for(int i=0; i<3; i++)
    {
        x=o=0;
        for(int g=0; g<3; g++)
        {
            if(arr[i][g]=='x') x++;
            else if (arr[i][g]=='o') o++;
            else teest++;
        }
        if(x==3) return 'x';
        if(o==3) return 'o';
    }

    for(int g=0; g<3; g++)
    {
        x=o=0;
        for(int i=0; i<3; i++)
        {
            if(arr[i][g]=='x') x++;
            else if(arr[i][g]=='o') o++;
        }
        if(x==3) return 'x';
        if(o==3) return 'o';
    }

    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x') return 'x';
    if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o') return 'o';
    if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x') return 'x';
    if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o') return 'o';

    if(teest==0) return 'z';
    return '.';
}

int main()
{
    char win = '.';
    while(win=='.')
    {
        show();
        play();
        system("cls");
        win = winner();
    }

    show();
    if(win=='z') cout << "\nDRAW! No winner.\n";
    else cout << "\nTHE WINNER IS " << win << "! Congratulations!\n";

    return 0;
}
