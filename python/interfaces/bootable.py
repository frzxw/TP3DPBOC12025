from abc import ABC, abstractmethod

class Bootable(ABC):
    @abstractmethod
    def boot(self):
        pass

    @abstractmethod
    def shutdown(self):
        pass

    @abstractmethod
    def restart(self):
        pass