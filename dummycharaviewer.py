""" A script for reading .dat files in Dummymeuporg. """

import struct


path = "gordon.dat"
expected_magic_word = 0xdeadface

def check_magic_word():
    magic_word = struct.unpack("<L", dat_file.read(4))[0]   
    if magic_word == expected_magic_word:
        print("Everything OK!")
    else:
        print("Invalid Magic Word.")


def read_character_name():
    name_length = struct.unpack("<2L", dat_file.read(8))
    print("8 first bytes = ", name_length)
    name_length = name_length[1]
    name = struct.unpack("<"+ str(name_length) + "s", dat_file.read(name_length))[0]
    print("Name length = ", name_length)
    print("name type: ", type(name))
    print("Name = ", name)


def read_filename():
    filename_length = struct.unpack("<3LHL", dat_file.read(18))
    print("18 first bytes = ", filename_length)
    filename_length = filename_length[4]
    print("Filename length = ", filename_length)
    filename = struct.unpack("<" + str(filename_length) + "s", dat_file.read(filename_length))[0]
    print("Name type: ", type(filename))
    print("Name = ", filename)


def read_coordinates():
    map_and_position = struct.unpack("<4sL6sL15s2HL8s", dat_file.read(49))
    print("49 first bytes = ", map_and_position)
    the_map = map_and_position[8]
    x, y = map_and_position[5], map_and_position[6]
    print("Coordinates = {} ({},{})".format(the_map, x, y))


with open(path, "rb") as dat_file:
    # check_magic_word()
    # read_character_name()
    # read_filename()
    read_coordinates()
