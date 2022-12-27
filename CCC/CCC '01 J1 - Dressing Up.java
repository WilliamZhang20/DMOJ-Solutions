import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int height;
    Scanner ins = new Scanner(System.in);
    height = ins.nextInt();

    System.out.print("\n");
    for(int i=0; i<(height-1)/2; i++) {
      for(int j=0; j<2*i+1; j++) {
        System.out.print("*");
      }
      for(int j=0; j<2*height-4*i-2; j++) {
        System.out.print(" ");
      }
      for(int j=0; j<2*i+1; j++) {
        System.out.print("*");
      }
      System.out.print("\n");
    }
      
    //Print out middle row 
    for(int i=0; i<height*2; i++) {
      System.out.printf("*");
    }
    System.out.print("\n");
    
    for(int i=(height-1)/2-1; i>=0; i--) {
      for(int j=0; j<2*i+1; j++) {
        System.out.print("*");
      }
      for(int j=0; j<2*height-4*i-2; j++) {
        System.out.print(" ");
      }
      for(int j=0; j<2*i+1; j++) {
        System.out.print("*");
      }
      System.out.print("\n");
    }
  }
}
