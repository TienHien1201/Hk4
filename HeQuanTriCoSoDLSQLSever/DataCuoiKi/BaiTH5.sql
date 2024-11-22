--Bài 2: Query
--a
SELECT HangHoa.tenhh, ChiTietGiaoHang.slgiao, ChiTietGiaoHang.dongiagiao
FROM ChiTietGiaoHang
JOIN HangHoa ON ChiTietGiaoHang.mahh = HangHoa.mahh
WHERE ChiTietGiaoHang.magiao = 'GH01';

--b
SELECT DonDatHang.madat, DonDatHang.ngaydat, KhachHang.tenkh
FROM DonDatHang
LEFT JOIN KhachHang ON DonDatHang.makh = KhachHang.makh
WHERE DonDatHang.madat NOT IN (SELECT DISTINCT madat FROM PhieuGiaoHang);

--c
SELECT TOP 1 tenhh, dongiahh
FROM HangHoa
ORDER BY dongiahh DESC;
--d
SELECT KhachHang.makh, KhachHang.tenkh, COUNT(DonDatHang.madat) AS 'SoLanDatHang'
FROM KhachHang
LEFT JOIN DonDatHang ON KhachHang.makh = DonDatHang.makh
GROUP BY KhachHang.makh, KhachHang.tenkh;

--e
SELECT PhieuGiaoHang.magiao, ngaygiao, SUM(slgiao*dongiagiao) AS 'TongTien'
FROM PhieuGiaoHang
JOIN ChiTietGiaoHang ON PhieuGiaoHang.magiao = ChiTietGiaoHang.magiao
WHERE YEAR(ngaygiao) = 2023
GROUP BY PhieuGiaoHang.magiao, ngaygiao;

--f
SELECT KhachHang.makh, KhachHang.tenkh, COUNT(DonDatHang.madat) AS 'SoLanDatHang'
FROM KhachHang
JOIN DonDatHang ON KhachHang.makh = DonDatHang.makh
GROUP BY KhachHang.makh, KhachHang.tenkh
HAVING COUNT(DonDatHang.madat) >= 2;

--g
SELECT TOP 1 ChiTietGiaoHang.mahh, HangHoa.tenhh, SUM(slgiao) AS 'TongSoLuongGiao'
FROM ChiTietGiaoHang
JOIN HangHoa ON ChiTietGiaoHang.mahh = HangHoa.mahh
GROUP BY ChiTietGiaoHang.mahh, HangHoa.tenhh
ORDER BY SUM(slgiao) DESC;

--h
UPDATE HangHoa
SET slcon = slcon + 10
WHERE mahh LIKE 'M%';

--i
-- Tạo bảng HangHoa1 sao chép từ bảng HangHoa
SELECT *
INTO HangHoa1
FROM HangHoa;

-- Xóa những mặt hàng chưa được đặt trong bảng HangHoa
DELETE FROM HangHoa
WHERE mahh NOT IN (SELECT DISTINCT mahh FROM ChiTietDatHang);

-- Chèn lại vào bảng HangHoa những dòng bị xóa từ bảng HangHoa1
INSERT INTO HangHoa (mahh, tenhh, dvt, slcon, dongiahh)
SELECT mahh, tenhh, dvt, slcon, dongiahh
FROM HangHoa1
WHERE mahh NOT IN (SELECT mahh FROM HangHoa);

--j
-- Thêm cột thanhtien cho bảng ChiTietGiaoHang
ALTER TABLE ChiTietGiaoHang
ADD thanhtien INT;

-- Cập nhật thanhtien = slgiao*dongiagiao
UPDATE ChiTietGiaoHang
SET thanhtien = slgiao * dongiagiao;

--Bài 3: View
--b
CREATE VIEW vw_TongSoLuongDat_2023
AS
SELECT mahh, SUM(sldat) AS tong_sldat
FROM ChiTietDatHang
JOIN DonDatHang ON ChiTietDatHang.madat = DonDatHang.madat
WHERE YEAR(ngaydat) = 2023
GROUP BY mahh;

--c
CREATE VIEW vw_KhachHang_HCM
AS
SELECT *
FROM KhachHang
WHERE diachi = 'HCM'
WITH CHECK OPTION;


-- Chèn khách hàng có địa chỉ HCM
INSERT INTO vw_KhachHang_HCM (makh, tenkh, diachi, dienthoai)
VALUES ('KH07', 'Nguyễn Văn A', 'HCM', 123456789);

