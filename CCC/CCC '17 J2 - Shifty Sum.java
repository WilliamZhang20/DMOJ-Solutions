import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int n, k; 
    long out=0;
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    k = in.nextInt();
    out=n;
    for(int i=0; i<k; i++) {
      n*=10;
      out+=n;
    }
    System.out.println(out);
  }
}
