 
create database QLDDH
go
use QLDDH
go

create table KhachHang(
makh varchar(10) primary key,
tenkh nvarchar(50),
diachi nvarchar(50),
dienthoai int

)
go

create table PhieuGiaoHang(
magiao varchar(10) primary key,
ngaygiao date,
madat varchar(10)
)
go
create table HangHoa(
mahh varchar(10) primary key,
tenhh nvarchar(50),
dvt nvarchar(20),
slcon int,
dongiahh int

)
go
create table ChiTietGiaoHang(
magiao varchar(10) ,
mahh varchar(10), 
slGiao int,
dongiagiao int,
 CONSTRAINT fk_magiaoCTDH FOREIGN KEY (magiao) REFERENCES PhieuGiaoHang(magiao), -- Thay 'phieugiaohang' bằng 'PhieuGiaoHang'
 CONSTRAINT fk_maHHCTDH FOREIGN KEY (mahh) REFERENCES HangHoa(mahh)
)
go

create table DonDatHang(
madat varchar(10) primary key,
ngaydat date,
makh varchar(10),
tinhtrang nvarchar(20),
CONSTRAINT fk_maKHDDH FOREIGN KEY (makh) REFERENCES KhachHang(makh)
)
go

create table LichSuGia(
mahh varchar(10) ,
ngayhl date,
dongia int,
CONSTRAINT fk_maHHlsg FOREIGN KEY (mahh) REFERENCES HangHoa(mahh)
)
go

create table ChiTietDatHang(
madat varchar(10) ,
mahh varchar(10),
sldat int,
CONSTRAINT fk_maDatDDH FOREIGN KEY (madat) REFERENCES DonDatHang(madat),
CONSTRAINT fk_maHHCTDHDH FOREIGN KEY (mahh) REFERENCES HangHoa(mahh) -- Thay 'fk_maHHCTDH' bằng 'fk_maHHCTDHDH' để tránh trùng tên
)
go

--b,
ALTER TABLE HangHoa
ADD CONSTRAINT uq_tenhh UNIQUE (tenhh);
go

--c,
ALTER TABLE HangHoa
ADD CONSTRAINT chk_slcon CHECK (slcon >= 0);

--d,
ALTER TABLE DonDatHang
ADD CONSTRAINT df_ngaydat DEFAULT GETDATE() FOR ngaydat;
go

-- f, Xóa cột diachi
ALTER TABLE KhachHang
DROP COLUMN diachi;
go

-- Thêm lại cột diachi với ràng buộc mặc định
ALTER TABLE KhachHang
ADD diachi NVARCHAR(50) DEFAULT 'HCM';
go

-- g, Xóa khóa ngoại
ALTER TABLE PhieuGiaoHang
DROP CONSTRAINT fk_madat;
go

-- Tạo lại khóa ngoại
ALTER TABLE PhieuGiaoHang
ADD CONSTRAINT fk_madat FOREIGN KEY (madat) REFERENCES DonDatHang(madat);
go

-- Thêm dữ liệu vào bảng KhachHang
INSERT INTO KhachHang (makh, tenkh, diachi, dienthoai)
VALUES
('KH01', 'Cửa hàng Lộc Phú', 'HCM', 0398451950),
('KH03', 'Nguyễn Lan Anh', 'Cần Thơ', 398451950),
('KH02', 'Cửa hàng Hoàng Gia', 'Long An', 938776266),
('KH05', 'Huỳnh Ngọc Trung', 'HCM', 896317388),
('KH04', 'Cty TNHH An Phước', 'Long An', 916783565),
('KH06', 'Cửa hành Trung Tín' ,'Tây Ninh', 938435706);

