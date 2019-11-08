struct tm  *data_atual, *data_entrega;     

 
  time(&emprestar->segundos2);
  data_atual = localtime(&emprestar->segundos2);



  printf("\n\nData de empréstimo........ %d/", data_atual->tm_mday);
  printf("%d/", data_atual->tm_mon+1);
  printf("%d\n", data_atual->tm_year+1900);

  printf("Hora ....................: %d:",data_atual->tm_hour);//hora   
  printf("%d:",data_atual->tm_min);//minuto
  printf("%d\n",data_atual->tm_sec);//segundo  


  
  time(&emprestar->segundos);
  emprestar->segundos = emprestar->segundos + 259200; 
  data_entrega = localtime(&emprestar->segundos); 

  printf("\n\nData para entrega........ %d/", data_entrega->tm_mday);
  printf("%d/", data_entrega->tm_mon+1);
  printf("%d\n", data_entrega->tm_year+1900);


  printf("Hora ...................: %d:",data_entrega->tm_hour); 
  printf("%d:",data_entrega->tm_min);
  printf("%d\n",data_entrega->tm_sec);