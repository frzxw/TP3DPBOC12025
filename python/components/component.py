class Component:
    def __init__(self, id="", manufacturer="", model="", price=0.0):
        self._id = id
        self._manufacturer = manufacturer
        self._model = model
        self._price = price

    # Setters
    def set_id(self, id):
        self._id = id

    def set_manufacturer(self, manufacturer):
        self._manufacturer = manufacturer

    def set_model(self, model):
        self._model = model

    def set_price(self, price):
        self._price = price

    # Getters
    def get_id(self):
        return self._id

    def get_manufacturer(self):
        return self._manufacturer

    def get_model(self):
        return self._model

    def get_price(self):
        return self._price