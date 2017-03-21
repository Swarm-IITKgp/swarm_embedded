
void interrupt_init(){
  //Initialise the Timer and attach Interrupt.
  Timer1.initialize(50000);
  Timer1.attachInterrupt(calculateRPM);
  
  //Attach Interrupts to the encoders input.
  attachInterrupt(digitalPinToInterrupt(interruptEncoderPinA),increase_CounterA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptEncoderPinD),increase_CounterB, CHANGE);
}

void increase_CounterA() {
  ext_counterA++;
}

void increase_CounterB(){
  ext_counterB++;
}

void calculateRPM(){
  curr_rpmA=(ext_counterA*60)/(CPR*gear_ratio*del_t);
  curr_rpmB=(ext_counterB*60)/(CPR*gear_ratio*del_t);
  
  if(motion_direction==1){
    Dl=2*PI*wheel_radius*curr_rpmA*del_t/60;
    Dr=2*PI*wheel_radius*curr_rpmB*del_t/60;
  }
  else if(motion_direction==2){
    Dl=(-1)*2*PI*wheel_radius*curr_rpmA*del_t/60;
    Dr=2*PI*wheel_radius*curr_rpmB*del_t/60;
  }
  else if(motion_direction==3){
    Dl=2*PI*wheel_radius*curr_rpmA*del_t/60;
    Dr=(-1)*2*PI*wheel_radius*curr_rpmB*del_t/60;
  }
  else if(motion_direction==4){
    Dl=(-1)*2*PI*wheel_radius*curr_rpmA*del_t/60;
    Dr=(-1)*2*PI*wheel_radius*curr_rpmB*del_t/60;
  }  

  Dc=(Dl+Dr)/2;
  theta+=(Dr-Dl)/w2w;
  curr_pos_x+=(Dc*cos(theta));
  curr_pos_y+=(Dc*sin(theta));
  
//  Serial.print(ext_counterA);
//  Serial.print("\t");
//  Serial.println(ext_counterB);
  
  ext_counterA=0;
  ext_counterB=0;

}
