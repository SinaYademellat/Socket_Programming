import numpy as np
import os

def DataLoader(dataPath:str):
    if not os.path.exists(dataPath):
        print(f"File not found: {dataPath}")
        return None
    loaded_data = np.load(dataPath)
    print('shape:', loaded_data.shape)
    return loaded_data

if(__name__ == '__main__'):
        raw_data = DataLoader(dataPath='my_data.npy')
        type(raw_data)