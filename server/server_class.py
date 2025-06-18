import socket
import numpy as np
import os
import random

from file_manager import FileManager 
# ================================================================================
def isIpV4(inputIp:str)->bool:
    try:
        socket.inet_pton(socket.AF_INET, inputIp)
    except:
        return False
    return True

def getBinaryIPv4(ipv4: str) -> str:
    ipv4_parts = ipv4.split('.')
    binary_parts = [format(int(part), '08b') for part in ipv4_parts]
    return '.'.join(binary_parts)

def calculate_subnet(ip_binary: str, mask_binary: str) -> str:
    ip_list = ip_binary.split('.')
    mask_list = mask_binary.split('.')
    subnet_octets_binary = []
    for i in range(4):
        and_result_int = int(ip_list[i], 2) & int(mask_list[i], 2)
        subnet_octets_binary.append(format(and_result_int, '08b')) 
    return '.'.join(subnet_octets_binary)

def binaryToDsimal(binarystr:str)->str:
    binaryList = binarystr.split('.')
    resultList =[str(int(part,2))  for part in binaryList]
    return '.'.join(resultList)

def is_valid_credentials_string(input_string) -> bool:
    if not isinstance(input_string, str):
        print("Error: Input is not a string.")
        return False
    if (len(input_string)==0):
        print("Error: Input string cannot be empty.")
        return False
    tmplist = input_string.split()
    if(len(tmplist)!=1):
        print("Error: Input string cannot contain whitespace.")
        return False

    return True

def check_socket_bindable(ip,port)->bool:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tmpSocket:
            try:
                tmpSocket.bind((ip, port))
                return True
            except OSError as e:
                return False

def DataLoader(dataPath:str):
    if not os.path.exists(dataPath):
        print(f"File not found: {dataPath}")
        return None
    loaded_data = np.load(dataPath)
    print('shape:', loaded_data.shape)
    return loaded_data


