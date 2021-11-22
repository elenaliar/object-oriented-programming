import java.util.Scanner;
import java.util.Vector;
import java.lang.Math; 


class Main{
    public static void main(String[] args){
        int Cclass, Ls, Lj, Lt, N;
        String s = "student";
        String t = "teacher";
        String tp = "senior";
        String occupation, name;
        int fl, room;
        Vector <Student> s_array = new Vector <Student>();
        Vector <Teacher> t_array = new Vector <Teacher>();
        Cclass = Integer.parseInt(args[0]);
        Lj = Integer.parseInt(args[1]);
        Ls = Integer.parseInt(args[2]);
        Lt = Integer.parseInt(args[3]);
        N = Integer.parseInt(args[4]);

        //dimiourgia sxoleiou
        School S = new School(Cclass);

        //dimiourgia mathiton/daskalon
        s_array.add(new Senior("maria", 1, 5, Ls));
        t_array.add(new Teacher("tom", 2, 4, Lt));
        t_array.add(new Teacher("paul", 2, 1, Lt));
        s_array.add(new Junior("noah", 1, 1, Lj));
        s_array.add(new Junior("liam", 2, 2, Lj));
        t_array.add(new Teacher("mairi", 1, 2, Lt));
        s_array.add(new Senior("anna", 3, 4, Ls));
        t_array.add(new Teacher("john", 1, 3, Lt));
        t_array.add(new Teacher("fred", 1, 4, Lt));
        s_array.add(new Junior("liz", 3, 3, Lj));
        s_array.add(new Junior("david", 3, 2, Lj));
        t_array.add(new Teacher("xristina", 3, 1, Lt));
        t_array.add(new Teacher("panagiotis", 1, 5, Lt));
        t_array.add(new Teacher("sia", 3, 6, Lt));
        s_array.add(new Junior("logan", 3, 1, Lj));
        t_array.add(new Teacher("maritini", 3, 3, Lt));
        t_array.add(new Teacher("elena", 2, 2, Lt));
        t_array.add(new Teacher("stavros", 1, 1, Lt));
        t_array.add(new Teacher("nick", 2, 3, Lt));
        t_array.add(new Teacher("chris", 3, 2, Lt));
        t_array.add(new Teacher("andreas", 2, 6, Lt));
        s_array.add(new Junior("luke", 2, 1, Lj));
        s_array.add(new Junior("joseph", 1, 2, Lj));
        s_array.add(new Junior("sofia", 1, 3, Lj));
        t_array.add(new Teacher("george", 1, 6, Lt));
        t_array.add(new Teacher("stratos", 2, 5, Lt));
        t_array.add(new Teacher("niki", 3, 5, Lt));
        t_array.add(new Teacher("ifi", 3, 4, Lt));
        s_array.add(new Junior("scarlett", 1, 3, Lj));
        s_array.add(new Senior("elena", 3, 6, Ls));
        s_array.add(new Senior("katerina", 2, 5, Ls));
        s_array.add(new Senior("will", 3, 5, Ls));
        s_array.add(new Junior("chloe", 2, 3, Lj));
        s_array.add(new Junior("mia", 1, 1, Lj));
        s_array.add(new Senior("jacob", 1, 6, Ls));
        s_array.add(new Senior("harper", 1, 4, Ls));
        s_array.add(new Junior("emily", 2, 2, Lj));
        s_array.add(new Senior("avery", 2, 6, Ls));
        s_array.add(new Senior("oliver", 2, 4, Ls));
        s_array.add(new Senior("dan", 2, 4, Ls));
        s_array.add(new Senior("ben", 3, 6, Ls));
        s_array.add(new Junior("amelia", 3, 3, Lj));
        s_array.add(new Junior("madison", 3, 1, Lj));
        s_array.add(new Senior("ava", 2, 6, Ls));
        s_array.add(new Senior("ella", 3, 4, Ls));
        s_array.add(new Senior("alex", 3, 5, Ls));
        s_array.add(new Senior("mike", 2, 5, Ls));
        s_array.add(new Junior("ethan", 3, 2, Lj));
        s_array.add(new Junior("elijah", 2, 1, Lj));
        s_array.add(new Senior("rachel", 1, 4, Ls));
        s_array.add(new Senior("jim", 1, 5, Ls));
        s_array.add(new Junior("matthew", 2, 3, Lj));
        s_array.add(new Senior("pam", 1, 6, Ls));
        s_array.add(new Junior("emma", 1, 2, Lj));
        
        //eisagogi mathiton/daskalon sto sxoleio
        int students = s_array.size();//sinolikos arithmos mathiton
        int teachers=t_array.size();//sinolikos arithmon daskalon
        while(students>0 || teachers>0){
            int random1 = (int) (Math.random() * (students + 1)) + 0;//posoi mathites tha mpoun se auti tin epanalipsi
            int random2 = (int) (Math.random() * (teachers + 1)) + 0;//posoi daskaloi tha mpoun se ayti tin epanalipsi
            while(random1>0){
                S.enter(s_array.get(students-1));
                System.out.println("\n");
                random1--;
                students--;
            }
            while(random2>0){
                S.place(t_array.get(teachers-1));
                random2--;
                teachers--;
            }
        }

        S.operate(N);
        S.print();
        S.empty();
    }
}