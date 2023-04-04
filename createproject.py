import sys
import os
import re

#https://stackoverflow.com/questions/4128144/replace-string-within-file-contents
def renameProjectnameInFile(filename, old_string, new_string):
    with open(filename) as f:
        s = f.read()
        if old_string not in s:
            print('"{old_string}" not found in {filename}.'.format(**locals()))
            return

    with open(filename, 'w') as f:
        print('Changing "{old_string}" to "{new_string}" in {filename}'.format(**locals()))
        s = s.replace(old_string, new_string)
        f.write(s)

if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("This tool is supposed to be called from the command line. Usage: createproject.py [YourProjectName]")

    else:
        newName = sys.argv[1].strip()

        #try:
        renameProjectnameInFile("Ascendit-Unity-Framework.sln", "Ascendit-Unity-Framework", newName)
        os.rename("Ascendit-Unity-Framework.sln", newName + ".sln")
        os.rename("Ascendit-Unity-Framework", newName)

        os.chdir(os.getcwd() + "/" + newName)

        directory = os.listdir(os.getcwd())
        for fname in directory:
            if(os.path.isfile(fname)):
                cleanedName = re.sub(r"\s+", "", re.sub(r'[^\w]', ' ', newName))
                renameProjectnameInFile(fname, "Ascendit-Unity-Framework", newName)
                renameProjectnameInFile(fname, "ASCENDITUNITYFRAMEWORK", cleanedName.upper())
                renameProjectnameInFile(fname, "AscenditUnityFramework", cleanedName)

        print("Done!")
            
        #except Exception as e:
        #    print(e.with_traceback())
        #    print("An error occured. Maybe an invalid name or there are certain files missing")


    