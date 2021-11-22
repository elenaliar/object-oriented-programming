public abstract class Person{
    String name;
    int fl, room;
    int inside;
    public Person(String n, int f, int r){
        this.name = n;
        this.fl = f;
        this.room = r;
        this.inside = 0;
    }
    public String getname(){return this.name;}
    public int getfl(){return this.fl;}
    public int getroom(){return this.room;}
    public int isinside(){return this.inside;}
    public void setinside(){this.inside =1;}
    public void notinside(){this.inside =0;}
    public void print1(){
        System.out.println("His/Her name is "  + name +  " and his/her class is in floor: "+ fl + " and room: "+ room);
    }
    abstract public void print();
}