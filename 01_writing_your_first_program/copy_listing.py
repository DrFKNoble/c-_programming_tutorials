from absl import app, flags

import pathlib

def main(argv):

    path = pathlib.Path(argv[0]).parent

    listing = list(path.glob("listing*"))
    print(str(listing))

    listing_cpp =  list(listing[0].glob("*.cpp"))
    print(str(listing_cpp[0]))

    main = list(listing[0].glob("qt"))
    print(str(main))
    
    main_cpp =  list(main[0].glob("*.cpp"))
    print(str(main_cpp[0]))

    print()

    return 0


if __name__ == "__main__":

    app.run(main)

