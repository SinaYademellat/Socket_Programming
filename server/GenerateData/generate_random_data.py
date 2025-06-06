import numpy as np

if(__name__ == "__main__"):
    data = np.random.randint(low=1, high=1_000, size=(10000, 100))
    np.save('my_data.npy', data)

