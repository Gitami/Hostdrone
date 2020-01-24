<?php

  include("version.inc");

// ######################################################
// ## INI SET (php.ini)
// ######################################################

  ini_set('sendmail_from', 'system@hostdrone.com'); 


// ######################################################
// ## Global variables
// ######################################################

  // path excl. filename
  $localpath_nofile_arr = explode('/', $_SERVER["PHP_SELF"]);
  $localpath_nofile = "";
  $pathvalueticker = 0;
  foreach ($localpath_nofile_arr as $pathvalue)
    {
      if(!strstr($pathvalue, ".php") && $pathvalue != "" && $pathvalue != "sys") 
        {
          $localpath_nofile = ($localpath_nofile . $pathvalue . '/');
        }
      $pathvalueticker = $pathvalueticker + 1;
    }

  unset($pathvalueticker);

  $versionstringmaxlength = 20; // The maximun length of the version string html output (to long will break the table layout)
                            

// ######################################################
// ## INCLUDES
// ######################################################

  include("config.inc");

  // $languagefilepath = ($system_document_root . '/' . 'sys/language/');
  $languagefilepath = ($system_document_root . '/' . $localpath_nofile . 'sys/language/');
               
  $languagevar = ($setlanguage . '.inc');
  
    if(@file_exists($languagefilepath . $languagevar))
      {
        include($languagefilepath . $languagevar);
      }
    else
      {
        if(file_exists($languagefilepath . 'en.inc'))
          {
            include($languagefilepath . 'en.inc');
          }
      }


// ######################################################
// ## REG EX. PATTERNS
// ######################################################

  $removeallbutnumberspattern = '([a-zA-Z:])';
  $removeallbutnumbersreplace = '';
  $removedecimals = '/\..*/';

// ######################################################
// ## Outputformatting
// ######################################################

  $serviceon  = ('<a class="validate-green">' . $output_service_on . '</a>');
  $serviceoff = ('<a class="validate-red">' . $output_service_off . '</a>');
  $serviceavailable  = ('<a class="validate-green">' . $output_service_available . '</a>');
  $serviceunavailable = ('<a class="validate-red">' . $output_service_notavailable . '</a>');
  $serviceconnected  = ('<a class="validate-green">' . $output_service_connected . '</a>');
  $servicenotconnected = ('<a class="validate-red">' . $output_service_notconnected . '</a>');
  $servicenotpossible = ('<a class="validate-grey">' . $output_service_notpossible . '</a>');
  $servicena = ('<a class="validate-grey">' . $output_service_unknown . '</a>');
  $serviceloggedin  = ('<a class="validate-green">' . $output_service_loggedin . '</a>');
  $servicenotloggedin = ('<a class="validate-red">' . $output_service_notloggedin . '</a>');

  $servicenotrunning = ('<p class="error">' . $service_notinstalled . '</p>');
  $servicenotresolving = ('<p class="error">' . $service_filenotresolving . '</p>');
  $servicenofile = ('<p class="error">' . $service_filenotexist . '</p>');
  $servicenoconfig = ('<p class="error">' . $service_notconfigured . '</p>');

// ######################################################
// ## FUNCTIONS
// ######################################################

  function milisectotaltimer()
  {
     list($milisec, $seconds) = explode(" ", microtime());
     return ((float)$milisec + (float)$seconds);
  }

  // Check if a URL resolves, return content if yes, error if no
  function url_exists($url) {
    $handle = @fopen($url,'r');
    
    if($handle == FALSE){
      return "error";
    }
    else{
      while (!feof($handle)) {
        $linecontent = fgets($handle, 8192);
        $pieces = explode("<", $linecontent);
        if(isset($pieces[1])){
          return "error";
        }
        else{
          $contents = $contents . $linecontent;
        }
      }
      return $contents;
    }
  }

  // FUNCTION ¤ Return a trimmed string
  function doTrimString($str, $max_length){     //  ex. doTrimString($myarticle, 100)
    if(strlen($str) > $max_length){ 
      $offset = ($max_length - 3) - strlen($str); 
      $str = substr($str, 0, strrpos($str, ' ', $offset));
    }
    return $str; 
  } 


