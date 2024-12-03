import googlemaps
import requests


class MapTilesAPI(object):
    pass
    
    def __init__(self, Lat, Long, Session_URL, Tiles_URL, API_Key, token):
        self.Session_URL = Session_URL
        self.Tiles_URL = Tiles_URL
        self.Lat = Lat  # instance variable
        self.Long = Long    # instance variable
        self.API_Key = "AIzaSyAHFnNvs2uAGYs7ur-uETNR-6Kle2VFIIo"
        self.token = token

    def __setLat__(self):
        print("HellO")

    def __setLong__(self):
        print("HellO")
    
    def __getLat__(self):
        return self.Lat

    def __getLong__(self):
        return self.Long

    def __make_token_url__(self):
        # Make the request to Google Maps API for the static map
        self.Session_URL = "https://tile.googleapis.com/v1/createSession?key=" + self.API_Key
       
    def __make_tiles_url__(self, z, x, y, orientation):
        self.Tiles_URL = "https://tile.googleapis.com/v1/2dtiles/" + z + "/" + x + "/" + y + "?session=" + self.token + "&key=" + self.API_Key + "&orientation=" + orientation

    def __retrieveSessionToken(self, size):
        self.__make_token_url__()

        # Ensure that 'size' is a tuple of width and height
        if not isinstance(size, tuple) or len(size) != 2:
            raise ValueError("Size must be a tuple of width and height.")
        
        response = requests.get(self.Session_URL)
    
        if response.status_code == 200:
            # save the sessionToken
            self.token = response.conetent
            print("Token Saved!")
        else:
            print( self.Session_URL )
            print(f"error: {response.status_code}")

    def __retrieveTiles__(self, size):
        self.__make_tiles_url__(2, self.Lat, self.Long, 270)
        
        # Ensure that 'size' is a tuple of width and height
        if not isinstance(size, tuple) or len(size) != 2:
            raise ValueError("Size must be a tuple of width and height.")

        response = requests.get(self.URL)
    
        if response.status_code == 200:
            # Save the map image
            with open("tile.png", "wb") as file:
                file.write(response.content)
            print("Map saved as 'tile.png'")
        else:
            print( self.Tiles_URL )
            print(f"Error: {response.status_code}")




