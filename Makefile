init:
	npm install

regenerate:
	npm run ergogen:build
	mv ./ergogen/output/pcbs/production.kicad_pcb ./ergogen/kicad/