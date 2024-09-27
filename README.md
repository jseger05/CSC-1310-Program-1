CSC 1310 Program 1 -- A "media library" <br><br>
Media class holds different type of media (all the same thing, just called different names) <br>
Media has attributes of title, creator, year created, and a number of "plays" <br><br>
Shelf class holds one of a specific type of media, with options to edit <br>
Shelf has no attributes, but accessors and mutators for the Media elements within it <br><br>
Storage class holds ptrs to different Shelf objects<br>
This allows us to only have to deal with one Storage object in Driver<br>