<!DOCTYPE html>
<html>
<head>
	<title>Fibonnaci</title>
</head>
<body>
<?php
$awal = array(0, 1) ;
fibo() ;
output() ;
function fibo(){
	$i ;
	global $awal ;
	for ($i=0; $i <= 10; $i++) { 
		if ($i == 0) {
			$awal[0] = 0 ;
		}if ($i == 1) {
			$awal[1] = 1 ;
		}if ($i == 2) {
			$awal[2] = 1 ;
		}else{
			$awal[$i] = $awal[$i-2] + $awal[$i-1] ;
		}
	}
}
function output(){
	$i ;
	global $awal ;
	for ($i=0; $i <= 10 ; $i++) { 
		echo "$awal[$i] " ;
	}
}
?>
</body>
</html>