import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    short trout, pike, pickerel;
    int limit, combos=0;
    Scanner in = new Scanner(System.in);
    trout = in.nextShort();
    pike = in.nextShort();
    pickerel = in.nextShort();
    limit = in.nextInt();
    for(int i=0; i<=limit; i++) {
      for(int j=0; j<=limit; j++) {
        for(int k=0; k<=limit; k++) {
          if(trout*i+pike*j+pickerel*k<=limit && (i!=0 || j!=0 || k!=0)) {
            combos++;
            System.out.printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", i, j, k);
          }
        }
      }
    }
    System.out.printf("Number of ways to catch fish: %d\n", combos);
  }
}
