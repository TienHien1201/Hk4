create database QLLHC
use QLLHC
go
-- 5.1 Tạo bảng với các ràng buộc khóa chính, khóa ngoại
CREATE TABLE NgachLuong (
    msngach INT PRIMARY KEY,
    mota NVARCHAR(255)
);

CREATE TABLE DMNgachBac (
    msngach INT,
    bac INT,
    hsluong DECIMAL(18,2),
    PRIMARY KEY (msngach, bac),
    FOREIGN KEY (msngach) REFERENCES NgachLuong(msngach)
);

CREATE TABLE NhanVien (
    msnv INT PRIMARY KEY,
    ho NVARCHAR(50),
    ten NVARCHAR(50),
    msngach INT,
    bac INT DEFAULT 1,
    ngaynlcc DATE,
    FOREIGN KEY (msngach) REFERENCES NgachLuong(msngach)
);

-- 5.2 Khai báo bổ sung các ràng buộc
ALTER TABLE DMNgachBac ADD CONSTRAINT UC_hsluong UNIQUE (msngach, hsluong);

-- 5.3 Tạo các view
CREATE VIEW vwhsluong AS
SELECT NhanVien.msnv, NhanVien.msngach, NhanVien.bac, DMNgachBac.hsluong
FROM NhanVien
JOIN DMNgachBac ON NhanVien.msngach = DMNgachBac.msngach AND NhanVien.bac = DMNgachBac.bac;

CREATE VIEW vwNangLuong AS
SELECT *
FROM NhanVien
WHERE DATEDIFF(MONTH, ngaynlcc, GETDATE()) >= 24;

-- 5.4 Tạo trigger
CREATE TRIGGER tr_UpdateBacLuong
ON NhanVien
AFTER UPDATE
AS
BEGIN
    IF UPDATE(bac)
    BEGIN
        DECLARE @maxBac INT;
        SELECT @maxBac = MAX(bac) FROM DMNgachBac WHERE msngach = (SELECT msngach FROM inserted);
        IF EXISTS (SELECT 1 FROM inserted WHERE inserted.bac > @maxBac)
        BEGIN
            RAISERROR ('Bậc lương mới không được lớn hơn bậc lương cao nhất trong ngạch lương', 16, 1);
            ROLLBACK TRANSACTION;
        END;
    END;
END;

-- 5.5 Tạo stored procedure
CREATE PROCEDURE sp_NhanVienNangLuong
    @Nam INT = NULL
AS
BEGIN
    IF @Nam IS NULL
        SET @Nam = YEAR(GETDATE());
        
    SELECT * 
    FROM NhanVien 
    WHERE YEAR(ngaynlcc) = @Nam;
END;