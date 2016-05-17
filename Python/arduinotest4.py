import serial
import time
import MySQLdb
from timeit import default_timer

dbase = MySQLdb.connect(
        host = "127.0.0.1",
        user = "root",
        passwd = "",
        db = "dbtest",
        unix_socket="/opt/lampp/var/mysql/mysql.sock")

ser = serial.Serial(6, 115200, timeout=1)
#reduce timeout to make it faster
#check how to bring down timer to milliseconds
#calculate the time with no data omitted from database [4:]--> []
#changing hash into small text dosent affect reaction time


for x in range (0,100):
        start = default_timer()
        #starting default timer
         
        #Try giving dbauth as a separate file and check time    
        cursor = dbase.cursor()
        
        read1 = ser.readline() [4:]
        
         
        #print read1
        
        #print ("SELECT sno,fname,lname,age FROM nfc_data1 WHERE sno LIKE %s", read1)

        #sql = ("SELECT * FROM user_data WHERE FName == '%s'") % read1

        dbase.commit()

        cursor.execute("SELECT sno,fname FROM nfc_data1 WHERE sno LIKE %s", (read1))
        #print "executed query"
        #print cursor.fetchall()

        for row in cursor.fetchall():
                print row
                print"ACCESS GRANTED"
                print default_timer() - start
        #ser.flush()
        #ptinting end time - start time


    
