import re

raw_path = "./raw_lines.txt"
result_path = "./od.eds"
mand_path = "./MandatoryEntries.txt"

fin = open(raw_path, "r")
fout = open(result_path, "w")
fmand = open(mand_path, "r")

print("Parsing lines into object dictionary:")
print("in:", raw_path, "\nout:", result_path)

fout.write(";******************************************************************\n;Object Dictionary\n;*****************************************************************\n\n")
fout.write("[MandatoryObjects]\nSupportedObjects=3\n")
fout.write("1=0x1000\n2=0x1001\n3=0x1018\n\n")

regList = []

#parses text file into regex capture groups
for line in fin:
	#Note empty fields in data are replaced with "NONE"
	#                 0x00           (RO):      0x0000 000     1234        werewr 2343 er     (were er3<  )              all
	reg = re.search("(0x[\d|\w]{2}) (\(\w*\):) (0x[\d|\w|.]*) ([-]?[\d]*) ([^\s]+[\s[\S]*]*) (\([^\s]*[\s[\S]*]*[ ]?\)) (.*)", line)
	regList.append(reg)
	print(reg.group(0))

#declares list of thingymabobers
fout.write("[OptionalObjects]\nSupportedObjects=")
fout.write(str(len(regList)))
fout.write("\n")

for i in range(0, len(regList)):
	fout.write(str(i+1))
	fout.write("=")
	fout.write(regList[i].group(1))
	fout.write("\n")

fout.write("\n")
fout.write(fmand.read())
fout.write("\n\n")

for i in range(0, len(regList)):
	fout.write("[")
	fout.write(regList[i].group(1)[2:])
	fout.write("]\nParameterName=")	
	fout.write(regList[i].group(5))
	fout.write("\nObjectType=0x7\n")
	fout.write("DataType=0x7\n")
	fout.write("AccessType=")
	if regList[i].group(2)[1].lower() != 'r':
		fout.write("ro")
	else:
		fout.write(regList[i].group(2)[1:3].lower())
	fout.write("\nDefaultValue=")
	fout.write(regList[i].group(3))
	fout.write("\nPDOMapping=0")
	fout.write("\nObjFlags=1")
	fout.write("\n\n")


'''fout.write()

[OptionalObjects]
SupportedObjects=78
1=0x1003
2=0x1005
3=0x1008
4=0x100C
5=0x100D
6=0x1010
7=0x1011

[1000]
ParameterName=Device Type
ObjectType=0x7
DataType=0x7
AccessType=ro
DefaultValue=$NODEID+0x80
PDOMapping=0
ObjFlags=1
'''