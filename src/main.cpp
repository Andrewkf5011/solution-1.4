#include <mbed.h>

enum { Red, Green, Blue, SRed, SGreen, SBlue};
DigitalOut LED[] = {
  DigitalOut(PTB22,1),
  DigitalOut(PTE26,1),
  DigitalOut(PTC21,1),
  DigitalOut(D5,1),
  DigitalOut(D9,1),
  DigitalOut(D8,1),

};

void LEDon(int n) {
  LED[n].write(0);
}
void LEDoff(int n) {
  LED[n].write(1);
}


enum { Btn1, Btn2, sw_up, sw_down, sw_left, sw_right, sw_center};
struct pushbutton {
    DigitalIn sw;
    bool invert;
} buttons[] = {
  {DigitalIn(SW2),true},
  {DigitalIn(SW3),true},
  {DigitalIn(A2),false},
  {DigitalIn(A3),false},
  {DigitalIn(A4),false},
  {DigitalIn(A5),false},
  {DigitalIn(D4),false},
};

bool ispressed(int b) {
  return (buttons[b].sw.read())^buttons[b].invert;
}

int main() {


    while(1) {
      int k;
      for( k=0 ; k<6 ; k++){
        LEDon(k);
        wait(0.5);
        LEDoff(k);
      }
    }
}
