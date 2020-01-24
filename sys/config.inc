<?php
// ##################################################################################
// # HostManager configuration ######################################################
// ##################################################################################
// # 1 = Enabled
// # 0 = Disabled
// ##################################################################################

// ----------------------------------------------------------------------------------
// System variables
// ----------------------------------------------------------------------------------

  $system_document_root = $_SERVER["DOCUMENT_ROOT"];   // full local path, default: $_SERVER["DOCUMENT_ROOT"]

// ----------------------------------------------------------------------------------
// Checklist
// ----------------------------------------------------------------------------------

  $docheck_php = 1;                               // PHP components and version check
  $docheck_asp = 0;                               // ASP components and version check
  $docheck_aspnet = 0;                            // .NET version check
  $docheck_mysql = 0;                             // MYSQL database connection check
  $docheck_ftp = 0;                               // FTP server connection check
  $docheck_email = 0;                             // Email server POP3 check

// ----------------------------------------------------------------------------------
// Servers settings
// ----------------------------------------------------------------------------------

  $mysql_address = "";                            // MYSQL server hostname or IP
  $mysql_dbname = "";                             // MYSQL database name
  $mysql_dbusername = "";                         // MYSQL username
  $mysql_dbpassword = "";                         // MYSQL password

  $ftp_address = "";   							  // FTP server hostname or IP
  $ftp_username = "";                             // FTP username
  $ftp_password = "";                             // FTP password
  $ftp_conndir = "";                              // FTP server directory path

  $email_address  = '';                           // POP3 server hostname or IP
  $email_imap_port = "143";                       // IMAP port (default: 143)
  $email_pop3_port = "110";                       // POP3 port (default: 110)
  $email_username = '';                           // POP3 username
  $email_password = '';                           // POP3 password

// ----------------------------------------------------------------------------------
// Look and feel
// ----------------------------------------------------------------------------------

  $setlanguage = "en";                            // default (english) = "en";

  $setskin = "default";                           // default = "default"
  $hostdronelogocolor = "0";                      // default = "0" (use "1" if running a dark skin)

  $footer_showicons = "1";                        // Show system icons in the footer.

  $usecustomlogo = "";                            // Swap hostdrone logo with your own

  $xmloutput = 0;                                 // Allow XML output
  $xmloutput_showicon = 0;                        // Public XML icons on site

  $header_showversion = "1";                      // Show version data in headline
  $header_showhostname = "1";                     // Show host/domain in page headline
  

// ----------------------------------------------------------------------------------
// Advanced features
// ----------------------------------------------------------------------------------

  $header_showjumplist = "0";                     // Show host/domain in page headline

  $jumplist = "";                                 // url to serverlist textfile. ex.: http://example.net/sys/serverlist.txt 
  
  $serverjumplisticons = "0";                     // Display icons in dropdownbox (does not work with IE)


?>


                   
