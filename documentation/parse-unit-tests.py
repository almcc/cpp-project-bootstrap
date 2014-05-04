#!/usr/bin/python

import os
import re

path = "../source/src/test/common/" # Must end it "/"

introduction = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Typi non habent claritatem insitam; est usus legentis in iis qui facit eorum claritatem. Investigationes demonstraverunt lectores legere me lius quod ii legunt saepius. Claritas est etiam processus dynamicus, qui sequitur mutationem consuetudium lectorum. Mirum est notare quam littera gothica, quam nunc putamus parum claram, anteposuerit litterarum formas humanitatis per seacula quarta decima et quinta decima. Eodem modo typi, qui nunc nobis videntur parum clari, fiant sollemnes in futurum."

files = result = [os.path.join(dp, f) for dp, dn, filenames in os.walk(path) for f in filenames if os.path.splitext(f)[1] == '.h']

regex = re.compile('.*void test(.*)\(.*')

def sphinxDirective(cppclass, members):
    return ".. doxygenclass:: {0}\n   :members: {1}\n\n".format(cppclass, ' '.join(members))

print("============")
print(" Unit Tests ")
print("============")

print("")
print(introduction)
print("")

for file in files:
    cppclass = file[len(path):len(file)-2].replace('/', '::')
    tests = []
    for line in open(file):
        mt = regex.match(line)
        if mt != None:
            tests.append("test" + mt.group(1))

    print(sphinxDirective(cppclass, tests))