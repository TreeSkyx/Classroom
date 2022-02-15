import java.util.Scanner;

public class Pro5_64010815 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Tax tax1 = new Tax();

        // Tax rates
        double[] rates = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};
        tax1.setRates(rates);

        // The brackets for each rate for all the filing statuses
        int[][] brackets = {
            {8350, 33950, 82250, 171550, 372950}, // Single filer
            {16700, 67900, 137050, 20885, 372950}, // Married jointly
                                                    // -or qualifying widow(er)
            {8350, 33950, 68525, 104425, 186475}, // Married separately
            {11950, 45500, 117450, 190200, 372950} // Head of household
        };
        tax1.setBrackets(brackets);

        /* User Input */
        System.out.println("Filing Status");
        System.out.println("[0]-Single filer");
        System.out.println("[1]-Married jointly or qualifying widow(er)");
        System.out.println("[2]-Married separately");
        System.out.println("[3]-Head of household");
        System.out.print("Enter the filing status: ");
        int status = getStatus();
		System.out.print("Enter the taxable income: ");
		double income = in.nextDouble();

        tax1.setFilingStatus(status);
        tax1.setTaxableIncome(income);

        System.out.println("Tax is " + tax1.getTax());
    }



    /* Returns a valid status */
	public static int getStatus(){
		Scanner in = new Scanner(System.in);
		int status;
		do {
			status = in.nextInt();
			if (status < 0 || status > 3)
				System.out.println("Error: invalid status!!!");
		} while (status < 0 || status > 3);
		return status;
	}
}
