<?php 

if (isset($_GET['action'])) { 
require("php_serial.php");
$serial = new phpSerial();
$serial->deviceSet("COM7");
$serial->confBaudRate(9600);
$serial -> deviceOpen();

if ($_GET[’action’] == "lock") {
$serial->sendMessage("1\r"); 
} else if ($_GET[’action’] == "unlock") {
$serial->sendMessage("0\r");
}

$serial->deviceClose();
} 

?>
