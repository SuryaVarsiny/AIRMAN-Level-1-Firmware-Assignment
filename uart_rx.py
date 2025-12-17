import sys
import csv

def checksum_xor(data):
    chk = 0
    for c in data:
        chk ^= ord(c)
    return chk

with open("output.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["timestamp","ax","ay","az","gx","gy","gz","alt","temp"])

    for line in sys.stdin:
        line = line.strip()

        if not line.startswith("$") or "*" not in line:
            continue

        payload, recv_chk = line[1:].split("*")
        calc_chk = checksum_xor(payload)

        if int(recv_chk, 16) != calc_chk:
            print("Checksum error")
            continue

        fields = payload.split(",")

        timestamp = fields[1]
        values = fields[2:]

        writer.writerow([timestamp] + values)

        print(
            f"t={timestamp}ms | "
            f"ax={values[0]} ay={values[1]} az={values[2]} | "
            f"gx={values[3]} gy={values[4]} gz={values[5]} | "
            f"alt={values[6]} temp={values[7]}"
        )
