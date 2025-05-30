init:
	npm install

regenerate:
	npm run ergogen:build
	mv ./ergogen/output/pcbs/* ./ergogen/kicad/
	if find ./ergogen/output/cases -name "*.jscad" | grep -q .; then \
		for i in ./ergogen/output/cases/*.jscad; do \
			npx @jscad/cli@1 "$$i" -of stla; \
		done; \
	fi