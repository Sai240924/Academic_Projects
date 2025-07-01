package project;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class CarRentalSystem {
    static class Car {
        String name;
        boolean available;

        Car(String name, boolean available) {
            this.name = name;
            this.available = available;
        }
    }

    public static void main(String[] args) {
        List<Car> cars = new ArrayList<>();
        cars.add(new Car("Toyota Corolla", true));
        cars.add(new Car("Honda Civic", true));
        cars.add(new Car("Ford Mustang", true));

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Welcome to the Car Rental System");
            System.out.println("1. View available cars");
            System.out.println("2. Rent a car");
            System.out.println("3. Return a car");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int option = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (option) {
                case 1:
                    viewAvailableCars(cars);
                    break;
                case 2:
                    rentCar(cars, scanner);
                    break;
                case 3:
                    returnCar(cars, scanner);
                    break;
                case 4:
                    System.out.println("Thank you for using the Car Rental System. Goodbye!");
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }

    private static void viewAvailableCars(List<Car> cars) {
        System.out.println("Available cars:");
        for (Car car : cars) {
            if (car.available) {
                System.out.println(car.name);
            }
        }
    }

    private static void rentCar(List<Car> cars, Scanner scanner) {
        System.out.print("Enter the name of the car you want to rent: ");
        String carName = scanner.nextLine();
        for (Car car : cars) {
            if (car.name.equalsIgnoreCase(carName) && car.available) {
                car.available = false;
                System.out.println("You have rented the " + car.name);
                return;
            }
        }
        System.out.println("Car not available or does not exist.");
    }

    private static void returnCar(List<Car> cars, Scanner scanner) {
        System.out.print("Enter the name of the car you want to return: ");
        String carName = scanner.nextLine();
        for (Car car : cars) {
            if (car.name.equalsIgnoreCase(carName) && !car.available) {
                car.available = true;
                System.out.println("You have returned the " + car.name);
                return;
            }
        }
        System.out.println("Car not rented or does not exist.");
    }
}