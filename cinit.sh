#!/bin/bash

SAMPLES=/opt/cinit/samples

function usage() {
    echo "$1 [--project|-p project-type project-name]"
    exit
}

function project-manager() {
    case $1 in
        default|d)
            default $2
        ;;

        udp|udp-client-server|ucs)
            udp-client-server $2
        ;;

        tcp|tcp-client-server|tcs)
            tcp-client-server $2
        ;;
    esac
}

function argparser() {
    iterator=1

    for item in $@; do
        # echo $item
        case $item in
        --project|-p)
            number=$(($iterator+1))

            project-manager ${@: $number}
        ;;
        esac

        iterator=$(($iterator+1))
    done    
}

function main() {
    if [[ -z $1 ]]; then
        usage $@
    fi

    argparser $@
}


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

main $@