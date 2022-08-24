class Polygon{
    public void display(){
        System.out.println("in inner class");
    }
}
class Ademo{
    public void createClass(){
        Polygon p1 = new Polygon(){
            public void display(){
                System.out.println("in niming class");
            }
        };
        p1.display();
    }
}
public class MainClass{
    public static void main(String[] args){
        Polygon gon = new Polygon();
        gon.display();
        Ademo demo = new Ademo();
        demo.createClass();
    }
}
