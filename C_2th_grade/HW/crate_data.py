from sqlite3 import connect

champions = (
    (1, '다리우스', 8, '탑', 1),
    (2, '마스터 이', 3, '정글', 3),
    (3, '르블랑', 10, '미드', 2)
)

with connect('champ.db') as conn:
    cur = conn.cursor()
    cur.execute('''create table if not exists champions
        (id int primary key, name varchar(10), winrate int, position varchar(20), tier int)''')
    sql = 'insert into champions(id, name, winrate, position, tier) values(?, ?, ?, ?, ?)'
    cur.executemany(sql, champions)
    cur.execute('select * from champions')
    rows = cur.fetchall()
    print(rows)
    conn.commit()
