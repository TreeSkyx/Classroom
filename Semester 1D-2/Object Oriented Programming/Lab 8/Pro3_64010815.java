public class Pro3_64010815 {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(4, 6, "sky blue", true);
        Rectangle r2 = new Rectangle(3.5, 8, "red", false);
        Rectangle r3 = new Rectangle(6, 4, "sky blue", true);

        System.out.println("Area of Rectangle \nRectangle1 Area :" + r1.getArea());
        System.out.println("Rectangle2 Area :" + r2.getArea());
        System.out.println("Rectangle3 Area :" + r3.getArea());

        System.out.println("\nCompared Result\nRectangle1 is " + (r1.equals(r2) ? "" : "not ") +
			"equal to Rectangle2");

		System.out.println("Rectangle1 is " + (r1.equals(r3) ? "" : "not ") +
			"equal to Rectangle3");

            System.out.println("Rectangle2 is " + (r2.equals(r3) ? "" : "not ") +
			"equal to Rectangle3");
    }

}