-- Chèn khách hàng có địa chỉ ở Long An
-- Việc chèn này sẽ gây lỗi vì view vw_KhachHang_HCM được định nghĩa với điều kiện WHERE diachi = 'HCM'
-- Vì vậy, chỉ có thể chèn khách hàng có địa chỉ HCM vào view này
go
--Bài 5: Thủ Tục
--a
CREATE PROCEDURE sp_SoLuongHangDatTrongDon
    @madat CHAR(10),
    @mahh CHAR(10),
    @soluong INT OUTPUT
AS
BEGIN
    SELECT @soluong = sldat 
    FROM ChiTietDatHang
    WHERE madat = @madat AND mahh = @mahh;
END;
go
--c
CREATE PROCEDURE sp_HienThiDonDatHangCuaKhachHang
    @makh CHAR(10)
AS
BEGIN
    SELECT ddh.madat, ddh.ngaydat, pg.magiao, pg.ngaygiao
    FROM DonDatHang ddh
    LEFT JOIN PhieuGiaoHang pg ON ddh.madat = pg.madat
    WHERE ddh.makh = @makh;
END;
go
--d
CREATE PROCEDURE sp_DemPhieuGiaoHangTrongKhoangThoiGian
    @ngay1 DATE,
    @ngay2 DATE,
    @sophieu INT OUTPUT
AS
BEGIN
    SELECT @sophieu = COUNT(*)
    FROM PhieuGiaoHang
    WHERE ngaygiao BETWEEN @ngay1 AND @ngay2;
END;
go
--Câu 5e
-- Thêm cột tổng tiền vào bảng PhieuGiaoHang
ALTER TABLE PhieuGiaoHang
ADD tongtien int;
go
CREATE PROCEDURE CapNhatTongTienPhieuGiaoHang
AS
BEGIN
    BEGIN TRY
        BEGIN TRANSACTION; -- Bắt đầu giao dịch

        -- Cập nhật giá trị cho cột tongtien
        UPDATE PhieuGiaoHang
        SET tongtien = (
            SELECT SUM(slgiao * dongiagiao)
            FROM ChiTietGiaoHang
            WHERE ChiTietGiaoHang.magiao = PhieuGiaoHang.magiao
        );

        COMMIT TRANSACTION; -- Hoàn thành giao dịch
        PRINT 'Cập nhật tổng tiền cho phiếu giao hàng thành công.';
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION; -- Quay lại trạng thái trước khi bắt đầu giao dịch
        
    END CATCH
END
--e
ALTER TABLE KhachHang
ADD thuong2023 int; -- Giả sử kiểu dữ liệu cho thuong2023 là int, bạn có thể điều chỉnh theo nhu cầu thực tế

go
CREATE PROCEDURE CapNhatThuong2023
AS
BEGIN
    BEGIN TRY
        BEGIN TRANSACTION; -- Bắt đầu giao dịch

        -- Cập nhật giá trị cho cột thuong2023
        UPDATE KhachHang
        SET thuong2023 = CASE
                            WHEN EXISTS (
                                SELECT 1
                                FROM DonDatHang
                                INNER JOIN ChiTietDatHang ON DonDatHang.madat = ChiTietDatHang.madat
                                INNER JOIN HangHoa ON ChiTietDatHang.mahh = HangHoa.mahh
                                WHERE YEAR(DonDatHang.ngaydat) = 2023
                                GROUP BY DonDatHang.makh
                                HAVING SUM(ChiTietDatHang.sldat * HangHoa.dongiahh) > 50000000
                            )
                            THEN 3000000
                            WHEN EXISTS (
                                SELECT 1
                                FROM DonDatHang
                                INNER JOIN ChiTietDatHang ON DonDatHang.madat = ChiTietDatHang.madat
                                INNER JOIN HangHoa ON ChiTietDatHang.mahh = HangHoa.mahh
                                WHERE YEAR(DonDatHang.ngaydat) = 2023
                                AND EXISTS (
                                    SELECT 1
                                    FROM ChiTietDatHang AS CTDH
                                    INNER JOIN HangHoa AS HH ON CTDH.mahh = HH.mahh
                                    WHERE CTDH.madat = DonDatHang.madat
                                    AND HH.tenhh LIKE '%Máy giặt%'
                                )
                                GROUP BY DonDatHang.makh
                                HAVING SUM(ChiTietDatHang.sldat * HangHoa.dongiahh) > 35000000
                            )
                            THEN 2000000
                            WHEN EXISTS (
                                SELECT 1
                                FROM DonDatHang
                                WHERE YEAR(ngaydat) IN (2022, 2023)
                                GROUP BY makh
                                HAVING COUNT(DISTINCT YEAR(ngaydat)) = 2
                            )
                            THEN 1000000
                            ELSE 0
                        END;

        COMMIT TRANSACTION; -- Hoàn thành giao dịch
        PRINT 'Cập nhật tiền thưởng cho khách hàng năm 2023 thành công.';
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION; -- Quay lại trạng thái trước khi bắt đầu giao dịch
        PRINT ERROR_MESSAGE(); -- In ra thông báo lỗi
    END CATCH
