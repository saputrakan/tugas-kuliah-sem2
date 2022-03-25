<!DOCTYPE html>
<html>
<head>
	<title>Konversi Nilai</title>
</head>
<body>
<?php
main() ;
function main(){
	$nilai = 54 ;
	$hasil ;
	$hasil = konversi($nilai) ;
	output($hasil) ;
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
	if($hasil == 'D' || $hasil == 'E'){
		warna($hasil) ;
	}else{
		echo "$hasil";
	}
}

function warna($hasil){
	echo '<span style="color: red;">' . $hasil . '</span><br>';
}
?>
</body>
</html>