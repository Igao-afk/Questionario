import java.util.Scanner;

public class exercicio2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        System.out.print("Digite um número para verificar se pertence à sequência de Fibonacci: ");
        int numero = scanner.nextInt();

       
        scanner.close();

      
        if (verificarFibonacci(numero)) {
            System.out.println(numero + " pertence à sequência de Fibonacci.");
        } else {
            System.out.println(numero + " não pertence à sequência de Fibonacci.");
        }
    }

    
    public static boolean verificarFibonacci(int n) {
        if (n < 0) return false;

        int a = 0, b = 1;

        if (n == a || n == b) return true;

        while (b < n) {
            int temp = a + b;
            a = b;
            b = temp;
        }

        
        return b == n;
    }
}
