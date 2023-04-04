import sys
import os
import re
import shutil

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

# https://stackoverflow.com/questions/2656322/shutil-rmtree-fails-on-windows-with-access-is-denied
def onerror(func, path, exc_info):
    import stat
    if not os.access(path, os.W_OK):
        os.chmod(path, stat.S_IWUSR)
        func(path)
    else:
        raise

if __name__ == "__main__":
    if(len(sys.argv) != 2):
        print("This tool is supposed to be called from the command line. Usage: createproject.py [YourProjectName]")

    else:
        newName = sys.argv[1].strip()

        try:
            shutil.rmtree('.git/', onerror=onerror)
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

            os.rename("Ascendit-Unity-Framework.rc", newName + ".rc")
            os.rename("Ascendit-Unity-Framework.vcxproj", newName + ".vcxproj")
            os.rename("Ascendit-Unity-Framework.vcxproj.filters", newName + ".vcxproj.filters")

            print("Done!")
            
        except Exception as e:
            print(e)

    