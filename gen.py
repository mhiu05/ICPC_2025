import random

def gen():
    # Sinh N ngẫu nhiên, ví dụ để test nhỏ
    N = random.randint(3, 15)   # nếu muốn test lớn thì đổi 15 → 200000
    print(N)
    
    A = [str(random.randint(1, 10**6)) for _ in range(N)]
    print(" ".join(A))

if __name__ == "__main__":
    gen()
