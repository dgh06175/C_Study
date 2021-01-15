from flask import Flask, render_template
from sqlite3 import connect

app = Flask(__name__)
database = 'champ.db'


def findall():
    with connect(database) as conn:
        cur = conn.cursor()
        cur.execute('select id, name from champions')
        rows = cur.fetchall()
    return rows


def findone(id):
    with connect(database) as conn:
        cur = conn.cursor()
        cur.execute('select * from champions where id=?', (id,))
        row = cur.fetchone()
    return row


@app.route('/')
def index():
    rows = [{'id': cmp[0], 'name': cmp[1]} for cmp in findall()]
    return render_template('index.html', champions=rows)


@app.route('/champions/<int:id>')
def champions(id):
    row = findone(id)
    champion = {
        'id': row[0], 'name': row[1], 'winrate': row[2],
        'position': row[3], 'tier': row[4]
    } if row else None
    return render_template('champion.html', champion=champion)


if __name__ == '__main__':
    app.run(port=8080)
