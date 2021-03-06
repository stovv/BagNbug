class Vibro
{
private:
    int pin;
public:
    Vibro(int pin);
    ~Vibro();
    void run();
    void stop();
    void my_melody();
};

Vibro::Vibro(int pin)
{
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

Vibro::~Vibro()
{
    pinMode(this->pin, INPUT);
}

void Vibro::run(){
    digitalWrite(this->pin, HIGH);
}

void Vibro::stop(){
    digitalWrite(this->pin, LOW);
}

void Vibro::my_melody(){
  run();
  delay(100); 
  stop();
  delay(50);
  run();
  delay(100);
  stop();
  run();
  delay(50);
}
