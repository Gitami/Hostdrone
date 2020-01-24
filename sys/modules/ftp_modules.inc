<?php
      $ftpmodulesarray[] = "";

      $ftpmodulesarray["Server"] = array(
       "state"      => $strftpsystype,
       "alternate"    => $strftpsystypea
      );

      $ftpmodulesarray["Connection"] = array(
       "state"      => $strftpconnectcheck,
       "alternate"    => $strftpconnectchecka
      );

      $ftpmodulesarray["SSL Connect"] = array(
       "state"      => $sslftpconnsupport,
       "alternate"    => $sslftpconnsupporta
      );

      $ftpmodulesarray["Login"] = array(
       "state"      => $strftplogincheck,
       "alternate"    => $strftploginchecka
      );

      $ftpmodulesarray["Allow LIST"] = array(
       "state"      => $strftplistcmd,
       "alternate"    => $strftplistcmda
      );

      $ftpmodulesarray["RootDir access"] = array(
       "state"      => $strftpdirectorych,
       "alternate"    => $strftpdirectorycha
      );

      $ftpmodulesarray["Write access"] = array(
       "state"      => $strftpwriteaccess,
       "alternate"    => $strftpwriteaccessa
      );

      $ftpmodulesarray["chmod over FTP"] = array(
       "state"      => $strftpchmodaccess,
       "alternate"    => $strftpchmodaccessa
      );

      $ftpmodulesarray["Delete files"] = array(
       "state"      => $strftpdeletefile,
       "alternate"    => $strftpdeletefilea
      );

      $ftpmodulesarray["Timeout (TO)"] = array(
       "state"      => $ftpconnectiontimeout,
       "alternate"    => $ftpconnectiontimeouta
      );

      $ftpmodulesarray["Allow TO change"] = array(
       "state"      => $ftpconnectiontimeoutchange,
       "alternate"    => $ftpconnectiontimeoutchangea
      );

      $ftpmodulesarray["FTP Run-time"] = array(
       "state"      => $strftpconnectandopentimer,
       "alternate"    => $strftpconnectandopentimera
      );

?>
