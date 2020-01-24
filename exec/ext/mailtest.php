<?php 

  ini_set("SMTP","vip.cybercity.dk" ); 
  ini_set('sendmail_from', 'system@hostdrone.com'); 

  $Subject="Trying to send"; 
  $SendTo="youremail@example.com"; 
  $Message2="Trying"; 

  if(mail($SendTo, $Subject, $Message2))
  { 
    echo("SUCCESS! (" . $SendTo . ")"); 
  }
  else
  { 
    echo("FAILED (" . $SendTo . ")"); 
  } 

?>
