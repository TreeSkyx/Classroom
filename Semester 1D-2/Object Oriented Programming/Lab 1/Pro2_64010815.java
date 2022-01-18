public class Pro2_64010815 {
    public static void main(String[] args) {
        double a = 3.4 , b = 50.2 , c =2.1 , d = 0.55 , e = 44.5 , f = 5.9; //  Number from equation
        /* Calculate the value of X */
        double x = ((e*d) - (b*f)) / ((a*d)-(b*c));
        /* Calculate the value of Y */
        double y = ((a*f) - (e*c)) / ((a*d)-(b*c)); 
         
        System.out.println("The Value of x is "+x);
        System.out.println("The Value of y is "+y);
    }
}
