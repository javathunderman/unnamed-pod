import re

raw_path = "./raw_lines.txt"
result_path = "./od.eds"

fin = open(raw_path, "r")
fout = open(result_path, "w")

print("Parsing lines into object dictionary:")
print("in:", raw_path, "\nout:", result_path)

for line in fin:
	#print(line[0:len(line)-1])
	#Note empty fields in data are replaced with "NONE"
	#                 0x00           (RO):      0x0000 000     1234        werewr 2343 er     (were er3<  )              all
	reg = re.search("(0x[\d|\w]{2}) (\(\w*\):) (0x[\d|\w|.]*) ([-]?[\d]*) ([^\s]+[\s[\S]*]*) (\([^\s]*[\s[\S]*]*[ ]?\)) (.*)", line)
	print(reg.group(0))

