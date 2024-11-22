
--Bài 1: Tách họ
create function fc_tachho (@hoten nvarchar(100))
returns NVARCHAR(50)
as
begin
    declare @ho nvarchar(50)
    set @ho = LEFT(@hoten, CHARINDEX(' ', @hoten) - 1)
    return @ho
end

print dbo.fc_tachho(N'Nguyễn Văn A')

--Bài 2 Tách họ đệm
create function fc_tachhodem (@hoten nvarchar(100))
returns nvarchar(50)
as
begin
    declare @hodem nvarchar(50)
    set @hodem = SUBSTRING(@hoten, CHARINDEX(' ', @hoten) + 1, CHARINDEX(' ', @hoten, CHARINDEX(' ', @hoten) + 1) - CHARINDEX(' ', @hoten) - 1)
    return @hodem
end

print dbo.fc_tachhodem(N'Nguyễn Văn A')

--Bài 3 tách tên 
create function fc_tachten(@hoten nvarchar(100))
returns nvarchar(50)
as
begin
    declare @ten nvarchar(50)
    set @ten = REVERSE(LEFT(REVERSE(@hoten), CHARINDEX(' ', REVERSE(@hoten) + ' ') - 1))
    return @ten
end

print dbo.fc_tachten(N'Nguyễn Văn A')



--Bài 4: Đọc số có 3 chữ số tương ứng
create function fc_doc3so (@so int)
returns nvarchar(100)
as
begin
    declare @chu nvarchar(100)

    if @so < 20
        set @chu = case 
                        when @so = 0 then N'Không'
                        when @so = 1 then N'Một'
                        when @so = 2 then N'Hai'
                        when @so = 3 then N'Ba'
                        when @so = 4 then N'Bốn'
                        when @so = 5 then N'Năm'
                        when @so = 6 then N'Sáu'
                        when @so = 7 then N'Bảy'
                        when @so = 8 then N'Tám'
                        when @so = 9 then N'Chín'
                        when @so = 10 then N'Mười'
                        when @so = 11 then N'Mười một'
                        when @so = 12 then N'Mười hai'
                        when @so = 13 then N'Mười ba'
                        when @so = 14 then N'Mười bốn'
                        when @so = 15 then N'Mười lăm'
                        when @so = 16 then N'Mười sáu'
                        when @so = 17 then N'Mười bảy'
                        when @so = 18 then N'Mười tám'
                        when @so = 19 then N'Mười chín'
                    end
    else 
        set @chu = case
                        when @so / 100 > 0 then (select dbo.fc_doc3so(@so / 100)) + ' trăm ' + (select dbo.fc_doc3so(@so % 100))
                        when @so / 10 > 0 then (select dbo.fc_doc3so(@so / 10)) + ' mươi ' + (select dbo.fc_doc3so(@so % 10))
                    end
    return @chu
end

print dbo.fc_doc3so(123)


--Bài 5
create function fc_doc10so(@a int)
returns nvarchar(10)
as
begin
    declare @chu_so nvarchar(10)

    if @a = 1
        set @chu_so = N'Một'
    if @a = 2
	    set @chu_so = N'Hai'
    if @a = 3
        set @chu_so = N'Ba'
    if @a = 4
	    set @chu_so = N'Bốn'
    if @a = 5
        set @chu_so = N'Năm'
    if @a = 6
	    set @chu_so = N'Sáu'
    if @a = 7
        set @chu_so = N'Bảy'
    if @a = 8
	    set @chu_so = N'Tám'
    if @a = 9
        set @chu_so = N'Chín'
    if @a = 10
	    set @chu_so = N'Mười'

    return @chu_so
end

print dbo.fc_doc10so(2)

--Bài 6
create function  fc_doanhthunam (@nam int )
returns int 
as 
begin
 declare @danhthu  int
 select @danhthu = sum(soluong *gia)
 from cthd, mathang, hoadon
 where cthd.mamh = mathang.mamh and hoadon.mahd = cthd.mahd 
 and YEAR(ngaylap) = @nam 
 end

 --bài 7
 create function  fc_doanhthuthang(@thang int)
 returns int 
 as 
 begin 
 declare @doanhthu int
 select @doanhthu = sum(soluong * gia)
 from ctdh, mathang, hoadon
 where cthd.mamh = mathang.mamh and hoadon.mahd = cthd.mahd 
 and MONTH(ngaylap) = @thang 
 end

--Bài 8
create function fc_doanhthuKH(@makh varchar(5))
returns varchar(5)
as
begin
declare @doanhthu int
select @doanhthu = sum(soluong * gia)
from hoadon, ctdh, mathang
where cthd.mamh = mathang.mamh and hoadon.mahd = cthd.mahd 
and hoadon.makh @makh
return @doanhthu
end

--Bài 9 
create function  fc_soluongban(@mamh varchar(10), @thang int = NULL)
returns int
as 
begin
declare @soluongban int
if @thang IS NULL
begin
    select @soluongban = SUM(soluong)
	from ctdh
	where mamh = @mamh and month(ngaylap) = @thang
return @soluongban
end 
  else 
  begin
   select @soluongban = sum(soluong)
   from ctdh
	where mamh = @mamh 
	end

	return ISNULL(@soluongban, 0)
  end

  --Bài 10
  create function fc_solanmuahang (@makhachhang char(4))
  returns int 
  as 
  begin
   declare @lanmua int
   select @lanmua = count(soluong)
   from cthd, hoadon
   where cthd.makh = hoadon.makh
    return @lanmua 
   end 
      
