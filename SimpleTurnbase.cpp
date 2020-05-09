#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
using namespace std;
string element[3]={"Fire","Water","Earth"},my_ele,enemy_ele,netral_ele;
string f_s1="Fire Bolt",f_s2="Punch",f_s3="EXPLOXION!!!!";
string w_s1="Water Cannon",w_s2="Blubub-Blubub",w_s3="Tackle";
string e_s1="Earthquacke",e_s2="Headbutt",e_s3="Heal";
float crit,dmg,total;
int pil;
class player{
    public :
    float atk,deff,cc,cd,hp;
}pl;
class enemy{
    public :
    float atk,deff,cc,cd,hp;
}en;
void hp(){
    if(pl.hp<0){
        pl.hp=0;
    }
    if(en.hp<0){
        en.hp=0;
    }
    cout<<"("<<my_ele<<")"<<"(you)HP="<<(int)pl.hp<<endl;
    cout<<"("<<enemy_ele<<")"<<"(enemy)HP="<<(int)en.hp<<endl;
}
void kal_dmg(){
        crit=rand() % 101;
        if(crit<=pl.cc){
            cout<<"It's Critical"<<endl;
            dmg=dmg*pl.cd/100;
            getch();
        }
        if((my_ele=="Fire"&&enemy_ele=="Earth")||(my_ele=="Water"&&enemy_ele=="Fire")||(my_ele=="Earth"&&enemy_ele=="Water")){
            cout<<"It's Effective"<<endl;
            dmg=dmg+dmg*0.2;
            getch();
        }else if(my_ele==enemy_ele){
     
        }else{
            cout<<"It's no Effective"<<endl;
            dmg=dmg-dmg*0.2;
            getch();
        }
        total=pl.deff/dmg*100;
        if(total>=60){
            dmg=dmg*40/100;
        }else{
            dmg=dmg-en.deff;
        }
        cout<<"Damage="<<(int)dmg<<endl;
}
void enemy_fire_skill(){
    cout<<"=Giliran Lawan="<<endl;
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    srand(time(0));
    pil=rand() % 3;
    if(enemy_ele=="Earth"){
        if(pil==1){
            pil=0;
        }
    }
    switch(pil){
        case 0 :
        cout<<"Enemy Using "<<f_s1<<endl;
        dmg=en.atk*150/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        break;
        case 1 :
        cout<<"Enemy Using "<<f_s2<<endl;
        my_ele=enemy_ele;
        dmg=en.atk*110/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        my_ele=netral_ele;
        break;
        case 2 :
        cout<<"Enemy Using "<<f_s3<<endl;
        dmg=en.atk*800/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        cout<<"Enemy HP decrase to 1";
        en.hp=1;
        getch();
        break;
    }
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    getch();
}
void enemy_water_skill(){
    cout<<"=Giliran Lawan="<<endl;
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    if(enemy_ele=="Fire"){
        srand(time(0));
        pil=rand() % 2;
    }else{
        srand(time(0));
        pil=rand() % 3;
    }
    switch(pil){
        case 0 :
        cout<<"Enemy Using "<<w_s1<<endl;
        dmg=en.atk*150/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        break;
        case 1 :
        int rng;
        cout<<"Enemy Using "<<w_s2<<endl;
        srand(time(0));
        rng=rand() % 1000;
        dmg=en.atk*rng/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        break;
        case 2 :
        cout<<"Enemy Using "<<w_s3<<endl;
        my_ele=enemy_ele;
        dmg=en.atk*120/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        my_ele=netral_ele;
        break;
    }
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    getch();
}
void enemy_earth_skill(){
    cout<<"=Giliran Lawan="<<endl;
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    srand(time(0));
    pil=rand() % 3;
    if(en.hp<(en.hp*10/100)){
        pil=2;
    }
    switch(pil){
        case 0 :
        cout<<"Enemy Using "<<e_s1<<endl;
        dmg=en.atk*150/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        break;
        case 1 :
        cout<<"Enemy Using "<<e_s2<<endl;
        my_ele=enemy_ele;
        dmg=en.atk*110/100;
        kal_dmg();
        pl.hp=pl.hp-dmg;
        my_ele=netral_ele;
        break;
        case 2 :
        int heal;
        cout<<"Enemy Using "<<e_s3<<endl;
        heal=en.hp*10/100;
        en.hp=en.hp+heal;
        cout<<"Your HP restore "<<heal<<" Point"<<endl;
        break;
    }
    netral_ele=enemy_ele;
    enemy_ele=my_ele;
    my_ele=netral_ele;
    getch();
}
void fire_skill(){
    cout<<"=Giliran Kamu="<<endl;
    cout<<"1."<<f_s1<<"(dmg x150%)(fire)"<<endl;
    cout<<"2."<<f_s2<<"(dmg x110%)(netral)"<<endl;
    cout<<"3."<<f_s3<<"(dmg x800% but hp decrase to 1)(fire)"<<endl;
    cout<<"Pilih Skill : ";cin>>pil;
    switch(pil){
        case 1 :
        cout<<"You Using "<<f_s1<<endl;
        dmg=pl.atk*150/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        break;
        case 2 :
        cout<<"You Using "<<f_s2<<endl;
        my_ele=enemy_ele;
        dmg=pl.atk*110/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        my_ele=element[0];
        break;
        case 3 :
        cout<<"You Using "<<f_s3<<endl;
        dmg=pl.atk*800/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        cout<<"Your HP decrase to 1"<<endl;
        pl.hp=1;
        break;
    }
    getch();
}
void water_skill(){
    cout<<"=Giliran Kamu="<<endl;
    cout<<"1."<<w_s1<<"(dmg x150%)(water)"<<endl;
    cout<<"2."<<w_s2<<"(dmg x?%)(water)"<<endl;
    cout<<"3."<<w_s3<<"(dmg x120%)(netral)"<<endl;
    cout<<"Pilih Skill : ";cin>>pil;
    switch(pil){
        case 1 :
        cout<<"You Using "<<w_s1<<endl;
        dmg=pl.atk*150/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        break;
        case 2 :
        int rng;
        cout<<"You Using "<<w_s2<<endl;
        srand(time(0));
        rng=rand() % 1000;
        dmg=pl.atk*rng/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        break;
        case 3 :
        cout<<"You Using "<<w_s3<<endl;
        my_ele=enemy_ele;
        dmg=pl.atk*120/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        my_ele=element[1];
        break;
    }
    getch();
}
void earth_skill(){
    cout<<"=Giliran Kamu="<<endl;
    cout<<"1."<<e_s1<<"(dmg x150%)(earth)"<<endl;
    cout<<"2."<<e_s2<<"(dmg x110%)(netral)"<<endl;
    cout<<"3."<<e_s3<<"(heal 10% max hp)(support)"<<endl;
    cout<<"Pilih Skill : ";cin>>pil;
    switch(pil){
        case 1 :
        cout<<"You Using "<<e_s1<<endl;
        dmg=pl.atk*150/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        break;
        case 2 :
        cout<<"You Using "<<e_s2<<endl;
        my_ele=enemy_ele;
        dmg=pl.atk*110/100;
        kal_dmg();
        en.hp=en.hp-dmg;
        my_ele=element[2];
        break;
        case 3 :
        int heal;
        cout<<"You Using "<<e_s3<<endl;
        heal=pl.hp*10/100;
        pl.hp=pl.hp+heal;
        cout<<"Your HP restore "<<heal<<" Point"<<endl;
        break;
    }
    getch();
}
void battle_bot(){
    int ele;
    cout<<"Pilih Element Anda"<<endl;
    cout<<"1.Fire"<<endl
        <<"2.Water"<<endl
        <<"3.Earth"<<endl;
    cout<<"Pilihan : ";cin>>pil;
    switch(pil){
        case 1 :
        my_ele=element[0];
        pl.atk=pl.atk+100;
        pl.cc=pl.cc+20;
        pl.cd=pl.cd+50;
        system("cls");
        break;
        case 2 :
        my_ele=element[1];
        pl.hp=pl.hp+3000;
        pl.atk=pl.atk+50;
        pl.cc=pl.cc+30;
        system("cls");
        break;
        case 3 :
        my_ele=element[2];
        pl.hp=pl.hp+5000;
        pl.deff=pl.deff+200;
        pl.cd=pl.cd+75;
        system("cls");
        break;
    }
    cout<<"=status kamu="<<endl;
    cout<<"Hit Point="<<pl.hp<<endl
        <<"Attack="<<pl.atk<<endl
        <<"Deffens="<<pl.deff<<endl
        <<"Critical Chance="<<pl.cc<<endl
        <<"Critical Damage="<<pl.cd<<endl;
    getch();
    system("cls");
    srand(time(0));
    ele=rand() % 3;
    enemy_ele=element[ele];
    cout<<"Element Musuh adalah "<<enemy_ele<<endl;
    if(enemy_ele=="Fire"){
        en.atk=en.atk+100;
        en.cc=en.cc+20;
        en.cd=en.cd+50;
    }
    if(enemy_ele=="Water"){
        en.hp=en.hp+3000;
        en.atk=en.atk+50;
        en.cc=en.cc+30;
    }
    if(enemy_ele=="Earth"){
        en.hp=en.hp+5000;
        en.deff=en.deff+200;
        en.cd=en.cd+75;
    }
    getch();
    system("cls");
    battle :
    hp();
    if(pl.hp==0){
        cout<<"!!!!!YOU LOSE!!!!!!"<<endl;
        goto end;
    }
    if(my_ele=="Fire"){
        fire_skill();
    }
    if(my_ele=="Water"){
        water_skill();
    }
    if(my_ele=="Earth"){
        earth_skill();
    }
    system("cls");
    hp();
    if(en.hp==0){
        cout<<"!!!!!YOU WIN!!!!!!"<<endl;
        goto end;
    }
    if(enemy_ele=="Fire"){
        enemy_fire_skill();
    }
    if(enemy_ele=="Water"){
        enemy_water_skill();
    }
    if(enemy_ele=="Earth"){
        enemy_earth_skill();
    }
    system("cls");
    goto battle;
    end :
    getch();
    system("cls");
}
int main(){
    main :
    pl.atk=500,pl.deff=100,pl.cc=50,pl.cd=150,pl.hp=10000;
    en.atk=500,en.deff=250,en.cc=70,en.cd=200,en.hp=10000;
    cout<<"1.VS Bot"<<endl;
    cout<<"2.VS Player"<<endl;
    cout<<"3.Keluar"<<endl;
    cout<<"Masukan Pilihan : ";cin>>pil;
    switch(pil){
        case 1 :
        system("cls");
        battle_bot();
        goto main;
        break;
        case 2 :
        
        break;
        case 3 :
        return 0;
        break;
    }
}