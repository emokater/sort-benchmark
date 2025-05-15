import random
import pandas as pd

flower_names = [
    "Роза", "Лилия", "Тюльпан", "Маргаритка", "Орхидея",
    "Бархатцы", "Хризантема", "Гвоздика", "Гиацинт", "Лаванда",
    "Жасмин", "Нарцисс", "Бегония", "Пион"
]

colors = [
    "красный", "жёлтый", "белый", "розовый",
    "оранжевый", "фиолетовый", "синий", "зелёный", "голубой"
]

aroma_levels = ["сильный", "умеренный", "слабый"]

regions = [
    "Азия", "Европа", "Северная Америка",
    "Южная Америка", "Африка", "Австралия"
]

sizes = [100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000]

def generateData(n):
    data = []
    for _ in range(n):
        name = random.choice(flower_names)
        color = random.choice(colors)
        aroma = random.choice(aroma_levels)
        region_list = random.sample(regions, random.choice([1,2,3]))

        data.append({"name": name, "color": color, "aroma": aroma, "regions": region_list})
    return data

def saveCSV(data, filename):
    df = pd.DataFrame(data)
    file_path = f"/Users/ekaterinagridneva/Desktop/hse/mp/sort-benchmark/datasets/{filename}"

    df.to_csv(file_path, index=False)

for n in sizes:
    data = generateData(n)
    filename = f"dataset_{n}.csv"

    saveCSV(data, filename)

