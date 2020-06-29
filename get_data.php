
<?php
$url=$_SERVER['REQUEST_URI'];
header("Refresh: 60; URL=$url");  // Refresh the webpage every 5 seconds
?>
<html>
<head>
    <title>IR sensor</title>
</head>
    <body>
        <h1>IR obstacle sensor</h1>
    <table border="0" cellspacing="0" cellpadding="4">
      <tr>
            <td>ID</td>
            <td>Value</td>
            <td>Create at</td>
      </tr>
     
<?php
    // Connect to database

    $con=mysqli_connect("localhost","usern","usern","arduino");
     
		if (mysqli_connect_errno())
		{
			echo "Failed to connect to MySQL: " .mysqli_connect_error();
		}
		
    // Retrieve all records and display them   
    $result = mysqli_query($con,'SELECT * FROM capture ORDER BY id DESC');
      
    // Process every record
    
    while($row = mysqli_fetch_array($result))
    {      
        echo "<tr>";
        echo "<td>" . $row['id'] . "</td>";
        echo "<td>" . $row['valeur'] . "</td>";
        echo "<td>" . $row['create_at'] . "</td>";
        echo "</tr>";
        
    }
        
    // Close the connection   
    mysqli_close($con);
?>
    </table>
    </body>
</html>

