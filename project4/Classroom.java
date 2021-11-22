import java.util.Iterator;
import java.util.Vector;

class Classroom extends Space{
    int num;
    int max;
    Teacher t;
    public Classroom(int cclass, int n){
        super();
        this.num = n;
        this.max = cclass;
        System.out.println("A new Classroom has been created!");
    }
    public void enter (Student s){
        System.out.println(s.getname() + " enters classroom!");
        s.setinside();
        students.add(s);
    }
    public void print(){
        System.out.println("People in class " + num +" are:");
        Iterator<Student> iterate = students.iterator();
        while(iterate.hasNext()) {
            Student s = (iterate.next());
            s.print();
        }
        System.out.println("The teacher is: ");
        t.print();
    }
    public void place(Teacher t){
        t.setinside();
        this.t = t;
    }
    public void operate(int hours){
        Iterator<Student> iterate = students.iterator();
        while(iterate.hasNext()) {
            Student s = (iterate.next());
            s.attend(hours);
        }
        t.teach(hours);
    }
    public int getstudents(){return students.size();}
    public Student exit(){
        Student s = super.exit();
        System.out.println(s.getname() + " starts exiting!");
        System.out.println(s.getname() + " exits classroom!");
        s.notinside();
        return s;
    }
    public void teacher_out(){
        this.t.notinside();
        this.t.print2();
        System.out.println(t.getname() + " teacher is out!");
        this.t = null;
        System.out.print("\n");
    }
}