-- Thêm dữ liệu vào bảng HangHoa
INSERT INTO HangHoa (mahh, tenhh, dvt, slcon, dongiahh)
VALUES
('BU1', 'Bàn ủi Phillip', 'Cái', 60, 300000),
('BU2', 'Bàn ủi Sharp', 'Cái', 100,350000),
('DM1', 'Đầu máy Sharp', 'Cái', 100, 250000),
('CD1', 'Nồi cơm điện Sharp', 'Cái', 100, 650000),
('MG1', 'Máy giặt Sanyo', 'Cái', 10, 1200000),
('MQ1', 'Máy quạt Senko', 'Cái', 40, 400000),
('MQ2', 'Máy quạt Daikin', 'Cái', 60, 450000),
('TL1', 'Tủ lạnh Hitachi', 'Cái', 50, 5500000),
('TV1', 'Tivi Samsung', 'Cái', 33, 7800000),
('TV2', 'Tivi LG', 'Cái', 20, 7500000),
('TV3', 'Tivi Sony', 'Cái', 60, 8000000);
go
-- Thêm dữ liệu vào bảng LichSuGia
INSERT INTO LichSuGia (mahh, ngayhl, dongia)
VALUES
('BU1', '2022-01-01', 300000),
('BU1', '2023-01-01', 350000),
('BU2', '2023-01-06', 250000),
('CD1', '2022-01-06', 650000),
('CD1', '2023-01-01', 700000),
('DM1', '2022-01-01', 1000000),
('DM1', '2023-01-01', 1200000),
('MQ1', '2023-01-01', 400000),
('MQ2', '2022-01-01', 450000),
('MQ2', '2023-01-01', 600000),
('TL1', '2023-01-01', 5500000),
('TV1', '2023-01-01', 7800000),
('TV2', '2023-01-01', 7500000),
('TV3', '2023-01-01', 8000000);
go
-- Thêm dữ liệu vào bảng DonDatHang
INSERT INTO DonDatHang (madat, ngaydat, makh, tinhtrang)
VALUES
('DH01', '2022-02-02', 'KH01', '1'),
('DH02', '2022-02-12', 'KH03', '1'),
('DH03', '2023-02-23', 'KH03', '1'),
('DH04', '2023-04-01', 'KH02', '0'),
('DH05', '2023-05-09', 'KH05', '1'),
('DH06', '2023-05-16', 'KH03', '1'),
('DH07', '2023-06-19', 'KH05', '0'),
('DH08', '2023-06-26', 'KH01', '0');
go
-- Thêm dữ liệu vào bảng PhieuGiaoHang
INSERT INTO PhieuGiaoHang (magiao, ngaygiao, madat)
VALUES
('GH01', '2022-02-02', 'DH01'),
('GH02', '2022-02-15', 'DH02'),
('GH03', '2023-02-24', 'DH03'),
('GH05', '2023-05-10', 'DH05'),
('GH06', '2023-06-18', 'DH06'),
('GH07', '2023-07-10', 'DH07'),
('GH08', '2023-08-20', 'DH08');
go
-- Thêm dữ liệu vào bảng ChiTietGiaoHang
INSERT INTO ChiTietGiaoHang (magiao, mahh, slgiao, dongiagiao)
VALUES
('GH01', 'BU1', 15, 300000),
('GH01', 'DM1', 10, 1000000),
('GH01', 'TL1', 4, 5000000),
('GH02', 'BU2', 10, 300000),
('GH03', 'MG1', 8, 4700000),
('GH05', 'BU2', 12, 350000),
('GH05', 'DM1', 15, 1200000),
('GH05', 'MG1', 5, 4700000),
('GH05', 'TL1', 5, 5500000),
('GH06', 'BU1', 20, 350000),
('GH06', 'MG1', 30, 4700000),
('GH06', 'MQ1', 10, 400000),
('GH06', 'MQ2', 15, 450000),
('GH07', 'BU1', 20, 300000),
('GH08', 'MQ1', 30, 400000);

-- Thêm dữ liệu vào bảng ChiTietDatHang
INSERT INTO ChiTietDatHang (madat, mahh, sldat)
VALUES
('DH01', 'BU1', 15),
('DH01', 'DM1', 10),
('DH01', 'TL1', 4),
('DH02', 'BU2', 20),
('DH02', 'TL1', 3),
('DH03', 'MG1', 8),
('DH04', 'TL1', 5),
('DH04', 'TV1', 5),
('DH05', 'BU2', 12),
('DH05', 'DM1', 15),
('DH05', 'MG1', 10),
('DH05', 'TL1', 5),
('DH06', 'BU1', 30),
('DH06', 'MG1', 30),
('DH06', 'MQ1', 30),
('DH06', 'MQ2', 30),
('DH07', 'BU1', 20),
('DH08', 'MQ1', 50),
('DH08', 'TL1', 10);