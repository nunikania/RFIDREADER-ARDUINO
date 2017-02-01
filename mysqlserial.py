import serial
import MySQLdb

while True:
#establish connection to MySQL. You'll have to change this for your database.
 dbConn = MySQLdb.connect("localhost","root","password","databaseschema") or die ("could not connect to database")
#open a cursor to the database
 cursor = dbConn.cursor()

 device = '/dev/ttyUSB0' #this will have to be changed to the serial port you are using
 try:
   print "Trying...",device
   arduino = serial.Serial(device, 9600)
   print "connected to arduino ",device
 except:
   print "Failed to connect on",device

#sidikganteng = arduino.readline()
#print "masuk sini ",sidikganteng

 try:
   data = arduino.readline()  #read the data from the arduino
   print "arduino readline"
   pieces = data.split("\t")  #split the data by the tab
   print "pieces of data = ",data
  #Here we are going to insert the data into the Database'

   try:
     cursor.execute("INSERT INTO log (rfid_id) VALUES (%s)", data)
     dbConn.commit() #commit the insert
     cursor.close()  #close the cursor
   except MySQLdb.IntegrityError:
     print "failed to insert data"
   finally:
    cursor.close()  #close just incase it failed
 except:
   print "Failed to get data from Arduino!"