// ######################################################
// ## MYSQL START
// ######################################################


  $mysqltimerstart = milisectotaltimer();

  $doMySQL = 1;

	if (function_exists('mysql_connect')){

	    if (!$strmysqlconnect = @mysql_connect($mysql_address, $mysql_dbusername, $mysql_dbpassword)) {
	       $doMySQL = 0;
	    }

	    if (!$strmysqlopendb = @mysql_select_db($mysql_dbname, $strmysqlconnect)){
	       $doMySQL = 0;
	    }

	  if($doMySQL == 1){
	  
	    $mysqltimerend = milisectotaltimer();
	  
	    $strmysqlserverversion1 = @mysql_get_host_info();
	    $strmysqlserverversion1 = explode(" ", $strmysqlserverversion1);
	    $strmysqlserverversion = trim($strmysqlserverversion1[0]);
	    
	    $strmysqlserverversion = gethostbyname($strmysqlserverversion);
	  
	    $strmysqlprotocolversion = $strmysqlserverversion1[2];;
	    $strmysqlprotocolversionv = @mysql_get_proto_info();
	    
	    
	    $strmysqlserverversionv = @mysql_get_server_info();
	  
	    $strmysqlcharset = @mysql_client_encoding($strmysqlconnect);
	  
	    $arraymysqlstatistics = explode('  ', @mysql_stat($strmysqlconnect));
	  
	      $strmysqlstatisticsuptime = $arraymysqlstatistics[0];
		$mysqluptimedays = preg_replace($removedecimals, '', (preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsuptime)/60/60/24));
		$mysqluptimehours = preg_replace($removedecimals, '', (preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsuptime)/60/60));
		$mysqluptimeminutes = preg_replace($removedecimals, '', (preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsuptime)/60));
		  $strmysqlstatisticsuptime = ($mysqluptimedays . "D, " . ($mysqluptimehours - ($mysqluptimedays * 24)) . "H, " . ($mysqluptimeminutes - ($mysqluptimehours * 60)) . "M");
	  
	      $strmysqlstatisticsthreads = $arraymysqlstatistics[1];
		$strmysqlstatisticsthreads = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsthreads);
	  
	      $strmysqlstatisticsquestions = $arraymysqlstatistics[2];
		$strmysqlstatisticsquestions = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsquestions);
	  
	      $strmysqlstatisticsslowqueries = $arraymysqlstatistics[3];
		$strmysqlstatisticsslowqueries = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsslowqueries);
	  
	      $strmysqlstatisticsopens = $arraymysqlstatistics[4];
		$strmysqlstatisticsopens = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsopens);
	  
	      $strmysqlstatisticsflushtables = $arraymysqlstatistics[5];
		$strmysqlstatisticsflushtables = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsflushtables);
	  
	      $strmysqlstatisticsopentables = $arraymysqlstatistics[6];
		$strmysqlstatisticsopentables = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsopentables);
	  
	      $strmysqlstatisticsqueriespersecond = $arraymysqlstatistics[7];
		$strmysqlstatisticsqueriespersecond = preg_replace($removeallbutnumberspattern, $removeallbutnumbersreplace, $strmysqlstatisticsqueriespersecond);
	  
	    $strmysqlconnectandopentimer = round(($mysqltimerend - $mysqltimerstart), 3) . " sec.";
	    $strmysqlconnectandopentimerv = "";
	  
	    @mysql_close($strmysqlconnect);
	}
	else{
		$strmysqlserverversion = $serviceunavailable;
		$strmysqlserverversionv = "";
		$strmysqlprotocolversion = $servicenotpossible;
		$strmysqlprotocolversionv = "parrent: server";
		$strmysqlcharset = $servicenotpossible;
		$strmysqlcharsetv = "parrent: connect";
		$strmysqlstatisticsuptime = $servicenotpossible;
		$strmysqlstatisticsuptimev = "parrent: server";
		$strmysqlstatisticsthreads = $servicenotpossible;
		$strmysqlstatisticsthreadsv = "parrent: server";
		$strmysqlstatisticsquestions = $servicenotpossible;
		$strmysqlstatisticsquestionsv = "parrent: server";
		$strmysqlstatisticsslowqueries = $servicenotpossible;
		$strmysqlstatisticsslowqueriesv = "parrent: server";
		$strmysqlstatisticsopens = $servicenotpossible;
		$strmysqlstatisticsopensv = "parrent: server";
		$strmysqlstatisticsflushtables = $servicenotpossible;
		$strmysqlstatisticsflushtablesv = "parrent: server";
		$strmysqlstatisticsopentables =$servicenotpossible;
		$strmysqlstatisticsopentablesv = "parrent: server";
		$strmysqlstatisticsqueriespersecond = $servicenotpossible;
		$strmysqlstatisticsqueriespersecondv = "parrent: server";
		$strmysqlconnectandopentimer = $servicenotpossible;
		$strmysqlconnectandopentimerv = "parrent: server";
	}
  }

