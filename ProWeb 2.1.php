<!DOCTYPE html>
<html>
<head>
	<title>Fungsi Prima</title>
</head>
<body>
<?php
main() ;
function main(){
	$angka = 8 ;
	$cek ;
	$cek = prima($angka) ;
	output($angka ,$cek) ;
}
function prima($angka){
	for ($i = 1; $i <= $angka; $i++) { 
		$cek = 0 ;
		for ($j=1; $j <= $i ; $j++) { 
			if ($i % $j == 0) {
				$cek++ ;
			}
		}
	}
	return $cek ;
}
function output($angka ,$cek){
	if ($cek == 2) {
		echo "$angka adalah bilangan prima";
	}else{
		echo "$angka adalah bukan bilangan prima";
	}
}
?>
</body>
</html>