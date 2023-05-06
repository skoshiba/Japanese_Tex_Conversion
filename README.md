# Japanese Tex Conversion
JTEC(Japanese TEx Conversion) is a convenient tool for japanese people which write papers in japanese. For example, it is important to note that we must use "," instead of japanese comma "、” , when writing a peper in Japanese .    Period as well. But it is take a lot of time to convert japanese mode to english mode every time input these character. So, JTEC converts these character automatically.

## Function
JTEC automatically performs the following functions
- Converts "、” to ","
- Converts "。" to "."
- Converts full-width numbers to half-width numbers
- Place white space in appropriate positions to make the text easier to readpositions

## Installing
You can install JTEC from command line.
```bash
git clone https://github.com/skoshiba/Japanese_Tex_Conversion.git
```

## Usage
After installing, you need to pass through the path to the executable file
```bash
export PATH=$PATH: skoshiba/tex_format/bin
```
After that, this command converts sample.tex to output.tex by JTEC. sample.tex is a input file and output.tex is a output file.
```bash
jtec sample.tex output.tex
```
When add `--number-only` option, JTEC only converts full-width numbers to half-width numbers.
```bash
jtec sample.tex output.tex --number-only
```
When add `--character-only` option, JTEC only converts "、" to "," and "。" to "." .
```bash
jtec sample.tex output.tex --character-only
```
