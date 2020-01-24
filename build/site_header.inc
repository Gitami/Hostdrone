<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xml:lang="da" lang="da" xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <title>HostDrone ver. <?php echo($systemversion . ' ' . $systemversionstate); ?></title>
  	<meta http-equiv="content-type" content="text/html; charset=UTF-8"/>
    <link type="image/x-icon" rel="shortcut icon" href="gfx/hostdrone.ico"/>
    <link type="text/css" rel="stylesheet" href="build/skins/<?php echo($setskin);?>/styles.css" title="primary"/>
  </head>
  <body>
  <div class="logocontainer">

<?php
  
  if($hostdronelogocolor == "0"){
    $hostdronelogo = "logoblack.png"; 
  }
  else{
    $hostdronelogo = "logowhite.png";
  }

  $sitelogopath = "gfx/logos/" . $hostdronelogo;
  if($usecustomlogo != "")
    {
      $sitelogopath = $usecustomlogo;
    }

  echo('<div style="position:absolute; top:0px; left:20px; z-index:5;">');
    echo('<img src="' . $sitelogopath . '" title="HostDrone" alt="Hostdrone logo"/>');
  echo('</div>');

  echo('<div style="position:absolute; top:0px; left:0px; width:99%; height:200px;">');
    
    echo('<div style="display:inline; clear:none;">');
      if($header_showversion == "1")
        {
          echo('<h2>HostDrone | Release: ' . $systemversionstate . ' ver.' . $systemversion . '</h2>');
        }
      if($header_showhostname == "1")
        {
          echo('<h1 class="httphost">');
            echo($_SERVER["HTTP_HOST"]);
          echo('</h1>');        
        }
  
    echo('</div>' . "\r\n");
    
    echo('<div style="display:inline; clear:none;">');
    
      if($header_showjumplist == "1")
        {
  

            echo('<form class="jumpform" action="exec/jumper.php" method="post">' . "\r\n\r\n");


              $liststr = url_exists($jumplist);
              if($liststr == "error"){
                echo('<small class="error" style="margin-bottom:4px;">Unable to load server-list</small>');
              }
              else{


                    echo('<small style="margin-bottom:4px;">' . $serverselecttext . '</small>' . "\r\n");
                    echo('<select name="hdserver" onchange="this.form.submit();">' . "\r\n");
        
              
                      $arrlines = explode("\n", $liststr);
                      for($i=0; $i < count($arrlines); $i++){

                          $item = explode('::', $arrlines[$i]);
                          $thisone = "";
                          $jumphost = explode('/', $item[1]);

                          if($_SERVER["HTTP_HOST"] == $jumphost[0]){
                              $thisone = (' selected="selected"');
                          }
      
                          if($serverjumplisticons == "1"){
                              $iconstyles = ('background-repeat:no-repeat; padding-left:22px; background-position:left; background-image:url(build/skins/' . $setskin . '/images/icons/');
                              if(strtolower($item[0]) == "windows"){
                                $srvtypeicon = 'serverwindows.png';
                              }
                              else if(strtolower($item[0]) == "linux"){
                                $srvtypeicon = 'serverlinux.png';
                              }
                              else{
                                $srvtypeicon = 'server.png';
                              }
                          }
      
                          echo('<option style="' . $iconstyles . $srvtypeicon . '" value="' . $item[1] . '" title="' . $item[1] . '"' . $thisone . '>' . "\r\n" . $jumphost[0] . "\r\n" . '</option>' . "\r\n");
                          unset($jumphost);
                        }


                    echo('</select>' . "\r\n\r\n");
                    // echo('<noscript>' . "\r\n");
                      echo('<input name="submit" type="image" value="Change" src="build/skins/' . $setskin . '/images/icons/jump.png" style="height:19px; width:19px; margin:-5px 0px -5px 0px;">' . "\r\n");
                    //echo('</noscript>' . "\r\n\r\n");


              }


            echo('</form>' . "\r\n");
         
        }
    echo('</div>' . "\r\n");


  echo('</div>' . "\r\n");

?>

  </div>
