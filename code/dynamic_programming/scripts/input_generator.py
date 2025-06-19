import os
import shutil
import random

def make_case(n, m, letter="A", with_spaces=False):
    base = letter + chr(ord(letter)+1) + chr(ord(letter)+2)

    def build(length, variant=0):
        result = []
        for i in range(length):
            c = base[i % len(base)]
            if with_spaces and i % 5 == 0:
                result.append(" ")
            elif variant and i % 7 == 0:
                result.append(chr((ord(c) + 3 - variant) % 26 + ord('A')))
            else:
                result.append(c)
        return ''.join(result).strip()

    s = build(n, variant=1)
    t = build(m, variant=2)
    return f"{n} {s}\n{m} {t}"

def generate_static_input():
    sizes = [5, 10, 20, 40, 60, 80, 100, 120, 140, 160]
    letters = "ABCDEFGHIJ"
    lines = [str(len(sizes))]

    for i, size in enumerate(sizes):
        letter = letters[i]
        with_spaces = (i % 2 == 1)
        lines.append(make_case(size, size, letter, with_spaces))

    return "\n".join(lines)

def save_input_to_both_locations(content, filename="a.txt"):
    dp_path = f"../data/dynamic_programming_input/{filename}"
    bf_path = f"../../brute_force/data/brute_force_input/{filename}"

    os.makedirs(os.path.dirname(dp_path), exist_ok=True)
    os.makedirs(os.path.dirname(bf_path), exist_ok=True)

    with open(dp_path, "w") as f:
        f.write(content)

    shutil.copy(dp_path, bf_path)
    print(f"✅ Input estático generado y copiado a ambas carpetas.")

if __name__ == "__main__":
    content = generate_static_input()
    save_input_to_both_locations(content)
