//import scanner class which is use to take input from user
import java.util.Scanner;


//create class
public class Table{

//main function
public static void main(String[] args){

Scanner sc = new Scanner(System.in);

System.out.print("Enter a number which table you want to print : ");

//variable declare and taking input
int n = sc.nextInt();;

//fuunction calling
print_table(n);
}



//function which print table
public static void print_table(int n){

//using for loop for print the table from 1 to 10
for(int i=1;i<=10;i++){
System.out.println(n+"*"+i+"="+n*i);
}
}
}
