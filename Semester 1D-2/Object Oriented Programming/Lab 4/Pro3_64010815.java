public class Pro3_64010815 {
    public static void main(String[] args) {
        Stopwatch stopwatch = new Stopwatch();
        /* Create Array and Sorting */

        // Create Array
        double[] randomList = createArrray();
        System.out.println("Sorting stopwatch start...");

        stopwatch.start(); // Start stopwatch

        selectionSort(randomList); // Sorting Func.

        /* Display Sorted Array*/
        int count = 0;
        for(int i=0;i < randomList.length;i++){
            double r = (double)(Math.round(randomList[i]*100.0d)/100.0d);
            if(count <= 4 ){
                System.out.print("   "+r);
            }
            else{
                System.out.println(" ");
                count=0;
            }
        count++;
        }

        stopwatch.stop(); // Stop stopwatch
        System.out.println("\nSorting stopwatch stopped.");
        // display the ElapsedTime
        System.out.println("The sort time is "+stopwatch.getElapsedTime()+" milliseconds."); 

        System.out.println("------------------------------------------------------------"); // breaker

        /* Create PalindromePrime */
        System.out.println("The palindromPrime stopwatch starts...");

        stopwatch.start();  // Start stopwatch

        // Create PalindromePrime and Display the ElapsedTime
        if(createPalinPrime()){
            stopwatch.stop();
            System.out.println("The palindromPrime time is "+stopwatch.getElapsedTime()+" milliseconds.");
        }

    }
    /* Create Array */
    public static double[] createArrray() {
        System.out.println("Creating a list contain 1000 elements,");

        double[] array  = new double[1000];
        int count = 1;
        for(int i=0;i < array.length;i++){
            array[i] = (double)(Math.random()*1000); //random number in array
            double r = (double)(Math.round(array[i]*100.0d)/100.0d); //format to .2 
            if(count <= 4 ){
                System.out.print("   "+r);
            }
            else{
                System.out.println(" "); //line checker
                count=0;
            }
        count++;
        }
        System.out.println("List created.");    
        return array; 
    }
    /* Selection Sort Function */
    public static void selectionSort(double[] array) {
		for (int i = 0; i < array.length - 1; i++) {
			double min = array[i];
			double minIndex = i;

			for (int j = i + 1; j < array.length; j++) {
				if (array[j] < min) {
					min = array[j];
					minIndex = j;
				}
			}

			if (i != minIndex) {
				array[(int) minIndex] = array[i];
				array[i] = min;
			}
		}
	} 
    /* Create PalindromePrime Function */
    public static boolean createPalinPrime() {
        boolean finish = false; // checker

        System.out.println("Creating 100 PalindromePrime...");

        int n=0,num=1;
        while(n<100){
            int temp,r,sum=0,count=0;
            temp = num;
            /* Check for the prime number */
            for(int i=1;i<=temp;i++){
                if(temp%i==0){
                    count++;
                }
                if(count>2) continue; //skip if number isn't the prime number
            }
            /* Check for the palindome number*/
            while(num>0){
                r = num%10;
                sum = (sum*10)+r;
                num=num/10;
            }
            /* Print Palindome prime number */
            if(temp==sum && count==2){
                System.out.print(temp+" ");
                n++;
                if(n%10==0){
                    System.out.println(" ");
                }
            }
            num = temp; //return number for next loop
            num++; // move to next number
        }
        finish = true; // return when finish
        System.out.println("PalindromePrime created.");
        return finish;
    }
}