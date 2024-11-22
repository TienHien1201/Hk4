--B�i 1
create login user1  
with password = '123456'
create login user2  
with password = '123456'
create login manager  
with password = '123456'
create login viewer  
with password = '123456'
create login developer  
with password = '123456'
create login admin_user  
with password = '123456'

create user user1
for login user1
create user user2
for login user2
create user manager
for login manager
create user viewer
for login viewer
create user developer
for login developer
create user admin_user
for login admin_user

create role sales_team
create role orther_management

--B�i 2
grant select on khachhang to user1 
execute as user = 'user1'
select * from khachhang

--B�i 3
revert
grant select,insert on cthd to user2 
execute as user = 'user2'
select * from cthd

--B�i 4
revert
grant select on khachhang(makh, tenkh,diachi, sdt) to viewer 
execute as user = 'viewer'
select makh, tenkh,diachi, sdt from khachhang

--B�i 5
GRANT EXECUTE ON dbo.tinhdoanhthu TO manager;

--B�i 6
grant create table to developer

--B�i 7
GRANT ALL TO admin_user;

--B�i 8
grant select,update on mathang to manager 

--B�i 9
grant insert,update on hoadon to  sales_team

--B�i 10
GRANT REFERENCES (mahd) ON hoadon TO order_management;

--B�i 11
REVOKE SELECT ON khachhang FROM user1;

--B�i 12
REVOKE UPDATE ON hoadon FROM sales_team;