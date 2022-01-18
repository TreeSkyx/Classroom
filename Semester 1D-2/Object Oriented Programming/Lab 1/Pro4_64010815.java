import java.text.DecimalFormat;
import java.util.Scanner;

public class Pro4_64010815 {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("##.####");
        Scanner input = new Scanner(System.in);
        System.out.print("Enter weight in pound: "); 

        /* Calculate weight in kilograms */
        double weight = (input.nextDouble() * 0.45359237);
        System.out.print("Enter height in inches: ");

        /* Calculate height in meters */
        double height = (input.nextDouble() * 0.0254);
        
        /* Calculate BMI */
        double BMI = weight / Math.pow(height, 2);
        System.out.print("BMI is " + df.format(BMI));
    }
}
