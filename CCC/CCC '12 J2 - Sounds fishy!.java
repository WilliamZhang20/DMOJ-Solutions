import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);
  public static void main(String[] args) {
    int a = getInt();
    int b = getInt();
    int c = getInt();
    int d = getInt();
    if(d>c && c>b && b>a) {
      System.out.println("Fish Rising");
    }
    else if(a>b && b>c && c>d) {
      System.out.println("Fish Diving");
    }
    else if(a==b && b==c && c==d) {
      System.out.println("Fish At Constant Depth");
    }
    else {
      System.out.println("No Fish");
    }
  }
  public static int getInt() {
    try
    {
      return Integer.parseInt(br.readLine());
    }
    catch (Exception e)
    {
      return 0;
    }
  }
}
