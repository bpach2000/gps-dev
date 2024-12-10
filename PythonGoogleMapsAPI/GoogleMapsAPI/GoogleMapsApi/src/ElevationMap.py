import requests

class ElevationMap(object):
    
#     def __init__(self, api_key):
#         """
#         Initializes the ElevationMap object with the API key.
#         :param api_key: Google Maps Elevation API key
#         """
#         self.api_key = api_key

#     def __make_url(self, locations):
#         """
#         Constructs the request URL for the Google Elevation API based on the locations.
#         :param locations: A list or string of coordinates (lat,lng)
#         :return: The full URL string for the API request
#         """
#         # Locations should be in the format lat,lng (can be a single coordinate or a path)
#         locations_str = '|'.join(locations)  # Join multiple locations with '|' if needed
#         url = f"https://maps.googleapis.com/maps/api/elevation/json?locations={locations_str}&key={self.api_key}"
#         return url

#     def get_elevation(self, locations):
#         """
#         Fetches the elevation data for the given locations using the Google Elevation API.
#         :param locations: A list or string of coordinates (lat,lng) or a single location
#         :return: A dictionary with elevation data or an error message
#         """
#         # Ensure that locations is a list even if a single location is provided
#         if isinstance(locations, str):
#             locations = [locations]
        
#         # Make the API request
#         url = self.__make_url(locations)
#         response = requests.get(url)
        
#         if response.status_code == 200:
#             data = response.json()
            
#             # Check if the API response is valid
#             if data['status'] == 'OK':
#                 elevations = []
#                 for result in data['results']:
#                     elevation = result['elevation']
#                     location = result['location']
#                     elevations.append({'location': location, 'elevation': elevation})
#                 return elevations
#             else:
#                 return {"error": "Invalid response from API", "message": data.get('error_message')}
#         else:
#             return {"error": "Request failed", "status_code": response.status_code}
        
#     def download_static_map(self, location, zoom=15, size=(600, 600), filename="static_map.png"):
#         """
#         Downloads a static map image for the specified location and saves it in the same directory.
#         :param location: The latitude and longitude (lat,lng) of the location
#         :param zoom: Zoom level for the static map (default is 15)
#         :param size: Size of the image (default is 600x600)
#         :param filename: The filename to save the image as (default is 'static_map.png')
#         """
#         # Construct the Static Maps API URL
#         base_url = "https://maps.googleapis.com/maps/api/staticmap?"
#         params = {
#             'center': location,
#             'zoom': zoom,
#             'size': f"{size[0]}x{size[1]}",  # 'widthxheight'
#             'key': self.api_key
#         }
#         response = requests.get(base_url, params=params)
        
#         # Check if the request was successful
#         if response.status_code == 200:
#             # Save the image in the same directory as the script
#             with open(filename, "wb") as file:
#                 file.write(response.content)
#             print(f"Map image saved as '{filename}'")
#         else:
#             print(f"Error downloading static map: {response.status_code}")

# # Example usage
# if __name__ == "__main__":
#     api_key = "AIzaSyAHFnNvs2uAGYs7ur-uETNR-6Kle2VFIIo"
#     elevation_map = ElevationMap(api_key)
    
#     # Single location
#     result = elevation_map.get_elevation("39.7391536,-104.9847034")
#     print(result)
    
#     # Multiple locations
#     locations = ["39.7391536,-104.9847034", "40.748817,-73.985428"]
#     result = elevation_map.get_elevation(locations)
#     print(result)

#     # Download static map
#     elevation_map.download_static_map("39.7391536,-104.9847034", zoom=10, filename="denver_map.png")

