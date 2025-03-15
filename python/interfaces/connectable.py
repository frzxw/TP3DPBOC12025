from abc import ABC, abstractmethod

class Connectable(ABC):
    @abstractmethod
    def connect(self):
        pass

    @abstractmethod
    def disconnect(self):
        pass