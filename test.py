import subprocess

NTEST = 100

# Mở file log để lưu toàn bộ kết quả
with open("log.txt", "w", encoding="utf-8") as log:

    for t in range(1, NTEST+1):
        # Sinh input
        with open("input.txt", "w") as f:
            f.write(subprocess.check_output(["python", "gen.py"]).decode())

        # Chạy brute
        with open("input.txt","r") as fin, open("out1.txt","w") as fout:
            subprocess.run(["brute.exe"], stdin=fin, stdout=fout)

        # Chạy fast
        with open("input.txt","r") as fin, open("out2.txt","w") as fout:
            subprocess.run(["fast.exe"], stdin=fin, stdout=fout)

        # Đọc output
        out1 = open("out1.txt").read().strip()
        out2 = open("out2.txt").read().strip()
        inp = open("input.txt").read()

        # Ghi vào log
        log.write(f"Test {t}\n")
        log.write(f"Input:\n{inp}")
        log.write(f"Brute: {out1}\n")
        log.write(f"Fast : {out2}\n")
        log.write("="*40 + "\n")

        # Kiểm tra WA
        if out1 != out2:
            log.write(f"❌ Wrong Answer tại test {t}\n")
            print(f"❌ Wrong Answer tại test {t} (xem log.txt)")
            break
        else:
            print(f"✔ Test {t} OK")