END
go

--f
CREATE PROCEDURE sp_ThemMoiHangHoa
    @mahh CHAR(10),
    @tenhh NVARCHAR(255),
    @donvitinh NVARCHAR(50),
    @soluong INT,
    @dongia MONEY
AS
BEGIN
    IF EXISTS (SELECT * FROM HangHoa WHERE mahh = @mahh)
    BEGIN
        Print N'Mã hàng hóa đã tồn tại!';
        RETURN;
    END;

    IF @tenhh IS NOT NULL AND EXISTS (SELECT * FROM HangHoa WHERE tenhh = @tenhh)
    BEGIN
        print N'Tên hàng hóa đã tồn tại!';
        RETURN;
    END;

    IF @soluong IS NOT NULL AND @soluong < 0
    BEGIN
        print N'Số lượng phải lớn hơn hoặc bằng 0!';
        RETURN;
    END;

    IF @dongia IS NOT NULL AND @dongia < 0
    BEGIN
        print N'Đơn giá phải lớn hơn hoặc bằng 0!';
        RETURN;
    END;

    INSERT INTO HangHoa (mahh, tenhh, dvt, slcon, dongiahh)
    VALUES (@mahh, @tenhh, @donvitinh, @soluong, @dongia);
END;
go

--g
CREATE PROCEDURE ThemChiTietGiaoHang
    @magiao varchar(10),
    @mahh varchar(10),
    @slGiao int
AS
BEGIN
    BEGIN TRY
        BEGIN TRANSACTION; -- Bắt đầu giao dịch

        -- Kiểm tra hàng hóa này có được đặt không
        IF NOT EXISTS (
            SELECT 1
            FROM ChiTietDatHang
            WHERE madat IN (
                SELECT madat
                FROM PhieuGiaoHang
                WHERE magiao = @magiao
            ) AND mahh = @mahh
        )
        BEGIN
            print N'Hàng hóa này không được đặt trong đơn đặt hàng tương ứng.';
        END

        -- Kiểm tra số lượng giao có nhỏ hơn số lượng đặt ứng với hàng hóa này không
        IF @slGiao > (
            SELECT sldat
            FROM ChiTietDatHang
            WHERE madat IN (
                SELECT madat
                FROM PhieuGiaoHang
                WHERE magiao = @magiao
            ) AND mahh = @mahh
        )
        BEGIN
            Print N'Số lượng giao không thể lớn hơn số lượng đặt ứng với hàng hóa này.';
        END

        -- Kiểm tra số lượng giao có nhỏ hơn số lượng còn của hàng hóa này không
        IF @slGiao > (
            SELECT slcon
            FROM HangHoa
            WHERE mahh = @mahh
        )
        BEGIN
            Print N'Số lượng giao không thể lớn hơn số lượng còn của hàng hóa này.';
        END

        -- Thêm mới vào chi tiết giao hàng
        INSERT INTO ChiTietGiaoHang (magiao, mahh, slGiao, dongiagiao)
        VALUES (@magiao, @mahh, @slGiao, (SELECT dongiahh FROM HangHoa WHERE mahh = @mahh));

        -- Cập nhật số lượng còn của hàng hóa
        UPDATE HangHoa
        SET slcon = slcon - @slGiao
        WHERE mahh = @mahh;

        COMMIT TRANSACTION; -- Hoàn thành giao dịch
        PRINT 'Thêm chi tiết giao hàng thành công.';
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION; -- Quay lại trạng thái trước khi bắt đầu giao dịch
        PRINT ERROR_MESSAGE(); -- In ra thông báo lỗi
    END CATCH
END

go
--6 Hàm
--a
CREATE FUNCTION LaySoLuongHangDat
(
    @madat varchar(10),
    @mahh varchar(10)
)
RETURNS int
AS
BEGIN
    DECLARE @sldat int;

    -- Lấy số lượng hàng hóa được đặt trong đơn
    SELECT @sldat = sldat
    FROM ChiTietDatHang
    WHERE madat = @madat AND mahh = @mahh;

    -- Nếu không tìm thấy số lượng, trả về 0
    IF @sldat IS NULL
        SET @sldat = 0;

    RETURN @sldat;
