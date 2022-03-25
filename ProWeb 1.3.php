<!DOCTYPE html>
<html>
<head>
	<title>Array Warna</title>
</head>
<body>
<?php
arrWarna() ;
function arrWarna(){
	$jenisBuah = array("Pisang", "Jambu", "Mangga");
	echo "JENIS BUAH :";
	echo "<br>";
	for ($i=0; $i < 3 ; $i++) { 
		if ($i==0) {
			echo '<span style="color: yellow;">' . $jenisBuah[$i] . '</span><br>';
		}elseif ($i==1) {
			echo '<span style="color: red;">' . $jenisBuah[$i] . '</span><br>';
		}elseif ($i==2) {
			echo '<span style="color: green;">' . $jenisBuah[$i] . '</span><br>';
		}
	}
}
?>
</body>
</html>