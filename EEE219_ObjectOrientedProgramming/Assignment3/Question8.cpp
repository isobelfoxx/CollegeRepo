// Question 8
#include <iostream>
using namespace std;

class SalesItem
{
private:
  string description;
  float price;
  static double VATRate;

public:
  SalesItem (string des, float p)
  {
    description = des;
    price = p;
  }
  
  static void setVATRate (double VAT)
  {
    VATRate = VAT;
  }

  void print ()
  {
    cout << description << ", this costs " << price << " Euros" << endl;
  }
  
float
getPriceWithVAT (SalesItem p1)
{
  p1.price = p1.price + ((p1.price)*VATRate);
  return p1.price;
}
};

double
  SalesItem::VATRate = 0.23;

main ()
{
  SalesItem s1 = SalesItem("ipad", 230.88);
  s1.print ();
  cout << s1.getPriceWithVAT(s1);
  return 0;
}