// ######################################################
// ## FTP START
// ######################################################

  if (function_exists('ftp_connect')){


	if (function_exists('ftp_ssl_connect')){

		$sslftpconntest = @ftp_ssl_connect($ftp_address);
	
		if (@ftp_login($sslftpconntest, $ftp_username, $ftp_password)){
			$sslftpconnsupport = $serviceconnected;
		}
		else{
			$sslftpconnsupport = $servicenotconnected;
			$sslftpconnsupporta = "";
		}
	
		@ftp_close($sslftpconntest);

	}
	else{
		$sslftpconnsupport = $servicenotconnected;
	}



	  $ftptimerstart = milisectotaltimer();

	      $strftpconnect = @ftp_connect($ftp_address);

	      // Timeout
	      $ftpconnectiontimeout = (@ftp_get_option($strftpconnect, FTP_TIMEOUT_SEC) . " sec.");
	      $ftpconnectiontimeouta = "";

	      // TimeoutChange
	      $myTimeOutValue = 120;
	      @ftp_set_option($strftpconnect, FTP_TIMEOUT_SEC, $myTimeOutValue);

	      if(@ftp_get_option($strftpconnect, FTP_TIMEOUT_SEC) == $myTimeOutValue)
	      {
		$ftpconnectiontimeoutchange = $serviceconnected;
		$ftpconnectiontimeoutchangea = $myTimeOutValue . " sec.";
	      }
	      else
	      {
		$ftpconnectiontimeoutchange = $servicenotconnected;
		$ftpconnectiontimeoutchangea = "aasdfsdf";
	      }

	    $ftptimerend = milisectotaltimer();



	  if (!$strftpconnect)
	    {

		// Check that cannot be completed, due to failure of this one (child-checks)
		$strftpconnectcheck = $servicenotpossible;
		$strftpconnectchecka = "parrent: server";
		$sslftpconnsupport = $servicenotpossible;
		$sslftpconnsupporta = "parrent: server";
		$strftplogincheck = $servicenotpossible;
		$strftploginchecka = "parrent: connect";
		$strftplistcmd = $servicenotpossible;
		$strftplistcmda = "parrent: login";
		$strftpdirectorych = $servicenotpossible;
		$strftpdirectorycha = "parrent: dir";
		$strftpwriteaccess = $servicenotpossible;
		$strftpwriteaccessa = "parrent: cd";
		$strftpchmodaccess = $servicenotpossible;
		$strftpchmodaccessa = "parrent: write";
		$strftpdeletefile = $servicenotpossible;
		$strftpdeletefilea = "parrent: chmod";
		$ftpconnectiontimeoutchange = $servicenotpossible;
		$ftpconnectiontimeoutchangea = "parrent: connect";
		$ftpconnectiontimeout = $servicenotpossible;
		$ftpconnectiontimeouta = "parrent: connect";
		$strftpsystype = $serviceunavailable;
		$strftpsystypea = "";

	    }
	  else
	    {
	      $strftpconnectcheck = $serviceconnected;
	      if (@ftp_login($strftpconnect, $ftp_username, $ftp_password))
		{
		  $strftplogincheck = $serviceloggedin;
		  $strftploginchecka = "";

		      $filename = "hostdrone.txt";
		      
		      $file = ($system_document_root . '/' . $localpath_nofile . 'sys/files/' .$filename); // local file to upload
		      
		      $fp = @fopen($file, 'r'); // read from file

		      if(@ftp_nlist($strftpconnect, ".") !== false) // Array of contents for the current directory, returns false if fails
			{
			  $strftplistcmd = $serviceconnected;
			  $strftplistcmda = "";

			      if (@ftp_chdir($strftpconnect, $ftp_conndir)) // Change directory
			      {
				  $strftpdirectorych = $serviceconnected;
				  $strftpdirectorycha = "";

				      if(@ftp_fput($strftpconnect, $filename, $fp, FTP_ASCII)) // Attempt FTP file upload
				      {
				        $strftpwriteaccess = $serviceconnected;
				        $strftpwriteaccessa = $filename;


				              if (@ftp_chmod($strftpconnect, 0644, $filename) !== false)
				              {
				                $strftpchmodaccess = $serviceconnected;
				                $strftpchmodaccessa = $chmodresult;
				              }
				              else
				              {
				                $strftpchmodaccess = $servicenotconnected;
				                $strftpchmodaccessa = "";
				              }


				                if (@ftp_delete($strftpconnect, $filename)) // delete file
				                {
				                  $strftpdeletefile = $serviceconnected;
				                  $strftpdeletefilea = "";
				                }
				                else
				                {
				                  $strftpdeletefile = $servicenotconnected;
				                  $strftpdeletefilea = "";
				                }
			   }
				      else
				      {
				        $strftpwriteaccess = $servicenotconnected;
				        $strftpwriteaccessa = $filename;

						// Check that cannot be completed, due to failure of this one (child-checks)
						$strftpchmodaccess = $servicenotpossible;
					        $strftpchmodaccessa = "parrent: write";
						$strftpdeletefile = $servicenotpossible;
						$strftpdeletefilea = "parrent: chmod";
				      }

			      }
			      else
			      {
				$strftpdirectorych = $servicenotconnected;
				$strftpdirectorycha = "";

					// Check that cannot be completed, due to failure of this one (child-checks)
					$strftpwriteaccess = $servicenotpossible;
					$strftpwriteaccessa = "parrent: cd";
					$strftpchmodaccess = $servicenotpossible;
					$strftpchmodaccessa = "parrent: write";
					$strftpdeletefile = $servicenotpossible;
					$strftpdeletefilea = "parrent: chmod";

			      }

			}
			else
			{
			  $strftplistcmd = $servicenotconnected;
			  $strftplistcmda = "";

				// Check that cannot be completed, due to failure of this one (child-checks)
				$strftpdirectorych = $servicenotpossible;
				$strftpdirectorycha = "parrent: dir";
				$strftpwriteaccess = $servicenotpossible;
				$strftpwriteaccessa = "parrent: cd";
				$strftpchmodaccess = $servicenotpossible;
				$strftpchmodaccessa = "parrent: write";
				$strftpdeletefile = $servicenotpossible;
				$strftpdeletefilea = "parrent: chmod";
			}
		
		}
	      else
		{
		  $strftplogincheck = $servicenotloggedin;
		  $strftploginchecka = "";

			// Check that cannot be completed, due to failure of this one (child-checks)
			$strftplistcmd = $servicenotpossible;
			$strftplistcmda = "parrent: login";
			$strftpdirectorych = $servicenotpossible;
			$strftpdirectorycha = "parrent: dir";
			$strftpwriteaccess = $servicenotpossible;
			$strftpwriteaccessa = "parrent: cd";
			$strftpchmodaccess = $servicenotpossible;
			$strftpchmodaccessa = "parrent: write";
			$strftpdeletefile = $servicenotpossible;
			$strftpdeletefilea = "parrent: chmod";
		}

	      @fclose($fp);

		      if(strlen($ftp_address) >= 16)
		      {
			$strftpsystype = (substr($ftp_address,0,13));
		      }
		      else
		      {
			$strftpsystype = $ftp_address;
		      }


		$strftpsystypea  = @ftp_systype($strftpconnect);





	      @ftp_close($strftpconnect);
	    }

	    $strftpconnectandopentimer  = $serviceconnected;  
	    $strftpconnectandopentimera = round(($ftptimerend - $ftptimerstart), 5) . " sec";  
	}

