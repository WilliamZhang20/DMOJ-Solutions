// CCC 2009 S1
import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);
  
  public static void main(String[] args) {
    int a, b, count=0;
    a=getInt();
    b=getInt();
    for(int i=a; i<=b; i++) {
      if(isPerfectSquare(i) && isPerfectCube(i)) {
        count++;
      }
    }
    System.out.println(count);
  }

  public static boolean isPerfectSquare(int n) {
    double sqrtN=Math.sqrt(n);
    return (sqrtN - Math.floor(sqrtN)==0);
  }

  public static boolean isPerfectCube(int x) {
    double cbrtx=Math.cbrt(x);
    return (cbrtx - Math.floor(cbrtx)==0);
  }

  public static int getInt() {
    try {
      return Integer.parseInt(br.readLine()); 
    } catch (Exception e) {
      return 0;
    }
  }
}
