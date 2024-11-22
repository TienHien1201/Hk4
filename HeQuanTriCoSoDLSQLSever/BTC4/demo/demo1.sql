--vd1
create proc sp_ShowSv
as
select * from sinhvien;
sp_ShowSv;

--vd2
create proc sp_SearchSv(@masv int)
as
 select * from sinhvien
where @masv = masv
 sp_SearchSv 2402

 --vd3
 alter proc sp_SearchSv(@masv int)
as
 select masv from sinhvien
where @masv = masv
 if not exists (select masv from sinhvien where @masv = masv)
 print 'Khong ton tai Sinh vien trong danh sach'
else
 select masv from sinhvien where @masv = masv
 sp_SearchSv @masv = 240223


 --Vd4
 alter proc sp_CheckSv(@masv1 int, @masv2 int)
 as
 declare @mlsv1 char(10);
 declare @mlsv2 char(10);
 --Cách 1
 select @mlsv1 = malop from sinhvien where @masv1 = masv
 select @mlsv2 = malop from sinhvien where @masv2 = masv
 /*Cách 2
 set @mlsv1 = (select  malop from sinhvien where @masv1 = masv)
 set @mlsv2 = (select  malop from sinhvien where @masv2 = masv)*/

 select @mlsv1 = malop from sinhvien
 where masv = @masv1
 set @mlsv2 = (select malop from sinhvien
 where masv = @masv2)
 if(@mlsv1 = @mlsv2)
   print 'Hai sinh vien hoc cung lop'
else
   print 'Hai sinh vien khong hoc cung lop'

exec sp_CheckSv @masv1 = 2402, @masv2 = 2403

--Vd4: 
alter proc sp_Sum(@int1 int, @int2 int)
as 
declare @Tong int = 0
set @Tong = @int1 + @int2;
 print 'Tong = ' +  str(@Tong)

 exec sp_Sum @int1 = 5, @int2 = 5

 --######################## Hàm #########################
 create function fc_Tong(@a int, @b int)
 returns int
 as
 begin
 return @a + @b
 end

 print 'Sum' + str(dbo.fc_Tong(100,1))

 --Vd1: Xuất kết quả học tập của sinh viên
 create function fc_SearchKqSv(@mssv int)
 returns table as
 return( select * from ketqua 
 where @mssv = masv)

 select * from dbo.fc_SearchKqSv(2401)

 --vd2: Viết hàm trả về điểm trung bình của 1 sinh viên theo mã sinh viên
 alter function fc_Avge(@masv int)
 returns float as
 begin
 declare @Dtb float
 set @Dtb = (select AVG(diem) from ketqua where @masv = masv)
 return @Dtb
 end

 print N'Điểm trung bình' + str(dbo.fc_Avge(2401))

 --Vd3: Viết hàm tìm các sinh viên có điểm trung bình môn > 8
 create function fc_SearchKQTren8()
 returns table
 as
return (
select masv, dbo.fc_Avge(masv) as dtb from sinhvien
where dbo.fc_Avge(masv) > 80
)
   select * from dbo.fc_SearchKQTren8()


