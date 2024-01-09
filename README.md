# Pharmacy Management System (File Handling in C++)

The Pharmacy Management System is a software application developed in C++ that manages the operations of a pharmacy using file handling to store and manage data. The system offers a wide range of functionalities for both administrators and customers.

## Features

### Admin

#### Login
- Admins can log in using their credentials.

#### Medicine Management
- Add a new medicine, capturing details such as medicine name, expiry date, price, and quantity.
- Update the details of an existing medicine.
- Delete a medicine from the inventory.
- View a list of all medicines currently in the store.
- Search for a specific medicine by its name.

#### User Management
- View a list of all registered customers.

#### Purchase Records
- View a list of all purchases made, including details like customer name, medicine purchased, date of purchase, and quantity.

### Customer

#### Registration and Login
- Register as a new user by providing necessary details.
- Log in using registered credentials.

#### Medicine Purchase
- Browse through the list of available medicines.
- Purchase a desired medicine, which reduces the medicine's stock quantity.
- Search for a specific medicine by its name to buy.

#### Order History
- View a list of all previous medicine purchases made, including details like medicine name, date of purchase, and quantity.

#### Feedback
- Provide feedback or review about a purchased medicine or the overall shopping experience.

## File Handling
The system uses file handling in C++ to store information about medicines, customers, purchases, and feedback. Data is stored in text files and managed using file input/output operations in C++.

## Installation
To run the application, you need to have a C++ compiler installed. You can then compile the source code and run the application from the command line or an integrated development environment (IDE).

## Usage
- As an admin, you can log in and manage medicines, view purchase records, and manage users.
- As a customer, you can register, log in, purchase medicines, view order history, and provide feedback.

## Contribution
Contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).

