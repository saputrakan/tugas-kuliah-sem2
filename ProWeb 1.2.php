<!DOCTYPE html>
<html>
<head>
	<title>Prima</title>
</head>
<body>
<?php
prima() ;
function prima(){
	for ($i=2; $i <= 50; $i++) { 
		$cek = 0 ;
		for ($j=1; $j <= $i ; $j++) { 
			if ($i % $j == 0) {
				$cek++ ;
			}
		}
		if ($cek == 2) {
			echo "$i ";
		}
	}	
}
?>
</body>
</html>