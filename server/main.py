from server_class import ServerClass

def Main() -> int:
    server_1 = ServerClass()
    if(server_1.canRunServer(configPath ='config.json')):
        for i in range(10):
            server_1.handle_client_connection(i)
        return 0
    else:
        return -1



if( __name__ == '__main__'):
    resultIs = Main()
    print( 'result: ',resultIs)
  