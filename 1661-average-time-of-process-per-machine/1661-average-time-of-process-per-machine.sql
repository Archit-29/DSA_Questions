-- 1. We want to see machine IDs and their average processing times
SELECT 
    s.machine_id,
    ROUND(AVG(e.timestamp - s.timestamp), 3) AS processing_time

-- 2. Look at the Activity table (we'll call it 's' for start times)
FROM Activity s

-- 3. Connect it to the same Activity table (now called 'e' for end times)
JOIN Activity e
    -- Match records for the SAME machine AND SAME process
    ON s.machine_id = e.machine_id 
    AND s.process_id = e.process_id

-- 4. Only look at:
--    - 's' records that are starts
--    - 'e' records that are ends
WHERE 
    s.activity_type = 'start'
    AND e.activity_type = 'end'

-- 5. Group the results by machine
GROUP BY s.machine_id
