#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 4             //Вывод на светодиод
#define BUTTON_PIN 2           //Вывод на кнопку

int main() {
    DDRB=0;
    DDRD=0;
	DDRB |= 1 << LED_PIN;       //Переключаем вывод светодиода на выход
    PORTD |= 1 << BUTTON_PIN;   //Включаем подтягивающий регистр
	while(1)
    {
        if (PIND & (1 << BUTTON_PIN))   //Если на выводе кнопки высокий уровень
        {
            _delay_ms(100);            //Ждем 100 мс
            if (PIND & (1<< BUTTON_PIN))    //Если на выводе по прежнему высокий уровень
            {
                PORTB &= ~(1 << LED_PIN);   //Отключаем светодиод
            }
        }
        else                            //Есди на выводе кнопки низкий уровень
        {
            _delay_ms(100);                 //Ждем 100 мс
            if (!(PIND & (1 << BUTTON_PIN)))   //и проверяем состояние вывода
            {
                PORTB |= 1 << LED_PIN;      //Уровень по прежнему низкий _> включаем светодтод
            }
		}
	}
	return 0;
}


