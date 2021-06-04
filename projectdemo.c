#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_choice(void);
int atomic_number(void);
int atomic_symbol(void);
int atomic_name(void);
int atomic_weight(void);
int electronic_configuration(void);
int atomic_period(int);
char atomic_block(int);
char atomic_property(int);
int atomic_group(int );
char atomic_class(int);
void display(int,char,char,char,char, char);

char atoms[118][25] = {
    "Hydrogen", "Helium",                                                                                                                                                                                                                                                                                                                                                                                                              //2
    "Lithium",  "Beryllium", "Boron",     "Carbon",    "Nitrogen",     "Oxygen",     "Fluorine",   "Neon",                                                                                                                                                                                                                                                                                                                                               //8
    "Sodium",   "Magnesium", "Aluminium", "Silicon",   "Phosphorus",    "Sulphur",    "Chlorine",   "Argon",                                                                                                                                                                                                                                                                                                                                        //8
    "Potassium","Calcium",   "Scandium",  "Titanium",  "Vanadium",     "Chromium",   "Manganese",   "Iron",      "Cobalt",    "Nickel",      "Copper",    "Zinc",        "Gallium",    "Germanium", "Arsenic",     "Selenium",   "Bromine",    "Krypton",                                                                                                                                                                                                                            //18
    "Rubudium", "Strontium", "Yttrium",   "Zirconium", "Niobium",      "Molybdenum", "Technetium",  "Ruthenium", "Rhodium",   "Palladium",   "Silver",    "Cadmium",     "Indium",     "Tin",       "Antimony",    "Tellurium",  "Iodine",     "Xenon",                                                                                                                                                                                                                     //18
    "Cesium",   "Barium",    "Lanthanum", "Cerium",    "Praseodymium", "Neodymium",  "Promethium",  "Samarium",  "Europium",  "Gadolinium",  "Terbium",   "Dysprosium",  "Holmium",    "Erbium",    "Thulium",     "Ytterbium",  "Lutetium",   "Hafnium",       "Tantalum", "Tungsten",   "Rhenium", "Osmium",  "Iridium",    "Platinum",     "Gold",        "Mercury",     "Thalium",  "Lead",      "Bismuth",   "Polonium",    "Astatine",   "Radon",                                          //32
    "Francium", "Radium",    "Actinium",  "Thorium",   "Protactinium", "Uranium",    "Neptunium",   "Plutonium", "Americium", "Curium",      "Berkelium", "Californium", "Ensteinium", "Fermium",   "Mendelevium", "Nobelium",   "Lawrencium", "Rutherfordium", "Dubnium",  "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson", //32
};
char at_symbols[118][2] = {
    "H",  "He",                                                                                                                                                                                     //2
    "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",                                                                                                                                                     //8
    "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar",                                                                                                                                                  //8
    "K",  "Ca", "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",                                                                                      //18
    "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",                                                                                      //18
    "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", //32
    "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", //32
};
double at_weight[118] = {
    1.008,  4.0026,                                                                                                                                                                                                                                                   //2
    6.94  , 9.0122, 10.81, 12.011, 14.007, 15.999, 18.998, 20.18,                                                                                                                                                                                                      //8
    22.990, 24.305, 26.982, 28.085, 30.974, 32.06, 35.45, 39.95,                                                                                                                                                                                                     //8
    39.098, 40.078, 44.956, 47.867, 50.942, 51.996, 54.938, 55.845, 58.933, 58.693, 63.546, 65.38, 69.723, 72.63, 74.922, 78.971, 79.904, 83.796,                                                                                                                    //18
    85.468, 87.62, 88.906, 91.224, 92.906, 95.95, 97.00, 101.07, 102.91, 106.42, 107.87, 112.41, 114.82, 118.71, 121.76, 127.60, 126.90, 131.29,                                                                                                                     //18
    132.91, 137.33, 138.91, 140.12, 140.91, 144.24, 145.00, 150.36, 151.96, 157.25, 158.93, 162.50, 164.93, 167.26, 168.93, 173.05, 174.97, 178.49, 180.95, 183.84, 186.21, 190.23, 192.22, 195.08, 196.97, 200.59, 204.38, 207.20, 208.98, 209.00, 210.00, 222.00,  //32
    223.00, 226.00, 227.00, 232.04, 231.04, 238.03, 237.00, 244.00, 243.00, 247.00, 247.00, 251.00, 252.00, 257.00, 258.00, 259.00, 266.00, 267.00, 268.00, 269.00, 270.00, 269.00, 278.00, 281.00, 282.00, 285.00, 286.00, 289.00, 290.00, 293.00, 294.00, 294.00}; //32
