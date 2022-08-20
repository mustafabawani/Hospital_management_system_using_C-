#include "Accountant.h"
#include "globalFunctions.h"
#include <iostream>
using namespace std;

Accountant::Accountant()
{
    TotalBedCharges=0;
    medicine_charges=0;
    test_charges=0;
    total_bill=0;
    totalAdmitBill=0;
    checkupCharges=0;
    admitCharges=0;
    totalCheckupBill=0;
    tax=0;
}

Accountant::Accountant(const Accountant & a){
}

void Accountant::setTotalBedCharges(string user_room)
{
    int total_days;
    transform(user_room.begin(), user_room.end(), user_room.begin(), ::tolower);
    cout << "Enter total number of days a patient admit in hospital" << endl;
    cin >> total_days;
    string room;
    string price;
    double double_price;
    ifstream is("bed charges.csv");
    while(true)
    {
        if(is.eof())
        {
            break;
        }
        getline(is,room, ',');
        getline(is,price);
        if(room==user_room)
        {
            double_price=stod(price);
            cout << "price: " << double_price << endl;
            TotalBedCharges=total_days*double_price;
            break;
        }
    }
    is.close();
}
double Accountant::getTotalBedCharges()
{
    return this->TotalBedCharges;
}

void Accountant::setMedicineCharges(double medicine_charges)
{
    this->medicine_charges=medicine_charges;
}
double Accountant::getMedicineCharges()
{
    return this->medicine_charges;
}

void Accountant::setTestCharges(string name)
{
    admit * a=new admit();

    ifstream is ("admitData.csv");
    while(true)
    {
        a->readFromFile(is);
        if(a->getName()==name)
        {
            break;
        }
        
        if(is.eof())
        {
            break;
        }
    }
    is.close();
    string read;
    read=a->getTests();
    int k=0,j=0;
	vector<string> test;
	for(int i=0; i<read.size();i++ )
	{		
			if(read[k]=='|' || read[k+1]=='\0')
			{
				test.push_back("");
				for(i=j-1;i<k;i++)
				{
					if(read[j]!='|')
					{
						test[test.size()-1] += read[j];
					}
					j++;
				}
			}
			k++;
	}
    string file_test;
    string price;
    double total_price;
    double double_price;
    for(int i=0;i<test.size() ;i++)
    {
        ifstream is("test.csv");
        while(true)
        {
            if(is.eof())
            {
                break;
            }
            getline(is,file_test, ',');
            getline(is,price);
            if(file_test==test[i])
            {
                double_price=stod(price);
                break;
            }  
        }
        is.close();
        total_price = total_price + double_price;
    }
    test_charges=total_price;
    test.clear();
    test.shrink_to_fit();
}

double Accountant::getTestCharges()
{
    return test_charges;
}

void Accountant::setAdmitCharges(string name)
{
    string user;
    double medicine;
    cout << "Enter the room: ";
    getline(cin, user);
    setTotalBedCharges(user);
    cin.ignore();
    setTestCharges(name);
    cout << "Enter the price of medication: ";
    cin>> medicine;
    setMedicineCharges(medicine);
    admitCharges= getTestCharges()+getTotalBedCharges()+getMedicineCharges() ;
}

double Accountant::getAdmitCharges()
{
    return this->admitCharges;
}

void Accountant::set_tax(double total)
{
    tax= (total * rate);
}

double Accountant::get_tax()
{
    return this->tax;
}


void Accountant::total_admit_bill(string name)
{
    adm = new admit;
    setAdmitCharges(name);
    set_tax(getAdmitCharges()+hospital_charges);
    totalAdmitBill=getAdmitCharges() + get_tax() +hospital_charges; 

    ifstream is("admitData.csv");
    while(true)
    {
        if(is.eof())
        {
            break;
        }
        adm->readFromFile(is);
        if(adm->getName() == name)
        {
            break;
        }
    }
    ofstream os("AdmitPatientBill.csv",ios::app);
    os << name << "," << hospital_charges << "," << getTestCharges() << "," << getTotalBedCharges()<<"," << getMedicineCharges() << "," <<  getAdmitCharges() << "," << get_tax() << "," << totalAdmitBill << "," << adm->getDateOfDischarge() << endl;
    os.close();

    display_bill(name,getAdmitCharges(),hospital_charges);

}


