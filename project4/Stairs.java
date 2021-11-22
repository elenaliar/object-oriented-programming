import java.util.Iterator;
import java.util.Vector;

class Stairs extends Space{
    public Stairs(){
        super();
        System.out.println("The Stairs have been created!");
    }
    public void enter (Student s){
        System.out.println(s.getname() + " enters stairs!");
        students.add(s);
    }
    public Student exit(){
        Student s = super.exit();
        System.out.println(s.getname() + " exits stairs!");
        return s;
    }
}

