import java.util.Iterator;
import java.util.Vector;

class Yard extends Space{
    public Yard(){
        super();
        System.out.println("The Yard has been created!");
    }
    public void enter (Student s){
        System.out.println(s.getname() + " enters yard!");
        students.add(s);
    }
    public Student exit(){
        Student s = super.exit();
        System.out.println(s.getname() + " exits yard!");
        return s;
    }
}