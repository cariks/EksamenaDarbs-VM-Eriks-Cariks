#include <iostream>

using namespace std;

void Nosaukums(){
  cout<<"\x1b[38;5;0m  <<  \x1b[38;5;221mC++ Viendimensiju Masīvi Test\x1b[38;5;221m\x1b[38;5;0m >> \x1b[0m\n\n\n";
}

int main() {
  
  int izvele;
  bool apturet=false;

  //---------------Sākumlogs
  do{
    system("clear");
    Nosaukums();
    cout<<"Sveicināti testā par viendimensiju masīviem programmēšanas valodā C++! \n\nTestā ir 10 jautājumi, kas ir sakārtoti nejaušā secībā. Katram jautājumam ir 4 iespējamās atbildes, bet tikai 1 no tām ir pareiza. \n\nPēc tam, kad atbildēsiet uz jautājumu, programma parādīs, vai jūs atbildējāt pareizi vai nē. Testa beigās jums tiks sniegts to jautājumu saraksts, uz kuriem jūs atbildējāt nepareizi!\n\nIzvēlies darbību:\n\n";
    cout<<"\x1b[38;5;10m1 - Sākt testu\n";
    cout<<"\x1b[38;5;202m0 - Apturēt programmu\n\n\x1b[0m~ \x1b[0m";
    cin>>izvele;

    switch(izvele){
      case 1:
        system("clear");
        Nosaukums();
        int test;
        cin>>test;
      break;
      
      case 0:
        system("clear");
        cout<<"\x1b[38;5;202m!Programma ir apturēta!";
        apturet=true;
      break;

      default:
        int atpakal=0;
        do{
          system("clear");
          cout<<"\x1b[38;5;202m!Darbība nepastāv, rādas kļūda!\n\n\n\x1b[0mIevadi '\x1b[38;5;10m1\x1b[0m' lai atgriezties!\n\n~ ";
          cin>>atpakal;
          system("clear");
        }while(atpakal!=1);
    }
  }while(apturet==false);
}