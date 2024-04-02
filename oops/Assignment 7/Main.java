import java.util.*;

class Player
{
    String name,type;
    int age;
    public Player(int age,String name,String type)
    {
        this.age=age;
        this.name=name;
        this.type=type;
    }
}
class CricketPlayer extends Player
{
    int runs;
    CricketPlayer(int age,String name,String type,int runs)
    {
        super(age,name,type);
        this.runs=runs;
        System.out.println("\nCricket---");
        System.out.println("Player name is:"+name);
        System.out.println("Player age is:"+age);
        System.out.println("Player type is:"+type);
        System.out.println("Runs scored by the Player:"+runs);
    }
}
class FootballPlayer extends Player
{
    int goal;
    FootballPlayer(int age,String name,String type,int goal)
    {
        super(age,name,type);
        this.goal=goal;
        System.out.println("\nFootball---");
        System.out.println("Player name is:"+name);
        System.out.println("Player age is:"+age);
        System.out.println("Player type is:"+type);
        System.out.println("Goals scored by the Player:"+goal);
    }
}
class HockeyPlayer extends Player
{
    int hg;
    HockeyPlayer(int age,String name,String type,int hg)
    {
        super(age,name,type);
        this.hg=hg;
        System.out.println("\nHockey---");
        System.out.println("Player name is:"+name);
        System.out.println("Player age is:"+age);
        System.out.println("Player type is:"+type);
        System.out.println("Goals scored by the Player:"+hg);
    }
}
public class Main
{
    public static void main(String args[])
    {
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Name of the Cricket player:");
        String cname=sc.next();
        System.out.println("Enter the age of the player:");
        int cage=sc.nextInt();
        System.out.println("Enter the type of player:");
        String ctype=sc.next();
        System.out.println("Enter the runs scored by player:");
        int runs=sc.nextInt();
    
        System.out.println("Enter the Name of the Football player:");
        String fname=sc.next();
        System.out.println("Enter the age of the player:");
        int fage=sc.nextInt();
        System.out.println("Enter the type of player:");
        String ftype=sc.next();
        System.out.println("Enter the Goals scored by player:");
        int fgoals=sc.nextInt();
    
        System.out.println("Enter the Name of the Hockey player:");
        String hname=sc.next();
        System.out.println("Enter the age of the player:");
        int hage=sc.nextInt();
        System.out.println("Enter the type of player:");
        String htype=sc.next();
        System.out.println("Enter the Goals scored by player:");
        int hgoals=sc.nextInt();

        CricketPlayer p1=new CricketPlayer(cage,cname,ctype,runs);
        FootballPlayer p2=new FootballPlayer(fage,fname,ftype,fgoals);
        HockeyPlayer p3=new HockeyPlayer(hage,hname,htype,hgoals);
    }
}