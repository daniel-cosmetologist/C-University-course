
-- Создание простой таблицы 

CREATE TABLE book(
    book_id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(50),
    author VARCHAR(30),
    price DECIMAL(8, 2),
    amount INT,
    /* expiration_date DATE */
);

-- Вставка новой записи в таблицу 

SELECT * FROM book;
INSERT INTO book (title, author, price, amount)
VALUES ('Мастер и Маргарита', 'Булгаков М.А.', 670.99, 3);
INSERT INTO book (title, author, price, amount)
VALUES ('Белая гвардия', 'Булгаков М.А.', 540.50, 5);
INSERT INTO book (title, author, price, amount)
VALUES ('Идиот', 'Достоевский Ф.М.', 460.00, 10);
INSERT INTO book (title, author, price, amount)
VALUES ('Братья Карамазовы', 'Достоевский Ф.М.', 799.01, 2);
SELECT * FROM book;


SELECT author, title, price FROM book -- Выборка отдельных столбцов

SELECT title AS Название, author AS Автор FROM book -- Выборка новых столбцов и присвоение им новых имен

SELECT title, amount, 1.65 * amount AS pack FROM book -- Выборка данных с созданием вычисляемого столбца

-- МАТЕМАТИЧЕСКИЕ ФУНКЦИИ 
-- https://docs.microsoft.com/ru-ru/sql/t-sql/functions/mathematical-functions-transact-sql?view=sql-server-ver15 

CEILING(x)	возвращает наименьшее целое число, большее или равное x
            (округляет до целого числа в большую сторону)	
            CEILING(4.2)=5
            CEILING(-5.8)=-5
ROUND(x, k)	округляет значение x до k знаков после запятой,
            если k не указано – x округляется до целого	    
            ROUND(4.361)=4
            ROUND(5.86592,1)=5.9
FLOOR(x)	возвращает наибольшее целое число, меньшее или равное x
            (округляет до  целого числа в меньшую сторону)	
            FLOOR(4.2)=4
            FLOOR(-5.8)=-6
POWER(x, y)	возведение x в степень y	
            POWER(3,4)=81.0
SQRT(x)	    квадратный корень из x	
            SQRT(4)=2.0
            SQRT(2)=1.41...
DEGREES(x)	конвертирует значение x из радиан в градусы	
            DEGREES(3) = 171.8...
RADIANS(x)	конвертирует значение x из градусов в радианы	
            RADIANS(180)=3.14...
ABS(x)	    модуль числа x	
            ABS(-1) = 1
            ABS(1) = 1
PI()	    pi = 3.1415926...


-- Для каждой книги из таблицы book вычислим налог на добавленную стоимость (имя столбца tax) , 
-- который включен в цену и составляет k = 18%,  а также цену книги (price_tax) без него.
SELECT title, 
    price, 
    ROUND((price*18/100)/(1+18/100),2) AS tax, 
    ROUND(price/(1+18/100),2) AS price_tax 
FROM book;

-- IF STATEMENT
SELECT author,
       title,
       ROUND(IF(author='Булгаков М.А.', 1.1 * price, IF(author='Есенин С.А.', 1.05 * price, price)), 2) AS new_price
FROM book

-- Условный выбор
SELECT author, title, price FROM book WHERE amount < 10

SELECT title, author, price, amount FROM book
WHERE (price < 500 OR price > 600) AND price * amount >= 5000;

SELECT title, author FROM book
 WHERE price BETWEEN 540.50 AND 800
   AND amount IN (2, 3, 5, 7);

-- Сортировка по возрастанию (ASC) и по убыванию (DESC)
SELECT author, title FROM book
 WHERE amount BETWEEN 2 AND 14
ORDER BY author DESC, title ASC;

SELECT title, author FROM book
WHERE title LIKE "%_ %" AND (author LIKE "% С._.%" OR author LIKE "% _.С.%")
ORDER BY title ASC;

-- Групповые запросы
SELECT author FROM book GROUP BY author;


