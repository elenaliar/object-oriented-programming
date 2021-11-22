#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    int cyard, cstairs, ccorr, cclass;
    cclass = atoi(argv[1]);
    cyard = atoi(argv[2]);
    cstairs = atoi(argv[3]);
    ccorr = atoi(argv[4]);

    //dimiourgia sxoleiou
    School S(cstairs, cyard, ccorr, cclass);

    //dimiougia mathiton kai daskalon
    Student** s_array = new Student*[cclass*18];
    for(int y=0; y<(cclass*18); y++)
        s_array[y] = NULL;
    Teacher** t_array = new Teacher*[18];
    for(int y=0; y<18; y++)
        t_array[y] = NULL;

    string name, occupation;
    string s = "student";
    string t = "teacher";
    int fl, room;
    int cnt=0, counter=0;
    do{
        cin >> occupation;
        cin >> name;
        cin >> fl;
        cin >> room;
        if(!cin.fail()){
            if(occupation == s){
                s_array[cnt] = new Student(name, fl, room);
                cnt++;
            }
            else if(occupation == t){
                t_array[counter] = new Teacher(name, fl,  room);
                counter++;
            }
        }
    }while(!cin.fail());

    //topothetisi mathiton kai daskalon
    counter--; 
    int sum=18, amount_t;
    while(cnt>0){
        while(!S.fullyard() && cnt>0){
            cnt--;
            S.enter(*s_array[cnt]);
        }
        S.enters();
        S.enterfl();
        S.enterclass();
        //o elegxos ginetai afou osoi mathites iparxoun mesa sto sxoleio exoun ftasei mexri to pio makrino simeio sto opoio xorane na pane
        if((S.stairsfull() == 1) && (S.fullyard() == 1))//molis gemisoun ta stiars kai to yard stamataei i eisagogi kathigiton/mathiton
            break;
        int random = rand()%(2);//edo elegxoume an tha mpei kathigitis random=1
            if(random != 0){
                if(sum > 0) 
                    amount_t = rand()%(sum);//edo ipologizoume posoi kathigites tha mpoun
                if(amount_t != 0  && counter>=0){
                    for(int j=0; j< amount_t; j++){
                        S.place(*t_array[counter]);
                        counter--;
                        sum--;
                    }
                }
            }
    }

    //ektiposi sxolikou ktiriou
    cout << endl;
    S.print();
    cout << endl;
    
    for(int d=0; d<18; d++)
        delete t_array[d];
    delete[] t_array;
    for(int d=0; d<(cclass*18); d++)
        delete s_array[d];
    delete[] s_array;
    return 0;
}
