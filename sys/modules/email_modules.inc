<?php

      $emailmodulesarray[] = "";

      $emailmodulesarray["IMAP Connect"] = array(
       "state"      => $emailconnstate,
       "details"    => $emailconnstatev,
       "alternate"    => $emailconnstatea
      );

      $emailmodulesarray["IMAP msg count"] = array(
       "state"      => $emailmsgcount,
       "details"    => $emailmsgcountv,
       "alternate"    => $emailmsgcounta
      );

      $emailmodulesarray["IMAP Load time"] = array(
       "state"      => $stremailconnectandlisttimer,
       "details"    => $stremailconnectandlisttimerv,
       "alternate"    => $stremailconnectandlisttimera
      );

      $emailmodulesarray["POP3 Connect"] = array(
       "state"      => $pop3connstate,
       "details"    => $pop3connstatev,
       "alternate"    => $pop3connstatea
      );

      $emailmodulesarray["POP3 msg count"] = array(
       "state"      => $pop3msgcount,
       "details"    => $pop3msgcountv,
       "alternate"    => $pop3msgcounta
      );

      $emailmodulesarray["POP3 Load time"] = array(
       "state"      => $strpop3connectandlisttimer,
       "details"    => $strpop3connectandlisttimerv,
       "alternate"    => $strpop3connectandlisttimera
      );

?>
