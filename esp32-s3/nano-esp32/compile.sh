#!/bin/sh

export LOCAL_DIR="."

payload() {
    arduino-cli compile \
	--verbose \
	--fqbn arduino:esp32:nano_nora \
	${LOCAL_DIR}
}

payload

# end.
