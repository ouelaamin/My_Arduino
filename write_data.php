<?php
    //step 3 create files that will capture data sent from arduino and write it to database
    // Prepare variables for database connection
   
    $dbusername = "usern"; 
    $dbpassword = "usern"; 
    $server = "localhost"; 
   
    $dbconnect = mysqli_connect($server, $dbusername, $dbpassword);
    $dbselect = mysqli_select_db("arduino",$dbconnect);

  

    $sql = "INSERT INTO arduino.capture (valeur) VALUES ('".$_GET["valeur"]."')";    

    // Execute SQL statement

    mysqli_query($sql);

?>