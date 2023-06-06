class Set:
    def _init_(self):
        self.elements = []

    def add(self, new_element):
        if new_element not in self.elements:
            self.elements.append(new_element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_set):
        intersection_set = Set()
        for element in self.elements:
            if element in other_set.elements:
                intersection_set.add(element)
        return intersection_set

    def union(self, other_set):
        union_set = Set()
        for element in self.elements:
            union_set.add(element)
        for element in other_set.elements:
            union_set.add(element)
        return union_set

    def difference(self, other_set):
        difference_set = Set()
        for element in self.elements:
            if element not in other_set.elements:
                difference_set.add(element)
        return difference_set

    def subset(self, other_set):
        for element in self.elements:
            if element not in other_set.elements:
                return False
        return True




