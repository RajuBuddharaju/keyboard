#!/usr/bin/env bash
set -euo pipefail

commands=(
  "cp -r src/* ~/qmk_firmware/keyboards/ergonator"
  "qmk flash -km default -kb ergonator --env handedness=right -bl avrdude-split-right"
  "qmk flash -km default -kb ergonator --env handedness=left -bl avrdude-split-left"
)

for cmd in "${commands[@]}"; do
  echo
  echo "▶ About to run: $cmd"
  read -p "Continue? [Y/n] " ans
  case "${ans:-Y}" in
    [Yy]* )
      eval "$cmd"
      ;;
    * )
      echo "Aborted."
      exit 1
      ;;
  esac
done

echo
echo "All done!"

