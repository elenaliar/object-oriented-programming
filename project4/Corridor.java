import java.util.Iterator;
import java.util.Vector;

class Corridor extends Space{
    public  Corridor(){
        super();
        System.out.println("A new Corridor has been created!");
    }
    public void enter (Student s){
        System.out.println(s.getname() + " enters corridor!");
        students.add(s);
    }
    public Student exit(){
        Student s = super.exit();
        System.out.println(s.getname() + " exits corridor!");
        return s;
    }
}
