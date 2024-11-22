--VD1: tạo trigger khi thêm sinh viên thì thông báo ....
create trigger trg_SinhVien_Them on sinhvien
after insert 
as 
print N'Bạn đã thêm sinh viên thành công !'

--VD1: tạo trigger khi thêm sinh viên thì thông báo ....
create trigger trg_SinhVien_Xoa on sinhvien
after delete
as 
print N'Bạn đã xóa sinh viên thành công !'


--Ví dụ 5: Chỉnh sửa trigger trg_sinhvien_Them tự động bổ sung điểm các 
--học phần tiếng anh vào bảng ketqua, mặc định là Null khi thêm mới một
--Sinh viên vào
alter trigger trg_SinhVien_Auto on sinhvien
after insert
as 
declare @mssv int 
select @mssv = masv from inserted
insert into ketqua values
(@mssv, 10, NULL),
(@mssv, 11, NULL),
(@mssv, 12, NULL)

insert into sinhvien values (
9602, N'Lê Văn', N'Nam','2000-01-01', 'Nam', 'HCM', 'PM24'
)

--Ví dụ 6: 
create trigger trg_donhang on donhang
after insert, update 
as 
    declare @ngayban date , @ngaygiao date
	select @ngaygiao= ngaygiao, @ngayban = ngayban 
	from inserted
	if @ngayban > @ngaygiao
	begin 
	 print N'nhập ngày giao hàng >= ngày bán hàng'
	 rollback transaction
    end