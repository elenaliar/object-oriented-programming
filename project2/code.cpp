#include <iostream>
#include <string>
#include "header.h"

using namespace std;

Student::Student(const string nam, int floor, int classroom){
    this->name  = nam;
    this->fl = floor;
    this->room = classroom;
    this->place = 0;
    cout << "A new Student has been created!"<< endl;
    cout <<"His/Her name is " << this->name << " his/her class details are: floor-" << this->fl << " class-" << this->room<< endl;
}

Student::~Student(){
        cout<< "A Student to be destroyed" << endl;
        cout <<"His/Her name is " << this->name << " his/her class details are: floor-" << this->fl << " class-" << this->room<< " , he/she was ";
        if(this->place == 1)
            cout <<"in the yard." << endl;
        else if (this->place == 2)
            cout <<"at the stairs."<< endl;
     else if (this->place == 3)
            cout <<"in the corridor."<< endl;
        else if (this->place == 4)
            cout <<"in classroom."<< endl;
        else if (this->place == 0)
            cout <<"outside of school."<< endl;
}

string Student::getname()const{
    return this->name;
}

int Student::getfl()const{
    return this->fl;
}

int Student::getroom()const{
    return this->room;
}

int Student::getplace()const{
    return this->place;
}


void Student::setplace(){
    (this->place)++;
}

void Student::prevplace(){
    (this->place)--;
}

Teacher::Teacher(const string nam, int floor, int classroom){
    this->name = nam;
    this->fl = floor;
    this->room = classroom;
    this->loc = 0;
    cout << "A new Teacher has been created!"<< endl;
    cout <<"His/Her name is " << this->name << " his/her class details are: floor-" << this->fl << " class-" << this->room<< endl;
}


Teacher::~Teacher(){
        cout<< "A Teacher to be destroyed" << endl;
        cout <<"His/Her name is " << this->name << " his/her class details are: floor-" << this->fl << " class-" << this->room<< " , he/she was ";
        if (this->loc == 0)
            cout<<"outside of the classroom" << endl;
        else if (this->loc == 1)
            cout <<"inside the classroom" << endl;
}


int Teacher::getfl()const{
    return this->fl;
}

int Teacher::getroom()const{
    return this->room;
}

void Teacher::setloc(){
    this->loc = 1;
}

string Teacher::getname()const{
    return this->name;
}

Yard::Yard(int max){
    this->Cyard = max;
    this->students_yard = 0;
    this->yard_array = new Student*[this->Cyard];
    for(int g=0; g<this->Cyard; g++)
        yard_array[g] = NULL;
    cout << "A yard has been created" << endl;
}

Yard::~Yard(){
    delete[] this->yard_array;
    cout <<"A Yard to be destroyed" << endl;
}

Stairs::Stairs(int max){
    this->Cstairs = max;
    this->students_stairs = 0;
    this->stairs_array = new Student*[this->Cstairs];
    for(int g=0; g<this->Cstairs; g++)
        stairs_array[g] = NULL;
    cout << "The Stairs have been created" << endl;
}

Stairs::~Stairs(){
    delete[] this->stairs_array;
    cout << "The Stairs to be destroyed" << endl;
}

Corridor::Corridor(int max){
    this->Ccorr = max;
    this->students_corr = 0;
    this->corr_array = new Student*[this->Ccorr];
    for(int g=0; g<this->Ccorr; g++)
        corr_array[g] = NULL;
    cout << "A Corridor has been created" << endl;
}

Corridor::~Corridor(){
    delete[] this->corr_array;
    cout << "A Corridor to be destroyed" << endl;
}

Classroom::Classroom(int max, int no){
    this->no_class = no;
    this->Cclass = max;
    this->students_class = 0;
    this->class_array = new Student*[this->Cclass];
    for(int g=0; g<this->Cclass; g++)
        class_array[g] = NULL;
    cout << "A class with number: "<< this->no_class << " has been created" << endl;
}

Classroom::~Classroom(){
    delete[] this->class_array;
    cout<< "A Class with number: "<< this->no_class<<" to be destroyed" << endl;
}

