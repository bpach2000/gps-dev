#******************************************************************************
# * Copyright (c) 2024 [Jason Parkinson-Brooke Pacheco]
# *
# * Permission is hereby granted, free of charge, to any person obtaining a copy
# * of this software and associated documentation files (the "Software"), to deal
# * in the Software without restriction, including without limitation the rights
# * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# * copies of the Software, and to permit persons to whom the Software is
# * furnished to do so, subject to the following conditions:
# *
# * The above copyright notice and this permission notice shall be included in
# * all copies or substantial portions of the Software.
# *
# * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# * THE SOFTWARE.
# *
# * SPDX-License-Identifier: MIT
# *****************************************************************************

import googlemaps
import requests


class MapTilesApi(object):
    pass
    
    def __init__(self, Lat, Long, Session_URL, Tiles_URL, API_Key, token):
        self.Session_URL = Session_URL
        self.Tiles_URL = Tiles_URL
        self.Lat = Lat  # instance variable
        self.Long = Long    # instance variable
        self.API_Key = "AIzaSyAHFnNvs2uAGYs7ur-uETNR-6Kle2VFIIo"
        self.token = token

    def __setLat__(self, lat):
        self.Lat = lat

    def __setLong__(self, long):
        self.Long = long
    
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

