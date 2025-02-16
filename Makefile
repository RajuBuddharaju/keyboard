init:
	npm install

regenerate:
	npm run ergogen:build
	mv ./ergogen/output/pcbs/* ./ergogen/kicad/