public class Senior extends Student{
    int l;
    int tired;
    public Senior(String n, int f, int r, int L){
        super(n, f, r);
        this.l = L;
        this.tired = 0;
        System.out.println("A new Senior student has been created!");
        print1();
    }
    public void print(){
        System.out.println("His/Her name is " + name + " and his/her tired grade was " + tired);
    }
    public void settired(int hours){
        this.tired += hours*(this.l);
    }
    public void attend(int hours){
        settired(hours);
    }
    public int gettired(){return this.tired;}
    public void print2(){
        System.out.println("His/Her name is " + name+ " and his/her class is in floor: "+ fl +" and room: "+ room);
        System.out.print("He/She ");
        if(gettired() == 0)
            System.out.print("was outside  of the classroom ");
        else
            System.out.print("was inside of the classroom ");
        System.out.println("and his/her tired grade was "+ tired);
    }

    
}
