import sqlite3

def print_db(str):
    print(str)
    curs.execute('SELECT * FROM food ORDER BY Expiration_date')  # 유통기한 얼마 안남은 순서
    rows = curs.fetchall()
    print(rows)

foods = (('과자', '2', 20220417),
    ('우유', '1', 20200520),
    ('아이스크림', '3', 20200921),
    ('라면', '4', 20230823))

conn = sqlite3.connect('foods.db')  # db파일 열기
curs = conn.cursor()
curs.execute('''CREATE TABLE IF NOT EXISTS food
    (name VARCHAR(20), num_of_unit INT, Expiration_date INT)''')

ins = 'INSERT INTO food (name, num_of_unit, Expiration_date) VALUES(?, ?, ?)'
curs.executemany(ins, foods)

print_db('처음 재고')
curs.execute("UPDATE food SET name = '상한우유' WHERE name = '우유'")
print_db('업데이트 한 재고')
curs.execute('DELETE FROM food WHERE name = "상한우유"')
print_db('상한 것을 삭제한 재고')

conn.commit()
conn.close()
