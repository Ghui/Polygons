commit:
	git init
	git add .
	git commit -m "First Commit"
	git remote add origins https://github.com/Ghui/Polygons.git
	git remote -v
	git push origins master
	mv makefile ../line
