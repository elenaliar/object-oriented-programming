

abstract class Student extends Person{
    public Student(String n, int f, int r){
        super(n, f, r);
    }
    abstract public void print();
    abstract public void attend(int hours);
}
