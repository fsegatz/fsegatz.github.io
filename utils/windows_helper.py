import argparse
import os
import sys
import subprocess
import shutil

# Define the names of the directories
venv_name = ".venv"
qt_name = ".qt"
build_name = ".build"

# Define the paths
venv_path = os.path.join(os.getcwd(), venv_name)
qt_path = os.path.join(os.getcwd(), qt_name)
build_path = os.path.join(os.getcwd(), build_name)

# Parse command line arguments
parser = argparse.ArgumentParser(description='Build the project on Windows')
parser.add_argument('--qt-version', type=str, default='6.6.0', help='The version of Qt to use')
parser.add_argument('--qt-arch', type=str, default='msvc2019_64', help='The architecture of Qt to use')
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

if args.clean:
    # Remove the build directory
    if os.path.exists(build_path):
        shutil.rmtree(build_path)


if args.build:
    # Create Build System with command .\.qt\6.6.0\msvc2019_64\bin\qt-cmake.bat -B .build -S . 
    if not os.path.exists(build_path):
        # Generate build system
        subprocess.run([os.path.join(venv_path, "Scripts", "activate.bat"), "&&",
                        os.path.join(qt_path, args.qt_version, args.qt_arch, "bin","qt-cmake.bat"),
                        "-B", build_path, "-S", "."],
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        # Build
        subprocess.run([os.path.join(venv_path, "Scripts", "activate.bat"), "&&",
                        "cmake", "--build", ".build", "--target", "ALL_BUILD", "--config", "Debug"], 
                        stdout=sys.stdout, stderr=sys.stderr, text=True)
        
    else:
        print("The build directory already exists, please remove it or use the --clean flag")

if args.deploy:
    # Deploy the project with .\.qt\6.6.0\msvc2019_64\bin\windeployqt.exe .\.build\Debug
    subprocess.run([os.path.join(qt_path, args.qt_version, args.qt_arch, "bin", "windeployqt.exe"), 
                    os.path.join(build_path, "Debug")], 
                    stdout=sys.stdout, stderr=sys.stderr, text=True)

if args.run:
    subprocess.run([os.path.join(build_path, "Debug", "index.exe")], 
                   stdout=sys.stdout, stderr=sys.stderr, text=True)

