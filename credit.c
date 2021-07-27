#include <stdio.h>
#include <cs50.h> //includes get_long function
#include <math.h> //includes round function

int main(void)
{
    long int card, firstDigits;
    do{
        card=get_long("Card number: ");
    }
    while(!card);//printf("card = %li\n",card);
    
    //BLOCK of LUN algorithm with splitting long number on simple digits
    int summ = 0, cardNums = 0;
    while(card) 
    {
        cardNums++;
        if (card/10) { //on prelast itteration we will get first two digits of card
            firstDigits=card;}
        
        if (cardNums%2==0)
        {
            if ( (card%10 * 2) / 10 >0 )
                summ += (card%10 * 2) / 10 + (card%10 * 2) % 10;
            else
                summ += card %10 *2;    
        }
        else {
           summ += card%10;
        }
        card = card / 10;//decrease every time in 10 times
    }
    //BLOCK Of Verifing Cards
    string name;
    if (summ%10 != 0){
        name="INVALID";}
    else if ((firstDigits >=40 && firstDigits <50 ) && (cardNums == 13 || cardNums == 16)){
        name="VISA";}
    else if ((firstDigits ==34 || firstDigits ==37) && cardNums == 15 ){
        name="AMEX";}
    else if ((firstDigits >=51 && firstDigits <=55) && cardNums == 16){
        name="MASTERCARD";}
    else{
        name="INVALID";//printf ("INVALID, numbers - %i, firstdigits - %li, summ - %i\n",cardNums,firstDigits,summ);
    }
    printf ("%s\n",name);
}
