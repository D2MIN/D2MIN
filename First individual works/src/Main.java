import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Program is working");
        Point p1 = new Point();

        System.out.println("Input x");
        double x = input.nextDouble();
        System.out.println("Input y");
        double y = input.nextDouble();
        p1.setX(x);
        p1.setY(y);
        System.out.println(p1.toString());
        System.out.println(p1.getX());

        System.out.println("Input R");
        double radius = input.nextInt();
        Circle circle = new Circle(p1,radius);
        System.out.println(circle.toString());
        System.out.println("P = ");
        System.out.println(circle.P_Circle());
        System.out.println("S = ");
        System.out.println(circle.S_Circle());

        System.out.println("Input a");
        double a = input.nextDouble();
        System.out.println("Input b");
        double b = input.nextDouble();
        Ellipse ellipse = new Ellipse(a,b,circle);
        System.out.println(ellipse.toString());
        System.out.println("P = ");
        System.out.println(ellipse.P_Ellipse());
        System.out.println("S = ");
        System.out.println(ellipse.S_Ellipse());


    }
}