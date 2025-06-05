
# # class FileManager:
# #     def __init__(self,path) -> None:
# #         self._path = path
# #         pass 

# +++++++++++++++++++++++++++++++++++++++++++++++++++

# # file_manager.py
# import json
# from typing import Any
# class FileManager:
#     def __init__(self, filename: str):
#         self.filename = filename
#         self.data = None
#     def read_json(self) -> bool:
#         try:
#             with open(self.filename, 'r', encoding='utf-8') as file:
#                 self.data = json.load(file)
#             return True
#         except FileNotFoundError:
#             print("⚠️ فایل پیدا نشد.")
#             return False
#         except json.JSONDecodeError:
#             print("❌ فایل JSON معتبر نیست.")
#             return False
#         except Exception as e:
#             print(f"❌ خطا در خواندن فایل: {e}")
#             return False
#     def has_key(self, key: str) -> bool:
#         if isinstance(self.data, dict):
#             return key in self.data
#         return False
#     def get_value(self, key: str) -> Any:
#         if self.has_key(key):
#             return self.data[key]
#         return None
#     def show_structure(self):
#         if self.data:
#             print(json.dumps(self.data, indent=4, ensure_ascii=False))
#         else:
#             print("ℹ️ هیچ داده‌ای بارگذاری نشده.")



# fm = FileManager("data.json")
# if fm.read_json():
#     # fm.show_structure()  # نمایش ساختار فایل JSON
#     if fm.has_key("name"):
#         print("🔍 مقدار name:", fm.get_value("name"))
#     else:
#         print("❌ کلید 'name' پیدا نشد.")


# ---------------------------------------------------
import json

if (__name__ == '__main__'):
    
    # json_string = '{"name": "علی", "age": 25}'
    # data = json.loads(json_string)
    # print(data["name"])  # علی
    p = 'ssss'
    try:
        with open("data.json", "r", encoding="utf-8") as file:
            data = json.load(file) 
    except FileNotFoundError:
        print(f"Error --> NotFound path: {p}")
        # return False
    except Exception as e:
        print(f"Error -->{e}")

    print(type(data))
    print(data.keys())
