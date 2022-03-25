<!DOCTYPE html>
<html>
<head>
	<title>Hitung Huruf Vokal</title>
</head>
<body>
<?php 
main() ; 
function main(){
	$kata = "Haloo" ;
	$panjang = strlen($kata) ;
	$split = str_split($kata) ;
	$jum = cekVokal($split, $panjang) ;
	output($jum, $kata) ;
}
function cekVokal($split, $panjang){
	$cek = 0;
	$i ;
	for ($i=0; $i < $panjang ; $i++) { 
		if ($split[$i] == 'A' || $split[$i] == 'a'|| $split[$i] == 'I' || $split[$i] == 'i' || $split[$i] == 'U' || $split[$i] == 'u' || $split[$i] == 'E' || $split[$i] == 'e' || $split[$i] == 'O' || $split[$i] == 'o'){
			$cek++ ;
		}
	}
	return $cek ;
}
 
function output($jum, $kata){
	echo "Jumlah Huruf Vokal dalam kata $kata adalah $jum";
}
?>
</body>
</html>
