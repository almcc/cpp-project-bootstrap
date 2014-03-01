#!/usr/bin/python

from subprocess import call
import re

def getMakefileVariable(name):
  value = ""
  makefile = open( "Makefile", "r" )
  for line in makefile:
    a = re.compile(name+" = (.*)")
    match = a.match(line)
    if match:
      value = match.group(1).strip()
  makefile.close()
  return value

def getUserVariable(variable, regex):
  current = getMakefileVariable(variable)
  new = raw_input(variable.title() + " (Default = " + current + "): ")
  if new == "":
    new = current
  if re.match(regex, new) == None:
    print("'" + new + "' does not match the " + variable + " regex '" + regex + "'. Exiting...")
    exit()
  return new

def updateMakefileVariable(name, value):
  newLines = []
  makefile = open("Makefile", "r")
  for line in makefile:
    a = re.compile(name+" = (.*)")
    match = a.match(line)
    if match:
      newLines.append(name + " = " + value + "\n")
    else:
      newLines.append(line)
  makefile.close()

  tempMakefile = open('Makefile.tmp', 'w')
  for line in newLines:
    tempMakefile.write(line)
  tempMakefile.close()
  call(["mv", "Makefile.tmp", "Makefile"])


name = getUserVariable('NAME', '^[a-z0-9-]+$')
major = getUserVariable('MAJOR', '^[0-9]+$')
minor = getUserVariable('MINOR', '^[0-9]+$')
fix = getUserVariable('FIX', '^[0-9]+$')
label = getUserVariable('LABEL', '^(dev|alpha|beta|rc|rel){1}$')
build = getUserVariable('BUILD', '^[0-9]+$')

version = major + '.' + minor + '.' + fix
release = name + '-' + version + '-' + label + build

print("Building " + release)
confirm = raw_input("Confirm [y|n]: ")

if confirm == 'y':
  updateMakefileVariable("NAME", name)
  updateMakefileVariable("MAJOR", major)
  updateMakefileVariable("MINOR", minor)
  updateMakefileVariable("FIX", fix)
  updateMakefileVariable("LABEL", label)
  updateMakefileVariable("BUILD", build)
  call(["make", "release"])

