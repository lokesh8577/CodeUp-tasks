//create class
public class Table{

//main function
public static void main(String[] args){


//variable declare
int n = 5;

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
