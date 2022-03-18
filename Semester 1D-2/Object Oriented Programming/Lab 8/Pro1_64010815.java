import java.util.Scanner;

public class Pro1_64010815 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.println("Enter triangle sides:");
            double side1 = in.nextDouble();
            double side2 = in.nextDouble();
            double side3 = in.nextDouble();

            if(side1 > 0 && side2 > 0 && side3 > 0){
            System.out.println("Enter a color:");
            String color = in.next();

            System.out.println("Wanna filled this triangle? (true/false):");
            boolean filled = in.nextBoolean();

            Triangle triangle = new Triangle(side1, side2, side3, color, filled);

            System.out.println(triangle);
            }
            else System.out.println("Error : triangle side shouldn't less than 0");
        }
    }
}
