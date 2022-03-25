<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<?php 
$_GET["name"];
$_GET["nilaiAngka"]; 
main() ;
function main(){
	$panjangNama = strlen($_GET["name"]) ;
	$splitNama = str_split($_GET["name"]) ;
	$panjangNilai = strlen($_GET["nilaiAngka"]) ;
	$splitNilai = str_split($_GET["nilaiAngka"]) ;
	$hasil ;
	if (cekNama($panjangNama, $splitNama) > 0 || cekNilai($panjangNilai, $splitNilai) > 0) {
		if(cekNama($panjangNama, $splitNama) > 0 && cekNilai($panjangNilai, $splitNilai) > 0){
			echo "Input Nilai Dan Angka Tidak Valid";
		}else if (cekNama($panjangNama, $splitNama) > 0) {
			echo "Input Nama Tidak Valid";
		}else if (cekNilai($panjangNilai, $splitNilai) > 0) {
			echo "Input Nilai Tidak Valid";
		}
	}else{
		$hasil = konversi($_GET["nilaiAngka"]) ;
		output($hasil) ;		
	}
}

function cekNama($panjangNama, $splitNama){
	$i ;
	$flag = 0 ;
	for ($i=0; $i < $panjangNama ; $i++){
		if ($splitNama[$i] <= '9') {
			$flag++ ;
		}
	}
	return $flag ;
}
function cekNilai($panjangNilai, $splitNilai){
	$i ;
	$flag = 0 ;
	for ($i=0; $i < $panjangNilai ; $i++){
		if ($splitNilai[$i] >= 'A' && $splitNilai[$i] <= 'Z' || $splitNilai[$i] >= 'a' && $splitNilai[$i] <= 'z'){
			$flag++ ;
		}
	}
	return $flag ;
}
function konversi($nilai){
	$konv ;
	if($nilai >= 41)
		if($nilai >= 56)
			if($nilai >= 61)
				if($nilai >= 66)
					if($nilai >= 71)
						if($nilai >= 81)
							$konv = 'A' ;
						else
							$konv = 'AB' ;
					else
						$konv = 'B' ;
				else
					$konv = 'BC' ;
			else
				$konv = 'C' ;
		else
			$konv = 'D'	;				
	else
		$konv = 'E' ;

	return $konv ;
}
function output($hasil){
	echo "Nama: ";
	echo $_GET["name"];
	echo "<br>";
	echo "Nilai anda adalah $hasil";
}

?>
</body>
</html>