// ######################################################
// ## PHP START
// ######################################################
  // ## PHPINFO() MODULE VARIABLES ARRAY, Amite 2009-06-27
  // ######################################################

  $pattern1 = "/^\<tr\>.*/i";
  $pattern2 = "/^\<h2\>.*/i";
  $actionstring = ('http://' . $_SERVER["HTTP_HOST"] . '/' . $localpath_nofile . 'exec/modules.php');

  $lines = file($actionstring);

  foreach ($lines as $line_num => $line)
    {
      if (preg_match($pattern2, $line, $resultarr1))
        {
          $currentheadline = trim(strip_tags($resultarr1[0]));
        }


      if (preg_match($pattern1, $line, $resultarr1))
        {
          $xarr1 = explode('</tr>', $line);
          $xarr2 = explode('</td>', $xarr1[0]);

            $xvar1 = $xarr2[0];
              $xvar1 = trim(strip_tags($xvar1));
            $xvar2 = $xarr2[1];
              $xvar2 = trim(strip_tags($xvar2));
            $xvar3 = $xarr2[2];
              $xvar3 = trim(strip_tags($xvar3));

            $xvar1a = ($currentheadline . '.' . $xvar1);
            if($xvar3 != "")
              {
                $modulesarr[$xvar1a] = ($xvar2 . '___' . $xvar3);
              }
            else
              {
                $modulesarr[$xvar1a] = ($xvar2);
              }
        }

    }

  // ######################################################

    $phploadedextension = get_loaded_extensions();

    $strphpversion1 = $_SERVER["GATEWAY_INTERFACE"];
      $strphpversion1arr = explode('/', $strphpversion1);
        $strphpversion = $strphpversion1arr[0];
    $strphpversionv = phpversion();

    // SERVER PLATFORM AND VERSION
    $strphpserverplatform1 = $_SERVER["SERVER_SOFTWARE"];
      $strphpserverplatform1arr = explode(" ", $strphpserverplatform1);
        $strphpserverplatform2 = $strphpserverplatform1arr[0];
          $strphpserverplatform2arr = explode('/', $strphpserverplatform2);
    $strphpserverplatform = $strphpserverplatform2arr[0];
    $strphpserverplatformv = $strphpserverplatform2arr[1];
    $strphpserverplatforma = $strphpserverplatform1arr[1];
    $strphpserverplatforma = str_replace('(', '', $strphpserverplatforma);
    $strphpserverplatforma = str_replace(')', '', $strphpserverplatforma);


    if (ini_get("register_globals") == true)
      {
        $strphpregglobal = 'on';
        $strphpregglobalv = "";
      }
    else
      {
        $strphpregglobal = 'off';
        $strphpregglobalv = "";
      }


    if (ini_get("safe_mode") == true)
      {
        $strphpsafemode = 'on';
        $strphpsafemodev = "";
      }
    else
      {
        $strphpsafemode = 'off';
        $strphpsafemodev = "";
      }


    if (get_magic_quotes_gpc() == 1)
      {
        $strphpmagicquotes = 'on';
        $strphpmagicquotesv = "";
      }
    else
      {
        $strphpmagicquotes = 'off';
        $strphpmagicquotesv = "";
      }


    if (function_exists('zend_version'))
      {
        $strphpzend = $serviceon;
        $strphpzendv = zend_version();
      }
    else
      {
        $strphpzend = $serviceoff;
        $strphpzendv = "";
      }


    if (function_exists('curl_version'))
      {
        $strphpcurl = $serviceon;
        $curlversion = curl_version();
          $strphpcurlv = $curlversion['version'];
      }
    else
      {
        $strphpcurl = $serviceoff;
        $strphpcurlv = "";
      }


    if (in_array("imap", $phploadedextension))
      {
        $strphpimapext = $serviceon;
        $strphpimapextv = $modulesarr["imap.IMAP c-Client Version"];
      }
    else
      {
        $strphpimapext = $serviceoff;
        $strphpimapextv = "";
      }


    if (function_exists('imagegd'))
      {
        $strphpgdlib = $serviceon;

        $strphpgdlib1 = $modulesarr["gd.GD Version"];
        $strphpgdlib1arr = explode(" ", $strphpgdlib1);
        $strphpgdlibv = str_replace('(', " ", $strphpgdlib1arr[1]);
        $strphpgdlibv = trim($strphpgdlibv);
        
        $strphpgdliba = 'Freetype ver. ' . $modulesarr["gd.FreeType Version"];
      }
    else
      {
        $strphpgdlib = $serviceoff;
        $strphpgdlibv = "";
      }


    if (in_array("SimpleXML", $phploadedextension))
      {
        $strphpsimplexml = $serviceon;

        $strphpsimplexml1 = $modulesarr["SimpleXML.Revision"];
        $strphpsimplexml1arr = explode(" ", $strphpsimplexml1);
        $strphpsimplexmlv = round($strphpsimplexml1arr[1], 3);
        $strphpsimplexmla = 'Revision ' . $strphpsimplexml1arr[1];
      }
    else
      {
        $strphpsimplexml = $serviceoff;
        $strphpsimplexmlv = "";
      }


    if (in_array("dom", $phploadedextension))
      {
        $strphpdom = $serviceon;
        $strphpdomv = $modulesarr["dom.libxml Version"];
        $strphpdoma = 'Released ' . $modulesarr["dom.DOM/XML API Version"];
      }
    else
      {
        $strphpdom = $serviceoff;
        $strphpdomv = "";
      }


    if (in_array("xml", $phploadedextension))
      {
        $strphplibxml = $serviceon;
        $strphplibxmlv = $modulesarr["xml.libxml2 Version"];
      }
    else
      {
        $strphplibxml = $serviceoff;
        $strphplibxmlv = "";
      }


    if (function_exists('xslt_backend_version')) // Sablotron. PHP < 5.0
      {
        $strphplibxsl = $serviceon;
        $strphplibxslv = xslt_backend_version();
        $strphplibxsla = xslt_backend_name();
      }
    else if (in_array("xsl", $phploadedextension)) // XLS. PHP > 5.0
      {
        $strphplibxsl = $serviceon;
        $strphplibxslv = $modulesarr["xsl.libxslt Version"];
        $strphplibxsla = 'libexslt ver. ' . $modulesarr["xsl.libexslt Version"];
      }
    else
      {
        $strphplibxsl = $serviceoff;
        $strphplibxslv = "";
      }

    if (in_array("xmlrpc", $phploadedextension))
      {
        $strphpxmlrpc = $serviceon;
        $strphpxmlrpcv = $modulesarr["xmlrpc.php extension version"];
      }
    else
      {
        $strphpxmlrpc = $serviceoff;
        $strphpxmlrpcv = "";
      }


    if (function_exists('tidy_get_release'))
      {
        $strphptidy = $serviceon;

        $strphptidy1 = $modulesarr["tidy.Extension Version"];
        $strphptidy1arr = explode(" ", $strphptidy1);
        $strphptidyv = $strphptidy1arr[0];

        $strphptidya = 'Released ' . $modulesarr["tidy.libTidy Release"];
      }
    else
      {
        $strphptidy = $serviceoff;
        $strphptidyv = "";
      }


    if (function_exists('mysqli_get_client_info'))
      {
        $strphpmysqliinfo = $serviceon;
        $strphpmysqliinfov = mysqli_get_client_info();
      }
    else
      {
        $strphpmysqliinfo = $serviceoff;
        $strphpmysqliinfov = "";
      }


    if (in_array("json", $phploadedextension))
      {
        $strphpjson = $serviceon;
        $strphpjsonv = $modulesarr["json.json version"];
      }
    else
      {
        $strphpjson = $serviceoff;
        $strphpjsonv = "";
      }


    if (in_array("iconv", $phploadedextension))
      {
        $strphpiconv = $serviceon;
        $strphpiconvv = $modulesarr["iconv.iconv library version"];
        $strphpiconva = 'Implementation ' .$modulesarr["iconv.iconv implementation"];
      }
    else
      {
        $strphpiconv = $serviceoff;
        $strphpiconvv = "";
      }

    if (in_array("magickwand", $phploadedextension) || in_array("imagick", $phploadedextension))
      {
        $strphpImageMagick = $serviceon;
        $strphpImageMagickv = $modulesarr["magickwand.MagickWand Extension Version"];
        $strphpImageMagickv = $strphpImageMagickv . $modulesarr["imagick.imagick module version"];
        $strphpImageMagicka = 'Implementation ' .$modulesarr["magickwand.ImageMagick version"];
        $strphpImageMagicka = $strphpImageMagicka . $modulesarr["imagick.ImageMagick version"];
		
      }
    else
      {
        $strphpImageMagick = $serviceoff;
        $strphpImageMagickv = "";
      }

    if (function_exists('PDF_get_value'))
      {
        $strphppdflib = $serviceon;
        $strphppdflibv = $modulesarr["pdf.PDFlib GmbH Version"];
        $strphppdfliba = 'PECL ver. ' . $modulesarr["pdf.PECL Version"];
        
        
      }
    else
      {
        $strphppdflib = $serviceoff;
        $strphppdflibv = ""; 
      }


    if (in_array("mcrypt", $phploadedextension))
      {
        $strphpmcrypt = $serviceon;
        $strphpmcryptv = $modulesarr["mcrypt.Version"]; 
        $strphpmcrypta = 'Released ' . $modulesarr["mcrypt.Api No"]; 
      }
    else
      {
        $strphpmcrypt = $serviceoff;
        $strphpmcryptv = "";
      }


    if (in_array("openssl", $phploadedextension))
      {
        $strphpopenssl = $serviceon;

        $strphpopenssl1 = $modulesarr["openssl.OpenSSL Version"];
        $strphpopenssl1arr = explode(" ", $strphpopenssl1);
        $strphpopensslv = $strphpopenssl1arr[1];
      }
    else
      {
        $strphpopenssl = $serviceoff;
        $strphpopensslv = "";
      }


    if (in_array("exif", $phploadedextension))
      {
        $strphpexif = $serviceon;

        $strphpexif1 = $modulesarr["exif.EXIF Version"];
        $strphpexif1arr = explode(" ", $strphpexif1);
        $strphpexifv = $strphpexif1arr[0];
        
        $strphpexifa = $modulesarr["exif.Supported filetypes"];
      }
    else
      {
        $strphpexif = $serviceoff;
        $strphpexifv = "";
      }


    if (in_array("zlib", $phploadedextension))
      {
        $strphpzlib = $serviceon;
        $strphpzlibv = $modulesarr["zlib.Compiled Version"];
      }
    else
      {
        $strphpzlib = $serviceoff;
        $strphpzlibv = "";
      }


    if (in_array("zip", $phploadedextension))
      {
        $strphpzip = $serviceon;
        $strphpzipv = $modulesarr["zip.Zip version"];
        $strphpzipa = 'Libzip ver. ' . $modulesarr["zip.Libzip version"];
      }
    else
      {
        $strphpzip = $serviceoff;
        $strphpzipv = "";
      }


    if (in_array("bz2", $phploadedextension))
      {
        $strphpbz2 = $serviceon;
        
        $strphpbz21 = $modulesarr["bz2.BZip2 Version"];
        $strphpbz21arr = explode(",", $strphpbz21);
        $strphpbz2v = $strphpbz21arr[0];
        
        $strphpbz2a = 'Released ' . $strphpbz21arr[1];
      }
    else
      {
        $strphpbz2 = $serviceoff;
        $strphpbz2v = "";
      }


    if (in_array("pcre", $phploadedextension))
      {
        $strphppcre = $serviceon;

        $strphppcre1 = $modulesarr["pcre.PCRE Library Version"];
        $strphppcre1arr = explode(" ", $strphppcre1);
        $strphppcrev = $strphppcre1arr[0];
        
        $strphppcrea = 'Released ' . $strphppcre1arr[1];
      }
    else
      {
        $strphppcre = $serviceoff;
        $strphppcrev = "";
      }


    if (in_array("SQLite", $phploadedextension))
      {
        $strphpsqlite = $serviceon;
        $strphpsqlitev = sqlite_libversion();
        $strphpsqlitea = 'Encoding ' . sqlite_libencoding();
      }
    else
      {
        $strphpsqlite = $serviceoff;
        $strphpsqlitev = "";
      }


    if (in_array("ADOdb", $phploadedextension))
      {
       	$strphpadodb = $serviceon;
       	$strphpadodbv = $modulesarr["ADOdb.API Version"];
      }
    else
      {
        $strphpadodb = $serviceoff;
        $strphpadodbv = "";
      }


    if (in_array("svn", $phploadedextension))
      {
       	$strphpsvn = $serviceon;
       	$strphpsvnv = $modulesarr["svn.svn extension version"];
       	$strphpsvna = 'client version: ' . $modulesarr["svn.svn client version"];
      }
    else
      {
        $strphpsvn = $serviceoff;
        $strphpsvnv = "";
      }


    if (in_array("geoip", $phploadedextension))
      {
       	$strphpgeoip = $serviceon;
       	$strphpgeoipv = $modulesarr["geoip.geoip extension version"];
       	$strphpgeoipa = 'lib version: ' . $modulesarr["geoip.geoip library version"];
      }
    else
      {
        $strphpgeoip = $serviceoff;
        $strphpgeoipv = "";
      }


    if (in_array("ps", $phploadedextension))
      {
       	$strphpps = $serviceon;
       	$strphppsv = $modulesarr["ps.PSlib Version"];
       	$strphppsa = $modulesarr["ps.Revision"] . "\r\n" . $modulesarr["ps.GD Support"];
      }
    else
      {
        $strphpps = $serviceoff;
        $strphppsv = "";
      }


    if (in_array("sysvmsg", $phploadedextension))
      {
       	$strphpsysvmsg = $serviceon;
       	$strphpsysvmsgv = str_replace('$Revision: ', '', $modulesarr["sysvmsg.Revision"]);
       	$strphpsysvmsgv = str_replace('$', '', $strphpsysvmsgv);
	$strphpsysvmsgv = trim($strphpsysvmsgv);
      }
    else
      {
        $strphpsysvmsg = $serviceoff;
        $strphpsysvmsgv = "";
      }



