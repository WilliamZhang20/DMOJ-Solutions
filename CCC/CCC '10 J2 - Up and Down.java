// CCC 2010 J2
import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int a, b, c, d, s;
    int nikky, byron;
    // Take input
    a = getInt();
    b = getInt();
    c = getInt();
    d = getInt();
    s = getInt();

    nikky = (s/(a+b))*(a-b); 
    if (s%(a+b)<=a) {
      nikky+=s%(a+b);  
    }
    else {
      nikky+=a-(s%(a+b)-a);
    }
    byron = (s/(c+d))*(c-d);
    if (s%(c+d)<=a) {
      byron+=s%(c+d);
    }
    else {
      byron+=c-(s%(c+d)-c);
    }
    // Final check and printout
    if(nikky>byron) {
      System.out.println("Nikky");
    }
    else if (byron>nikky) {
      System.out.println("Byron");
    }
    else {
      System.out.println("Tied");
    }
  }

  public static int getInt() {
    try {
      return Integer.parseInt(br.readLine()); 
    } catch (Exception e) {
      return 0;
    }
  }
}
