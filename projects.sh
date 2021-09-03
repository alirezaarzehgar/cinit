
function default() {
    if [[ -z $1 ]]; then
        echo "Project name not found"
    fi

    if [[ ! -f $1 ]]; then
        cp -rf $SAMPLES/default $1
    else
        echo "$1 already exists"
    fi
}

function udp-client-server() {
    echo $1 TODO UDP
}

function tcp-client-server() {
    echo $1 TODO TCP
}