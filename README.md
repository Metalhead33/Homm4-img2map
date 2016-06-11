# Homm4-img2map
Currently, this is not functioning and needs a lot of work, but I decided to upload it anyway, in case other people are interested too.

The way it works is, is that it takes an existing image, to convert it to a map for Heroes of Might and Magic IV. Well, not exactly. First of all, it converts the file into an uncompressed map, that you later need to compress to .bz, and add the Homm4 campaign header to it. But for now, that is trivialities.

Currently, I am unable to compile becuase sf::Image::loadFromFile causes undefined references. Besides that, the Lua script does not write into a file yet, just returns the file information.

The basis of this program is to read a picture, scan the needed pixels (depending on the desired map size, 76x76, 152x152, 228x228 or 304x304), passes the first two bytes of the RGB value of the pixel to be interpreted as the terrain type (for example, 0x00 0x00 for lush green grass, 0x00 0x01 for dry yellowish grass).
