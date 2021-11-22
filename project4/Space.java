import java.util.Vector;

abstract class Space{
    protected Vector <Student> students;
    public Space(){
        students = new Vector <Student>();
    }
    abstract public void enter(Student s);
    public Student exit(){
        return students.remove(students.size()-1);
    }
}