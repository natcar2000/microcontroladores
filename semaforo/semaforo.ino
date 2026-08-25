const int BOTAO_VERMELHO = 2;
const int BOTAO_AMARELO  = 3;
const int BOTAO_VERDE    = 4;

const int LED_VERMELHO = 8;
const int LED_AMARELO  = 9;
const int LED_VERDE    = 10;

int estado_anterior_vermelho = HIGH;
int estado_anterior_amarelo  = HIGH;
int estado_anterior_verde    = HIGH;

void setup()
{
    pinMode(BOTAO_VERMELHO, INPUT_PULLUP);
    pinMode(BOTAO_AMARELO, INPUT_PULLUP);
    pinMode(BOTAO_VERDE, INPUT_PULLUP);

    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);

    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
}

void loop()
{
    int estado_vermelho = digitalRead(BOTAO_VERMELHO);
    int estado_amarelo  = digitalRead(BOTAO_AMARELO);
    int estado_verde    = digitalRead(BOTAO_VERDE);

    if (estado_anterior_vermelho == HIGH && estado_vermelho == LOW)
    {
        digitalWrite(LED_VERMELHO, HIGH);
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(LED_VERDE, LOW);
    }

    if (estado_anterior_amarelo == HIGH && estado_amarelo == LOW)
    {
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_AMARELO, HIGH);
        digitalWrite(LED_VERDE, LOW);
    }

    if (estado_anterior_verde == HIGH && estado_verde == LOW)
    {
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(LED_VERDE, HIGH);
    }

    estado_anterior_vermelho = estado_vermelho;
    estado_anterior_amarelo = estado_amarelo;
    estado_anterior_verde = estado_verde;

    delay(20);
}
