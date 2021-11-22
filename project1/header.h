#include <string>
using namespace std;

class Student{
        string name;
        int fl, room;//stoixeia taksis
        int place;//1-yard, 2-stairs, 3-corridor, 4-classroom, 0-ektos ktiriou
    public:
        Student(const string name, int floor, int classroom);
        ~Student();
        string getname()const;
        int getfl()const;
        int getroom()const;
        int getplace()const;
        void setplace();
        void prevplace();
};


class Teacher{
        string name;
        int fl, room;//stoixeia taksis
        int loc; // location 0-ekso, 1-mesa
    public:
        Teacher(const string nam, int floor, int classroom);
        ~Teacher();
        int getfl()const;
        int getroom()const;
        string getname()const;
        void setloc();
};

class Yard{
        int Cyard;//max arithmos foititon sto yard
        int students_yard;//posoi briskontai sto yard mia sigekrimeni stigmi
        Student** yard_array;
    public:
        Yard(int max);
        ~Yard();
        int yardfull();//epistrefei 0 an iparxei xoros
        void enter(Student &s);
        Student* exit();
        void print()const;
        int getnum()const;
};


class Stairs{
        int Cstairs;
        int students_stairs;
        Student** stairs_array;
    public:
        Stairs(int max);
        ~Stairs();
        void enter(Student& s);
        Student* exit();
        Student* getstudent()const;
        int getnum()const;
        void setnum1(int vari);
        void setnum2(int vari);
        void print()const;
        int fullstairs();
};

class Corridor{
        int Ccorr;
        Student** corr_array;
        int students_corr;
    public:
        Corridor(int max);
        ~Corridor();
        int corrfull();
        void enter(Student& s);
        Student* exit();
        Student* getstudent()const;
        int getnum()const;
        void setnum1(int var);
        void print()const;
        void setnum2(int var);
};

class Classroom{
        int no_class;//arithmos tis taksis  se sigekrimeno orofo times apo 1-6
        int Cclass;
        Teacher* T;
        int flag; //an flag=0 o daskalos einai ektos, an flag=1 tote einai mesa
        Student **class_array;
        int students_class;
    public:
        Classroom(int max, int no);
        ~Classroom();
        int classfull();
        void enter(Student& s);
        void place(Teacher& t);
        int getflag()const;
        void print(int f)const;
};

class Floor{
        Classroom *C[6];
        Corridor Cor;
    public:
        Floor(int maxclass, int maxcorr);
        ~Floor();
        void enter(Student& s);
        void place(Teacher& t);
        int corridorfull();
        void enterclass();
        void print(int l)const;
};

class School{
        Yard Y;
        Stairs S;
        Floor *F[3];
    public:
        School(int maxstairs, int maxyard, int maxcorr, int maxclass);
        ~School();
        int enter(Student** s_array, int cnt);//epistrefei tin nea timi tou cnt afou exei meiothei meta tis eisagoges ton mathiton
        void enter(Student &s);
        void enters();
        void enterfl();
        void enterclass();
        int fullyard();
        void place(Teacher& t); 
        void print()const;
        int stairsfull();
};

