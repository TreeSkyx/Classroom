import java.util.Scanner;

public class Pro1_64010815 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter name: ");
        String name = input.nextLine();

        System.out.print("Enter age: ");
        int age = input.nextInt();
        
        System.out.print("Enter weight(in pounds): ");
        double weight = input.nextDouble();

        System.out.println("Enter height:");
        System.out.print("feet: ");
        double feet = input.nextDouble();
        System.out.print("inches: ");
        double inches = input.nextDouble();

        BMI bmi = new BMI(name, age, weight, feet, inches);
        System.out.println("Your BMI is " + bmi.getBMI() + " -> " + bmi.checkBMI());
        

    }
}
