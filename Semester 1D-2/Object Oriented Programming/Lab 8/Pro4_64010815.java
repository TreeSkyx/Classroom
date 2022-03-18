public class Pro4_64010815 {
    public static void main(String[] args) throws CloneNotSupportedException {
        Octagon octagon1 = new Octagon(5);

        System.out.println("Octagon\nArea: " + octagon1.getArea());
        System.out.println("Perimeter: " + octagon1.getPerimeter());

        System.out.println("Cloning...");
        Octagon octagon2 = (Octagon)octagon1.clone();

        int compareReasult = (octagon1.compareTo(octagon2));

        if (compareReasult == 1)
			System.out.println("Octagon is greather than cloned octagon.");
		else if (compareReasult == -1)
			System.out.println("Octagon is less than cloned octagon"); 
		else
			System.out.println("Octagon is equal to cloned octagon");

    }
}
