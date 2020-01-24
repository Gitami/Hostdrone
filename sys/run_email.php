<?php

    if($_GET["format"] == "xml_1.0")
      {
        include('engine_php.inc');
      }

    include('modules/email_modules.inc');
    $i = 1; // to loop over
    if($_GET["format"] == "xml_1.0")
      {
        if($xmloutput == 1)
          {
            header('Content-Type: application/xml');
            header('Content-Disposition: inline; emailserverstatus.xml');
            echo('<?xml version="1.0" encoding="UTF-8"?>' . "\r\n");
    
            $xmlbuildstring = $xmlbuildstring . ('<emailserverstatus>' . "\r\n");
              reset($emailmodulesarray);
              foreach($emailmodulesarray as $value)
                {
                  if(count($emailmodulesarray) > $i)
                  {
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '<emailmodule>' . "\r\n"); 
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<service>' . key($emailmodulesarray) . '</service>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<state>' . strip_tags($emailmodulesarray[key($emailmodulesarray)]["state"]) . '</state>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<details>' . strip_tags($emailmodulesarray[key($emailmodulesarray)]["details"]) . '</details>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<alternate>' . strip_tags($emailmodulesarray[key($emailmodulesarray)]["alternate"]) . '</alternate>' . "\r\n");
                      next($emailmodulesarray);
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '</emailmodule>' . "\r\n");
                  }
                  $i++;
                }
            $xmlbuildstring = ($xmlbuildstring . '</emailserverstatus>' . "\r\n");
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
            $xmlicon = '<a href="sys/run_email.php?format=xml_1.0"><img src="build/skins/' . $setskin . '/images/icons/xml.png" title="' . $xmlicon_titletext . '" alt="XML icon" class="xmlicon"/></a>';
          }

        echo('<h3>Email ' . $xmlicon . '</h3><small></small>');

        echo('<table>');
   
        echo('<tr><th>' . $th_service . '</th><th>' . $th_state . '</th><th>' . $th_details . '</th></tr>');

          reset($emailmodulesarray);
          foreach($emailmodulesarray as $value)
            {
              if(count($emailmodulesarray) > $i)
              {
                if($emailmodulesarray[key($emailmodulesarray)]["alternate"] != "")
                {
                  $alternateCurserHelp = ' style="cursor:help;"';
                }
                else
                {
                  $alternateCurserHelp = "";
                }
                $xmlbuildstring = ($xmlbuildstring . "\t" . '<tr title="' . $emailmodulesarray[key($emailmodulesarray)]["alternate"] . '"' . $helponalternate . '>' . "\r\n"); 
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn1" style="background-image:url(build/skins/' . $setskin . '/images/layout/fieldtitlebg.png); background-repeat:no-repeat;">' . key($emailmodulesarray) . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn2">' . $emailmodulesarray[key($emailmodulesarray)]["state"] . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn3"' . $alternateCurserHelp . '>' . $emailmodulesarray[key($emailmodulesarray)]["details"] . '</td>' . "\r\n");
                  next($emailmodulesarray);
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


