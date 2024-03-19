# -*- coding: utf-8 -*-
"""
Created on Thu Mar  7 17:40:43 2024

@author: vison
"""
import subprocess
import time
import datetime
import json
import numpy as np
import os
####################################   Read Me!!   ################################################    
# set your impitool.exe path
path = os.getcwd()
file_path = str(path) + "\\ipmitool.exe"
# set your BMC IP
ip = "192.9.85.29"
# set number of CPUs
CPU_num = 2

# default range = 0x400-0x47f, add the index you want to check in np.array([])
MSR_index = np.concatenate((np.arange(0x400, 0x480), np.array([], dtype=int)))

BDF = CPU_num * [None]
BDF[0] = np.array([[0x00, 0x00, 0x00, 0xE0], [0x1E, 0x00, 0x00, 0xA4], [0x1E, 0x00, 0x00, 0xA8], [0x1F, 0x1E, 0x01, 0x80], [0x1F, 0x1E, 0x01, 0x84]]) 
BDF[1] = np.array([[0x00, 0x00, 0x00, 0xE0], [0x1E, 0x00, 0x00, 0xA4], [0x1E, 0x00, 0x00, 0xA8], [0x1F, 0x1E, 0x01, 0x80], [0x1F, 0x1E, 0x01, 0x84]]) 

####################################   Read Me!!   ################################################     
# user & password
user = "admin"
password = "password"
###################################################################################################
arrayMSR0 = CPU_num * [[None]*8]
arrayMSR0_final = [None]

arrayBDF_0 = [None]*4
index_BDF = 0x40

list_MSR0 = CPU_num * [None]
list_BDF = CPU_num * [None]

# define PCI Address Bytes
byte5 = byte6 = byte7 = byte8 = 0

CPU_innerlist = 2*[None]
total_array = {}       

test0 = subprocess.run([file_path, "-H", ip, "-U", user, "-P", password, "-I", "lanplus", "raw", "6", "1"], stdout=subprocess.PIPE,stderr=subprocess.PIPE, text = True)
test1 = subprocess.run([file_path, "-H", ip, "-U", user, "-P", password, "-I", "lanplus", "-b", "6", "-t", "0x2c", "raw", "6", "1"], stdout=subprocess.PIPE,stderr=subprocess.PIPE, text = True)

if test0.returncode == 0 and test1.returncode == 0: 
    ###############################    calculate all CPU    ##############################
    for i in range(CPU_num):
        print("getting CPU_" + str(i) + " value...")
        
        list_MSR0[i] = {}
        list_BDF[i] = {}
        CPU_innerlist[i] = {}
        # cal MSR
        for j in range(MSR_index.shape[0]):
        # for j in range(1):
            MSB = int(MSR_index[j] / 0x100)
            LSB = MSR_index[j] % 0x100
            # looped for getting value, delay 1s while fail getting value
            for trials in range(3): 
                MSR0_data = subprocess.run([file_path, "-H", ip, "-U", user, "-P", password, "-I", "lanplus", "-b", "6", "-t", "0x2c", "raw", "0x2e", "0x46", "0x57", "0x01", "0x00", str(i), "0x00", str(LSB), str(MSB), "0x04"], stdout=subprocess.PIPE,stderr=subprocess.PIPE, text = True)
                if (MSR0_data.returncode == 0):
                    break
                else:
                    time.sleep(1)
            # get 8 bytes
            for k in range(8):
                front = 3*(k+3)
                end = 3*(k+4)
                arrayMSR0[i][7-k] = (MSR0_data.stdout)[front+1:end] 
            arrayMSR0_final = ''.join(arrayMSR0[i])
            if MSR0_data.returncode == 0:    
                list_MSR0[i]["MSR_0x" + f"{MSR_index[j]:04X}"] = "0x" + arrayMSR0_final
            else:
                list_MSR0[i]["MSR_0x" + f"{MSR_index[j]:04X}"] = "N/A"
                
        # cal PCI
        for j in range(BDF[i].shape[0]):
            # calculate byte5-byte8
            byte8 = int(BDF[i][j, 0] / 16)
            byte7 = ((BDF[i][j, 0] % 16) << 4) + int(BDF[i][j, 1] / 2)
            byte6 = ((BDF[i][j, 1] % 2) << 7) + (BDF[i][j, 2] << 4) + int(BDF[i][j, 3] / 256)
            byte5 = (BDF[i][j, 3] % 256)
            for trials in range(3): 
                BDF_data_0 = subprocess.run([file_path, "-H", ip, "-U", user, "-P", password, "-I", "lanplus", "-b", "6", "-t", "0x2c", "raw", "0x2e", "0x44", "0x57", "0x01", "0x00", str(index_BDF + i) , str(byte5).upper(), str(byte6).upper(), str(byte7).upper(), str(byte8).upper(), "0x03"], stdout=subprocess.PIPE,stderr=subprocess.PIPE, text = True)
                if (BDF_data_0.returncode == 0):
                    break
                else:
                    time.sleep(1)
            # get 4 bytes
            for k in range(4):
                front = 3*(k+3)
                end = 3*(k+4)
                arrayBDF_0[3-k] = (BDF_data_0.stdout)[front+1:end] 
            arrayBDF_0_final = ''.join(arrayBDF_0)
            if BDF_data_0.returncode == 0:    
                list_BDF[i]["Bus0x" + f"{BDF[i][j, 0]:02X}" + "_Dev0x" + f"{BDF[i][j, 1]:02X}" + "_Fun0x" + f"{BDF[i][j, 2]:02X}" + "_Reg0x" + f"{BDF[i][j, 3]:03X}"] = "0x" + arrayBDF_0_final 
            else:
                list_BDF[i]["Bus0x" + f"{BDF[i][j, 0]:02X}" + "_Dev0x" + f"{BDF[i][j, 1]:02X}" + "_Fun0x" + f"{BDF[i][j, 2]:02X}" + "_Reg0x" + f"{BDF[i][j, 3]:03X}"] = "NA"
        
        CPU_innerlist[i]["MSR"] = list_MSR0[i]
        CPU_innerlist[i]["PCI"] = list_BDF[i]
        
        if i == 0:
            total_array["CPU0"] = CPU_innerlist[i]
        else:
            total_array["CPU1"] = CPU_innerlist[i]
        
    # Notice the user
    print("Ready to finish...")
    
    now = datetime.datetime.now()
    month = now.month
    day = now.day
    
    # Create json file in the same directory this python file located
    with open("eagle_stream" + str(month).zfill(2) + str(day).zfill(2) + ".json", "w") as f:
        json.dump(total_array, f)
else:
    print("fail to get value...")
    time.sleep(5)