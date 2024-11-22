--Xem ai đang dùng 
select current_user

--Tạo 1 user nam
create login nhanvien 
with password = '123456'

--tạo 1 cái tên cho người dùng là nhân viên
create user nam 
for login nhanvien

--Xem có bao nhiêu người dùng 
select name from sys.sql_logins

--chuyển đổi người dùng
execute as user = 'nam'

--Muốn biết có bao nhiêu người dùng đăng nhập vào db qlsv
execute sp_helpuser

--Xóa người dùng
drop user nam

--Quay lại người dùng trước đó 
revert 

--Tạo  nhóm người dùng
create role giaovu

--Thêm người dùng vào nhóm
exec sp_addrolemember giaovu, nam


--Mõi lần cấp phát quyền cho ai đó thì phỉa revert về người dùng trước đó(dbo) rồi mới phát quyền
--Cấp phát quyền cho người sở hữu đối tượng cơ sở dữ liệu
grant select on sinhvien to nam   

select * from SinhVien
--Cấp phát quyền cho người dùng nào đó đc thao tác cái gì đó trên bảng nào đó
grant select,insert,update,delete 
on ketqua to nam
with grant option--Cho phép chuyển quyền cho người khác

grant create table to nam

grant select 
on lop(malop,tenlop) to nam