#!/bin/sh

export LOCAL_DIR="."

payload() {
    arduino-cli compile \
	--verbose \
	--fqbn esp32:esp32:esp32s3 \
	${LOCAL_DIR}
}

payload

# end.
