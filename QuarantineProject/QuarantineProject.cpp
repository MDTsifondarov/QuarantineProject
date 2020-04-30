#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct PRODUCTS
{
    string type;
    string name;
    float price;
    string availability;
    string origin;
    int id;

};

/*=========CRUD=========*/
int getProductIndex(PRODUCTS* products, int& productsCount, int id) //Gets product index by using the id of the product
{
    for (int i = 0; i < productsCount; i++)
    {
        if (products[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void createProducts(PRODUCTS* products, int& productsCount, int& maxId, PRODUCTS newProducts) // adds new product to the main list (the array)
{
    newProducts.id = maxId++;
    products[productsCount] = newProducts;
    productsCount++;
}

void updateProducts(PRODUCTS* products, int productsCount, int id, PRODUCTS newProducts) //edits the data of the product
{
    int index = getProductIndex(products, productsCount, id);
    products[index] = newProducts;
}

void deleteProducts(PRODUCTS* products, int& productsCount, int id) // "deletes" product
{
    int index = getProductIndex(products, productsCount, id);

    for (int i = index; i < productsCount - 1; i++)
    {
        products[i] = products[i + 1];
    }
    productsCount--;
}

PRODUCTS getProducts(PRODUCTS* products, int& productsCount, int id) // finds product by its index
{
    int index = getProductIndex(products, productsCount, id);
    return products[index];
}
/*======================*/


/*=====PRESENTATION LAYER=====*/

void menu() // diplsays main menu of the program
{
    cout << "   MENU:" << endl;
    cout << "1.Enter product" << endl;
    cout << "2.View all products" << endl;
    cout << "3.Edit product" << endl;
    cout << "4.Delete product" << endl;
    cout << "5.Others" << endl;
    cout << "6.Exit" << endl;
    cout << endl << "Your choice: ";
}

void menuOthers() //displays second menu of the program
{
    cout << "1.View only available products" << endl;
    cout << "2.View only unavailable products" << endl;
    cout << "3.View the most expensive product" << endl;
    cout << "4.View the cheapest product" << endl;
    cout << "5.Go back to main menu" << endl;
    cout << "Your choice: " << endl;
}

void enterProductsMenu(PRODUCTS* products, int& productsCount, int& maxId) //dislays the menu that help the user to enter products data
{
    PRODUCTS product;
    cout << "Enter type of the product(foods,cosmetics,sports etc.): "; cin >> product.type; cout << endl;
    cout << "Enter name of the product: "; cin >> product.name; cout << endl;
    cout << "Enter price of the product: "; cin >> product.price; cout << endl;
    cout << "Enter availability of the product(yes or no): "; cin >> product.availability; cout << endl;
    cout << "Enter origin of the product: "; cin >> product.origin; cout << endl;

    createProducts(products, productsCount, maxId, product);
    cout << "You are ready! The product has been added to your list!" << endl;
}

void showProductsMenu(PRODUCTS* products, int& productsCount, int& maxId) // shows all current saved products data to the user
{
    cout << "List of the entered products:" << endl;
    for (int i = 0; i < productsCount; i++)
    {
        cout << "Type: " << products[i].type << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Availability: " << products[i].availability << endl;
        cout << "Origin: " << products[i].origin << endl;
        cout << "Id:" << products[i].id << endl << endl;
    }
}

void editProductsMenu(PRODUCTS* products, int& productsCount) //displays the menu that help the user to edit data of a product
{
    int productId;

    cout << "please enter the id of the product that you want to edit: ";
    cin >> productId;

    PRODUCTS product = getProducts(products, productsCount, productId);

    cout << "1.Type" << endl;
    cout << "2.Name" << endl;
    cout << "3.Price" << endl;
    cout << "4.Availability" << endl;
    cout << "5.Origin" << endl;
    cout << "What do you want to edit: " << endl;

    int choose;
    cin >> choose;

    switch (choose)
    {
    case 1:
        cout << "Enter new type: ";
        cin >> product.type;
        updateProducts(products, productsCount, productId, product);
        break;
    case 2:
        cout << "Enter new name: ";
        cin >> product.name;
        updateProducts(products, productsCount, productId, product);
        break;
    case 3:
        cout << "Enter new price: ";
        cin >> product.price;
        updateProducts(products, productsCount, productId, product);
        break;
    case 4:
        cout << "Enter new availability: ";
        cin >> product.availability;
        updateProducts(products, productsCount, productId, product);
        break;
    case 5:
        cout << "Enter new origin: ";
        cin >> product.origin;
        updateProducts(products, productsCount, productId, product);
        break;
    default:
        cout << "Invalid input!" << endl;
    }
    cout << "You are ready! The product has been added to your list!" << endl;
}

void deleteProductsMenu(PRODUCTS* products, int& productsCount, int& maxId) //displays a menu that help the user to delete a whole product
{
    int productId;

    cout << "please enter the id of the order that you want to delete: ";
    cin >> productId;

    deleteProducts(products, productsCount, productId);

    cout << "You are ready!The product has been removed from the list!" << endl;
}

void showOnlyAvailableProducts(PRODUCTS* products, int& productsCount) //displays only available products
{
    int count = 0;
    cout << "Available products:" << endl;
    for (int i = 0; i < productsCount; i++)
    {
        if (products[i].availability == "yes" || products[i].availability == "Yes")
        {
            cout << "Type: " << products[i].type << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Availability: " << products[i].availability << endl;
            cout << "Origin: " << products[i].origin << endl;
            cout << "Id:" << products[i].id << endl << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "There are no available products!" << endl << endl;
    }

}

void showOnlyUnavailableProducts(PRODUCTS* products, int& productsCount) //displays only unavailable products
{
    int count = 0;
    cout << "Unavailable products:" << endl;
    for (int i = 0; i < productsCount; i++)
    {
        if (products[i].availability == "no" || products[i].availability == "No")
        {
            cout << "Type: " << products[i].type << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Availability: " << products[i].availability << endl;
            cout << "Origin: " << products[i].origin << endl;
            cout << "Id:" << products[i].id << endl << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "There are no unavailable products!" << endl << endl;
    }
}

void showTheCheapestProduct(PRODUCTS* products, int& productsCount)//displays the cheapest product
{
    PRODUCTS temp;

    for (int i = 0; i < productsCount; i++)
    {
        int min = i;
        for (int j = i; j < productsCount; j++)
        {
            if (products[min].price < products[j].price)
            {
                min = j;
            }
        }
        temp = products[min];
        products[min] = products[i];
        products[i] = temp;
    }
    cout << temp.price << endl;
}

void showTheMostExpensiveProduct(PRODUCTS* products, int& productsCount)//shows the most expensive product
{
    PRODUCTS temp;

    for (int i = 0; i < productsCount; i++)
    {
        int max = i;
        for (int j = i; j < productsCount; j++)
        {
            if (products[max].price > products[j].price)
            {
                max = j;
            }
        }
        temp = products[max];
        products[max] = products[i];
        products[i] = temp;
    }
    cout << temp.price << endl;
}
/*===================================================*/
int main() // the main function of the project
{
    PRODUCTS products[500];
    int productsCount = 0;
    int maxId = 1;
    int choice;
    int choiceOthers;
label:
    menu();

    cin >> choice;

    switch (choice)
    {
    case 1:
        enterProductsMenu(products, productsCount, maxId);
        goto label;
        break;
    case 2:
        if (maxId > 1) {
            showProductsMenu(products, productsCount, maxId);
            goto label;
            break;
        }
        else {
            cout << "You don't have products yet. Create at least one to access this feature!" << endl;
            goto label;
            break;
        }
    case 3:
        if (maxId > 1) {
            editProductsMenu(products, productsCount);
            goto label;
            break;
        }
        else {
            cout << "You don't have products yet. Create at least one to access this feature!" << endl;
            goto label;
            break;
        }
    case 4:
        if (maxId > 1) {
            deleteProductsMenu(products, productsCount, maxId);
            goto label;
            break;
        }
        else {
            cout << "You don't have products yet. Create at least one to access this feature!" << endl;
            goto label;
            break;
        }
    case 5:
        if (maxId > 1) {
        label2:
            menuOthers();

            cin >> choiceOthers;

            switch (choiceOthers)
            {
            case 1:

                showOnlyAvailableProducts(products, productsCount);
                goto label2;
                break;

            case 2:
                showOnlyUnavailableProducts(products, productsCount);
                goto label2;
                break;
            case 3:
                showTheMostExpensiveProduct(products, productsCount);
                goto label2;
                break;
            case 4:
                showTheCheapestProduct(products, productsCount);
                goto label2;
                break;
            case 5:
                goto label;
                break;
            }
            goto label;
            break;
        }
        else {
            cout << "You don't have products yet. Create at least one to access this feature!" << endl;
            goto label;
            break;
        }
    case 6:
        exit(1);
        break;
    }

}