char elec_config[118][30]={
    "1","2",
    "2,1","2,2","2,3","2,4","2,5","2,6","2,7","2,8"
    ,"2,8,1","2,8,2","2,8,3","2,8,4","2,8,5","2,8,6","2,8,7","2,8,8"
    ,"2,8,8,1","2,8,8,2","2,8,9,2","2,8,10,2","2,8,11,2","2,8,13,1","2,8,13,2","2,8,14,2","2,8,15,2","2,8,16,2","2,8,18,1","2,8,18,2","2,8,18,3","2,8,18,4","2,8,18,5","2,8,18,6","2,8,18,7","2,8,18,8"
    ,"2,8,18,8,1","2,8,18,8,2","2,8,18,9,2","2,8,18,10,2","2,8,18,12,1","2,8,18,13,1","2,8,18,13,2","2,8,18,15,1","2,8,18,16,1","2,8,18,18","2,8,18,18,1","2,8,18,18,2","2,8,18,18,3","2,8,18,18,4","2,8,18,18,5","2,8,18,18,6","2,8,18,18,7","2,8,18,18,8"
    ,"2,8,18,18,8,1","2,8,18,18,8,2","2,8,18,18,9,2","2,8,18,19,9,2","2,8,18,21,8,2","2,8,18,22,8,2","2,8,18,23,8,2","2,8,18,23,8,2","2,8,18,25,8,2","2,8,18,25,9,2","2,8,18,27,8,2","2,8,18,28,8,2","2,8,18,29,8,2","2,8,18,30,8,2","2,8,18,31,8,2","2,8,18,32,8,2","2,8,18,32,9,2","2,8,18,32,10,2","2,8,18,32,11,2","2,8,18,32,12,2","2,8,18,32,13,2","2,8,18,32,14,2","2,8,18,32,15,2","2,8,18,32,17,1","2,8,18,32,18,1","2,8,18,32,18,2","2,8,18,32,18,3","2,8,18,32,18,4","2,8,18,32,18,5","2,8,18,32,18,6","2,8,18,32,18,7","2,8,18,32,18,8"
    ,"2,8,18,32,18,8,1","2,8,18,32,18,8,2","2,8,18,32,18,9,2","2,8,18,32,18,10,2","2,8,18,32,20,9,2","2,8,18,32,21,9,2","2,8,18,32,22,9,2","2,8,18,32,24,8,2","2,8,18,32,25,8,2","2,8,18,32,25,9,2","2,8,18,32,27,8,2","2,8,18,32,28,8,2","2,8,18,32,29,8,2","2,8,18,32,30,8,2)","2,8,18,32,31,8,2","2,8,18,32,32,8,2","2,8,18,32,32,8,3","2,8,18,32,32,10,2","2,8,18,32,32,11,2","2,8,18,32,32,12,2","2,8,18,32,32,13,2","2,8,18,32,32,14,2","2,8,18,32,32,15,2","2,8,18,32,32,16,2","2,8,18,32,32,17,2","2,8,18,32,32,18,2","2,8,18,32,32,18,3","2,8,18,32,32,18,4","2,8,18,32,32,18,5","2,8,18,32,32,18,6","2,8,18,32,32,18,7","2,8,18,32,32,18,8"
};
char year_of_discovery[118][10]={
    "1766",  "1895",                                                                                                                                                                                                                                                             //2
    "1817", "1797", "1808",  "Ancient",  "1772",  "1774",  "1896",  "1898",                                                                                                                                                     //8
    "1807", "1755", "1825", "1824", "1669",  "Ancient",  "1774", "1894",                                                                                                                                                  //8
    "1807",  "1808", "1879", "1791", "1801",  "1798", "1774", "Ancient", "1739", "1751", "Ancient", "20 BC", "1875", "1886", "1250", "1817", "1826", "1898",                                                                                      //18
    "1861", "1790", "1794",  "1789", "1801", "1781", "1937", "1844", "1803", "1803", "Ancient", "1817", "1863", "Ancient", "Ancient", "1783", "1811", "1898",                                                                                      //18
    "1860", "1808", "1839", "1803", "1885", "1885", "1945", "1879", "1901", "1880", "1843", "1896", "1878", "1843", "1879", "1878", "1907", "1923", "1802", "1783", "1925", "1803", "1803", "1750", "Ancient", "Ancient", "1861", "Ancient", "1500", "1898", "1940", "1900", //32
    "1939", "1898", "1899", "1829", "1913", "1789",  "1940", "1940", "1944", "1944", "1949", "1950", "1952", "1953", "1955", "1963", "1965", "1964", "1968", "1974", "1981", "1984", "1982", "1994", "1994", "1996", "2004", "1999", "2010", "2000", "2010", "2006" //32
};
int main(void)
{
    int i = 999,choice;
    do
    {
        choice = get_choice();
        char ch1, ch2, ch3,ch4,ch5;
        switch (choice)
        {
        case 1: i = atomic_number();
                break;
        case 2: i = atomic_symbol();
                break;
        case 3: i = atomic_name();
                // printf("%d",i);
                break;
        case 4: i = atomic_weight();
                break;
        case 5: return (0);

        default:
            printf("\t\t\t\tOops!\t\t\t\t");
            printf("Enter a valid choice");
        }
        if (i == -1)
        {
            
            printf("\t\t\t\t OOPS \n\t\t\t");
            printf("\t\t\t\t Make a right choice \n\t\t\t");
        }
        else if (i == 999)
        {
            continue;
        }
        else 
        {
            ch1 = atomic_block(i);
            ch2 = atomic_property(i);
			ch3 = atomic_period(i);
            ch4 = atomic_group(i);
            ch5= atomic_class(i);
            display(i, ch1, ch2,ch3,ch4,ch5);
        }
        i = 999;
    }
    while(choice!=6); 
    fflush(stdin);

    return (0);
}

