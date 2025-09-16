import java.util.Scanner;
public class table {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = 0, range = 0;
	while(true){
        System.out.print("Enter the number: ");
        if (sc.hasNextInt()) {
            number = sc.nextInt();
	break;
        } else {
            System.out.println("Enter number value only!");
            sc.next();
        }
}
   	while(true){
        System.out.print("Enter the range: ");
        if (sc.hasNextInt()) {
            range = sc.nextInt();
            break;
        } else {
            System.out.println("Enter number value only!");
            sc.next();
        }
    }
    

        System.out.println("\nMultiplication Table of " + number + " up to " + range + ":");
        for (int i = 1; i <= range; i++) {
            System.out.println(number + " x " + i + " = " + (number * i));
        }


       sc.close();
}
}
