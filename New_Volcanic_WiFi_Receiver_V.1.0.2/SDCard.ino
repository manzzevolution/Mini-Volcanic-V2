bool initSDCard(){ 
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return false;
  } else {
    Serial.println("SD Card OK!");
    return true;
  }
}

bool SDCardWriter(String fileName, String writeText){
  File myFile;
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(fileName, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to ");Serial.println(fileName);
    myFile.println(writeText);
    myFile.close();
    Serial.println("Done !");
    return true;
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening ");Serial.println(fileName);
    return false;
  }
}

void SDCardReader(String fileName){
  File myFile;
  myFile = SD.open(fileName);
  if (myFile) {
    Serial.print("Opening ");Serial.println(fileName);
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening ");Serial.println(fileName);
  }
}

void fileDateTime (uint16_t* date, uint16_t* time){
  //*date=FAT_DATE(year, month, day);
  //*time=FAT_TIME(hour, minute, second);
  *date = FAT_DATE((uint16_t(tahun)), uint16_t(bulan), uint16_t(tanggal));
  *time = FAT_TIME(uint16_t(jam), uint16_t(menit), uint16_t(detik));
}

void SDCardInfo(){
  Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);


  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
}

//------------------------------------------------------------------------------------------------------------------
void SaveToSDCard(String dataStream, String extension){
  String textFile;
  String timeNow = getTimeRTC() + ",";
  if (bulan < 10){
    if (tanggal < 10){
      textFile = String(tahun) + "0" + String(bulan) + "0" + String(tanggal) + extension;
    } else {
      textFile = String(tahun) + "0" + String(bulan) + String(tanggal) + extension;
    }
  } else {
    if (tanggal < 10){
      textFile = String(tahun) + String(bulan) + "0" + String(tanggal) + extension;
    } else {
      textFile = String(tahun) + String(bulan) + String(tanggal) + extension;
    }
  }
  Serial.print("Writing file ");Serial.print(textFile);
  SdFile::dateTimeCallback(fileDateTime);
  if(SDCardWriter(textFile ,timeNow + dataStream)){
    Serial.println(" Done !");
    delay(2000);
  }else {
    Serial.println(" Failed !");
    delay(3000);
  }
}
