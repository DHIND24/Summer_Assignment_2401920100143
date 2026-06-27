public class Point{
    private int x, y;
    public Point(){
        x = 0;
        y = 0;
    }
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    public void setX(int x){
        this.x = x;
    }
    public void setY(int y){
        this.y = y;
    }
    public void setXY(int x, int y){
        this.x = x;
        this.y = y;
    }
    public void display(){
        System.out.println("Point = (" + x + ", " + y + ")");
    }
    public static void main(String[] args){
        Point p1 = new Point();
        Point p2 = new Point(10, 20);

        System.out.println("Default Constructor:");
        p1.display();

        System.out.println("Parameterized Constructor:");
        p2.display();

        p1.setX(5);
        p1.setY(8);

        System.out.println("After setX() and setY():");
        p1.display();

        p2.setXY(15, 25);

        System.out.println("After setXY():");
        p2.display();
    }
}