Floor::Floor(int maxclass, int maxcorr): Cor(maxcorr){
    for(int i=0; i<6; i++)
        C[i] = new Classroom(maxclass, i+1);
    cout<<"A Floor has been created" << endl;
}

Floor::~Floor(){
    cout <<"A Floor to be destroyed" << endl;
    for(int i=0; i<6; i++)
        delete C[i];
}

School::School(int maxstairs, int maxyard, int maxcorr, int maxclass): S(maxstairs), Y(maxyard){
    for(int i=0; i<3; i++)
        F[i] = new Floor(maxclass, maxcorr);
    cout << "A School has been created" << endl;
}

School::~School(){
    cout << "A School to be destroyed" << endl;
    for(int i=0; i<3; i++){
        delete F[i];
    }
}


int Corridor::corrfull(){
    if(this->students_corr < this->Ccorr)
        return 0;
    else
        return 1;   
}

int Classroom::classfull(){
    if (this->students_class < this->Cclass)
        return 0;
    else
        return 1;  
}

int Yard::yardfull(){//epistrefei 0 an xoraei kai allos mathitis na mpei sto yard
    if(this->students_yard <  this->Cyard)
        return 0;
    else
        return 1;
}
int Stairs::fullstairs(){
    if(this->students_stairs <  this->Cstairs)
        return 0;
    else
        return 1;
}
int School::stairsfull(){
    return S.fullstairs();
}
int Classroom::getflag()const{
    return this->flag;
}

int Floor::corridorfull(){
    return Cor.corrfull();
}

int School::fullyard(){
    return Y.yardfull();
}


Student* Corridor::getstudent()const{
    Student* s=NULL;
    int tmp = this->students_corr -1;
    if(tmp >= 0){
       s = (corr_array[tmp]);
    }
    return s;
}

Student* Stairs::getstudent()const{
    Student* s=NULL;
    int tmp = this->students_stairs -1;
    if(tmp >= 0){
        s =(stairs_array[tmp]);
    }
    return s;
    
}

void Yard::enter(Student& s){
    cout << s.getname() << " enters schoolyard!" << endl;
    s.setplace();
    if(this->students_yard<0)
        (this->students_yard)++;
    (yard_array[this->students_yard]) = (&s);
    (this->students_yard)++;
}
 
Student* Yard::exit(){
    Student* s=NULL;
    (this->students_yard)--;
    if(this->students_yard >= 0){
        s = (yard_array[this->students_yard]);
        yard_array[this->students_yard]  = NULL;
        cout << (*s).getname() << " exits schoolyard!" << endl;
    }
    return s;
}

void Stairs::enter(Student& s){
    cout << s.getname() << " enters stairs!" << endl;
    s.setplace();
    (stairs_array[this->students_stairs]) = (&s);
    (this->students_stairs)++;
}

Student* Stairs::exit(){
    Student* s=NULL;
    (this->students_stairs)--;
    if(this->students_stairs >= 0){
        s = (stairs_array[this->students_stairs]);
        stairs_array[this->students_stairs] = NULL;
        cout << (*s).getname() << " exits stairs!" << endl;
    }
    return s;
}

void Corridor::enter(Student& s){
    cout << s.getname() << " enters corridor!"  << endl;
    s.setplace();
    (corr_array[this->students_corr])= (&s);
    (this->students_corr)++;
}


void Floor::enter(Student& s){
            cout << s.getname() << " enters floor!" << endl;
            Cor.enter(s);
}

Student* Corridor::exit(){
    Student* s=NULL;
    (this->students_corr)--;
    s = (corr_array[this->students_corr]);
    corr_array[this->students_corr] = NULL;
    cout << (*s).getname() << " exits corridor!" << endl;
    return s;
}
void Stairs::setnum1(int vari){
    this->students_stairs = this->students_stairs - vari;
}

void Stairs::setnum2(int var){
    this->students_stairs = this->students_stairs + var;
}

void School::enterfl(){
    int var =1;
    Student* s2=NULL;
    s2 = (S.getstudent());
    int floor = (*s2).getfl();
    int st_num = S.getnum();
    while(S.getnum() !=0 && var<=st_num)
        if(!(*F[floor-1]).corridorfull()){
            s2 = (S.exit());
            floor = (*s2).getfl();
            (*F[floor-1]).enter(*s2);
        }
        else{
            Student* s3=NULL, *temporary=NULL;
            S.setnum1(var);
            s3 = (S.getstudent());
            S.setnum2(var);
            temporary = s3;
            s3 = s2;
            s2 = temporary;
            var++;
    }
}

