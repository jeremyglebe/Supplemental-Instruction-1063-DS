# python script to make a better input file
# don't worry about this
clean_animals = ''
with open('animals.txt', 'r') as f:
    lines = f.readlines()
    for line in lines:
        if 'list' not in line and 'Common ' not in line and 'by ' not in line:
            if len(line.split()) == 1:
                clean_animals += line
            else:
                new_line = ''
                for word in line.split():
                    if '(' not in word:
                        new_line += word + '_'
                new_line = new_line[0:-1] + '\n'
                clean_animals += new_line
num_animals = len(clean_animals.splitlines())
clean_animals = str(num_animals) + '\n' + clean_animals
with open('clean_animals.txt', 'w') as f:
    f.write(clean_animals)
