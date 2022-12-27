import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int num;
    Scanner In = new Scanner(System.in);
    num = In.nextInt();
    if(num == 1) {
      System.out.println("\n      *\n      *\n      *\n\n      *\n      *\n      *\n");
    }
    else if(num==2) {
      System.out.println(" * * *\n      *\n      *\n      *\n * * *\n*\n*\n*\n * * *");
    }
    else if(num==3) {
      System.out.println(" * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n      *\n * * *");
    }
    else if(num==4) {
      System.out.println("\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n");   
    }
    else if(num==5) {
      System.out.println(" * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *");
    }
    else if(num==6) {
      System.out.println(" * * *\n*\n*\n*\n * * *\n*     *\n*     *\n*     *\n * * *");
    }
    else if(num==7) {
      System.out.println(" * * *\n      *\n      *\n      *\n\n      *\n      *\n      *\n");
    }
    else if(num==8) {
      System.out.println(" * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     *\n*     *\n * * *");
    }
    else if(num==9) {
      System.out.println(" * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *");
    }
    else if(num==0) {
      System.out.println(" * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     *\n * * *");
    }
  }
}
