--########## Dạng 3 ##############

--Bài 6
create trigger trg_xoasv
on sinhvien
for delete
as 
update lop
set lop.siso = lop.siso - 1
from deleted
where lop.malop = deleted.malop
go
--Bài 7
create trigger trg_kTDiem
on ketqua
for update, insert
as 
declare @diem int
select @diem = diem from inserted
if @diem > 10 
begin
print N'Cần nhập điểm bé hơn hoặc bằng 10'
rollback transaction 
end

go
--Bài 8
create trigger trg_SinhVien
on SinhVien
for insert, update
as

    declare @checkmlsv varchar(10);

    select @checkmlsv = malop from inserted;

    if @checkmlsv not in (select malop from lop)
    begin
        print 'Mã lớp không tồn tại';
        rollback transaction;
    end
go

--Bài 9
create trigger trg_Update_Malop on sinhvien
after update 
as 
begin
declare @ml varchar(10)
        SET @ml = (select malop from inserted)
         UPDATE lop
		 set siso = siso - 1
		 where @ml = malop
end 

go

--Bài 10
create trigger trg_Update_Malop1 on sinhvien
after update 
as 
begin
declare @ml varchar(10)
        SET @ml = (select malop from inserted)
         UPDATE lop
		 set siso = siso - 1
		 where @ml = malop
end 

go

--########### Bài tập tự giải ###############
--Bài 1
CREATE TRIGGER trg_check_foreignkey
ON cthd
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (SELECT 1 FROM inserted i JOIN HoaDon hd ON i.mahd = hd.mahd WHERE hd.mahd
	IS NULL)
    BEGIN
        PRINT N'Không thể thêm hoặc cập nhật chi tiết hóa đơn với mã hóa đơn không tồn tại trong bảng HoaDon.'
        ROLLBACK TRANSACTION
    END
END
go
--Bài 2
CREATE TRIGGER tr_check_cascade_delete
ON cthd
for DELETE
AS
BEGIN
    SET NOCOUNT ON;

    DELETE FROM cthd
    WHERE mahd IN (SELECT mahd FROM deleted)
    AND mahd NOT IN (SELECT mahd FROM HoaDon); 
END
go
--Bài 3
CREATE TRIGGER tr_Check_TenMatHangNhap
ON mathang
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (
        SELECT 1
        FROM inserted i1
        JOIN inserted i2 ON i1.tenmh = i2.tenmh AND i1.tenmh != i2.tenmh
    )
    BEGIN
        print N'Không thể thêm hai mặt hàng có cùng tên.';
        ROLLBACK TRANSACTION;
    END;
END; 
go
--Bài 4
CREATE TRIGGER tr_Check_XoaMatHang
ON mathang
For DELETE
AS
BEGIN
    

    IF (SELECT COUNT(*) FROM deleted) > 1
    BEGIN
        PRINT N'Không thể xóa nhiều hơn một mặt hàng cùng một lúc.';
        ROLLBACK TRANSACTION;
    END
    ELSE
    BEGIN
        DELETE FROM mathang WHERE mamh IN (SELECT mamh FROM deleted);
    END;
END;
go
--Bài 5
CREATE TRIGGER tr_check_SoLuongSua
ON cthd
AFTER INSERT
AS
BEGIN

    IF EXISTS (
        SELECT 1
        FROM inserted i
        JOIN mathang mh ON i.mamh = mh.mamh
        WHERE mh.tenmh = N'Sữa%' AND i.SoLuong % 10 <> 0
    )
    BEGIN
        PRINT N'Chỉ được bán mặt hàng sữa với số lượng là bội số của 10.';
        ROLLBACK TRANSACTION;
    END;
END;
go
--Bài 6
CREATE TRIGGER tr_check_ChenCTHD
ON cthd
AFTER INSERT
AS
BEGIN

   
    IF EXISTS (
        SELECT 1
        FROM inserted i
        LEFT JOIN mathang mh ON i.mamh = mh.mamh
        WHERE mh.mamh IS NULL
    )
    BEGIN
        PRINT N'Mã mặt hàng không tồn tại.';
        ROLLBACK TRANSACTION;
        RETURN;
    END;

    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE SoLuong < 0
    )
    BEGIN
        PRINT N'Số lượng không được nhập âm.';
        ROLLBACK TRANSACTION;
        RETURN;
    END;
END;
go

--Bài 7
CREATE TRIGGER tr_Xoa_CacBanLienQuan
ON mathang
AFTER DELETE
AS
BEGIN

    DELETE FROM cthd
    WHERE mamh IN (SELECT mamh FROM deleted);

END;
go

--Bài 8
CREATE TRIGGER tr_check_DVT
ON mathang
AFTER INSERT, UPDATE
AS
BEGIN

    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE dvt NOT IN ('lốc', 'lon', 'gói', 'hộp')
    )
    BEGIN
        print N'Đơn vị tính chỉ có thể là lốc, lon, gói hoặc hộp.'
        ROLLBACK TRANSACTION;
    END;
END;
go
--Bài 9
CREATE TRIGGER tr_check_SDT
ON KhachHang
AFTER INSERT, UPDATE
AS
BEGIN

    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE LEN(sdt) != 10
        OR (LEFT(sdt, 2) NOT IN ('01', '03'))
    )
    BEGIN
        print N'Số điện thoại phải gồm 10 số và bắt đầu bằng ''01'' hoặc ''03'
        ROLLBACK TRANSACTION;
    END;
END;
go
--Bài 10
CREATE TRIGGER tr_update_LoaiKH
ON hoadon
AFTER INSERT, UPDATE
AS
BEGIN
   
    UPDATE KhachHang
    SET loaikh = 'VIP'
    FROM khachhang k
    JOIN (
        SELECT hoadon.makh, SUM((cthd.soluong)*(mathang.gia))  AS TongTien
        FROM cthd
        JOIN mathang ON cthd.mamh = mathang.mamh
        JOIN hoadon ON cthd.mahd = hoadon.mahd
        WHERE YEAR(hoadon.ngaylap) = YEAR(GETDATE()) 
        GROUP BY hoadon.makh
    ) AS h ON k.makh = h.makh
    WHERE h.TongTien >= 10000000; 
END; 

