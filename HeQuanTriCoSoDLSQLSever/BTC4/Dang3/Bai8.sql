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


insert into sinhvien values(
9602, N'Nguyễn Văn', 'A', '2000-01-01','Nam', 'HCM', 'KK000')