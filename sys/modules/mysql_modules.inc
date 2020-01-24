<?php
      $mysqlmodulesarray[] = "";

      $mysqlmodulesarray["Server"] = array(
       "state"      => $strmysqlserverversion,
       "version"    => $strmysqlserverversionv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Protocol"] = array(
       "state"      => $strmysqlprotocolversion,
       "version"    => $strmysqlprotocolversionv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Charset"] = array(
       "state"      => $strmysqlcharset,
       "version"    => $strmysqlcharsetv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Server Uptime"] = array(
       "state"      => $strmysqlstatisticsuptime,
       "version"    => $strmysqlstatisticsuptimev,
       "alternate"  => ""
      );


      $mysqlmodulesarray["Threads"] = array(
       "state"      => $strmysqlstatisticsthreads,
       "version"    => $strmysqlstatisticsthreadsv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Questions"] = array(
       "state"      => $strmysqlstatisticsquestions,
       "version"    => $strmysqlstatisticsquestionsv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Slow Queries"] = array(
       "state"      => $strmysqlstatisticsslowqueries,
       "version"    => $strmysqlstatisticsslowqueriesv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Opens"] = array(
       "state"      => $strmysqlstatisticsopens,
       "version"    => $strmysqlstatisticsopensv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Flush Tables"] = array(
       "state"      => $strmysqlstatisticsflushtables,
       "version"    => $strmysqlstatisticsflushtablesv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Open tables"] = array(
       "state"      => $strmysqlstatisticsopentables,
       "version"    => $strmysqlstatisticsopentablesv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Queries/sec"] = array(
       "state"      => $strmysqlstatisticsqueriespersecond,
       "version"    => $strmysqlstatisticsqueriespersecondv,
       "alternate"  => ""
      );

      $mysqlmodulesarray["Respons time"] = array( // (Connect+Open)
       "state"      => $strmysqlconnectandopentimer,
       "version"    => $strmysqlconnectandopentimerv,
       "alternate"  => ""
      );
?>
