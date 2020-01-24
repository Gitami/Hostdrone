<?php
    if($_GET["format"] == "xml_1.0")
      {
        include('engine_php.inc');
      }

    include('modules/php_modules.inc');
    $i = 1; // to loop over
    if($_GET["format"] == "xml_1.0")
      {
        if($xmloutput == 1)
          {

            header('Content-Type: application/xml');
            header('Content-Disposition: inline; phpserverstatus.xml');
            echo('<?xml version="1.0" encoding="UTF-8"?>' . "\r\n");
    
            $xmlbuildstring = $xmlbuildstring . ('<phpserverstatus>' . "\r\n");
              reset($modulesarray);
              foreach($modulesarray as $value)
                {
                  if(count($modulesarray) > $i)
                  {
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '<phpmodule>' . "\r\n"); 
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<service>' . key($modulesarray) . '</service>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<state>' . strip_tags($modulesarray[key($modulesarray)]["state"]) . '</state>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<version>' . strip_tags($modulesarray[key($modulesarray)]["version"]) . '</version>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<alternate>' . strip_tags($modulesarray[key($modulesarray)]["alternate"]) . '</alternate>' . "\r\n");
                      next($modulesarray);
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '</phpmodule>' . "\r\n");
                  }
                  $i++;
                }
            $xmlbuildstring = ($xmlbuildstring . '</phpserverstatus>' . "\r\n");
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
            $xmlicon = '<a href="sys/run_php.php?format=xml_1.0"><img src="build/skins/' . $setskin . '/images/icons/xml.png" title="' . $xmlicon_titletext . '" alt="XML icon" class="xmlicon"/></a>';
          }
        echo('<h3>PHP ' . $xmlicon . '</h3><small>' . $modulesarray["PHP"]["version"] . '</small>');

        echo('<table>');
   
        echo('<tr><th>' . $th_service . '</th><th>' . $th_state . '</th><th>' . $th_version . '</th></tr>');

          reset($modulesarray);
          foreach($modulesarray as $value)
            {
              if(count($modulesarray) > $i)
              {
                if($modulesarray[key($modulesarray)]["alternate"] != "")
                {
                  $alternateCurserHelp = ' style="cursor:help;"';
                }
                else
                {
                  $alternateCurserHelp = "";
                }
                $xmlbuildstring = ($xmlbuildstring . "\t" . '<tr title="' . $modulesarray[key($modulesarray)]["alternate"] . '"' . $helponalternate . '>' . "\r\n"); 
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn1" style="background-image:url(build/skins/' . $setskin . '/images/layout/fieldtitlebg.png); background-repeat:no-repeat;">' . key($modulesarray) . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn2">' . $modulesarray[key($modulesarray)]["state"] . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn3"' . $alternateCurserHelp . '>' . doTrimString($modulesarray[key($modulesarray)]["version"], $versionstringmaxlength) . '</td>' . "\r\n");
                  next($modulesarray);
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


