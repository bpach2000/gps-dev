import googlemaps
import requests

class ElevationMap(object):
    
    def __init__(self, name, age):
        self.name = name
        self.age = age


    def make_url(params):
        # Make the request to Google Maps API for the static map
        url = "https://maps.googleapis.com/maps/api/elevation/json" + "?locations=39.7391536%2C-104.9847034&key=YOUR_API_KEY"
      #   https://maps.googleapis.com/maps/api/elevation/json
      # ?locations=39.7391536%2C-104.9847034
      # &key=YOUR_API_KEY
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

# Example usage
api_key = "AIzaSyAHFnNvs2uAGYs7ur-uETNR-6Kle2VFIIo"
client = googlemaps.Client(api_key)

download_static_map(
    client,
    size=(400, 400),
    center=(63.259591, -144.667969),  # Coordinates of the center of the map
    zoom=6,
    scale=2,
    format="png",
    maptype="roadmap",
    markers=[(62.107733, -145.541936), "Delta+Junction,AK"]
)

# Example JSON
# {
#   "results":
#     [
#       {
#         "elevation": 1608.637939453125,
#         "location": { "lat": 39.7391536, "lng": -104.9847034 },
#         "resolution": 4.771975994110107,
#       },
#     ],
#   "status": "OK",
# }


