import sys
import os
import re

#https://stackoverflow.com/questions/4128144/replace-string-within-file-contents
def renameProjectnameInFile(filename, old_string, new_string):
    with open(filename) as f:
        s = f.read()
        if old_string not in s:
            print('"{old_string}" not found in {filename}.'.format(**locals()))
            input()
            return

    with open(filename, 'w') as f:
        print('Changing "{old_string}" to "{new_string}" in {filename}'.format(**locals()))
        s = s.replace(old_strings, new_string)
        f.write(s)

if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("This tool is supposed to be called from the command line. Usage: createproject.py [YourProjectName]")
        input()
    
    newName = sys.argv[1].strip()

    try:
        renameProjectnameInFile("Ascendit-Unity-Framework.sln", "Ascendit-Unity-Framework", newName)
        os.rename("Ascendit-Unity-Framework.sln", newName + ".sln")
        os.rename("Ascendit-Unity-Framework", newName)

        os.chdir(os.getcwd() + "/" + "Ascendit-Unity-Framework")

        directory = os.listdir(os.getcwd())
        for fname in directory:
            cleanedName = re.sub(r"\s+", "", re.sub(r'[^\w]', ' ', newName)).upper()
            renameProjectnameInFile(fname, "Ascendit-Unity-Framework", newName)
            renameProjectnameInFile(fname, "ASCENDITUNITYFRAMEWORK", cleanedName)
            renameProjectnameInFile(fname, "AscenditUnityFramework", cleanedName)

        print("Done!")
        input()
        
    except:
        print("An error occured. Maybe an invalid name or there are certain files missing")
        input()


    