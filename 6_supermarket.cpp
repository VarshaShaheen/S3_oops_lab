//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class supermarket{
    int item_code, quantity;
    char item_name[20];
    float price;
public:
    void init(){
        cout<<"Enter the item code:";
        cin>>item_code;
        cout<<"Enter the item name:";
        cin>>item_name;
        cout<<"Enter the quantity:";
        cin>>quantity;
        cout<<"Enter the price:";
        cin>>price;
    }
    void delete_item(supermarket ob){
        item_code=ob.item_code;
        strcpy(item_name,ob.item_name);
        price=ob.price;
        quantity=ob.quantity;
    }
    void display(){
        cout<<"Item code: "<<item_code;
        cout<<" Item name: "<<item_name;
        cout<<" Price: "<<price<<endl;
        cout<<" Quantity: "<<quantity<<endl;
    }
    friend class cart;
};

class cart{
    int item_code;
    char item_name[20];
    float price;
    int quantity;
public:
    int init(supermarket ob, int q){
        if(q<=ob.quantity){
            item_code=ob.item_code;
            strcpy(item_name,ob.item_name);
            price=ob.price*q;
            quantity=q;
            ob.quantity-=q;
            return 1;
        }
        else{
            cout<<"The quantity is not available"<<endl;
            return 0;
        }
    }
    void display(){
        cout<<"Item code: "<<item_code;
        cout<<" Item name: "<<item_name;
        cout<<" Price: "<<price<<endl;
    }
    int get_price(){
        return price*quantity;
    }
};

int main(){
    supermarket s[100];
    cart c[100];
    int choice,n,i,code,num=0,buy_no,quantity,total=0,transactions=0;
    cout<<"Enter 1 to add an item, 2 to delete an item, 3 to buy items, 4 to print the number of transactions and 0 to quit:"<<endl;
    cin>>choice;
    do{
        switch(choice){
            case 1:
                cout<<"Enter the number of items to be added:";
                cin>>n;
                for(i=0;i<n;i++){
                    s[i].init();
                    num++;
                }
                break;
            case 2:
                cout<<"Enter the item code of the item to be deleted:";
                cin>>code;
                for(i=code-1;i<n-1;i++){
                    s[i].delete_item(s[i+1]);
                }
                num--;
                break;
            case 3:
                cout<<"Enter the number of items to be bought:";
                cin>>buy_no;
                for(i=0;i<num;i++){
                    s[i].display();
                }
                for(i=0;i<buy_no;i++){
                    cout<<"Enter the item code of the item to be bought:";
                    cin>>code;
                    cout<<"Enter the quantity of the item to be bought:";
                    cin>>quantity;
                    c[i].init(s[code-1],quantity);
                }
                cout<<"Your cart is:"<<endl;
                for(i=0;i<buy_no;i++){
                    c[i].display();
                }
                for(i=0;i<buy_no;i++){
                    total+=c[i].get_price();
                }
                cout<<"Total price:"<<total<<endl;
                transactions++;
                break;
            case 4:
                cout<<"The number of transactions is: "<<transactions<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;

        }
        cout<<"Enter 1 to add an item, 2 to delete an item, 3 to buy items, 4 to print the number of transactions and 0 to quit:"<<endl;
        cin>>choice;
    }while(choice!=0);
}