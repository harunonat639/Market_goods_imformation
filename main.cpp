#include<iostream>
#include<list>
#include<string>
#include<ctime>
using namespace std;
struct product{
    int pbarcode;
    string  pname;
    int pnum;
    int p_lastdate[3];
};
list<product>listofpro;
void p_add()
{
    product xx;
    cout<<"enter product barcode...:";cin>>xx.pbarcode;
    if(xx.pbarcode<10000000){
        cout<<"barcode must be 8 digit try again";cin>>xx.pbarcode;
    }

    cout<<"enter product name...:";cin>>xx.pname;
    cout<<"enter_number_of_product..:";cin>>xx.pnum;
    cout<<"enter last using date..;\n";
    cout<<"day..:";cin>>xx.p_lastdate[0];
    cout<<"mount..:";cin>>xx.p_lastdate[1];
    cout<<"year...:";cin>>xx.p_lastdate[2];
    listofpro.push_back(xx);
}

void tmcalcute(int *comee,int *returndate)
{
    int  comedate[3];
    comedate[0]=comee[0];
    comedate[1]=comee[1];
    comedate[2]=comee[2];

    int nowx[3];
    time_t now=time(0);
    tm* kk=localtime(&now);
    nowx[0]=(*kk).tm_mday;
    nowx[1]=(*kk).tm_mon+1;
    nowx[2]=(*kk).tm_year+1900;

    if(comedate[0]<nowx[0])
    {
        comedate[1]-=1;
        comedate[0]+=30;
        returndate[0]=comedate[0]-nowx[0];

    }
    else
        returndate[0]=comedate[0]-nowx[0];

    if(comedate[1]<nowx[1])
    {
        comedate[2]-=1;
        comedate[1]+=12;
        returndate[1]=comedate[1]-nowx[1];
    }
    else
    { returndate[1]=comedate[1]-nowx[1];
    }

    returndate[2]=comedate[2]-nowx[2];






}
void listproduct()
{
    int datee[3];

    list<product>::iterator xx=listofpro.begin();
    cout<<"barcode\tname<\tnumber\tlast_date\t ramain_time"<<endl;
    for(int i=0;i<listofpro.size();i++)
    {

        tmcalcute((*xx).p_lastdate,datee);
        cout<<(*xx).pbarcode<<"\t"<<(*xx).pname<<"\t"<<(*xx).pnum<<"\t"<<(*xx).p_lastdate[0]<<"/"<<(*xx).p_lastdate[1]<<"/"<<(*xx).p_lastdate[2]<<"\t";
        if(datee[0]==0&&datee[1]==0&&datee[2]==0)
            cout<<"USING TAME OVER!";
        else    if(datee[0]<0||datee[1]<0||datee[2]<0)
            cout<<"USING TAME OVER!";
        else{
            cout<<datee[0]<<"/"<<datee[1]<<"/"<<datee[2];}
        advance(xx,1);
        cout<<endl;

    }


}
void p_sell()
{
    int bbarcode,dtimet[3];

    cout<<"enter barcode....:";cin>>bbarcode;
    list<product>::iterator ee=listofpro.begin();
    for(int i=0;i<listofpro.size();i++)
    {

        if(bbarcode==(*ee).pbarcode)
        {
            tmcalcute((*ee).p_lastdate,dtimet);
            if(dtimet[0]==0&&dtimet[1]==0&&dtimet[2]==0)
            {cout<<"USING TAME OVER!";}
            else   if(dtimet[0]<0||dtimet[1]<0||dtimet[2]<0)
            { cout<<"USING TAME OVER!";}

            else
            {
                int num;
                cout<<"number of product sell..:";cin>>num;
                if(num<=(*ee).pnum)
                {
                    (*ee).pnum-=num;
                    cout<<"\n"<<(*ee).pname<<"\t"<<(*ee).pnum<<"\n";

                }
                else
                    cout<<"dont have this product..."<<endl;

            }

        }

        advance(ee,1);







    }









}

int main()
{
    while(true)
    {
        int choice;
        cout<<"---------WELLCOME------------"<<endl;
        cout<<"..........enter your choice............"<<endl;
        cout<<"1-add_product\t2-list_all_product\t3-sell_product\t4- break....:";cin>>choice;
        if(choice==4)
            break;
        if(choice>0&&choice<5)
        {
            switch (choice) {
                case 1:
                    while (true)
                    {
                        int dd;
                        p_add();
                        cout<<"for break enter 2 else enter  something!";cin>>dd;
                        if(dd==2)
                            break;



                    }
                    break;
                case 2:
                    listproduct();
                    break;
                case 3:
                    while (true)
                    {
                        int dd;
                        p_sell();
                        cout<<"for break enter 2 else enter  something!";cin>>dd;
                        if(dd==2)
                            break;



                    }
                    break;
                default:
                    break;



            }







        }



    }





}
