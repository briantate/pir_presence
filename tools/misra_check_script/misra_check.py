#! python3
"""
Standalone Python script that when run executes MISRA checks. 
Source files that need to be checked should be included in checkDetails.

IMPORTANT: Since this runs a .bat and .exe file, this needs to be run in a Windows environment.

Within checkDetails: 
- The first element indicates the name to be used for report generation
- The second element indicates the path of the source file to be checked
"""

import os
import sys
import subprocess
import glob
import platform

#Modify input start
MISRATOOL = "\"C:/Program Files/Microchip/MPLABX/v6.05/mplab_platform/bin/misracli.bat\""
XCLICENSEMANAGER = "\"C:/Program Files/Microchip/MPLABX/v6.05/mplab_platform/bin/xclm.exe\""
checkDetails = [["app", "../../firmware/src/app/*.c"], \
                ["digital", "../../firmware/src/digital/*.c"], \
                ["led", "../../firmware/src/led/*.c"], \
                ["timer", "../../firmware/src/timer/*.c"], \
                ["command", "../../firmware/src/command/*.c"], \
                ["analog", "../../firmware/src/analog/*.c"]]
#Modify input ends

def run_misra_checks(name, source_path):
    "run the MISRA check tool"
    cmd = MISRATOOL + ' '\
        + "--quiet --xclm=" \
        + XCLICENSEMANAGER \
        + ' '  \
        + "--html=misra_" \
        + name \
        + ".html" \
        + ' ' \
        + source_path
    subprocess.call(cmd, shell=True)

def cleanup():
    "cleanup and remove unnecessary files"
    os.chdir("../../")
    clean_up_paths = glob.glob("./**/*.ctu-info", recursive=True)
    clean_up_paths.extend(glob.glob("./**/cppcheck-addon-ctu-file-list", recursive=True))
    for path in clean_up_paths:
        os.remove(path)

def remove_reports():
    "remove generated reports"
    clean_up_paths = glob.glob("./**/*.html", recursive=True)
    for path in clean_up_paths:
        os.remove(path)

#main
if platform.system() == "Linux":
    print("Unable to run batch/exe file here. Please run this from Windows environment.")
    sys.exit(-1)

if len(sys.argv) == 2:
    if sys.argv[1] == "--init":
        remove_reports()
        cleanup()
        print("Initialized.")
        sys.exit(0)

print("Running MISRA...")
for i in range(len(checkDetails)):
    for j in range(len(checkDetails[i]) - 1):
        run_misra_checks(checkDetails[i][j], checkDetails[i][j + 1])

print("Cleaning up...")
cleanup()
print("Done!")
