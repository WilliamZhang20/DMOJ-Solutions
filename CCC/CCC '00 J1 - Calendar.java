// CCC 2000 J1
import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String input = getString();
    int firstDay = Integer.parseInt(input.substring(0, 1));
    int numOfDays = Integer.parseInt(input.substring(2));
    int j=firstDay; // This helps keep track of day of week for moving to new line
    System.out.println("Sun Mon Tue Wed Thr Fri Sat");
    for(int i=1; i<=firstDay*4-2; i++) {
      System.out.print(" ");
    }
    for(int i=1; i<=numOfDays; i++) {
      if((i+(firstDay-1))%7==0) { // If at end of week
        if(i>=9) {
          if(i==numOfDays) {
            System.out.println(i); // End of week and end of program
          } else {
            System.out.print(i+"\n ");
          }
        } else {
          System.out.print(i+"\n  ");
        }
      } else {
        if(i>=9) {
          if(i==numOfDays) {
            System.out.print(i+"\n"); // End of program
          } else {
            System.out.print(i+"  ");
          }
        } else {
          System.out.print(i+"   ");
        }
      }
    }
  }

  public static String getString() {
    try {
      return br.readLine();
    } catch (Exception e) {
      return "";
    }
  }
}
