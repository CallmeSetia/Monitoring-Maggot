import time
import serial
import mysql.connector
import datetime
import random


# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/ttyUSB1',
    baudrate=9600
)

mydb = mysql.connector.connect(
  host="localhost",
  user="phpmyadmin",
  password="Maggot123",
  database="project_monitoring-system"
)

mycursor = mydb.cursor()
while 1 :
    tbl_db = ["data_sensor_a", "data_sensor_b", "data_sensor_c", "data_sensor_d",
                "data_sensor_e", "data_sensor_f", "data_sensor_g", "data_sensor_h",
                "data_sensor_i"]
    tbl_db1 = ["data_status_a", "data_status_b", "data_status_c"]
    tbl_db2 = ["data_pompa1", "data_pompa2", "data_pompa3"]
    
    t = datetime.datetime.now()
    arduinoData = ser.readline().decode('utf-8')
    print(arduinoData)
    
    x = arduinoData.split("#")
    print(x)
    if len(x) > 10 :
        for i, datas in enumerate(x):
            if i < 9:
             
                sql = "INSERT INTO "+ str(tbl_db[i])  +" (tanggal , jam, nilai_sensor) VALUES (%s, %s, %s)"
                val = [("{}/{}/{}".format(t.day, t.month, t.year)),
                                  ("{}:{}".format(t.hour, t.minute)), 
                                  ("{}".format(str(datas)))]
                mycursor.execute(sql, val)
                mydb.commit()
                print(mycursor.rowcount, " "+ str(tbl_db[i]) +" record inserted.")

        #print(sql, " " + str(tbl_db[i]) +" record inserted.")

    #    print("Data ke-{} = {}".format(i+1,datas))
    
    if len(x) > 8 :     
     sql = "INSERT INTO "+ str(tbl_db1[0])  +" (status_1 , status_2, status_3) VALUES (%s, %s, %s)"
     val = [("{}".format(str(x[9]))),
           ("{}".format(str(x[10]))), 
           ("{}".format(str(x[11])))]
     mycursor.execute(sql, val)
     mydb.commit()

     sql = "INSERT INTO "+ str(tbl_db1[1])  +" (status_1 , status_2, status_3) VALUES (%s, %s, %s)"
     val = [("{}".format(str(x[12]))),
           ("{}".format(str(x[13]))), 
           ("{}".format(str(x[14])))]

     mycursor.execute(sql, val)
     mydb.commit()

     sql = "INSERT INTO "+ str(tbl_db1[2])  +" (status_1 , status_2, status_3) VALUES (%s, %s, %s)"
     val = [("{}".format(str(x[15]))),
           ("{}".format(str(x[16]))), 
           ("{}".format(str(x[17])))]

     mycursor.execute(sql, val)
     mydb.commit()



     sql = "INSERT INTO "+ str(tbl_db2[0])  +" (pompa_up, pompa_down) VALUES (%s, %s)"
     val = [("{}".format(str(x[18]))),
           ("{}".format(str(x[19])))]

     mycursor.execute(sql, val)
     mydb.commit()


     sql = "INSERT INTO "+ str(tbl_db2[1])  +" (pompa_up, pompa_down) VALUES (%s, %s)"
     val = [("{}".format(str(x[20]))),
           ("{}".format(str(x[21])))]

     mycursor.execute(sql, val)
     mydb.commit()


     sql = "INSERT INTO "+ str(tbl_db2[2])  +" (pompa_up, pompa_down) VALUES (%s, %s)"
     val = [("{}".format(str(x[22]))),
           ("{}".format(str(x[23])))]

     mycursor.execute(sql, val)
     mydb.commit()

    

    
