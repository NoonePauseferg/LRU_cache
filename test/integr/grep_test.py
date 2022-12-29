#!/usr/bin/env python3

import logging
import subprocess
import os

def system_run_command(args, ignore_stderr = True, additional_env = dict()):
   command = ' '.join([str(arg) for arg in args]) # str - поддержка Path
   logging.debug('Run command %s', command)
   cmd_env = os.environ.copy()
   cmd_env.update(additional_env)
   p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                        env=cmd_env)
   output, errors = p.communicate()
   if p.returncode or (not ignore_stderr and errors):
       raise IOError("CMD = [{}]\nErrors: {}".format(command, errors if errors else "[]"))
   p.wait()
   result = output.decode("utf-8").strip()
   return result


# print(system_run_command(["echo", "343434", "|", "grep", "a"]))

# with open('f.txt', 'r') as f:
#     for line in f:
#         pass

print("Integration test is OK")

# while read <<< 
