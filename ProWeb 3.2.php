<!DOCTYPE html>
<html>
<head>
	<title>Input Angka</title>
</head>
<body>
<?php
main() ; 
function main(){
	$input = "123" ;
	$panjang = strlen($input) ;
	$split = str_split($input) ;
	$cout = cek($panjang, $split) ;
	output($cout) ;
}

function cek($panjang, $split){
	$i ;
	$flag = 0 ;
	for ($i=0; $i < $panjang ; $i++){
		if ($split[$i] >= 'A' && $split[$i] <= 'Z' || $split[$i] >= 'a' && $split[$i] <= 'z'){
			$flag++ ;
		}
	}
	return $flag ;
}

function output($cout){
	if ($cout > 0) {
		echo "Inputan Tidak Valid";
	}else{
		echo "Inputan Valid";
	}
}
?>
</body>
</html>