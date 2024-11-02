//Single responsibility principle - One class One responsibility or one change made



#include <bits/stdc++.h>
using namespace std;

// Marker Class
class Marker {
private:
    string color;
    string brand;
    double price;

public:
    // Constructor
    Marker(const string& color, const string& brand, double price)
        : color(color), brand(brand), price(price) {}

    // Getters
    string getColor() const {
        return color;
    }

    string getBrand() const {
        return brand;
    }

    double getPrice() const {
        return price;
    }
};

// MarkerPrinter Class
class MarkerPrinter {
public:
    // Function to display marker details
    static void display(const Marker& marker) {
        cout << "Color: " << marker.getColor() 
             << ", Brand: " << marker.getBrand() 
             << ", Price: $" << marker.getPrice() << endl;
    }
};

// Invoice Class
class Invoice {
private:
    vector<Marker> markers;
    double discount; // Discount percentage (0 to 100)

public:
    // Constructor
    Invoice(double discount = 0.0) : discount(discount) {}

    // Method to add a marker to the invoice
    void addMarker(const Marker& marker) {
        markers.push_back(marker);
    }

    // Getters
    const vector<Marker>& getMarkers() const {
        return markers;
    }

    double getDiscount() const {
        return discount;
    }
};

// InvoiceCalculator Class
class InvoiceCalculator {
public:
    // Method to calculate the total price
    static double calculateTotalPrice(const Invoice& invoice) {
        double total = 0.0;
        for (const auto& marker : invoice.getMarkers()) {
            total += marker.getPrice();
        }
        return total - (total * (invoice.getDiscount() / 100.0));
    }
};

// InvoicePrinter Class
class InvoicePrinter {
public:
    // Method to print the invoice
    static void print(const Invoice& invoice) {
        cout << "Invoice Details:" << endl;
        for (const auto& marker : invoice.getMarkers()) {
            MarkerPrinter::display(marker);
        }
        cout << "Total Price (after " << invoice.getDiscount() 
             << "% discount): $" 
             << InvoiceCalculator::calculateTotalPrice(invoice) << endl;
    }
};

// Main function to demonstrate the functionality
int main() {
    // Create marker objects
    Marker marker1("Red", "BrandA", 2.5);
    Marker marker2("Blue", "BrandB", 3.0);

    // Create an invoice and add markers
    Invoice invoice(10.0); // 10% discount
    invoice.addMarker(marker1);
    invoice.addMarker(marker2);

    // Print the invoice
    InvoicePrinter obj;
    obj.print(invoice);

    return 0;
}