void Accountant::setCheckupCharges(string doctor)
{
    int flag=0;
    string temp_name,temp_type;
    transform(doctor.begin(), doctor.end(), doctor.begin(), ::tolower);
    Doctor* doc=new Doctor();
    ifstream is("DoctorData.csv");

    doc->readFromFile(is);
    while (is)
    {
        temp_name=doc->getName();
        temp_type=doc->getType();
        transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::tolower);
        transform(temp_type.begin(), temp_type.end(), temp_type.begin(), ::tolower);
        if(temp_name==doctor)
        {
            checkupCharges=doc->getFee();
            flag=1; 
            break;
        }
        doc->readFromFile(is);
    }
    is.close();
    if(flag==0)
        cout<<"No doctor found!!!"<<endl;

}

double Accountant::getCheckupCharges()
{
    return this->checkupCharges;
}

void Accountant::total_checkup_bill(string name)
{
    string doctor;
    cout << "Enter the doctor name: ";
    getline(cin,doctor);
    setCheckupCharges(doctor);
    set_tax(checkupCharges);
    totalCheckupBill=getCheckupCharges()+get_tax();
    display_bill(name,getCheckupCharges());
    ofstream os("CheckupPatientBill.csv",ios::app);
    os << name << "," << getCheckupCharges() << "," << get_tax() << "," << totalCheckupBill << endl;
    os.close();
    
}

void Accountant::total_hospital_revenue()
{
    char c;
    string user_string;
    double user;
    double total_HospitalCharges=0;
    double total_TestCharges=0;
    double total_BedCharges=0;
    double total_MedicineCharges=0;
    double total_AdmitCharges=0;
    double total_CheckupCharges=0;
    double total_tax=0;
    double total_bill=0;

    ifstream is("AdmitPatientBill.csv");
    while(true)
    {
        getline(is,user_string,',');
        getline(is,user_string,',');
        is>>user>>c;
        total_HospitalCharges=total_HospitalCharges+user;
        is>>user>>c;
        total_TestCharges=total_TestCharges+user;
        is>>user>>c;
        total_BedCharges=total_BedCharges+user;
        is>>user>>c;
        total_MedicineCharges=total_MedicineCharges+user;
        is>>user>>c;
        total_AdmitCharges=total_AdmitCharges+user;
        is>>user>>c;
        total_tax=total_tax+user;
        is>>user>>c;;
        total_bill=total_bill+user;
        if(is.eof())
        {
            break;
        }
    }
    is.close();
    is.open("CheckupPatientBill.csv");
    while(true)
    {
        getline(is,user_string,',');
        getline(is,user_string,',');
        is>>user>>c;
        total_CheckupCharges=total_CheckupCharges+user;
        is>>user>>c;
        total_tax=total_tax+user;
        is>>user>>c;
        total_bill=total_bill+user;
        if(is.eof())
        {
            break;
        }
    }
    is.close();
    hospital_revenue=total_bill;

}

void Accountant::displayHospitalRevenue()
{
    //display all the total revenue
}

double Accountant::getTotalRevenue()
{
    return this->hospital_revenue;
}

void Accountant::display_bill(string name,double amount)
{
    cout<<"\n -------------------------------";
    cout<<"\n Displaying CheckUp Patient Bill";
    cout<<"\n -------------------------------";
    cout<<"\n Name.         :  "<< name;
    cout<<"\n Bill Excluding Tax.          :  "<<amount;
    cout<<"\n Tax.   :  "<<get_tax();
    cout<<"\n Bill Including Tax.          :  "<<amount+get_tax() << endl;
}

void Accountant::display_bill(string name,double amount,double charges)
{
    cout<<"\n -------------------------------";
    cout<<"\n Displaying Admit Patient Bill";
    cout<<"\n -------------------------------";
    cout<<"\n Name.         :  "<< name;
    cout<<"\n Hospital Charges.          :  "<< charges;
    cout<<"\n Bill Excluding Tax.          :  "<<amount+charges;
    cout<<"\n Tax.   :  "<<get_tax();
    cout<<"\n Bill Including Tax.          :  "<<amount+charges+get_tax()<< endl;
}