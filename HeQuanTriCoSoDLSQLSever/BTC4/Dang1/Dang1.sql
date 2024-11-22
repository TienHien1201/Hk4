--Bài 6
alter function fc_CountDiemDuoi8()
returns int as
begin 
declare @Count int
set @Count = (select COUNT(ketqua.masv) from ketqua
where diem < 80)
return @Count
end

print N'Số sinh viên có điểm dưới 8 la' + str(dbo.fc_CountDiemDuoi8())

--Bài 7
create function fc_CountHpDiemDuoi8()
returns int as
begin 
declare @Count int
set @Count = (select COUNT(ketqua.mahp) from ketqua
where diem < 80)
return @Count
end

print N'Số học phần có điểm dưới 8 la' + str(dbo.fc_CountHpDiemDuoi8())

