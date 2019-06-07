#!/usr/bin/env python
""" A script for reading .dat files in Dummymeuporg. """

import sys
import struct

expected_magic_word = 0xdeadface


def check_magic_word(dat_file):
    magic_word = struct.unpack("<L", dat_file.read(4))[0]

    if magic_word != expected_magic_word:
        print("Invalid Magic Word.")


def read_character_name(dat_file):
    name_length = struct.unpack("<L", dat_file.read(4))[0]
    name = (struct.unpack(f"<{name_length}s",
            dat_file.read(name_length))[0]).decode('UTF-8')

    print(f"Character’s Name: {name}")


def read_filename(dat_file):
    filename_length = struct.unpack("<L", dat_file.read(4))[0]
    filename = (struct.unpack(f"<{filename_length}s",
                dat_file.read(filename_length))[0]).decode('UTF-8')

    print(f"Filename: {filename}")


def read_coordinates(dat_file):
    coordinates = struct.unpack("<2H", dat_file.read(4))
    x, y = coordinates[0], coordinates[1]

    map_name_length = struct.unpack("<L", dat_file.read(4))[0]
    map_name = (struct.unpack(f"<{map_name_length}s",
                dat_file.read(map_name_length))[0]).decode('UTF-8')

    print(f"Coordinates: {map_name} ({x},{y})")


def main(argv):
    """Main function."""
    if len(argv) < 2:
        print(f"Usage: {argv[0]} <dat_file>")
        raise SystemExit(-1)

    source = argv[1]
    with open(source, "rb") as dat_file:
        check_magic_word(dat_file)
        read_character_name(dat_file)
        read_filename(dat_file)
        read_coordinates(dat_file)
        raise SystemExit(0)


if __name__ == "__main__":
    main(sys.argv)
