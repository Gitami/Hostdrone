<?php
  include("sys/engine_php.inc");
  include("build/site_header.inc");
?>

<div class="areacontainer">

<?php
    if($docheck_php == 1)
      {
        include("sys/run_php.php");
      }
    if($docheck_asp == 1)
      {
        $alt_ext = "asp";
        $alt_serv = "ASP"; 
        include('sys/run_alternate.php');
        unset($alt_ext);
        unset($alt_serv);
      }
    if($docheck_aspnet == 1)
      {
        $alt_ext = "aspx";
        $alt_serv = ".NET"; 
        include('sys/run_alternate.php');
        unset($alt_ext);
        unset($alt_serv);
      }
?>

<?php
    if($docheck_mysql == 1)
      {
        include("sys/run_mysql.php");
      }
    if($docheck_mssql == 1)
      {
        include("sys/run_mssql.inc");
      }
?>

<?php
    if($docheck_ftp == 1)
      {
        include("sys/run_ftp.php");
      }
    if($docheck_email == 1)
      {
        include("sys/run_email.php");
      }
?>

</div>

<?php
  include("build/site_footer.inc");
?>
