// Question1
#include <iostream>
#include <iomanip>
#include <array>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class Account
{
protected:
  int
    accountNumber;
  float
    balance;
public:
  Account (int acn, float bal):
  accountNumber (acn),
  balance (bal)
  {
  }
  virtual void
  display ()
  {
    cout << "account number: " << accountNumber
      << " has balance: " << std::setw (7) << balance << " Euro";
  }
  virtual void
  makeLodgement (float amount)
  {
    balance = balance + amount;
  }
  virtual void
  makeWithdrawal (float amount)
  {
    balance = balance - amount;
  }
  virtual float
  getBalance ()
  {
    return balance;
  }
  virtual string
  accountType () = 0;
  virtual ~ Account ()
  {
  }
};

class CurrentAccount:
public Account
{
private:
  float
    overdraftLimit;
public:
  CurrentAccount (int acn, float bal):
  Account (acn, bal),
  overdraftLimit (0)
  {
  }
  void
  display ()
    override
  {
    Account::display ();
    cout << " - Overdraft limit: " << overdraftLimit << endl;
  }
  void
  makeWithdrawal (float amount)
    override
  {
    if (amount <= (balance + overdraftLimit))
      Account::makeWithdrawal (amount);
  }
  void
  setOverdraftLimit (float limit)
  {
    overdraftLimit = limit;
  }
  virtual string
  accountType ()
    override
  {
    return "Current Account";
  }
};

class LoanAccount:
public Account
{
private:
  int
    loanTerm;
public:
  LoanAccount (int acn, float bal, float term):
  Account (acn, bal),
  loanTerm (term)
  {
  }
  void
  display ()
  {
    Account::display ();
    cout << " - Loan term: " << loanTerm << " months" << endl;
  }
  virtual string
  accountType ()
    override
  {
    return "Loan Account";
  }
};

// Question 1
class AccountsLedger
{
private:
  CurrentAccount ** cArray;
  int currentsize;
  LoanAccount ** lArray;
  int loansize;
  int cMaxsize;
  int lMaxsize;
  int maxsize = 1000;
public:
AccountsLedger ():
  currentsize (0), loansize (0), maxsize (1000)
  {
    cArray = new CurrentAccount *[cMaxsize];
    lArray = new LoanAccount *[lMaxsize];
    maxsize = cMaxsize + lMaxsize;
  }
  bool add (const CurrentAccount & current)
  {
    if (currentsize + loansize < 1000)
      {
	cArray[currentsize++] = new CurrentAccount (current);
	return true;
      }
  }
  bool add (const LoanAccount & loan)
  {
    if (currentsize + loansize < 1000)
      {
	lArray[loansize++] = new LoanAccount (loan);
	return true;
      }
  }
  void print ()
  {
    for (int i = 0; i < loansize; i++)
      lArray[i]->display ();
    for (int i = 0; i < currentsize; i++)
      cArray[i]->display ();
  }
  float applyCharges (float percentage)
  {
    for (int i = 0; i < currentsize; i++)
      {
	float cdeductbal = cArray[i]->getBalance ();
	return cdeductbal - (percentage * cdeductbal);
      }
    for (int i = 0; i < loansize; i++)
      {
	float ldeductbal = lArray[i]->getBalance ();
	return ldeductbal - (percentage * ldeductbal);
      }
  }
  ~AccountsLedger ()
  {
    for (int i = 0; i < currentsize; i++)
      delete cArray[i];
    delete[]cArray;
    for (int i = 0; i < loansize; i++)
      delete lArray[i];
    delete[]lArray;
  }
};

int
main ()
{
  AccountsLedger ledger;
  ledger.add (LoanAccount (1234, -100000, 20));
  ledger.add (LoanAccount (1235, -200000, 25));
  ledger.add (LoanAccount (1236, -300000, 15));
  ledger.add (CurrentAccount (1237, 3000));
  ledger.add (CurrentAccount (1238, 1000));
  ledger.add (CurrentAccount (1239, 2000));
  ledger.applyCharges (0.01);
  ledger.print ();
  return 0;
}
