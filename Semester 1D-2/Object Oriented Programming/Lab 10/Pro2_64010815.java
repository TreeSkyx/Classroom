import java.util.Scanner;

public class Pro2_64010815 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter Triangle's color: ");
        String color = input.next();

        System.out.print("Is the triangle filled? (true/false): ");
        boolean filled = input.nextBoolean();

        boolean repeatSideInput = true;
        do{
            System.out.print("Enter three side of the triangle: ");
            double side1 = input.nextDouble();
            double side2 = input.nextDouble();
            double side3 = input.nextDouble();
            try{
                Triangle triangle = new Triangle(side1,side2,side3);
                repeatSideInput = false;

                triangle.setColor(color);
                triangle.setFilled(filled);

                System.out.println(triangle.toString());
            }
            catch (IllegalTriangleException ex){
                System.out.println(ex.getMessage());
            }
        } while (repeatSideInput);

    }
}
