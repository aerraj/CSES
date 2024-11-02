#include <bits/stdc++.h>
using namespace std;

// Invoice class
class Invoice {
public:

    Invoice(int id, const string& customerName, double amount)
        {
            this->id=id;
            this->customerName=customerName;
            this->amount=amount;
        }

    int getId() const { return id; }
    const string& getCustomerName() const { return customerName; }
    double getAmount() const { return amount; }

private:
    int id;
    string customerName;
    double amount;
};

// InvoiceDAO interface
class InvoiceDAO {
public:
    virtual ~InvoiceDAO() = default; // Virtual destructor for proper cleanup
    virtual void save(const Invoice& invoice) = 0; // Pure virtual method to save an invoice
};

// Class for saving invoices to a database
class DatabaseInvoiceDAO : public InvoiceDAO {
public:
    void save(const Invoice& invoice) override {
        // Implementation to save to a database
        cout << "Saving invoice to database: ID = " << invoice.getId() 
             << ", Customer = " << invoice.getCustomerName() 
             << ", Amount = " << invoice.getAmount() << endl;
    }
};

// Class for saving invoices to a file
class FileInvoiceDAO : public InvoiceDAO {
public:
    void save(const Invoice& invoice) override {
        // Implementation to save to a file
        cout << "Saving invoice to file: ID = " << invoice.getId() 
             << ", Customer = " << invoice.getCustomerName() 
             << ", Amount = " << invoice.getAmount() << endl;
    }
};

// New implementation can be added here without modifying existing classes

/*Open/Closed Principle (OCP): The code still adheres to OCP by
 making it easy to add new InvoiceDAO implementations (like XMLInvoiceDAO)
 without changing the existing code structure*/

class XMLInvoiceDAO : public InvoiceDAO {
public:
    void save(const Invoice& invoice) override {
        // Implementation to save to an XML file
        cout << "Saving invoice to XML: ID = " << invoice.getId() 
             << ", Customer = " << invoice.getCustomerName() 
             << ", Amount = " << invoice.getAmount() << endl;
    }
};

// Example usage in main
int main() {
    // Create instances of the DAO implementations
    InvoiceDAO* dbDao = new DatabaseInvoiceDAO();
    InvoiceDAO* fileDao = new FileInvoiceDAO();
    InvoiceDAO* xmlDao = new XMLInvoiceDAO(); // New XML DAO instance

    // Create an invoice
    Invoice invoice(1, "John Doe", 250.0);

    // Save the invoice using the database DAO
    dbDao->save(invoice);

    // Save the invoice using the file DAO
    fileDao->save(invoice);

    // Save the invoice using the XML DAO
    xmlDao->save(invoice); // New functionality without modifying existing code

    // Clean up
    delete dbDao;
    delete fileDao;
    delete xmlDao;

    return 0;
}
