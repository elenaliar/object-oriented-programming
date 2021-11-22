import java.util.Iterator;
import java.util.Vector;

class School extends Space{
    int  max_class;
    Yard Y;
    Stairs S;
    Floor[] F;
    public School(int cclass){
        super();
        this.max_class = cclass;
        Y = new Yard();
        S = new Stairs();
        F = new Floor[3];
        for(int i=0; i<3; i++)
            F[i] = new Floor(cclass, i+1);
        System.out.println("A new School has been created!\n");
    }
    public void place(Teacher t){
        int fl = t.getfl();
        F[fl-1].place(t);
    }
    public void print(){
        System.out.println("School life consists of: ");
        for(int i=0; i<3; i++)
            F[i].print();
    }
    public void operate(int hours){
        for(int i=0; i<3; i++){
            F[i].operate(hours);
        }
    }
    public void enter(Student s){
        System.out.println(s.getname() +  " enters school!");
        Y.enter(s);
        Student s2 = Y.exit();
        S.enter(s2);
        s2 = S.exit();
        int fl = s2.getfl();
        F[fl-1].enter(s2);
    }
    public void empty(){
        for(int i=0; i<3; i++){
            for(int j=0; j<6; j++){
                for(int k=0; k<this.max_class; k++){
                    Student s = F[i].Cl[j].exit();
                    F[i].C.enter(s);
                    s = F[i].C.exit();
                    System.out.println(s.getname() + " exits floor!");
                    S.enter(s);
                    s = S.exit();
                    Y.enter(s);
                    s = Y.exit();
                    System.out.println(s.getname() + " exits school!");
                    System.out.println("\n");
                }
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<6; j++){
                F[i].Cl[j].teacher_out();
            }
        }
    }
}
