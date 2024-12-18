#include <iostream>
using namespace std;
int main() {
    cout<<"*******NUMBER GUESSING GAME*******"<<endl;
    srand(time(0));
    int n = rand() % 101;
    cout<<"Guess any number from 0 to 100\nYou have only 10 guesses"<<endl;
    int g=10,C=0;
    for(int i=0;i<10;i++){
        int m;
        cout<<"Enter a number= ";
        cin>>m;
        if(m==n){
            cout<<"You have guessed the number correctly\nYou Win!"<<endl;
            C++;
            break;
        }
        else if(m>n){
        cout<<"Too High"<<endl;
        cout<<"You have "<<--g<<" guesses left"<<endl;}
        else{
        cout<<"Too Low"<<endl;
        cout<<"You have "<<--g<<" guesses left"<<endl;}
        
    }
    if(C==0)
    cout<<"You lose :(\nthe number was "<<n<<endl;
    return 0;
}

