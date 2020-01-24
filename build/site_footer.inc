  <div class="footer">

    <div style="margin-bottom:0px; text-align:center;">

        <!-- POWERED BY -->
        <p>
          Hostdrone | <?php echo('Release: ' . $systemversionstate . ' ver.' . $systemversion); ?>. Skin: <?php echo($setskin);?>. Copyright (C) Tom Richard Andersen.<br/>
          Released under <a href="http://www.gnu.org/licenses/gpl.txt">GNU General Public License</a>.
          For latest version see <a href="http://hostdrone.com/">hostdrone.com</a>.
        </p>

<?php
        if($footer_showicons == 1){
?>
          <a href="http://hostdrone.queryhouse.com/">
            <img src="gfx/footer/poweredby.png" alt="Powered by Hostdrone icon" title="Powered by Hostdrone"/>
          </a> 
  
           <!-- TECHNOLOGIES -->
    
          <a href="http://www.mysql.com/">
            <img src="gfx/footer/mysql.png" alt="MySQL icon" title="MySQL open source database technology"/>
          </a>
          <a href="http://msdn.microsoft.com/">
            <img src="gfx/footer/asp.png" alt="Classic Microsoft ASP icon" title="Microsoft Classic ASP / VB script"/>
          </a>
          <a href="http://msdn.microsoft.com/">
            <img src="gfx/footer/dotnet.png" alt="Microsoft ASP.NET icon" title="ASP.NET on Microsofts .NET framework"/>
          </a>
          <a href="http://php.net/">
            <img src="gfx/footer/php.png" alt="PHP icon" title="php - Hypertext Preprocessor"/>
          </a>  
    
          <!-- W3C VALIDATION -->
    
          <a href="http://validator.w3.org/check?uri=referer">
            <img src="gfx/footer/w3xhtml.png" alt="Valid XHTML 1.0 Strict" title="w3 XHTML validation"/>
          </a>  
          <a href="http://jigsaw.w3.org/css-validator/check/referer">
            <img src="gfx/footer/w3css.png" alt="Valid CSS!" title="w3 CSS validation"/>
          </a>
<?php
       }
?>

  </div>



  </body>
</html>
                      
