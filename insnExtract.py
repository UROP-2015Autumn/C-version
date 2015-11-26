
if __name__ == '__main__':

	origin = open("origin.txt",'r')
	res = open("extract.txt", 'w')
	strList = origin.readlines()
	for line in strList:
		temp = line.split('\t')
		if(len(temp) == 2):
			res.write((temp[1].split(' '))[0]+'\n')
