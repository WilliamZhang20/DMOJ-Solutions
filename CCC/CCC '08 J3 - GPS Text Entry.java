// CCC 2008 J3
import java.io.*;
import java.lang.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String s;
    int steps=0, a=0, b=0; // a and b are coordinates of initial position.
    char[][] grid = { {'A', 'B', 'C', 'D', 'E', 'F'}, {'G', 'H', 'I', 'J', 'K', 'L'}, {'M', 'N', 'O', 'P', 'Q', 'R'}, {'S', 'T', 'U', 'V', 'W', 'X'}, {'Y', 'Z', ' ', '-', '.', '*'} }; // grid is in multidimensional char array with enter being the asterisk. 
    s=getLine();
    for(int i=0; i<s.length(); i++) {
      for(int j=0; j<5; j++) {
        for(int k=0; k<6; k++) {
          if(s.charAt(i)==grid[j][k]) {
            steps+=Math.abs(j-a)+Math.abs(k-b); //Search for char in the grid and add num of steps needed.
            a=j;
            b=k;
          }
        }
      }
    }
    steps+=Math.abs(4-a)+Math.abs(5-b);
    System.out.println(steps);
  }

  public static String getLine() {
    try {
      return br.readLine();
    } catch(Exception e) {
      return "";
    }
  }
}
