import java.util.Scanner;

public class CurrencyConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Exchange rates (as of September 2021)
        double usdToEur = 0.84;
        double usdToGbp = 0.72;
        double usdToJpy = 109.96;

        System.out.println("Currency Converter");
        System.out.println("1. USD to EUR");
        System.out.println("2. USD to GBP");
        System.out.println("3. USD to JPY");
        System.out.println("Enter your choice: ");
        int choice = scanner.nextInt();

        System.out.println("Enter the amount in USD: ");
        double amountUSD = scanner.nextDouble();

        double convertedAmount;

        switch (choice) {
            case 1:
                convertedAmount = amountUSD * usdToEur;
                System.out.println("Converted amount: " + convertedAmount + " EUR");
                break;
            case 2:
                convertedAmount = amountUSD * usdToGbp;
                System.out.println("Converted amount: " + convertedAmount + " GBP");
                break;
            case 3:
                convertedAmount = amountUSD * usdToJpy;
                System.out.println("Converted amount: " + convertedAmount + " JPY");
                break;
            default:
                System.out.println("Invalid choice!");
        }

        scanner.close();
    }
}
