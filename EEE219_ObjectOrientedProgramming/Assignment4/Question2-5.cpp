#include <iostream>
using namespace std;

// Question 2
class Student {
protected:
  string firstname;
  string lastname;
  int ID;
public:
  virtual string getType() = 0 ;
  Student (int id, string fn, string ln):ID (id), firstname (fn), lastname (ln)
  {}
  int getID(){ return ID; }   
  virtual void printInfo()
  { 
    cout << endl << "Student Type: " << getType() << endl;
    cout << "Student Details:" << endl;
    cout  << "Student Name: " << firstname << " " << lastname << endl << 
    "Student Number: " << ID << endl;
  }
};

// Question 3
class ResearchStudent : public Student {
private:
  string supervisorname;
  string thesistitle;
public:
  ResearchStudent (int id, string fn, string ln, string sn, string tt): 
  Student (id, fn, ln), supervisorname(sn), thesistitle(tt) {}
  void printInfo() override{
  Student::printInfo();
  cout << "Supervisor Name: " << supervisorname << endl << "Thesis Title: " 
  << thesistitle << endl;
  }
   string getType() override {
   return "Research Student"; 
  }
};

// Question 4
class TaughtStudent: public Student {
private:
  string modulenames[9];
  int numRegisteredModules;
public:
  TaughtStudent (int id, string fn, string ln, mname[9]): Student(id,fn, ln),
  mname[9](modulename[0]),numRegisteredModules(0) {}
  bool registerFor(const string & moduleName){

  if (numRegisteredModules < 10)  {
  numRegisteredModules ++;
  modulenames[numRegisteredModules - 1] = "Systems";
  return true;
  }
  else 
  return false;
  }
  void printInfo() override
  { 
      Student::printInfo();
      cout << "Registered Modules: "; 
      for (int i=0; i<10; i++)
      cout << modulenames[i]<< endl;
  }
   string getType() override {
   return "Taught Student"; 
  }
};

//Question 5
void studentTester()
{
 ResearchStudent rs1(19423714, "Isobel", "Fox", "Conor Mcardle", "Bluetooth"), 
 rs2(12028342, "Niamh", "Murray","James dwyer", "Nanoelectronics");
 TaughtStudent ts1(1234567, "Erin", "Doarbes"), 
 ts2(1231234, "Nathan", "Hayward");
 
 string m1[3] = {"Electronics", "Computer Programming", "Embedded Systems"};
 ts1.registermodules(m1, 3);
 string m2[3] = {"Data Communications", "Mathematics", "Operating systems"};
 ts2.registermodules(m2, 3);
 
 Student* studentarray[4];
 studentarray[0] = new ResearchStudent(19423714, "Isobel", "Fox", "Conor Mcardle", "Bluetooth");
 studentarray[1] = new ResearchStudent(12028342, "Niamh", "Murray","James dwyer", "Nanoelectronics");
 studentarray[2] = new TaughtStudent(1234567, "Erin", "Doarbes");
 studentarray[3] = new TaughtStudent(1231234, "Nathan", "Hayward");
 
 for(int i=0; i<4; i++)
 {
  cout << "_______________________________________________" << endl;
  studentarray[i]->printInfo();
  cout << "_______________________________________________" << endl;
  delete studentarray[i];
 }
}

int
main ()
{
  studentTester ();
  return 0;
}
