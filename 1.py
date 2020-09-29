import os
import subprocess
result = subprocess.run(['sudo', 'airmon-ng'],
    stdout = subprocess.PIPE)
print(result.stdout)
