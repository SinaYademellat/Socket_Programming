import json

class FileManager:
    def __init__(self, file_path: str):
        self.file_path = file_path
        self.data = None
        # ++++++++++++++++++++++++++++++++++

    def read_json_file(self , debug_:bool = True) -> bool:
        try:
        # ---------------------
            with open(self.file_path, "r", encoding="utf-8") as file:
                self.data = json.load(file) 
            return True
        # ---------------------
        except FileNotFoundError:
            if(debug_):
                print(f"Error --> NotFound (path): {self.file_path}")
            return False
        # ---------------------
        except Exception as e:
            if(debug_):
                print(f"Error --> (json)  << {e} >>")
            return False
        # ++++++++++++++++++++++++++++++++++

    def show_json_keys(self):
        print(self.data.keys())