END;

--b
CREATE FUNCTION LayTongTienPhieuGiaoHang
(
    @magiao varchar(10)
)
RETURNS int
AS
BEGIN
    DECLARE @tongtien int;

    -- Lấy tổng tiền của phiếu giao hàng
    SELECT @tongtien = tongtien
    FROM PhieuGiaoHang
    WHERE magiao = @magiao;

    -- Nếu không tìm thấy tổng tiền, trả về 0
    IF @tongtien IS NULL
        SET @tongtien = 0;

    RETURN @tongtien;
END;

--c
CREATE FUNCTION HienThiDonDatHangCuaKhachHang
(
    @makh varchar(10)
)
RETURNS @DSDonDatHang TABLE
(
    madat varchar(10),
    ngaydat date,
    magiao varchar(10),
    ngaygiao date
)
AS
BEGIN
    INSERT INTO @DSDonDatHang (madat, ngaydat, magiao, ngaygiao)
    SELECT DDH.madat, DDH.ngaydat, PGH.magiao, PGH.ngaygiao
    FROM DonDatHang AS DDH
    LEFT JOIN PhieuGiaoHang AS PGH ON DDH.madat = PGH.madat
    WHERE DDH.makh = @makh;

    RETURN;
END;


--d
CREATE FUNCTION DemPhieuGiaoHangTrongKhoangThoiGian
(
    @ngay1 date,
    @ngay2 date
)
RETURNS int
AS
BEGIN
    DECLARE @soluong int;

    -- Đếm số lượng phiếu giao hàng được giao trong khoảng thời gian từ ngày1 đến ngày2
    SELECT @soluong = COUNT(*)
    FROM PhieuGiaoHang
    WHERE ngaygiao BETWEEN @ngay1 AND @ngay2;

    RETURN @soluong;
END;

--e
CREATE FUNCTION LayTongTien
(
    @magiao varchar(10)
)
RETURNS int
AS
BEGIN
    DECLARE @tongtien int;

    -- Lấy tổng tiền từ bảng ChiTietGiaoHang
    SELECT @tongtien = SUM(slgiao * dongiagiao)
    FROM ChiTietGiaoHang
    WHERE magiao = @magiao;

    RETURN @tongtien;
END;

--7 trigger
ALTER TABLE HangHoa
ADD CONSTRAINT CHK_SoLuongCon_Positive CHECK (slcon > 0);