// ######################################################
// ## Email START
// ######################################################

	 if ($strphpimapext == $serviceon){

    		// IMAP check
    		$emailtimerstart = milisectotaltimer(); // Timer Start
    
    		$mailbox_imap = '{'.$email_address.':'.$email_imap_port.'/notls}INBOX';
    		if($einbox = @imap_open($mailbox_imap,$email_username,$email_password)){
    			$emailconnstate = $serviceconnected;
    
    			$emailmsgcount = imap_num_msg($einbox);
    			$emailmsgcountv = "0";
    
    			for($x=$total; $x>0; $x--){
    			    $eheaders = imap_header($einbox, $x);
    			    $estructure = imap_fetchstructure($einbox, $x);
    			    $emailmsgcountv = (($emailmsgcountv) + (ceil($estructure-goog>bytes/1024000)));
    			  }
    			$emailmsgcountv = "~" . round($emailmsgcountv, 5) . " MB";
    			imap_close($einbox);
    		}
    		else{
    			$emailconnstate = $servicenotconnected;
    			$emailconnstatev = "";
    			$emailmsgcount = $servicenotpossible;
    			$emailmsgcountv = "";
    			$stremailconnectandlisttimer = $servicenotpossible;
    			$stremailconnectandlisttimerv = "";
    		}
    
    		// IMAP Load time counter output
    		$emailtimerend = milisectotaltimer();
    		
    		$stremailconnectandlisttimer = $servicenotpossible;
    		$stremailconnectandlisttimerv = "";
    		if($emailconnstate != $servicenotconnected){
    			$stremailconnectandlisttimer = (round(($emailtimerend - $emailtimerstart), 5));
    			$stremailconnectandlisttimerv = "(seconds)";
    		}
    
    
    		// IMAP connection state output
    		if(strlen($email_address) >= 13){
    			$emailconnstatev = (substr($email_address,0,13) . '...');
    		}
    		else{
    			$emailconnstatev = $email_address;
    		}
    
    
    		// POP3 check
    		$pop3timerstart = milisectotaltimer(); // Timer Start
    
    		$mailbox_pop3 = '{'.$email_address.':'.$email_pop3_port.'/pop3/notls}';
    		if($pop3box = @imap_open($mailbox_pop3,$email_username,$email_password)){
    
    			$pop3connstate = $serviceconnected;
    			$pop3msgcount = imap_num_msg($pop3box);
    
    			$pop3msgcountv = "0";
    			for($x=$total; $x>0; $x--){
    			    $eheaders = imap_header($pop3box, $x);
    			    $estructure = imap_fetchstructure($pop3box, $x);
    			    $pop3msgcountv = (($pop3msgcountv) + (ceil($estructure-goog>bytes/1024000)));
    			  }
    			$pop3msgcountv = "~" . round($pop3msgcountv, 5) . " MB";
    			imap_close($pop3box);
    		}
    		else{
    			$pop3connstate = $servicenotconnected;
    			$pop3connstatev = "";
    			$pop3msgcount = $servicenotpossible;
    			$pop3msgcountv = "";
    			$strpop3connectandlisttimer = $servicenotpossible;
    			$strpop3connectandlisttimerv = "";
    		}
    
    		// POP3 Load time counter output
    		$pop3timerend = milisectotaltimer();
    
    		$strpop3connectandlisttimer = $servicenotpossible;
    		$strpop3connectandlisttimerv = "";
    		if($pop3connstate != $servicenotconnected){
    			$strpop3connectandlisttimer = (round(($pop3timerend - $pop3timerstart), 5));
    			$strpop3connectandlisttimerv = "(seconds)";
    		}
    
    		// POP3 connection state output
    		if(strlen($email_address) >= 13){
    			$pop3connstatev = (substr($email_address,0,13) . '...');
    		}
    		else{
    			$pop3connstatev = $email_address;
    		}

    }


