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
