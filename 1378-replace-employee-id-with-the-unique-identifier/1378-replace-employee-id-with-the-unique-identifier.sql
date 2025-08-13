select unique_id,name from Employees as E 
LEFT JOIN
EmployeeUNI as U on E.id=U.id