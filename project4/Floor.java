import java.util.Iterator;
import java.util.Vector;

class Floor extends Space{
    int num;
    Corridor C;
    Classroom[] Cl;
    public Floor(int cclass, int n){
        super();
        this.num = n;
        Cl = new Classroom[6];
        for(int i=0; i<6; i++)
            Cl[i] = new Classroom(cclass, i+1);
        C = new Corridor();
        System.out.println("A new Floor has been created!");
    }
    public void place(Teacher t){
        int room = t.getroom();
        t.setinside();
        Cl[room-1].place(t);
    }
    public void operate(int hours){
        for(int i=0; i<6; i++)
            Cl[i].operate(hours);
    }
    public void enter(Student s){
        System.out.println(s.getname() + " enters floor!");
        C.enter(s);
        Student s2 = C.exit();
        int room = s2.getroom();
        Cl[room-1].enter(s2);
    }
    public void print(){
        System.out.println("Floor " + this.num + " contains: ");
        for(int i=0; i<6; i++)
            Cl[i].print();
    }
}