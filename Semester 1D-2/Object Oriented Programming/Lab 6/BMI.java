public class BMI {
    private String name;
    private int age;
    private double weight;
    private double height;
    public static final double KgToLb = 0.45359237;
    public static final double MeToIn = 0.0254;

    
    public BMI(String name, int age, double weight, double height){
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = height;
    }

    // Construct a BMI with the specified name, age, weight, feet, and inches
    public BMI(String name, int age, double weight, double feet, double inches){
        this(name, age, weight, inches + feet * 12);
    }

    public double getBMI(){
        double bmi = weight * KgToLb /  ((height * MeToIn) * (height * MeToIn));
        return Math.round(bmi * 100) / 100.0;
    }

    public String checkBMI(){
        double bmi = getBMI();
        if(bmi < 18.5){
            return "Underweight";
        }
        else if (bmi >= 18.5 && bmi < 25){
            return "Normal";
        }
        else if (bmi >= 25 && bmi < 30){
            return "Overweight";
        }
        else {
            return "Obese";
        }
    }

    public String getName(){
        return name;
    }

    public int getAge(){
        return age;
    }

    public double getWeight(){
        return weight;
    }

    public double getHeight(){
        return height;
    }

}
