#!/bin/bash

source projects.sh

SAMPLES=samples

function usage() {
    echo "$1 [--project|-p project-type]"
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

main $@