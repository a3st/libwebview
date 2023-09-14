import json

class Request:
    def __init__(self):
        self.data = None
    
    
    def on(self, message: str):
        self.data = json.loads(message)


request = Request()