// ######################################################
// ## ALTERNATE START
// ######################################################


    $aspcomponentsarr = @file('http://' . $_SERVER["HTTP_HOST"] . '/' . $localpath_nofile . 'exec/objects.asp');

    $aspxcomponentsarr = @file('http://' . $_SERVER["HTTP_HOST"] . '/' . $localpath_nofile . 'exec/objects.aspx');


// ######################################################
// ## ASP START
// ######################################################


    if(!empty($aspcomponentsarr["0"])) // ScriptEngine
      {
        $aspcomponentScriptEngine = $serviceavailable;
        $aspcomponentScriptEnginev = $aspcomponentsarr["0"];
        $aspcomponentScriptEnginea = "VB Script Engine";
      }
    else
      {
        $aspcomponentScriptEngine = $serviceunavailable;
      }


    if(!empty($aspcomponentsarr["1"])) // GatewayInterface
      {
        $aspcomponentGatewayInterface = $aspcomponentsarr["1"];
        $aspcomponentGatewayInterfacev = "";
        $aspcomponentGatewayInterfacea = "";
      }
    else
      {
        $aspcomponentGatewayInterface = $serviceunavailable;
      }


    if(!empty($aspcomponentsarr["2"])) // ServerScriptTimeout
      {
        $aspcomponentServerScriptTimeout = $aspcomponentsarr["2"];
        $aspcomponentServerScriptTimeoutv = "";
        $aspcomponentServerScriptTimeouta = "";

      }
    else
      {
        $aspcomponentServerScriptTimeout = $servicena;
      }


    if(!empty($aspcomponentsarr["3"])) // LocaleID
      {
        $aspcomponentLocaleID = $aspcomponentsarr["3"];
        $aspcomponentLocaleIDv = "ID";
        $aspcomponentLocaleIDa = "Locale IDs Assigned by Microsoft";
      }
    else
      {
        $aspcomponentLocaleID = $serviceoff;
      }


    if($aspcomponentsarr["4"] == 1) // w3Image
      {
        $aspcomponentw3Image = $serviceon;
        $aspcomponentw3Imagev = "";
      }
    else
      {
        $aspcomponentw3Image = $serviceoff;
      }

    if($aspcomponentsarr["5"] == 1) // w3upload
      {
        $aspcomponentw3upload = $serviceon;
        $aspcomponentw3uploadv = "";
      }
    else
      {
        $aspcomponentw3upload = $serviceoff;
      }

    if($aspcomponentsarr["6"] == 1) // w3JMail
      {
        $aspcomponentw3JMail = $serviceon;
        $aspcomponentw3JMailv = "";
      }
    else
      {
        $aspcomponentw3JMail = $serviceoff;
      }

    if($aspcomponentsarr["7"] == 1) // w3NetUtils
      {
        $aspcomponentNetUtils = $serviceon;
        $aspcomponentNetUtilsv = "";
      }
    else
      {
        $aspcomponentNetUtils = $serviceoff;
      }

    if($aspcomponentsarr["8"] == 1) // w3info
      {
        $aspcomponentw3info = $serviceon;
        $aspcomponentw3infov = "";
      }
    else
      {
        $aspcomponentw3info = $serviceoff;
      }

    if($aspcomponentsarr["9"] == 1) // w3SiteTree
      {
        $aspcomponentw3SiteTree = $serviceon;
        $aspcomponentw3SiteTreev = "";
      }
    else
      {
        $aspcomponentw3SiteTree = $serviceoff;
      }

    if($aspcomponentsarr["10"] == 1) // ASPSmartUpload
      {
        $aspcomponentASPSmartUpload = $serviceon;
        $aspcomponentASPSmartUploadv = "";
      }
    else
      {
        $aspcomponentASPSmartUpload = $serviceoff;
      }

    if($aspcomponentsarr["11"] == 1) // ASPImage
      {
        $aspcomponentASPImage = $serviceon;
        $aspcomponentASPImagev = "";
      }
    else
      {
        $aspcomponentASPImage = $serviceoff;
      }

    if($aspcomponentsarr["12"] == 1) // ASPMail
      {
        $aspcomponentASPMail = $serviceon;
        $aspcomponentASPMailv = "";
      }
    else
      {
        $aspcomponentASPMail = $serviceoff;
      }

    if($aspcomponentsarr["13"] == 1) // JROJetEngine
      {
        $aspcomponentJROJetEngine = $serviceon;
        $aspcomponentJROJetEnginev = "";
      }
    else
      {
        $aspcomponentJROJetEngine = $serviceoff;
      }

    if($aspcomponentsarr["14"] == 1) // Persits Aspemail
      {
        $aspcomponentAspemail = $serviceon;
        $aspcomponentAspemailv = "";
      }
    else
      {
        $aspcomponentAspemail = $serviceoff;
      }

    if($aspcomponentsarr["15"] == 1) // Persits XUpload
      {
        $aspcomponentXUpload = $serviceon;
        $aspcomponentXUploadv = "";
      }
    else
      {
        $aspcomponentXUpload = $serviceoff;
      }

    if($aspcomponentsarr["16"] == 1) // Microsoft MSXML3
      {
        $aspcomponentMSXML3 = $serviceon;
        $aspcomponentMSXML3v = "";
      }
    else
      {
        $aspcomponentMSXML3 = $serviceoff;
      }

    if($aspcomponentsarr["17"] == 1) // Microsoft MSXML4
      {
        $aspcomponentMSXML4 = $serviceon;
        $aspcomponentMSXML4v = "";
      }
    else
      {
        $aspcomponentMSXML4 = $serviceoff;
      }

    if($aspcomponentsarr["18"] == 1) // Hexillion HexIcmp
      {
        $aspcomponentHexIcmp = $serviceon;
        $aspcomponentHexIcmpv = "";
      }
    else
      {
        $aspcomponentHexIcmp = $serviceoff;
      }

    if($aspcomponentsarr["19"] == 1) // Hexillion HexLookup
      {
        $aspcomponentHexLookup = $serviceon;
        $aspcomponentHexLookupv = "";
      }
    else
      {
        $aspcomponentHexLookup = $serviceoff;
      }

    if($aspcomponentsarr["20"] == 1) // Hexillion HexTcpQuery
      {
        $aspcomponentHexTcpQuery = $serviceon;
        $aspcomponentHexTcpQueryv = "";
      }
    else
      {
        $aspcomponentHexTcpQuery = $serviceoff;
      }

    if($aspcomponentsarr["21"] == 1) // Hexillion EmailConnection
      {
        $aspcomponentEmailConnection = $serviceon;
        $aspcomponentEmailConnectionv = "";
      }
    else
      {
        $aspcomponentEmailConnection = $serviceoff;
      }


