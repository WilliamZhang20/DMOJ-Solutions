import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int a=0, b=0, c=0;
    String input;
    int[] printout = new int[1000];
    while(true) {
      input = getString();
      if(input.equals("7")) {
        break;
      }
      printout[c]=-50; //If nothing needs to be printed
      switch(input.charAt(0)) {
        case '1':
          // Assign value at index 4 to variable that has the name of index 2
          if(input.charAt(2)=='A') {
            a=Integer.parseInt(input.substring(4));
          } else {
            b=Integer.parseInt(input.substring(4));;
          }
          break;
        case '2':
          // Print value of variable at index 2
          if(input.charAt(2)=='A') {
            printout[c]=a;
          } else {
            printout[c]=b;
          }
          break;
        case '3':
          // 3 X Y means  calculate X+Y and store the value in variable X
          if(input.charAt(2)!=input.charAt(4)) {
            if(input.charAt(2)=='A') {
              a=a+b;
            } else {
              b=a+b;
            }
          } 
          else {
            if(input.charAt(2)=='A') {
              a=2*a;
            } else {
              b=2*b;
            }
          }
          break;
        case '4':
          // 4 X Y means calculate X×Y and store the value in variable X
          if(input.charAt(2)!=input.charAt(4)) {
            if(input.charAt(2)=='A') {
              a=a*b;
            } else {
              b=a*b;
            }
          } 
          else {
            if(input.charAt(2)=='A') {
              a=a*a;
            } else {
              b=b*b;
            }
          }
          break;
        case '5':
          // 5 X Y means calculate X−Y and store the value in variable X
          if(input.charAt(2)=='A' && input.charAt(4)=='B') {
            a=a-b;
          } else if(input.charAt(2)=='B' && input.charAt(4)=='A') {
            b=b-a;
          } else {
            if(input.charAt(2)=='A') {
              a=0;
            } else {
              b=0;
            }
          }
          break;
        case '6':
          // 6 X Y means calculate the quotient of XY and store the value in variable X as an integer, discarding the remainder
          if(input.charAt(2)!=input.charAt(4)) {
            if(input.charAt(2)=='A') {
              a=a/b;
            } else {
              b=b/a;
            }
          } 
          else {
            if(input.charAt(2)=='A') {
              a=1;
            } else {
              b=1;
            }
          }
          break;
        default:
          System.out.println("Wrong entry");
      }
      c++;
    }
    
    for(int i=0; i<c; i++) {
      if(printout[i] != -50) {
        System.out.println(printout[i]);
      }
    }
  }

  public static String getString() {
    try {
      return br.readLine();
    } catch(Exception e) {
      return "";
    }
  }
}
