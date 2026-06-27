import java.util.Scanner;
interface test{
    void square();
}
class Arithmetic implements test{
    int num;
    Arithmetic(Scanner sc){
        System.out.print("Enter a number: ");
        num = sc.nextInt();
    }
    @Override
    public void square(){
        System.out.println("Square = " + (num * num));
    }
}
public class ToTestInt{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Arithmetic obj = new Arithmetic(sc);
        obj.square();
        sc.close();
    }
}