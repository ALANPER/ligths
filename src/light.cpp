#include "ligth.hpp"
DigitalOut ligth[]={(PD_12),(PD_13),(PD_14)};//PD_12=0(STATE GREEN);PD_13=1(STATE YELLOW);PD_14=2(RED).
InterruptIn botao(PA_0);
int timed;
int state=1;
int i;
float times[]={20.0,4.0,10.0};
bool alert;
bool out;
Timer counter;
Ticker alarm;
Timeout timeout;

void clear_all (){
    int j;
    for(j=0;j<3;j++){
         ligth [j]=0;
        }
}

void transition(){
       clear_all ();
       if (state != 2){
           state++;
       }
       else {
           state =0;
       }
       ligth[state] = 1;
       timeout.attach (&transition, times[state]);// THE VARIABLE TIME OF OCCORENCE "CALLS" THE SPECIFIC STATE
    }
    
void yellow_blink() {
    ligth[1]= !ligth[1];
    }
void start_timer() {
    counter.start();
    }
    
    void finish_timer() { //interrupt for t<=3, downhill edge
    counter.stop();
    timed = counter.read();// read of the time button press
while(timed<=3&&ligth[0]==1){ // if<=3 green>>>>yellow
        transition();// chance for yellow(state=1)
        }
      if(timed>3&&timed<=10){
        if(out==0&&alert==0){    
                timeout.detach();
                clear_all();
                alarm.attach(&yellow_blink,0.5);
                alert=1;
                }
                
            else{
                clear_all();
                ligth[state]=1;
                timeout.attach(&transition, times[state]);
                alarm.detach();
                alert=0;
                    }
                }
    }
        
           while(timed>10){
                if (out==0){
                timeout.detach();
                alarm.detach();
                clear_all();
                out=1;
                alert=0;
                }
                
            
                else{
                
                state=2;
                ligth[state]=1;
                timeout.attach(&transition, times[state]);               
                out=0;
                }
          } 
           
    counter.reset();
}
       