CREATE TRIGGER trg_CheckSoLuongCon
ON HangHoa
AFTER UPDATE
AS
BEGIN
    IF EXISTS (SELECT 1 FROM deleted WHERE slcon <= 0)
    BEGIN
        RAISERROR ('Số lượng còn của hàng hóa phải lớn hơn 0.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--b
ALTER TABLE HangHoa
ADD CONSTRAINT CHK_DonViTinh_Valid CHECK (dvt IN ('Cái', 'Thùng', 'Chiếc', 'Chai', 'Lon'));

CREATE TRIGGER trg_CheckDonViTinh
ON HangHoa
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (SELECT 1 FROM inserted WHERE dvt NOT IN ('Cái', 'Thùng', 'Chiếc', 'Chai', 'Lon'))
    BEGIN
        RAISERROR ('Đơn vị tính của hàng hóa chỉ nhận một trong các giá trị: Cái, Thùng, Chiếc, Chai, Lon.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--c
CREATE TRIGGER trg_CheckMaxOnePhieuGiao
ON PhieuGiaoHang
AFTER INSERT, UPDATE
AS
BEGIN
    DECLARE @madat varchar(10);
    DECLARE @count int;

    SELECT @madat = madat FROM inserted;

    SELECT @count = COUNT(*)
    FROM PhieuGiaoHang
    WHERE madat = @madat;

    IF @count > 1
    BEGIN
        RAISERROR ('Mỗi đơn đặt hàng chỉ có tối đa 1 phiếu giao hàng.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;


ALTER TABLE PhieuGiaoHang
ADD CONSTRAINT CHK_MaxOnePhieuGiao CHECK (dbo.fn_CheckMaxOnePhieuGiao(madat) <= 1);

--e
CREATE TRIGGER trg_UpdateDongia
ON LichSuGia
AFTER INSERT
AS
BEGIN
    DECLARE @mahh varchar(10);
    DECLARE @ngayhieuluc date;
    DECLARE @dongiamoi int;

    SELECT @mahh = i.mahh, @ngayhieuluc = i.ngayhl, @dongiamoi = i.dongia
    FROM inserted i
    INNER JOIN (
        SELECT mahh, MAX(ngayhl) AS max_ngayhl
        FROM LichSuGia
        GROUP BY mahh
    ) l ON i.mahh = l.mahh AND i.ngayhl = l.max_ngayhl;

    IF @ngayhieuluc > ALL (SELECT ngayhl FROM LichSuGia WHERE mahh = @mahh)
    BEGIN
        UPDATE HangHoa
        SET dongiahh = @dongiamoi
        WHERE mahh = @mahh;
    END
    ELSE
    BEGIN
        print N'Ngày có hiệu lực mới không hợp lệ.';
        ROLLBACK TRANSACTION;
    END
END;

--f
CREATE TRIGGER trg_CheckSLGiaoVaSLDat
ON ChiTietGiaoHang
AFTER INSERT, UPDATE
AS
BEGIN
    DECLARE @magiao varchar(10);
    DECLARE @mahh varchar(10);
    DECLARE @slGiao int;
    DECLARE @sldat int;

    SELECT @magiao = magiao, @mahh = mahh, @slGiao = slGiao FROM inserted;
    SELECT @sldat = sldat 
    FROM ChiTietDatHang 
    WHERE madat = @magiao AND mahh = @mahh;

    IF @slGiao > @sldat
    BEGIN
        RAISERROR ('Số lượng hàng hóa được giao không được lớn hơn số lượng hàng hóa được đặt tương ứng.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--8 Bảo mật và an toàn dữ liệu
-- Tạo login cho Admin và Director
CREATE LOGIN AdminLogin WITH PASSWORD = 'adminpassword';
CREATE LOGIN DirectorLogin WITH PASSWORD = 'directorpassword';

-- Tạo user cho Admin và Director
CREATE USER AdminUser FOR LOGIN AdminLogin;
CREATE USER DirectorUser FOR LOGIN DirectorLogin;

-- Gán quyền quản trị cho Admin và Director
ALTER SERVER ROLE sysadmin ADD MEMBER AdminLogin;
ALTER SERVER ROLE sysadmin ADD MEMBER DirectorLogin;

--Tạo các login và user cho user1, user2, user3:
CREATE LOGIN user1Login WITH PASSWORD = 'user1password';
CREATE LOGIN user2Login WITH PASSWORD = 'user2password';
CREATE LOGIN user3Login WITH PASSWORD = 'user3password';

CREATE USER user1 FOR LOGIN user1Login;
CREATE USER user2 FOR LOGIN user2Login;
CREATE USER user3 FOR LOGIN user3Login;

--Tạo một role có quyền chỉ xem các bảng:
CREATE ROLE ViewOnlyRole;

--có quyền xem tất cả các bảng nhưng không có quyền thêm, xóa sửa bất
 --kỳ bảng nào.
EXEC sp_msforeachtable 'GRANT SELECT ON ? TO ViewOnlyRole';

--user1, user2, user3 kế thừa quyền từ ViewOnlyRole  quyền xem tất cả các bảng nhưng
-- không có quyền thêm, xóa sửa bất kỳ bảng nào.
EXEC sp_addrolemember 'ViewOnlyRole', 'user1';
EXEC sp_addrolemember 'ViewOnlyRole', 'user2';
EXEC sp_addrolemember 'ViewOnlyRole', 'user3';

-- Tạo role cho quyền đầy đủ truy cập
CREATE ROLE FullAccessRole;

-- Cấp quyền SELECT, INSERT, UPDATE, DELETE cho các bảng cụ thể
GRANT SELECT, INSERT, UPDATE, DELETE ON DonDatHang TO FullAccessRole;
GRANT SELECT, INSERT, UPDATE, DELETE ON ChiTietDatHang TO FullAccessRole;
GRANT SELECT, INSERT, UPDATE, DELETE ON PhieuGiaoHang TO FullAccessRole;
GRANT SELECT, INSERT, UPDATE, DELETE ON ChiTietGiaoHang TO FullAccessRole;

-- Tạo user
CREATE LOGIN User4 WITH PASSWORD = 'user4password';
CREATE LOGIN User5 WITH PASSWORD = 'user5password';
CREATE LOGIN User6 WITH PASSWORD = 'user6password';

CREATE USER User4 FOR LOGIN User4;
CREATE USER User5 FOR LOGIN User5;
CREATE USER User6 FOR LOGIN User6;

-- Thêm user vào role
EXEC sp_addrolemember 'FullAccessRole', 'User4';
EXEC sp_addrolemember 'FullAccessRole', 'User5';
EXEC sp_addrolemember 'FullAccessRole', 'User6';



