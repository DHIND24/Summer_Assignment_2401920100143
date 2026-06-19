import java.util.Random;
abstract class Compartment{
    public abstract String notice();
}
class FirstClass extends Compartment{
    @Override
    public String notice(){
        return "Welcome To First-Class Coach";
    }
}
class Ladies extends Compartment{
    @Override
    public String notice(){
        return "Welcome To Ladies-Coach";
    }
}
class General extends Compartment{
    @Override
    public String notice(){
        return "Welcome To General-Coach";
    }
}
class Luggage extends Compartment{
    @Override
    public String notice(){
        return "This is Luggage-Coach";
    }
}
public class TestCompartment{
    public static void main(String[] args) {
        Compartment[] arr = new Compartment[10];
        Random r = new Random();
        for(int i=0; i<10; i++){
            int n = r.nextInt(4);
            n += 1;
            System.out.println("Generated Number: "+n );

            switch(n){
                case 1:
                    arr[i] = new FirstClass();
                    break;
                case 2:
                    arr[i] = new Ladies();
                    break;    
                case 3:
                    arr[i] = new General();
                    break;
                case 4:
                    arr[i] = new Luggage();
                    break;
            }
        }
        System.out.println("Compartments and thier notices: \n");
        for(int i=0; i<10; i++){
            System.out.println(arr[i].notice());
        }
    }
}