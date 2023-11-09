import argparse
import os
import sys
import subprocess
import shutil

# Define the names of the directories
venv_name = ".venv"
qt_name = ".qt"
build_name = ".build"
emsdk_name = ".emsdk"

# Define the paths
venv_path = os.path.join(os.getcwd(), venv_name)
qt_path = os.path.join(os.getcwd(), qt_name)
build_path = os.path.join(os.getcwd(), build_name)
emsdk_path = os.path.join(os.getcwd(), emsdk_name)

# Parse command line arguments
parser = argparse.ArgumentParser(description='Build the project on Windows')
parser.add_argument('--qt-version', type=str, default='6.6.0', help='The version of Qt to use')
parser.add_argument('--qt-arch', type=str, default='wasm_singlethread', help='The architecture of Qt to use')
parser.add_argument('--setup', action='store_true', help='Setup the project')
parser.add_argument('--clean', action='store_true', help='Clean the build directory before building')
parser.add_argument('--build', action='store_true', help='Build the project')
parser.add_argument('--deploy', action='store_true', help='Deploy the project')
parser.add_argument('--run', action='store_true', help='Run the project')
args = parser.parse_args()

if args.setup:
    # Check if the virtual environment already exists
    if not os.path.exists(venv_path):
        # If it doesn't exist, create it
        subprocess.run(["python", "-m", "venv", venv_name], 
                    stdout=sys.stdout, stderr=sys.stderr, text=True)

    # Install the required packages
    subprocess.run([os.path.join(venv_path, "Scripts", "python"), 
                    "-m", "pip", "install", "-r", "requirements.txt"], 
                    stdout=sys.stdout, stderr=sys.stderr, text=True)

    # Check if the Qt directory already exists
    if not os.path.exists(qt_path):
        subprocess.run([os.path.join(venv_path, "Scripts", "python"), 
                        "-m", "aqt", "install-qt", "windows", "desktop", args.qt_version, args.qt_arch, "-O", qt_path],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        
    # Check if the emsdk directory already exists
    if not os.path.exists(emsdk_path):
        subprocess.run(["git", "clone", "https://github.com/emscripten-core/emsdk.git", emsdk_path],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        # ./.emsdk/emsdk install 3.1.37
        subprocess.run([os.path.join(emsdk_path, "emsdk"), "install", "3.1.37"],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        
if args.clean:
    # Remove the build directory
    if os.path.exists(build_path):
        shutil.rmtree(build_path)

if args.build:
    if not os.path.exists(build_path):
        # Generate build system
        subprocess.run([os.path.join(venv_path, "Scripts", "activate.bat"), "&&",
                        os.path.join(emsdk_path, "emsdk"), "activate", "3.1.37", "&&",
                        os.path.join(qt_path, args.qt_version, args.qt_arch, "bin", "qt-cmake.bat"),
                        "-G", "MinGW Makefiles", "-B", build_path, "-S", ".", 
                        "-DQT_HOST_PATH=" + os.path.join(qt_path, args.qt_version, "mingw_64"), 
                        "-DCMAKE_PREFIX_PATH=" + os.path.join(qt_path, args.qt_version, args.qt_arch), 
                        "-DCMAKE_MAKE_PROGRAM=C:/Qt/Tools/mingw810_64/bin/mingw32-make.exe"],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        # Build
        subprocess.run([os.path.join(venv_path, "Scripts", "activate.bat"), "&&",
                        os.path.join(emsdk_path, "emsdk"), "activate", "3.1.37", "&&",
                        "cmake", "--build", build_path],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
    else:
        print("Build directory already exists. Please clean it before building.")

if args.deploy:
    print("Deploying happens automatically when building for WASM")

if args.run:
    # emrun --browser=chrome .\.build\src\qttest.html  
    subprocess.run([os.path.join(emsdk_path, "emsdk.bat"), "activate", "3.1.37", "&&",
                    "emrun" , os.path.join(build_path, "app", "index.html")],
                    stdout=sys.stdout, stderr=sys.stderr, text=True)
