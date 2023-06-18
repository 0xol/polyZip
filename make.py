import os
import subprocess
from config import *

def compile(filePath: str):
    print(f"[{CC}] {filePath}")
    if filePath.split(".")[-1] == "c":
        subprocess.run(f"{CC} {CCFLAGS} -c {filePath} -o bin/{filePath.replace('.c', '').replace('/', '_')}.o", shell=True)
    if filePath.split(".")[-1] == "cpp":
        subprocess.run(f"{CC} {CCFLAGS} -c {filePath} -o bin/{filePath.replace('.cpp', '').replace('/', '_')}.o", shell=True)

def compilerDir(filePath: str):
    for file in os.listdir(filePath):
        if os.path.isdir(f"{filePath}/{file}"): compilerDir(f"{filePath}/{file}")
        else: compile(f"{filePath}/{file}")

if os.path.isdir("bin"):
    subprocess.run("rm -rf bin", shell= True)
subprocess.run("mkdir bin", shell= True)

compilerDir("core")

print(f"[{CC}] polyZip.exe")
subprocess.run(f"{CC} -O2 bin/*.o -o polyZip.exe", shell=True)