void Modefan(int state){
  int Ts = temp() ; 
  switch(state) {
    case 0:
      if (Ts == 25){
        Fan(50);
        //Serial.print(50) //
      }else if (Ts > 25){
        Fan(int(constrain((5*Ts)-75,0,100)));
        //Serila.print((5Ts)-75) // 
      }else if (Ts < 25){
        Fan(int(constrain((3.4*Ts)-35,0,100)));
        //Serial.print((3.4Ts)) // 
      }
      break;
    case 1:
      Fan(50);

      break;
    case 2:
      Fan(75);

      break;
    case 3:
      Fan(100);

      break;
  }
}