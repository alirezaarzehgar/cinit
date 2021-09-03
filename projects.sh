
function base() {
    if [[ -z $1 ]]; then
        echo "Project name not found"
    fi


    if [[ ! -f $1 ]]; then
        rm -rf $2
        cp -rf $SAMPLES/$1 $2
    else
        echo "$1 already exists"
    fi
}

function default() {
    base default $1
}

function udp-client-server() {
    base client-server/udp $1
}

function tcp-client-server() {
    base client-server/tcp $1
}