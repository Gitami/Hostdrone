<?php

  if($_GET["format"] == "xml_1.0")
    {
      include('engine_php.inc');
      $alt_ext = $_GET["ext"];
    }

  include('modules/' . $alt_ext . '_modules.inc');
  $i = 1; // to loop over
  if($_GET["format"] == "xml_1.0")
    {

      if($xmloutput == 1)
        {

          header('Content-Type: application/xml');
          header('Content-Disposition: inline; ' . $alt_ext . 'serverstatus.xml');
          echo('<?xml version="1.0" encoding="UTF-8"?>' . "\r\n");
  
          $xmlbuildstring = $xmlbuildstring . ('<' . $alt_ext . 'serverstatus>' . "\r\n");
            reset($alternatemodulesarray);
            foreach($alternatemodulesarray as $value)
              {
                if(count($alternatemodulesarray) > $i)
                {
                  $xmlbuildstring = ($xmlbuildstring . "\t" . '<' . $alt_ext . 'module>' . "\r\n"); 
                    $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<service>' . key($alternatemodulesarray) . '</service>' . "\r\n");
                    $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<state>' . strip_tags($alternatemodulesarray[key($alternatemodulesarray)]["state"]) . '</state>' . "\r\n");
                    $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<details>' . strip_tags($alternatemodulesarray[key($alternatemodulesarray)]["details"]) . '</details>' . "\r\n");
                    $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<alternate>' . strip_tags($alternatemodulesarray[key($alternatemodulesarray)]["alternate"]) . '</alternate>' . "\r\n");
                    next($alternatemodulesarray);
                  $xmlbuildstring = ($xmlbuildstring . "\t" . '</' . $alt_ext . 'module>' . "\r\n");
                }
                $i++;
              }
          $xmlbuildstring = ($xmlbuildstring . '</' . $alt_ext . 'serverstatus>' . "\r\n");
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

          $objectfilename = ($localpath_nofile . 'exec/objects.' . $alt_ext);
          
           if (file_exists($_SERVER["DOCUMENT_ROOT"] . '/' . $objectfilename))
              {
                $objectfile =   ('http://' . $_SERVER["HTTP_HOST"] . $objectfilename);

                $object1 = @implode('', @file($objectfile));

                if (!$object1)
                  {
                      echo('<h3>' . $alt_serv . '</h3>');
                      if ($hostformatcheck == -1 && $hostnamestring <> "")
                        {
                          echo($servicenotresolving);
                        }
                      else
                        {
                          echo($servicenotrunning);
                        }
                  }
                else
                  {
                    if (strstr($object1, '%'))
                      {
                          echo('<h3>' . $alt_serv . '</h3>');
                          echo ($servicenotrunning);
                      }
                    else
                      {
 
                        // Run file start

                        $xmlicon = "";            
                        if($xmloutput_showicon == 1)
                          {
                            $xmlicon = '<a href="sys/run_alternate.php?format=xml_1.0&ext=' . $alt_ext . '"><img src="build/skins/' . $setskin . '/images/icons/xml.png" title="' . $xmlicon_titletext . '" alt="XML icon" class="xmlicon"/></a>';
                          }

        		echo('<h3>' . $alt_serv . ' ' . $xmlicon . '</h3><small></small>');

                        echo('<table>');

                        echo('<tr><th>' . $th_service . '</th><th>' . $th_state . '</th><th>' . $th_version . '</th></tr>');

                          reset($alternatemodulesarray);
                          foreach($alternatemodulesarray as $value)
                            {
                              if(count($alternatemodulesarray) > $i)
                              {
                                if($alternatemodulesarray[key($alternatemodulesarray)]["alternate"] != "")
                                {
                                  $alternateCurserHelp = ' style="cursor:help;"';
                                }
                                else
                                {
                                  $alternateCurserHelp = "";
                                }    
                                 
                                $xmlbuildstring = ($xmlbuildstring . "\t" . '<tr title="' . $alternatemodulesarray[key($alternatemodulesarray)]["alternate"] . '"' . $helponalternate . '>' . "\r\n"); 
                                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn1" style="background-image:url(build/skins/' . $setskin . '/images/layout/fieldtitlebg.png); background-repeat:no-repeat;">' . key($alternatemodulesarray) . '</td>' . "\r\n");
                                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn2">' . $alternatemodulesarray[key($alternatemodulesarray)]["state"] . '</td>' . "\r\n");
                                  $xmlbuildstring = ($xmlbuildstring . "\t\t" . '<td class="tdcolumn3"' . $alternateCurserHelp . '>' . $alternatemodulesarray[key($alternatemodulesarray)]["details"] . '</td>' . "\r\n");
                                  next($alternatemodulesarray);
                                $xmlbuildstring = ($xmlbuildstring . "\t" . '</tr>' . "\r\n");
                              }
                              $i++;
                            }

                        echo($xmlbuildstring);

                        echo('</table>');
                        unset($xmlbuildstring);
                        unset($alternatemodulesarray);
                        // Run file end
                        
                      }
                  }
              }
            else
              {
                  echo('<h3>' . $alt_serv . '</h3>');
                  echo($servicenofile);
                  
                  echo('<p>' . $_SERVER["DOCUMENT_ROOT"] . '/' . $objectfilename . '</p>');
              }



        echo('</div>' . "\r\n");
    }

?>