// ######################################################
// ## ASPX START
// ######################################################


    if(!empty($aspxcomponentsarr["0"]))
      {
        $aspxcomponentversion = $serviceavailable;
          $tmparr = explode("." , $aspxcomponentsarr["0"]);
          $aspxcomponentversionv = $tmparr["0"] . '.' . $tmparr["1"];
          $aspxcomponentversiona = ".NET Framework\r\nBuild: " . $tmparr["2"] . "\r\nRevision: " . $tmparr["3"];
        unset($tmparr);
      }
    else
      {
        $aspxcomponent0 = $serviceunavailable;
      }

    if(!empty($aspxcomponentsarr["1"]))
      {
        $tmparr = explode("/", $aspxcomponentsarr["1"]);
          $aspxcomponentuser = $tmparr["1"];
          if($tmparr[0] == "WORKGROUP")
          {
            $tmpusrtype = $tmparr[0];
          }
          else
          {
            $tmpusrtype = "DOMAIN";
          }
          $aspxcomponentuserv = $tmpusrtype;
          $aspxcomponentusera = $tmparr[0];
        unset($tmparr);
      }
    else
      {
        $aspxcomponentuser = $servicena;
      }

    if(!empty($aspxcomponentsarr["2"]))
      {
        $aspxcomponentMachineName = $aspxcomponentsarr["2"];
        $aspxcomponentMachineNamev = "";
        $aspxcomponentMachineNamea = "";
      }
    else
      {
        $aspxcomponentMachineName = $servicena;
      }

    if(!empty($aspxcomponentsarr["3"]))
      {
        $tmparr = explode("\\", $aspxcomponentsarr["3"]);
          $aspxcomponentSystemDirectory = $tmparr[count($tmparr)-1];
          $aspxcomponentSystemDirectoryv = "";
          $aspxcomponentSystemDirectorya = $aspxcomponentsarr["4"];
        unset($tmparr);
      }
    else
      {
        $aspxcomponentSystemDirectory = $servicena;
      }

    if(!empty($aspxcomponentsarr["4"]))
      {
        $aspxcomponentWorkingSet = round(((($aspxcomponentsarr["5"])/1024)/1024), 2) . ' MB';
        $aspxcomponentWorkingSetv = $aspxcomponentsarr["4"];
        $aspxcomponentWorkingSeta = "Bytes of physical memory mapped to the process context";
      }
    else
      {
        $aspxcomponentWorkingSet = $servicena;
      }

    if(!empty($aspxcomponentsarr["5"]))
      {
        $aspxcomponentProcessorCount = $aspxcomponentsarr["5"];
        $aspxcomponentProcessorCountv = "core(s)";
        $aspxcomponentProcessorCounta = "The number of CPU cores available to Windows on the system";
      }
    else
      {
        $aspxcomponentProcessorCount = $servicena;
      }

    if(!empty($aspxcomponentsarr["6"]))
      {
        $aspxcomponentUptime = $aspxcomponentsarr["6"];
        $aspxcomponentUptimev = "";
        $aspxcomponentUptimea = "time passed since the last time the computer was started";
      }
    else
      {
        $aspxcomponentUptime = $servicena;
      }

?>
