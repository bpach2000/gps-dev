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


class StaticMapsAPI(object):
    def make_url(params):
        # Make the request to Google Maps API for the static map
        url = "https://maps.googleapis.com/maps/api/staticmap" + f"?center={params['center']}&zoom={params['zoom']}&size={params['size']}&key=" + "AIzaSyAHFnNvs2uAGYs7ur-uETNR-6Kle2VFIIo"
        return url

    def download_static_map(client, size, center=None, zoom=None, scale=None,
                            format=None, maptype=None, markers=None):
        # Ensure that 'size' is a tuple of width and height
        if not isinstance(size, tuple) or len(size) != 2:
            raise ValueError("Size must be a tuple of width and height.")

        # Construct the parameters for the static map
        params = {
            'size': f'{size[0]}x{size[1]}',  # Size as 'widthxheight'
            'zoom': zoom,
            'center': center,
            'scale': scale,
            'format': format,
            'maptype': maptype,
            'markers': markers,
            'key': client.client_id # Add the API key
        }
    
        # Get url
        url = make_url(params)

        response = requests.get(url, params=params)
    
        if response.status_code == 200:
            # Save the map image
            with open("static_map.png", "wb") as file:
                file.write(response.content)
            print("Map saved as 'static_map.png'")
        else:
            print( url )
            print(f"Error: {response.status_code}")
