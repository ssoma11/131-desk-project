# 131-project
## Device Catalog ##
- Arduino Nano Board
- Light sensor (using an old photoresistor from EE 120b with Arduino nano board)
- Temperature sensor (using an old photoresistor from EE 120b with Arduino nano board)
- For the Arduino nano board, may switch out with a different ARM board depending on our wifi/ethernet needs
- Desk Fan (using small 5V fan from Arduino nano kit)
- User Computer
- User Display

  
## Final Report on Operation ##
Initially, we planned to use different parts from what we ultimately used. However, due to cost concerns as well as the fact that we would be able to demo our project with what parts we already did have, we chose to use the parts listed in the Device List above. We used Bigquery in Google Cloud for our cloud layer of the project, utilizing a regression model to predict when the user would not be working and automatically shut off the display and the desk fan in the case that the user is not currently using their computer, they typically should not be using their computer, and their computer or fan is turned on. We also additionally decided to add on analytics on the cloud end using the same regression model to manage the user display based on their preferences, time of day, and time of year, however we only really managed to implement a basic time of day and time of year screen management on our display directly, as well as the photoresistor readings which was managed by the arduino edge device via the PC instead of the display directly. We shared data with the bigquery by uploading data to the fog device and running a python script that would periodically convert this data into a csv file and batch load it to the bigquery model via an API request. Our edge devices, the desk fan, temperature sensor, and light sensor, all shared the same arduino board so in practice it was that one device as well as our display monitor that were the edge devices. The board directly managed the lighting and fan depending on the readings from the sensors as well as the serial input. For the serial input, we had a python script running on the fog device that would take updates from the bigquery model every 20 minutes, the same frequency as our csv upload, and use the data to adjust the light settings when necessary. If no serial input was received by the arduino device, it would execute its lighting and fan as usual. The arduino device would also communicate lighting sensor changes with the user display, which would update accordingly. 
