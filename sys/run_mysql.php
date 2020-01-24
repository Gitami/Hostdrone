<?php
    if($_GET["format"] == "xml_1.0")
      {
        include('engine_php.inc');
      }

    include('modules/mysql_modules.inc');
    $i = 1; // to loop over
    if($_GET["format"] == "xml_1.0")
      {
        if($xmloutput == 1)
          {
            header('Content-Type: application/xml');
            header('Content-Disposition: inline; mysqlserverstatus.xml');
            echo('<?xml version="1.0" encoding="UTF-8"?>' . "\r\n");
    
            $xmlbuildstring = $xmlbuildstring . ('<mysqlserverstatus>' . "\r\n");
              reset($mysqlmodulesarray);
              foreach($mysqlmodulesarray as $value)
                {
                  if(count($mysqlmodulesarray) > $i)
                  {
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '<mysqlmodule>' . "\r\n"); 
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<service>' . key($mysqlmodulesarray) . '</service>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<state>' . strip_tags($mysqlmodulesarray[key($mysqlmodulesarray)]["state"]) . '</state>' . "\r\n");
                      $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<version>' . strip_tags($mysqlmodulesarray[key($mysqlmodulesarray)]["version"]) . '</version>' . "\r\n");
                      next($mysqlmodulesarray);
                    $xmlbuildstring = ($xmlbuildstring . "\t" . '</mysqlmodule>' . "\r\n");
                  }
                  $i++;
                }
            $xmlbuildstring = ($xmlbuildstring . '</mysqlserverstatus>' . "\r\n");
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
            $xmlicon = '<a href="sys/run_mysql.php?format=xml_1.0"><img src="build/skins/' . $setskin . '/images/icons/xml.png" title="' . $xmlicon_titletext . '" alt="XML icon" class="xmlicon"/></a>';
          }
        echo('<h3>MySQL ' . $xmlicon . '</h3><small>' . $strmysqlserverversionv . '</small>');

        echo('<table>');
    
        echo('<tr><th>' . $th_service . '</th><th>' . $th_result . '</th><th>' . $th_version . '</th></tr>');

          reset($mysqlmodulesarray);
          foreach($mysqlmodulesarray as $value)
            {
              if(count($mysqlmodulesarray) > $i)
              {
                if($mysqlmodulesarray[key($mysqlmodulesarray)]["alternate"] != "")
                {
                  $alternateCurserHelp = ' style="cursor:help;"';
                }
                else
                {
                  $alternateCurserHelp = "";
                }
                $xmlbuildstring = ($xmlbuildstring . "\t" . '<tr>' . "\r\n"); 
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn1" style="background-image:url(build/skins/' . $setskin . '/images/layout/fieldtitlebg.png); background-repeat:no-repeat;">' . key($mysqlmodulesarray) . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn2">' . $mysqlmodulesarray[key($mysqlmodulesarray)]["state"] . '</td>' . "\r\n");
                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn3"' . $alternateCurserHelp . '>' . doTrimString($mysqlmodulesarray[key($mysqlmodulesarray)]["version"], $versionstringmaxlength) . '</td>' . "\r\n");
                  next($mysqlmodulesarray);
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
