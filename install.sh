#!/bin/bash

project_name=cinit

dest_dir=/opt

cd ..

cp -r $project_name $dest_dir

ln -sf /opt/$project_name/cinit.sh /usr/bin/cinit

if [[ -f ~/.bashrc ]]; then
    source ~/.bashrc
fi

if [[ -f ~/.zshrc ]]; then
    source ~/.zshrc
fi