void Classroom::enter(Student& s){
        cout << s.getname() << " enters classroom!"  << endl;
        s.setplace();
        (class_array[this->students_class])  = (&s);
        (this->students_class)++;
}

int Corridor::getnum()const{
    return this->students_corr;
}
void Corridor::setnum1(int var){
    this->students_corr = this->students_corr - var;
}

void Corridor::setnum2(int var){
    this->students_corr = this->students_corr + var;
}

void Floor::enterclass(){
    Student* s4=NULL;
    int variable=1, cor_num=0;
    cor_num= Cor.getnum();
    while(Cor.getnum() != 0 && variable<=cor_num){
        s4 = (Cor.getstudent());
        int room = (*s4).getroom();
        if ((!((*C[room-1]).getflag())) && (!(*C[room-1]).classfull())){
            s4 = (Cor.exit());
            (*C[room-1]).enter(*s4);
        }
        else{
            Student* temporary=NULL, *s3=NULL;
            Cor.setnum1(variable);
            s3 = (Cor.getstudent());
            Cor.setnum2(variable);
            temporary = s3;
            s3 = s4;
            s4 = temporary;
            variable++;
        }
    }
}

void School::enterclass(){
    for(int o=0; o<3; o++)
        (*F[o]).enterclass();
}

int Stairs::getnum()const{
    return this->students_stairs;
}

int Yard::getnum()const{
    return this->students_yard;
}

void School::enters(){
    int total =0;
    while(!S.fullstairs() && (Y.getnum() != 0)){
        Student* s1=NULL;
        (s1)  =  (Y.exit());
        S.enter(*s1);
        total++;
    }
}

void School::enter(Student& s){
        cout<< s.getname() << " enters school!" << endl;
        Y.enter(s);
}

//oi epomenes treis sinartiseis aforoun tin topothetisi daskalon stis takseis  tous
void Classroom::place(Teacher& t){
    T = &t;
    (*T).setloc();
    this->flag = 1;
}

void Floor::place(Teacher& t){
    int room = t.getroom();
    (*C[room-1]).place(t);
}

void School::place(Teacher& t){
    int floor = t.getfl();
    (*F[floor-1]).place(t);
}

//oi sinartiseis pou akolouthoun aforoun stin ektiposi tis sxolikis zois

void Stairs::print()const{
    cout<<"People in stairs are: ";
    for(int j=0; j<this->students_stairs; j++){
        Student* s=NULL;
        s = (stairs_array[j]);
        cout <<  (*s).getname() << ", ";
    }
    cout << endl;
}

void Yard::print()const{
    cout<< "People in schoolyard are: "<< endl;
    for(int j=0; j<this->students_yard; j++){
        Student* s=NULL;
        s = (yard_array[j]);
        cout<< (*s).getname() << ", ";
    }
    cout << endl;
}

void Corridor::print()const{
    cout << "People in corridor are: ";
    for(int m=0; m<this->students_corr; m++){
        Student* s=NULL;
        s = (corr_array[m]);
        cout<< (*s).getname() << ", ";
    }
    cout << endl;
}

void Classroom::print(int f)const{
    cout <<"People in class: "<< f << " are: ";
    for(int m=0; m<this->students_class; m++){
        Student* s=NULL;
        s = (class_array[m]);
        cout<< (*s).getname() << ", ";
    }
    cout << endl;
    if(this->flag == 1)
        cout << "The teacher is: "<< (*T).getname()<< endl;
    else
        cout <<"The teacher is not in the class" << endl;
}

void Floor::print(int l)const{
    cout << "Floor number: "<< l << " contains: "<< endl;
    Cor.print();
    for(int h=0; h<6; h++){
        (*C[h]).print(h+1);
    }
}

void School::print()const{
     cout << "School life consists of: " << endl;
    Y.print();
    S.print();
    for(int k=0; k<3; k++){
        (*F[k]).print(k+1);
    }
}