import fnmatch
import os
import subprocess

cert = os.environ.get('CERT')
signtool_args = os.environ.get('SIGNTOOL_ARGS') || \
    'sign /t  http://timestamp.verisign.com/scripts/timstamp.dll' +
    ' /fd sha256'

assert (cert or signtool_args), 'One or both of the CERT or SIGNTOOL_ARGS must be' +
  'set. CERT by default is the name in the //CurrentUser/My windows certificate ' +
  'store. `SIGNTOOL_ARGS` can be used in combination `CERT` or by it self.'

def get_sign_cmd(file):
  # https://docs.microsoft.com/en-us/dotnet/framework/tools/signtool-exe
  cmd = 'signtool' + signtool_args
  if cert:
    cmd = cert + ' /n "' + cert + '"'
  return (cmd + ' "' + file + '"')

def run_cmd(cmd):
  p = subprocess.Popen(cmd, stdout=subprocess.PIPE)
  for line in p.stdout:
    print line
  p.wait()
  assert p.returncode == 0, "Error signing"

def sign_binaries(base_dir):
  matches = []
  for root, dirnames, filenames in os.walk(base_dir):
    for filename in filenames:
      if filename.endswith(('.exe', '.dll')):
        matches.append(os.path.join(root, filename))

  for binary in matches:
    sign_binary(binary)

def sign_binary(binary):
  cmd = get_sign_cmd(binary)
  run_cmd(cmd)
