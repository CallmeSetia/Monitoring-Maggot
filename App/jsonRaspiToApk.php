<?php
	//echo "ya";

	include_once './connection.php';	
	$connection = new mysqli($DB_HOST, $DB_USER, $DB_PASS, $DB_DATABASE);
	
	$sqlA = mysqli_query($connection, "SELECT * FROM data_sensor_a ORDER BY id DESC LIMIT 1");
	$sqlB = mysqli_query($connection, "SELECT * FROM data_sensor_b ORDER BY id DESC LIMIT 1");
	$sqlC = mysqli_query($connection, "SELECT * FROM data_sensor_c ORDER BY id DESC LIMIT 1");
	$sqlD = mysqli_query($connection, "SELECT * FROM data_sensor_d ORDER BY id DESC LIMIT 1");
	$sqlE = mysqli_query($connection, "SELECT * FROM data_sensor_e ORDER BY id DESC LIMIT 1");
	$sqlF = mysqli_query($connection, "SELECT * FROM data_sensor_f ORDER BY id DESC LIMIT 1");
	$sqlG = mysqli_query($connection, "SELECT * FROM data_sensor_g ORDER BY id DESC LIMIT 1");
	$sqlH = mysqli_query($connection, "SELECT * FROM data_sensor_h ORDER BY id DESC LIMIT 1");
	$sqlI = mysqli_query($connection, "SELECT * FROM data_sensor_i ORDER BY id DESC LIMIT 1");

	$sqlSA = mysqli_query($connection, "SELECT * FROM data_status_a ORDER BY id DESC LIMIT 1");
	$sqlSB = mysqli_query($connection, "SELECT * FROM data_status_b ORDER BY id DESC LIMIT 1");
	$sqlSC = mysqli_query($connection, "SELECT * FROM data_status_c ORDER BY id DESC LIMIT 1");
	
	$sqlPA =  mysqli_query($connection, "SELECT * FROM data_pompa1 ORDER BY id_pompa1  DESC LIMIT 1");
	$sqlPB =  mysqli_query($connection, "SELECT * FROM data_pompa2 ORDER BY id_pompa2  DESC LIMIT 1");
	$sqlPC =  mysqli_query($connection, "SELECT * FROM data_pompa3 ORDER BY id_pompa3 DESC LIMIT 1");
	
	if ($row = mysqli_fetch_assoc($sqlA)) {
        $dataA = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlB)) {
        $dataB = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlC)) {
        $dataC = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlD)) {
        $dataD = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlE)) {
        $dataE = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlF)) {
        $dataF = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlG)) {
        $dataG = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlH)) {
        $dataH = $row['nilai_sensor'];
    }
	if ($row = mysqli_fetch_assoc($sqlI)) {
        $dataI = $row['nilai_sensor'];
    }

	if ($row = mysqli_fetch_assoc($sqlSA)) {
        $statusA1 = $row['status_1'];
        $statusA2 = $row['status_2'];
        $statusA3 = $row['status_3'];
    }
	if ($row = mysqli_fetch_assoc($sqlSB)) {
        $statusB1 = $row['status_1'];
        $statusB2 = $row['status_2'];
        $statusB3 = $row['status_3'];
    }
	if ($row = mysqli_fetch_assoc($sqlSC)) {
        $statusC1 = $row['status_1'];
        $statusC2 = $row['status_2'];
        $statusC3 = $row['status_3'];
    }
    
    	if ($row = mysqli_fetch_assoc($sqlPA)) {
        $statusPompa1_Up = $row['pompa_up'];
        $statusPompa1_Down = $row['pompa_down'];
    }
    if ($row = mysqli_fetch_assoc($sqlPB)) {
        $statusPompa2_Up = $row['pompa_up'];
        $statusPompa2_Down = $row['pompa_down'];
    }
    if ($row = mysqli_fetch_assoc($sqlPC)) {
        $statusPompa3_Up = $row['pompa_up'];
        $statusPompa3_Down = $row['pompa_down'];
    }
    
    
	
	echo json_encode(array("dataA"=>$dataA, "dataB"=>$dataB,  "dataC"=>$dataC, "dataD"=>$dataD, "dataE"=>$dataE, "dataF"=>$dataF, "dataG"=>$dataG, "dataH"=>$dataH, "dataI"=>$dataI,
		"statusF1"=>$statusA1,"statusL1"=>$statusA2,"statusWP1"=>$statusA3,
		"statusF2"=>$statusB1,"statusL2"=>$statusB2,"statusWP2"=>$statusB3,
		"statusF3"=>$statusC1,"statusL3"=>$statusC2,"statusWP3"=>$statusC3,
		"pompa1Up"=>$statusPompa1_Up,"pompa1Bawah"=>$statusPompa1_Down,
		"pompa2Up"=>$statusPompa2_Up,"pompa2Bawah"=>$statusPompa2_Down,
		"pompa3Up"=>$statusPompa3_Up,"pompa3Bawah"=>$statusPompa3_Down,
	));
?>
