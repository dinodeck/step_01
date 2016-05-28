#
# I am not a build engineer at all, and my knowledge of the mac ecosystem
# is **very** limited.
#
# Dinodeck should statically link everything.
# The end user should be able to copy one file and start playing. Ideally.
# I've struggled to get Mac to not dyamically link to this SDL file.
# In order to move forward I just rename it.
# If you can fix this properly then please let me know :)
# Ideally I wouldn't use SDL all but it works!
#

if [ -e "/opt/local/lib/libSDL-1.2.0.dylib" ]
then
  mv /opt/local/lib/libSDL-1.2.0.dylib /opt/local/lib/libSDL-1.2.0.dylib_
fi
make PLATFORM_DD=MAC

if [ -e "/opt/local/lib/libSDL-1.2.0.dylib_" ]
then
  mv /opt/local/lib/libSDL-1.2.0.dylib_ /opt/local/lib/libSDL-1.2.0.dylib
fi
