#Krystal Hong
#I pledge my honor that I have abided by the Stevens Honor System. 

#!/bin/bash 

readonly dir="$HOME/.junk"

usage() { cat << HEREDOX
 Usage: $(basename $0) [-hlp] [list of files]
   -h: Display help.   
   -l: List junked files.
   -p: Purge all files.
   [list of files] with no other arguments to junk those files. 
HEREDOX
}


if [[ $# = 0 ]]
    then
    usage
    exit 1;
fi

helpF=0
listF=0
purgeF=0

while getopts ":hlp" options; do
    case "${options}" in

        :)
            usage
            exit 1;
            ;;
        h)

            helpF=1
            ;;
        l)
            listF=1
            ;;
        p)
            purgeF=1
            ;;
        *)
            echo "Error: Unknown option '${OPTARG}'."
            usage
            exit 1;
            ;;

    esac
done

if (( $helpF+$listF+$purgeF \> 1 )) || ( (($helpF+$listF+$purgeF == 1)) && (($# \> 1)) ); then
    echo "Error: Too many options enabled."
    usage
    exit 1;
elif [ $helpF == 1 ]; then 
    usage
    exit 0;
elif [ $listF == 1 ];then
    ls -lAF $dir
    exit 0;
elif [ $purgeF == 1 ];then 
    rm -r $dir
    mkdir -p $dir
    exit 0;  
fi



if [ ! -d $dir ]; then
  mkdir -p $dir
fi



for f in $@; do
    if [ ! -f $f ] && [ ! -d $f ]; then
        echo "Warning: '$f' not found."
    else
        mv $f $dir
    fi
done

exit 0
