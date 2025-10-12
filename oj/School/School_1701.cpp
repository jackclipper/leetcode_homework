#include <iostream>
#include <string>
using namespace std;

class book{
    public:

    string ISBN, bookname, author, copyright,booktype_string;
    bool in = true;
    enum class Genre {
        fiction,
        nonfiction,
        periodical,
        biography,
        children
    };
    Genre booktype;

    //构造函数
    book(string ISBN_input=" ", string bookname_input=" ", string author_input=" ", string copyright_input=" ", Genre booktype_input=Genre::fiction){
        ISBN = ISBN_input;
        bookname = bookname_input;
        author = author_input;
        copyright = copyright_input;
        booktype = booktype_input;
    }

    //查询值
    string ISBN_output(){
        return ISBN;
    }

    string bookname_output(){
        return bookname;
    }

    string author_output(){
        return author;
    }

    string copyright_output(){
        return copyright;
    }

    Genre booktype_output(){
        return booktype;
    }

    //借书
    void borrow(){
        if(in = true){
            in = false;
            cout << "You have successfully borrowed a book";
        }
        else{
            cout << "Sorry, the book has been borrowed.";
        }
    }

    //换书
    void back(){
        if(in = false){
            in = true;
            cout << "You have successfully returned a book";
        }
        else{
            cout << "Sorry, the book is already in the library.";
        }
    }

    //重载==
    bool operator==(book other){
        if(ISBN == other.ISBN){
            return true;
        }
        else{
            return false;
        }
    }

    //重载!=
    bool operator!=(book other){
        if(ISBN != other.ISBN){
            return true;
        }
        else{
            return false;
        }
    }

    //标签分配函数
    void ditribution(string booktype_input){
        if(booktype_input == "fiction"){
            booktype = Genre::fiction;
        }
        else if(booktype_input == "nonfiction"){
            booktype = Genre::nonfiction;
        }
        else if(booktype_input == "periodical"){
            booktype = Genre::periodical;
        }
        else if(booktype_input == "biography"){
            booktype = Genre::biography;
        }
        else if(booktype_input == "children"){
            booktype = Genre::children;
        }
    }
    
    //声明友元函数
    friend ostream& operator<<(ostream& os, const book& obj);
};

//在类外重载<<
ostream& operator<<(ostream& os, const book& obj){
    os <<obj.bookname <<' ' <<obj.author <<' ' <<obj.ISBN  <<' ' <<obj.copyright <<' ' <<obj.booktype_string;
    return os;
}


int main(){
    book data[3];
    for(int i=0; i<3; i++){
        cin >>data[i].bookname >>data[i].author >>data[i].ISBN >>data[i].copyright >>data[i].booktype_string;
        data[i].ditribution(data[i].booktype_string);
    }

    for(int i=0; i<3; i++){
        for(int j=0; j< 2-i; j++){
            if(data[j].ISBN > data[j+1].ISBN){
                book temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp; 
            }
        }
    }
    
    for(int i=0; i<3; i++){
        cout <<data[i] <<endl;
    }
    return 0;
}