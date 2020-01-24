<?php
    if($_GET["format"] == "xml_1.0")
      {
        include('engine_php.inc');
      }

    include('modules/ftp_modules.inc');
    $i = 1; // to loop over
    if($_GET["format"] == "xml_1.0")
      {
        if($xmloutput == 1)
          {

            header('Content-Type: application/xml');
            header('Content-Disposition: inline; ftpserverstatus.xml');
            echo('<?xml version="1.0" encoding="UTF-8"?>' . "\r\n");
    
            $xmlbuildstring = $xmlbuildstring . ('<ftpserverstatus>' . "\r\n");
              reset($ftpmodulesarray);
              foreach($ftpmodulesarray as $value)
                {
                  if(count($ftpmodulesarray) > $i)
                  {
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '<ftpmodule>' . "\r\n"); 
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<service>' . key($ftpmodulesarray) . '</service>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<state>' . strip_tags($ftpmodulesarray[key($ftpmodulesarray)]["state"]) . '</state>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<alternate>' . strip_tags($ftpmodulesarray[key($ftpmodulesarray)]["alternate"]) . '</alternate>' . "\r\n");
                      next($ftpmodulesarray);
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '</ftpmodule>' . "\r\n");
                  }
                  $i++;
                }
            $xmlbuildstring = ($xmlbuildstring . '</ftpserverstatus>' . "\r\n");
            echo($xmlbuildstring);
            unset($xmlbuildstring);

          }
        else
          {
            echo($xmloutput_disabled);
          }
      }
    else
      {
        echo('<div class="maincontainer">' . "\r\n");

        $xmlicon = "";            
        if($xmloutput_showicon == 1)
          {
            $xmlicon = '<a href="sys/run_ftp.php?format=xml_1.0"><img src="build/skins/' . $setskin . '/images/icons/xml.png" title="' . $xmlicon_titletext . '" alt="XML icon" class="xmlicon"/></a>';
          }

        echo('<h3>FTP ' . $xmlicon . '</h3><small>' . $strftpsystypea . '</small>');

        echo('<table>');

        echo('<tr><th>' . $th_service . '</th><th>' . $th_state . '</th><th>' . $th_details . '</th></tr>');

          reset($ftpmodulesarray);
          foreach($ftpmodulesarray as $value)
            {
              if(count($ftpmodulesarray) > $i)
              {
                $xmlbuildstring = ($xmlbuildstring . "\t" . '<tr>' . "\r\n"); 
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn1" style="background-image:url(build/skins/' . $setskin . '/images/layout/fieldtitlebg.png); background-repeat:no-repeat;">' . key($ftpmodulesarray) . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn2">' . $ftpmodulesarray[key($ftpmodulesarray)]["state"] . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn3">' . doTrimString($ftpmodulesarray[key($ftpmodulesarray)]["alternate"], $versionstringmaxlength) . '</td>' . "\r\n");
                  next($ftpmodulesarray);
                $xmlbuildstring = ($xmlbuildstring . "\t" . '</tr>' . "\r\n");
              }
              $i++;
            }

        echo($xmlbuildstring);

        echo('</table>');
        echo('</div>' . "\r\n");
        unset($xmlbuildstring);
      }

?> 


