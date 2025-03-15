from abc import ABC, abstractmethod

class Upgradable(ABC):
    @abstractmethod
    def upgrade(self):
        pass

    @abstractmethod
    def downgrade(self):
        pass