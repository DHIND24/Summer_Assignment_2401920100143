class Box{
    double length, breadth;
    Box(){
        length = 0; 
        breadth = 0;
    }
    Box(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }
    public void setValues(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }
    public void area(){
        System.out.println("Area = " + (length * breadth));
    }
}
class Box3D extends Box{
    double height;
    Box3D(){
        height = 0;
    }
    Box3D(double length, double breadth, double height){
        super(length, breadth);
        this.height = height;
    }
    public void setValues(double length, double breadth, double height){
        super.setValues(length, breadth);
        this.height = height;
    }
    public void volume(){
        System.out.println("Volume = " + (length * breadth * height));
    }
}

public class BoxDemo{
    public static void main(String[] args){
        Box b1 = new Box(10, 5);
        b1.area();
        
        Box3D b2 = new Box3D(10, 5, 4);
        b2.area();
        b2.volume();
    }
}