int get_choice(void)
{
    int input;
    printf("\t\t\t\t WELCOME \t\t\t\t\n");
    printf("Enter you choice below\n");
    printf("1.Search by Atomic No.\n");
    printf("2.Search by Atomic Symbol\n");
    printf("3.Search by Atomic Name\n");
    printf("4.Search by Atomic Weight\n");
    printf("5.To exit the programme\n");
    printf("Enter your choice:\n");
    scanf("%d", &input);
    return input;
}
int atomic_number(void)
{
    int atomicno;
    printf("Enter the atomic no. of the element:");
    scanf("%d", &atomicno);
    atomicno--;
    if (atomicno >= 0 && atomicno < 118)
    {
        return atomicno;
    }
    else
    {
        return -1;
    }
}
int atomic_name(void)
{
    char name[20];
    int i, flag = 0;
    printf("Enter the name of the element\nWarning:\n Please enter the first letter capital and make sure the spelling is correct:\n");
    scanf("%s", name);
    for (i = 0; i < 118; i++)
    {
        if (strcmp(name, atoms[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int atomic_symbol(void)
{
    char symbol[3];
    int i, flag = 0;
    printf("Enter the atomic symbol of the element:\n");
    scanf("%s", symbol);
    for ( i = 0; i < 118; i++)
    {
        if (strcmp(symbol, at_symbols[i]) == 0)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int atomic_weight(void)
{
    double atomic_mass;
    int i, flag=0;
    printf("Enter the atomic mass of the element\n");
    scanf("%lf", &atomic_mass);
    for ( i = 0; i < 118; i++)
    {
        if (at_weight[i]==atomic_mass)
            
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int electronic_configuration()
{
    int i, flag = 0;
    char electronic_config[30];
    printf("Enter the electronic configuration in terms of shell\n");
    scanf("%s",electronic_config);
    for ( i = 0; i < 118; i++)
    {
        if (strcmp(electronic_config, elec_config[i]) == 0)

        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
char atomic_block(int i)
{
    char ch= ' ';
    int n = i + 1;
    if (n == 1 || n == 3 ||n == 11 || n == 19 || n == 37 || n == 35 || n == 87 || n == 4 || n == 12 || n == 20 || n == 38 || n == 56 || n == 88)
    {
        ch = 's';
    }
    else if ((n>=5 &&  n<= 10) || (n>=13  && n<= 18 )|| (n>=31 && n <= 36) || (n>=49 && n <= 54) || (n>=81 && n <= 86) || (n>=113 && n <= 118))
    {
        ch = 'p';
    }
    else if (21 <= n <= 30 || 39 <= n <= 48 || 71 <= n <= 80 || 103 <= n <= 112)
    {
        ch = 'd';
    }
    else if (57 <= n <= 70 || 89 <= n <= 102)
    {
        ch = 'f';
    }

    // else
    // {
    //     printf("This element is yet to be discovered :p");
    // }
    return ch;
}
char atomic_property(int i)
{
    int n = i + 1;
    char ch=' ';
    if (n == 1 || n == 2 || (n >= 6 && n <= 10) || (n >= 15 && n <= 18) || (n >= 34 && n <= 36) || n == 53 || n == 54 || n == 86 || n == 117 || n == 118)
    {
        ch = 'n';
    }
    else if (n == 3 || n == 4 || (n >= 11 && n <= 13) || (n >= 19 && n <= 31) || (n >= 37 && n <= 50) || (n >= 55 && n <= 84) || (n >= 87 && n <= 116))
    {
        ch = 'm';
    }
    else
    {
        ch = 'x';
    }
    return ch;
}
int atomic_period(int i) 
{
    int n = i+1;
    int period;
    if (n==1 || n==2)
    {
        period = 1;
    }
    else if (n>=3 && n<=10)
    {
        period = 2;
    }
    else if (n>=11 && n<=18)
    {
        period = 3;
    }
    else if (n>=19 && n<=36)
    {
        period = 4;
    }
    else if (n>=37 && n<=54)
    {
        period = 5;
    }
    else if (n>=55 && n<=86)
    {
        period = 6;
    }
    else if (n>=87 && n<=118)
    {
        period = 7;
    }
	return period;
}
int atomic_group(int i)
{
	int group;
    char str[30];
	int n=i+1;
	if (n==1 || n==3 || n==11|| n==19||n==37||n==55||n==87)
	{
		group = 1 ;
	}
	else if (n==4 || n==12 || n==20 || n==38 || n==56 || n==88)
	{
		group = 2 ;
	}
	else if (n==21|| n==39 ||( n>=57 && n<=71 )|| (n>=89 && n<=103))
	{
		group = 3 ;
	}
	else if (n==22 || n==40 || n==72 || n==104)
	{
		group = 4 ;
	}
	else if (n==23 || n==41 || n==73 || n==105 )
	{
		group = 5 ;
	}
	else if (n==24|| n==42 || n==74 || n==106 )
	{
		group = 6 ;
	}
	else if (n==25 || n==43 || n==75 || n==107)
	{
		group = 7 ;
	}
	else if (n==26 || n==44 || n==76 || n==108 )
	{
		group = 8 ;
	}
	else if (n==27 || n==45|| n==77 || n==109 )
	{
		group = 9 ;
	}
	else if (n==28 || n==46 || n==78 || n==110 )
	{
		group = 10 ;
	}
	else if (n==29 || n==47 || n==79 || n==111 )
	{
		group = 11 ;
	}
	else if (n==30 || n==48 || n==80 || n==112 )
	{
		group = 12 ;
	}
	else if (n==5 || n==13 || n==31 || n==49 ||n==81 ||n==113 )
	{
		group = 13 ;
	}
	else if (n==6 || n==14 || n==32 || n==50 ||n==82 ||n==114 )
	{
		group = 14 ;
	}
	else if (n==7 || n==15 || n==33 || n==51 ||n==83 ||n==115 )
	{
		group = 15 ;
	}
	else if (n==8 || n==16 || n==34 || n==52 ||n==84 ||n==116 )
	{
		group = 16 ;
	}
	else if (n==9 || n==17 || n==35 || n==53 ||n==85 ||n==117 )
	{
		group = 17 ;
	}
	else if (n==2 ||n==10 || n==18 || n==36 || n==54 ||n==86 ||n==118 )
	{
		group = 18 ;
	}
	return group;
	
}
char atomic_class(int i)
{
    char ch= ' ' ;
    int n=i+1;
    if (n==1 || n==3 || n==11|| n==19||n==37||n==55||n==87)
	{
		ch ='a' ;
	}
    else if (n==4 || n==12 || n==20 || n==38 || n==56 || n==88)
	{
		ch= 'b';
	}
    else if ( n>=57 && n<=71)
	{
		ch= 'c' ;
	}
    else if ( n>=89 && n<=103)
	{
		ch= 'd';
	}
    else if ((n>=21 && n<=30)||(n>=39&&n<=48)||(n>=72&&n<=80)||(n>=104&&n<=108))
    {
        ch= 'e';
    }
    else if (n==13||n==31||n==49||n==50||n>=81&&n<=84)
    {
       ch= 'f';
    }
    else if (n>=6&&n<=9 || n>=15&&n<=17 || n==34 || n==35 ||n==53)
    {
        ch= 'g';
    }
    else if (n==2 ||n==10 || n==18 || n==36 || n==54 ||n==86 ||n==118)
    {
        ch='h';
    }
    else
    {
        ch='i';
    }
    
    return ch;   
}

void display(int i, char ch1, char ch2,char ch3, char ch4,char ch5)
{
    printf("\t\t\t\t\t\tHere is your result\n");
    printf("\t\t\t\t\t\tThe atomic number is : %d\n", (i + 1));
    printf("\t\t\t\t\t\tAtomic symbol is %.2s\n", at_symbols[i]);
    printf("\t\t\t\t\t\tAtomic name is %s\n", atoms[i]);
    printf("\t\t\t\t\t\tAtomic Weight is %.2f\n", at_weight[i]);
    printf("\t\t\t\t\t\tThe electronic configuration of the element is :(%s)\n",elec_config[i]);
    printf("\t\t\t\t\t\tThe block is %c\n", ch1);
	printf("\t\t\t\t\t\tThe period of the element is %d\n",ch3);
	printf("\t\t\t\t\t\tThe group of the element is %d\n",ch4);
	printf("\t\t\t\t\t\tThe class of the element is :");

    if (ch5 == 'a')
    {
        printf("Alkali Metals\n");
    }
    else if (ch5 == 'b')
    {
        printf("Alkaline Earth Metals\n");
    }
    else if (ch5=='c')
    {
        printf("Lanthanoids\n");
    }
    else if (ch5=='d')
    {
        printf("\t\t\t\t\t\tActinoids\n");
    }
    else if (ch5=='e')
    {
        printf("Transition Metals\n");
    }
    else if (ch5=='f')
    {
        printf("Post Transition Metals\n");
    }
    else if (ch5=='g')
    {
        printf("Reactive Non Metals\n");
    }
    else if (ch5=='h')
    {
        printf("Noble Gases\n");
    }
    else if (ch5=='i')
    {
        printf("Metalloid");
    }
    
    printf("\t\t\t\t\t\tThe Metallic Property is:");
    if (ch2 == 'n')
    {
        printf("Non-metal\n");
    }
    else if (ch2 == 'm')
    {
        printf("Metal\n");
    }
    else if (ch2 == 'x')
    {
        printf("Metalloid\n");
    }
  
    
              
    
    
}