# ================================================================================
class ServerClass:
    def __init__(self) -> None:
        self._Ip   = "x.x.x.x"
        self._subMask = "255.255.255.0"
        self._Port = 0

        self.ServerConfig   = None

        self.__subNet       = None
        self._UserName      = None
        self._Password      = None

        self.current_request_list = None
        self.curentPassword   = 'testPasspart2'
        self.raw_data = DataLoader(dataPath='GenerateData/my_data.npy')
        self.index_dataLoder = 0

    def __repr__(self) -> str:
        return (f"Ip     = {self._Ip}  \nport   = {self._Port}")

    def loadServerConfig(self , jsonـPath ) -> bool:
        file = FileManager(file_path = jsonـPath)
        if(file.read_json_file(debug_=True)):
            self.ServerConfig  = file.data
            return True
        else:
            self.ServerConfig  = None
            return False

    def ipServerInfo(self , inputIpstr):
            ipBinary      = getBinaryIPv4(inputIpstr)
            maskBinary    = getBinaryIPv4(self._subMask)
            subNetBinary  = calculate_subnet(ipBinary , maskBinary)
            print('~'*20 ,'<< ipServer info >>','~'*20)
            print('|',f'(  ip ) {inputIpstr} :'         , ipBinary,'|')
            print('|',f' Mask {self._subMask}' , maskBinary,'|')
            
            self.__subNet = binaryToDsimal(subNetBinary) 
            print('|',f'( Net ) {self.__subNet} :', subNetBinary,'|')
            print('~'*61)

    def __checkIpServer(self)->bool:
        tmpIp = self.ServerConfig['ipServer']
        if( isIpV4(tmpIp)):
            self.ipServerInfo(tmpIp)
            self._Ip = tmpIp
            return True
        else:
            return False

    def __checkPortServer(self)->bool:
        tmpPort = self.ServerConfig['portConfigServer']
        try:
            candidPort = int(tmpPort)
            if(candidPort>=0 and candidPort<=65535):
                self._Port=candidPort
                return True
            else:
                print('Port --> 16bit (unsigned integers) !')
                return False
        except ValueError:
            return False

    def __checkUsername(self)->bool:
        tmpUserName = self.ServerConfig['Username']
        if(is_valid_credentials_string(tmpUserName)):
            self._UserName = tmpUserName
            return True
        else:
            return False

    def __checkPassword(self)->bool:
        tmpPassword = self.ServerConfig['Password']
        if(is_valid_credentials_string(tmpPassword)):
            self._Password = tmpPassword
            return True
        else:
            return False

    def checkServerConfig(self) -> bool:
        # (1)
        if(self.__checkIpServer()):
            print(f"{'IP':14} is set successfully.")
        else:
            print(f"{'IP':14} is Wrong!")
            return False
        # (2)
        if(self.__checkPortServer()):
            print(f"{'Port':14} is set successfully.")
        else:
            print(f"{'Port':14} is Wrong!")
            return False
        # ---------------------
        # (3)
        if(check_socket_bindable(self._Ip , self._Port)):
            print(f'{"can Bind":14} {self._Ip}:{self._Port}')
        else:
            print(f'{"Cannot Bind":14} {self._Ip}:{self._Port}')
            return False
        # ---------------------
        # (4)
        if(self.__checkUsername()):
            print(f"{'UserName':14} is set successfully.")
        else:
            print(f"{'UserName':14} is Wrong!")
            return False
        # (5)
        if(self.__checkPassword()):
            print(f"{'Password':14} is set successfully.")
        else:
            print(f"{'Password':14} is Wrong!")
            return False
        
        return True

    def canRunServer(self , configPath)->bool:
        if(self.loadServerConfig(configPath)):
            print('Json file is Load.')
            if(self.checkServerConfig()):
                print('-'*20)
                print(f'configuration is valid for (Ip):{self._Ip} (Port): {self._Port}\n')
                return True
        
        print('-'*20)
        print('Cannot Run serve!')
        return False

    def listen_for_connection(self,number) ->tuple:
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((self._Ip, self._Port))
        server_socket.listen(1)
        print(f"[{number}]{'Server listening on':20} {self._Ip}:{self._Port}")
        conn, addr = server_socket.accept()
        return (conn, addr)

    def parse_client_data(self, inputData: str) -> int:
        codeNumber = -1
        if(len(inputData)==0):
            print('Lne = 0')
            return -1
        inputRequstList = inputData.split()
        try:
            codeNumber            = int(inputRequstList[0])
            self.current_request_list = inputRequstList
            return codeNumber
        except ValueError:
            print('Erro --> code part of request')
        return codeNumber

    def handle_request_code1(self):
        #(Authentication)  : type UserName Password
        if((self.current_request_list[1] == self._UserName) and ((self.current_request_list[2] == self._Password))):
            number = random.randint(0, 1000)
            self.curentPassword = str(number)
            return str(number)
        else:
            return '-1'

    def SendOneRow(self,mode:str , numberSampling:str)->str:
            sampelsize = int(numberSampling)

            if(mode == 'Normal'):
                dataList = list(self.raw_data[self.index_dataLoder%self.raw_data.shape[0]].data)
                result = ' '.join(str(n) for n in dataList)
                self.index_dataLoder += 1
                return result
            elif((mode == 'Max') and (self.raw_data.shape[1]%sampelsize ==0 )):
                dataList = self.raw_data[self.index_dataLoder%self.raw_data.shape[0]]
                result = list( [max(dataList[i:i+sampelsize].data) for i in range(0, len(dataList), sampelsize)] )
                result = ' '.join(str(n) for n in result)
                self.index_dataLoder += 1
                return result
            elif((mode == 'Min') and (self.raw_data.shape[1]%sampelsize ==0 )):
                dataList = self.raw_data[self.index_dataLoder%self.raw_data.shape[0]]
                result = list( [min(dataList[i:i+sampelsize].data) for i in range(0, len(dataList), sampelsize)] )
                result = ' '.join(str(n) for n in result)
                self.index_dataLoder += 1
                return result
            else:
                print(">> Error >> SendOneRow")
                return "MT"

    def handle_request_code2(self):
        #(Data)  : type Passwor mode  Range
        if(self.current_request_list[1] == self.curentPassword):
            return self.SendOneRow(self.current_request_list[2] , self.current_request_list[3])
        else:
            return 'Wrong Token'

    def creatServerAnsser(self , type_of_code ) -> str:
        if(type_of_code == 1):
            return self.handle_request_code1()
        elif(type_of_code == 2):
            return self.handle_request_code2()
        else:
            return 'Error in code part'
        
    def handle_client_connection(self,number):
        try:
            conn_client , addr_client = self.listen_for_connection(number)
            print(f"[{number}]{'Connected by':20}{addr_client}")
            data_raw       = conn_client.recv(1024)
            data_of_client = data_raw.decode()

            resurtParser = self.parse_client_data(inputData = data_of_client)
            print('resurtParser: ',resurtParser)
            print('[p]','~'*18,'> ',resurtParser)
            
            Ansser_is = self.creatServerAnsser(type_of_code = resurtParser)
            print('[A]','~'*18,'> ',Ansser_is)

            conn_client.send(Ansser_is.encode())
            conn_client.close()
            print("-"*50)

        except Exception as e:
            print(f"<< {number} >>  Error: {e}")

# +++++++++++++++++++++++++++++++++++++++++


