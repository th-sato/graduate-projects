#1 Mostrar a preferência dos usuários por lojas

select u.name, s.companyname from User u, Store s, Preferencia_Loja pl
where u.id = pl.id and pl.store_id = s.id;

#===============================================================================================

#2 Mostrar o nome das lojas e o de seus funcionários

select s.companyname, e.name from Employers e, Store s
where s.id = e.store_id;

#===============================================================================================

#3 Para cada cupom, mostrar seu titulo, descrição e tipo

select c.title, c.description, t.type from Coupon c, Type t
where c.type_id = t.id;

#===============================================================================================

#4 Para cada loja, imprimir seu nome e sua categoria

select s.companyname, cat.category from Store s, Category cat 
where s.category_id = cat.id;

#===============================================================================================

#5 Mostrar o nome do usuário e seu histórico com o nome do cupom

select u.name, c.title, h.date_hours, h.lat, h.lon, h.status from User u, History h, Coupon c 
where u.id = h.user_id and c.id = h.coupon_id;

#===============================================================================================

#6 Para todos usuarios em ordem alfabetica, mostrar as preferencias de categoria de cada um

select u.name, c.category from User u left join Preferencia p on (u.id = p.user_id) 
left join Category c on(c.id = p.category_id) 
order by u.name; 

#===============================================================================================

#7 Para todas as categorias em ordem alfabetica, mostrar os nomes das lojas do tipo delas

select c.category, s.companyname from Category c 
left join Store s on (c.id = s.category_id) 
order by c.category; 

#===============================================================================================

#8 Calcular a média do valor dos cupons para cada tipo de cupom

select t.type, avg(c.value) from Coupon c, Type t 
where c.type_id = t.id group by t.type;

#===============================================================================================

#9 Verificar a soma dos valores dos cupons que cada loja oferece, em ordem alfabética

select s.companyname, sum(c.value) from Store s, Coupon c 
where c.store_id = s.id group by s.companyname 
order by s.companyname;

#===============================================================================================

#10 Mostrar o nome da loja, o nome do cupom, o tipo de cupom, a categoria da loja
# e o valor do cupom para cupons com valores maiores ou iguais a 100

select s.companyname, c.title, t.type, cat.category, c.value from Store s, Type t, Category cat, Coupon c 
where s.id = c.store_id and cat.id = s.category_id and c.type_id = t.id
having c.value >= 100;

#===============================================================================================

#11 Para cada categoria, contar quantas lojas estao cadastradas 

select cat.category, count(s.id) from Category cat, Store s 
where cat.id = s.category_id 
group by cat.id
order by cat.category;

#===============================================================================================

#12 Mostrar o nome do usuário que mais gastou com cupons e o valor que foi gasto no total

select u.name, sum(c.value) from User u, History h, Coupon c
where u.id = h.user_id and c.id = h.coupon_id 
group by u.name
having sum(c.value) >= ALL (select sum(c.value) from User u, History h, Coupon c
where u.id = h.user_id and c.id = h.coupon_id group by u.name);
