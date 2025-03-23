#include<bits/stdc++.h>
using namespace std;

// Abstract base class representing a generic pizza
class Base{
	public:
	virtual string getdescription()=0; // Method to get the description of the pizza
	virtual int getprice()=0; // Method to get the price of the pizza
	virtual ~Base(){} // Virtual destructor to ensure proper cleanup
};

// Concrete class representing a Veg Delight pizza
class vegdelight : public Base{
 
 private:
 	int pizzaprice;
 	
 public:
 	vegdelight(int price){
 		this->pizzaprice=price;
 	} 
 	
 	string getdescription(){
 		return " Vegdelight pizza ";
 	}
 	
 	int getprice(){
 		return pizzaprice;
 	}
};

// Concrete class representing a Farm Villa pizza
class farmvilla : public Base{
 
 private:
 	int pizzaprice;
 	
 public:
 	farmvilla(int price){
 		this->pizzaprice=price;
 	} 
 	
 	string getdescription(){
 		return " farmvilla pizza ";
 	}
 	
 	int getprice(){
 		return pizzaprice;
 	}
};

// Abstract decorator class that wraps a Base pizza object
class Decorator : public Base{
      protected:
      Base *basepizza; // Pointer to base pizza object
      public:
      Decorator(Base *pizza){
      	basepizza=pizza;
      }
      virtual ~Decorator(){} // Virtual destructor for proper cleanup
};

// Concrete decorator class for adding extra cheese to a pizza
class extracheese : public Decorator{
    private:
    int extracheeseprice;
    public:
    extracheese(Base *pizza,int extraprice) : Decorator(pizza),extracheeseprice(extraprice){}
    
    string getdescription(){
    	return basepizza->getdescription() + " extracheese "; // Append extra cheese to description
    }
    
    int getprice(){
    	return basepizza->getprice() + extracheeseprice; // Add extra cheese cost to base price
    }
};

// Concrete decorator class for adding extra veggies to a pizza
class extaveggies : public Decorator{
    private:
    int extraveggiesprice;
    public:
    extaveggies(Base *pizza,int extraprice) : Decorator(pizza),extraveggiesprice(extraprice){}
    
    string getdescription(){
    	return basepizza->getdescription() + " extraveggies "; // Append extra veggies to description
    }
    
    int getprice(){
    	return basepizza->getprice() + extraveggiesprice; // Add extra veggies cost to base price
    } 	
};

int main(){
	// Creating a Veg Delight pizza with extra veggies
	Base *pizza = new extaveggies(new vegdelight(200),20);
    // Adding extra cheese to the previous pizza
    Base *extraloaded=new extracheese(pizza,90);
    
	// Printing details of the pizza with extra veggies
	cout<<pizza->getdescription()<<"\n";
	cout<<pizza->getprice()<<"\n";
	
	// Printing details of the pizza with extra veggies and extra cheese
	cout<<extraloaded->getdescription()<<"\n";
    cout<<extraloaded->getprice()<<"\n";
    
	// Free allocated memory
	delete extraloaded;
	delete pizza;
    
	return 0;
}
