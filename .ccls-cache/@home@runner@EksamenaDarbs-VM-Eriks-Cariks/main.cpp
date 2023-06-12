#include <vector>
#include <algorithm>  //shuffle
#include <iostream>

using namespace std;

void Nosaukums(){
  cout<<"\x1b[38;5;0m  <<  \x1b[38;5;221mC++ Viendimensiju Masīvi Test\x1b[38;5;221m\x1b[38;5;0m >> \x1b[0m\n\n\n";
}

void Jautajumi(){
  int CikJautajumusParadit = 10;    //Cik jautājumus paradīt testā?
  int KopJautajumuSkaits = 15;      //Kopējais jautājumu skaits


  //-----------------------------Jautājumu teksts
  vector<string> VisiJautajumi = {      
  "A jautājums", 
  "B jautājums", 
  "C jautājums", 
  "D jautājums", 
  "E jautājums", 
  "F jautājums", 
  "G jautājums", 
  "H jautājums", 
  "I jautājums", 
  "J jautājums", 
  "K jautājums", 
  "L jautājums", 
  "M jautājums", 
  "N jautājums", 
  "O jautājums"};

  //-----------------------------Atbildes teksts
  vector<vector<string>> VisasAtbildes(15, vector<string>(4));
  VisasAtbildes[0] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[1] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[2] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[3] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[4] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[5] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[6] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[7] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[8] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[9] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[10] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[11] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[12] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[13] = {"dfdf", "asdasd", "112df5d", "dfdf"};
  VisasAtbildes[14] = {"dfdf", "asdasd", "112df5d", "dfdf"};

  //-----------------------------Pareizas atbildes indekss
  vector<int> AtbildesIndekss = {
  1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

  vector<int> NepareizasAtbildes;    //Vektors kurš glabās neparezas atbildes indeksu
  
  vector<int> randSk;        //Vektors ar skaitļiem nejaušā secībā
  for(int i=0; i<KopJautajumuSkaits; i++){
    randSk.push_back(i);
  }
  random_shuffle(randSk.begin(), randSk.end());    //Sajaukt skaitļus vektorā
  
  int nejausausIndekss;
  int lietotajaAtbilde;
  for(int i=0; i<CikJautajumusParadit; i++){
    system("clear");
    Nosaukums();
    
    cout<<"\t\t\trandSk tagad ir = "<<randSk[i]<<endl<<endl;  //parbaudijums*
    
    cout<<i+1<<". Jautājums\n"<<VisiJautajumi[randSk[i]]<<endl<<endl;
    for(int j=0; j<4; j++){
      cout<<j+1<<". "<<VisasAtbildes[randSk[i]][j]<<endl;
    }
    cout<<endl<<"~ ";
    cin>>lietotajaAtbilde;

    //-----------------------------Parbaude
    do{
      int talak;
      if(lietotajaAtbilde==AtbildesIndekss[randSk[i]]){
        cout<<"\nPareizi! :)";
      }else{
        cout<<"\nNepareizi! :(";
        NepareizasAtbildes.push_back(randSk[i]);
      }
      do{
        cout<<"\n\nIevadi '1' lai turpināt pildīt testu: \n\n";
        cin>>talak;
        if(talak!=1){
          cout<<"\n\nDarbība nepastāv!";
        }
      }while(talak!=1);
    }while(lietotajaAtbilde<1 || lietotajaAtbilde>4);
  }
  
  //-----------------------------Rezultāts
  system("clear");
  Nosaukums();
  int uzSakumu;
  if(!NepareizasAtbildes.empty()){
    
    cout<<"Jautājumi, uz kuriem atbildējāt nepareizi:\n\n";
    for(int i=0; i<NepareizasAtbildes.size(); i++){
      cout<<VisiJautajumi[NepareizasAtbildes[i]]<<endl;
    }
  }else{
    cout<<"\n\nMalacis!\n\nTu atbildēji uz visiem jautājumiem bez nevienas kļūdas!";
  }
  
  do{
    cout<<"\n\nIevadi '2' lai atgriezties uz sākumu: \n\n";
    cin>>uzSakumu;
    if(uzSakumu!=2){
      cout<<"Darbība nepastāv!";
    }
  }while(uzSakumu!=2);
}



//-----------------------------Main daļa
int main() {
  srand(time(0));
  
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
        Jautajumi();
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