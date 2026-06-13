//Выполнил Черепович Дмитрий ТЭС-23
#include <stdio.h>//
#include <math.h>// подключение библиотеки с мат.функциями
// Задача 2. Даны x, y, z. Вычислить a, b, если
//https://ivtipm.github.io/Programming/Glava01/index01.htm#z4


int main() {

    // Ввод перемннных
    float x=5, y=2, z=9;
    float a,b;
    
    //Поиск переменной а
    a=  y + (x/(pow(y,2)+fabs(pow(x,2)/(y+pow(x,3)/3))) );
    printf("а: %.2f \n",a);
    
    //Поиск переменной b
    b = 1 + pow(tan(z/2),2);

    printf("b: %.2f",b);
}



// Задача 1 Выпонил Черепович Дмитирий Петрович
// Даны два действительных положительных числа. Найти среднее арифметическое и среднее геометрическое этих чисел.
//https://ivtipm.github.io/Programming/Glava01/index01.htm#z4
#include <stdio.h>
#include <math.h>
int main() {
    //ВВод переменных
	float p=5,o=7;//для целочисленного числа
	float d,i;//для вещественного числа
	
	
	//Среднее аримфметическое двух числел
	d=(p+o)/2;
	printf("%.1f \n", d);
	
	// Среднее геометрическое двух чисел
	i=sqrt((p*o));
	printf("%f", i);
}