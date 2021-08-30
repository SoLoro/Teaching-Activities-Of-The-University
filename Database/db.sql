--
-- PostgreSQL database dump
--

-- Dumped from database version 13.3
-- Dumped by pg_dump version 13.3

-- Started on 2021-08-30 23:00:41

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 211 (class 1255 OID 16901)
-- Name: edition_added(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.edition_added() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	insert into logs (log) values (concat(transaction_timestamp(), concat(' Edition added: ', new.edition_id::TEXT)));
		RETURN NEW;
	END;
$$;


ALTER FUNCTION public.edition_added() OWNER TO postgres;

--
-- TOC entry 212 (class 1255 OID 16905)
-- Name: edition_deleted(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.edition_deleted() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	insert into logs (log) values (concat(transaction_timestamp(), concat(' Edition deleted: ', old.edition_id::TEXT)));
		RETURN OLD;
	END;
$$;


ALTER FUNCTION public.edition_deleted() OWNER TO postgres;

--
-- TOC entry 213 (class 1255 OID 16903)
-- Name: edition_pages_changed(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.edition_pages_changed() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	insert into logs (log) values (concat(transaction_timestamp(), concat(' Edition pages changed: ', new.edition_id::TEXT)));
		RETURN NEW;
	END;
$$;


ALTER FUNCTION public.edition_pages_changed() OWNER TO postgres;

--
-- TOC entry 235 (class 1255 OID 16934)
-- Name: function_add_edition(text, text, text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_add_edition(_name text, _type text, _title text, _source text, _pages text, _status text, _contacts text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$DECLARE
return_val BOOLEAN := true;
edition_count INTEGER;
int_pages INT2 := _pages::INT2;
bool_status BOOLEAN := _status::BOOLEAN;
char_contacts VARCHAR(11) := _contacts::VARCHAR(11);
BEGIN
if (_name IS NULL)
THEN
raise EXCEPTION 'Name can not be an empty field!';
return_val := false;
END if;
if (_type IS NULL)
THEN
raise EXCEPTION 'Type can not be an empty field!';
return_val := false;
END if;
if (_title IS NULL)
THEN
raise EXCEPTION 'Title can not be an empty field!';
return_val := false;
END if;
if (_source IS NULL)
THEN
raise EXCEPTION 'Source can not be an empty field!';
return_val := false;
END if;
if (int_pages IS NULL)
THEN
raise EXCEPTION 'Pages can not be an empty field!';
return_val := false;
END if;
if (bool_status IS NULL)
THEN
raise EXCEPTION 'Status can not be an empty field!';
return_val := false;
END if;
if (char_contacts IS NULL)
THEN
raise EXCEPTION 'Contacts can not be an empty field!';
return_val := false;
END if;

BEGIN
SELECT count(*)
INTO edition_count 
FROM editions 
WHERE edition_title = _title;
end;
if (edition_count > 0)
THEN
raise EXCEPTION 'Edition with this name already exists!';
return_val := false;
END if;
if (return_val = TRUE)
THEN
INSERT INTO editions (edition_name , edition_type , edition_title ,edition_source ,edition_pages ,edition_status ,edition_contacts )
VALUES
(_name, _type, _title,_source,int_pages,bool_status,char_contacts);
END if;
RETURN return_val;
END; $$;


ALTER FUNCTION public.function_add_edition(_name text, _type text, _title text, _source text, _pages text, _status text, _contacts text) OWNER TO postgres;

--
-- TOC entry 238 (class 1255 OID 16938)
-- Name: function_add_pulpit(text, text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_add_pulpit(_title text, _telephone text, _head text, _teachername text, _workplandirection text, _editiontitle text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
char_telephone VARCHAR(11) := _telephone::VARCHAR(11);
new_teacher_id INT = -1;
new_workplan_id INT = -1;
new_edition_id INT = -1;
teacher_cursor CURSOR (firstCursor TEXT) FOR SELECT teacher_id FROM teachers 
WHERE 	
 teacher_name = firstCursor;
workplan_cursor CURSOR (secondCursor TEXT) FOR SELECT workplan_id FROM workplans 
WHERE 
 workplan_direction = secondCursor;
edition_cursor CURSOR (thirdCursor TEXT) FOR SELECT edition_id FROM editions 
WHERE 
 edition_title = thirdCursor;
 
BEGIN
OPEN teacher_cursor (firstCursor := _teachername);
FETCH teacher_cursor INTO new_teacher_id;
OPEN workplan_cursor (secondCursor := _workplandirection);
FETCH workplan_cursor INTO new_workplan_id;
OPEN edition_cursor (thirdCursor := _editiontitle);
FETCH edition_cursor INTO new_edition_id;

if (new_teacher_id = -1)
THEN
return_val = false;
end IF;
if (new_workplan_id = -1)
then 
return_val = false;
end if;
if (new_edition_id = -1)
THEN
return_val = FALSE;
end if;
if (return_val = true)
THEN
insert INTO pulpits (pulpit_title , pulpit_telephone , pulpit_head ,
pulpit_teacher_id , pulpit_workplan_id ,pulpit_edition_id ) 
values (_title, char_telephone,
_head, new_teacher_id, new_workplan_id,new_edition_id);
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_add_pulpit(_title text, _telephone text, _head text, _teachername text, _workplandirection text, _editiontitle text) OWNER TO postgres;

--
-- TOC entry 230 (class 1255 OID 16928)
-- Name: function_add_teacher(text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_add_teacher(_name text, _discipline text, _position text, _telephone text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$DECLARE
return_val BOOLEAN := true;
teacher_count INTEGER;
char_telephone VARCHAR(11) := _telephone::varchar(11);
BEGIN
if (_name IS NULL)
THEN
raise EXCEPTION 'Name can not be an empty field!';
return_val := false;
END if;
if (_discipline IS NULL)
THEN
raise EXCEPTION 'Discipline can not be an empty field!';
return_val := false;
END if;
if (_position IS NULL)
THEN
raise EXCEPTION 'Position can not be an empty field!';
return_val := false;
END if;
if (char_telephone IS NULL)
THEN
raise EXCEPTION 'Telephone can not be an empty field!';
return_val := false;
END if;

BEGIN
SELECT count(*)
INTO teacher_count 
FROM teachers 
WHERE teacher_name = _name;
end;
if (teacher_count > 0)
THEN
raise EXCEPTION 'Teacher with this name already exists!';
return_val := false;
END if;
if (return_val = TRUE)
THEN
INSERT INTO teachers (teacher_name, teacher_discipline ,teacher_position ,teacher_telephone ) 
VALUES
(_name, _discipline, _position, char_telephone);
END if;
RETURN return_val;
END; $$;


ALTER FUNCTION public.function_add_teacher(_name text, _discipline text, _position text, _telephone text) OWNER TO postgres;

--
-- TOC entry 232 (class 1255 OID 16931)
-- Name: function_add_workplan(text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_add_workplan(_direction text, _tasks text, _result text, _deadlines text, _main text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$DECLARE
return_val BOOLEAN := true;
workplan_count INTEGER;
date_deadlines DATE := _deadlines::DATE;
BEGIN
if (_direction IS NULL)
THEN
raise EXCEPTION 'Direction can not be an empty field!';
return_val := false;
END if;
if (_tasks IS NULL)
THEN
raise EXCEPTION 'Tasks can not be an empty field!';
return_val := false;
END if;
if (_result IS NULL)
THEN
raise EXCEPTION 'Result can not be an empty field!';
return_val := false;
END if;
if (date_deadlines IS NULL)
THEN
raise EXCEPTION 'Deadlines can not be an empty field!';
return_val := false;
END if;
if (_main IS NULL)
THEN
raise EXCEPTION 'Main can not be an empty field!';
return_val := false;
END if;

BEGIN
SELECT count(*)
INTO workplan_count 
FROM workplans 
WHERE workplan_direction = _direction;
end;
if (workplan_count > 0)
THEN
raise EXCEPTION 'Workplan with this name already exists!';
return_val := false;
END if;
if (return_val = TRUE)
THEN
INSERT INTO workplans (workplan_direction , workplan_tasks , workplan_result ,workplan_deadlines ,workplan_main ) 
VALUES
(_direction , _tasks , _result ,date_deadlines ,_main );
END if;
RETURN return_val;
END; $$;


ALTER FUNCTION public.function_add_workplan(_direction text, _tasks text, _result text, _deadlines text, _main text) OWNER TO postgres;

--
-- TOC entry 236 (class 1255 OID 16935)
-- Name: function_change_edition(text, text, text, text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_change_edition(_prevtitle text, _newname text, _newtype text, _newtitle text, _newsource text, _newpages text, _newstatus text, _newcontacts text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
edition_check INT;
int_newpages INT2 := _newpages::INT2;
bool_newstatus BOOLEAN := _newstatus::BOOLEAN;
char_newcontacts VARCHAR(11) := _newcontacts::VARCHAR(11);
BEGIN
begin
select count(*)
into edition_check 
from editions 
where edition_title = _newtitle;
end;
if (_prevtitle = _newtitle)
THEN
edition_check = edition_check -1 ;
end if;
if (edition_check > 0)
then
raise exception 'Edition with that name already exists!';
return_val = false;
end if;
if (return_val = true)
THEN
update editions 
set edition_name  = _newname,
edition_type  = _newtype,
edition_title  = _newtitle ,
edition_source =_newsource ,
edition_pages = int_newpages,
edition_status = bool_newstatus,
edition_contacts = char_newcontacts
where edition_title = _prevtitle;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_change_edition(_prevtitle text, _newname text, _newtype text, _newtitle text, _newsource text, _newpages text, _newstatus text, _newcontacts text) OWNER TO postgres;

--
-- TOC entry 240 (class 1255 OID 16939)
-- Name: function_change_pulpit(text, text, text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_change_pulpit(_id text, _newtitle text, _newtelephone text, _newhead text, _newteachername text, _newworkplandirection text, _neweditiontitle text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$
declare
return_val BOOLEAN := true;
int_id INT := _id::INT;
char_newtelephone VARCHAR(11):= _newtelephone::VARCHAR(11);
new_teacher_id INT = -1;
new_workplan_id INT = -1;
new_edition_id INT = -1;

teacher_cursor CURSOR (firstCursor TEXT) FOR SELECT teacher_id FROM teachers WHERE
teacher_name = firstCursor FOR UPDATE;

workplan_cursor CURSOR (secondCursor TEXT) FOR SELECT workplan_id FROM workplans WHERE
workplan_direction = secondCursor FOR UPDATE;

edition_cursor CURSOR (thirdCursor TEXT) FOR SELECT edition_id FROM editions WHERE
edition_title = thirdCursor FOR UPDATE;

BEGIN

OPEN teacher_cursor (firstCursor := _newteachername);
FETCH teacher_cursor INTO new_teacher_id;
CLOSE teacher_cursor;

OPEN workplan_cursor (secondCursor := _newworkplandirection);
FETCH workplan_cursor INTO new_workplan_id;
CLOSE workplan_cursor;

OPEN edition_cursor (thirdCursor := _neweditiontitle);
FETCH edition_cursor INTO new_edition_id;
CLOSE edition_cursor;

if (new_teacher_id = -1)
THEN
return_val = false;
end IF;

if (new_workplan_id = -1)
then
return_val = false;
end if;

if (new_edition_id = -1)
THEN
return_val = FALSE;
end if;

if (return_val = true)
THEN
update pulpits
set pulpit_title  = _newtitle,
pulpit_telephone  = char_newtelephone,
pulpit_head  = _newhead,
pulpit_teacher_id = new_teacher_id,
pulpit_workplan_id  = new_workplan_id,
pulpit_edition_id = new_edition_id
where pulpit_id = int_id;
end if;
return return_val;
END;
$$;


ALTER FUNCTION public.function_change_pulpit(_id text, _newtitle text, _newtelephone text, _newhead text, _newteachername text, _newworkplandirection text, _neweditiontitle text) OWNER TO postgres;

--
-- TOC entry 231 (class 1255 OID 16929)
-- Name: function_change_teacher(text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_change_teacher(_prevname text, _newname text, _newdiscipline text, _newposition text, _newtelephone text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
teacher_check INT;
char_newtelephone VARCHAR(11) := _newtelephone::varchar(11);
BEGIN
begin
select count(*)
into teacher_check 
from teachers 
where teacher_name = _newname;
end;
if (_prevname = _newname)
THEN
teacher_check = teacher_check -1 ;
end if;
if (teacher_check > 0)
then
raise exception 'Teacher with that name already exists!';
return_val = false;
end if;
if (return_val = true)
THEN
update teachers 
set teacher_name = _newname,
teacher_discipline  = _newdiscipline,
teacher_position = _newposition ,
teacher_telephone = char_newtelephone
where teacher_name = _prevname;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_change_teacher(_prevname text, _newname text, _newdiscipline text, _newposition text, _newtelephone text) OWNER TO postgres;

--
-- TOC entry 233 (class 1255 OID 16932)
-- Name: function_change_workplan(text, text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_change_workplan(_prevdirection text, _newdirection text, _newtasks text, _newresult text, _newdeadlines text, _newmain text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
workplan_check INT;
char_newdeadlines DATE:= _newdeadlines::DATE;
BEGIN
begin
select count(*)
into workplan_check 
from workplans 
where workplan_direction = _newdirection;
end;
if (_prevdirection = _newdirection)
THEN
workplan_check = workplan_check -1 ;
end if;
if (workplan_check > 0)
then
raise exception 'Workplan with that name already exists!';
return_val = false;
end if;
if (return_val = true)
THEN
update workplans 
set workplan_direction = _newdirection,
workplan_tasks  = _newtasks,
workplan_result  = _newresult ,
workplan_deadlines = char_newdeadlines,
workplan_main = _newmain
where workplan_direction = _prevdirection;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_change_workplan(_prevdirection text, _newdirection text, _newtasks text, _newresult text, _newdeadlines text, _newmain text) OWNER TO postgres;

--
-- TOC entry 237 (class 1255 OID 16936)
-- Name: function_delete_edition(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_delete_edition(_title text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
edition_check INT;
BEGIN
select count(*)
into edition_check 
from editions 
where edition_title = _title;
if (edition_check = 0)
then
raise exception 'No edition with this name!';
return_val = false;
end if;
if (edition_check = 1)
then
DELETE from editions 
where edition_title = _title;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_delete_edition(_title text) OWNER TO postgres;

--
-- TOC entry 239 (class 1255 OID 16941)
-- Name: function_delete_pulpit(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_delete_pulpit(_id integer) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
pulpit_check INT;
BEGIN
select count(*)
into pulpit_check
from pulpits 
where pulpit_id = _id;
if (pulpit_check = 0)
then
raise exception 'No pulpit with this id!';
return_val = false;
end if;
if (pulpit_check = 1)
then
DELETE from pulpits 
where pulpit_id = _id;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_delete_pulpit(_id integer) OWNER TO postgres;

--
-- TOC entry 216 (class 1255 OID 16930)
-- Name: function_delete_teacher(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_delete_teacher(_name text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
teacher_check INT;
BEGIN
select count(*)
into teacher_check 
from teachers 
where teacher_name = _name;
if (teacher_check = 0)
then
raise exception 'No teacher with this name!';
return_val = false;
end if;
if (teacher_check = 1)
then
DELETE from teachers 
where teacher_name = _name;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_delete_teacher(_name text) OWNER TO postgres;

--
-- TOC entry 234 (class 1255 OID 16933)
-- Name: function_delete_workplan(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.function_delete_workplan(_direction text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$declare
return_val BOOLEAN := true;
workplan_check INT;
BEGIN
select count(*)
into workplan_check 
from workplans 
where workplan_direction = _direction;
if (workplan_check = 0)
then
raise exception 'No workplan with this name!';
return_val = false;
end if;
if (workplan_check = 1)
then
DELETE from workplans 
where workplan_direction = _direction;
end if;
return return_val;
END; $$;


ALTER FUNCTION public.function_delete_workplan(_direction text) OWNER TO postgres;

--
-- TOC entry 214 (class 1255 OID 16921)
-- Name: get_workplan_direction(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.get_workplan_direction(_id integer) RETURNS text
    LANGUAGE plpgsql
    AS $$DECLARE
direction TEXT;
BEGIN
SELECT workplan_direction 
INTO direction 
FROM workplans 
where workplan_id = _id;
RETURN direction;
END; $$;


ALTER FUNCTION public.get_workplan_direction(_id integer) OWNER TO postgres;

--
-- TOC entry 229 (class 1255 OID 16920)
-- Name: get_workplan_maybe(text, text, text, date, text); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.get_workplan_maybe(_direction text, _tasks text, _result text, _deadlines date, _main text)
    LANGUAGE plpgsql
    AS $$
BEGIN 
	INSERT INTO workplans(workplan_direction  ,workplan_tasks  ,workplan_result ,workplan_deadlines  ,workplan_main  ) VALUES(_direction , _tasks ,_result , _deadlines ,_main);
IF _deadlines < CURRENT_DATE
THEN
	ROLLBACK;
end IF;
COMMIT;
RETURN;
END$$;


ALTER PROCEDURE public.get_workplan_maybe(_direction text, _tasks text, _result text, _deadlines date, _main text) OWNER TO postgres;

--
-- TOC entry 215 (class 1255 OID 16922)
-- Name: get_workplan_prog(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.get_workplan_prog() RETURNS TABLE(_id integer, _direction text, _tasks text, _result text, _deadlines date, _main text)
    LANGUAGE sql
    AS $$
select workplan_id , workplan_direction , workplan_tasks , workplan_result ,workplan_deadlines , workplan_main from
workplans where workplan_direction = 'Работа отдела экономики';
$$;


ALTER FUNCTION public.get_workplan_prog() OWNER TO postgres;

--
-- TOC entry 228 (class 1255 OID 16966)
-- Name: update_maybe(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.update_maybe() RETURNS trigger
    LANGUAGE plpgsql
    AS $$ declare
value int;
BEGIN   
        begin
                SELECT COUNT(*) INTO value FROM editions
                WHERE pulpit_edition_id = edition_id;
        end;
        if(pulpit_edition_id = edition_id) then
        insert into edition_pulpits Values(edition_id,edition_name,value);
        end if;
END;
$$;


ALTER FUNCTION public.update_maybe() OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 205 (class 1259 OID 16844)
-- Name: editions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.editions (
    edition_id integer NOT NULL,
    edition_name text,
    edition_type text,
    edition_title text,
    edition_source text,
    edition_pages smallint,
    edition_status boolean,
    edition_contacts character varying(11)
);


ALTER TABLE public.editions OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 16855)
-- Name: pulpits; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.pulpits (
    pulpit_id integer NOT NULL,
    pulpit_title text,
    pulpit_telephone character varying(11),
    pulpit_head text,
    pulpit_teacher_id integer,
    pulpit_workplan_id integer,
    pulpit_edition_id integer
);


ALTER TABLE public.pulpits OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 16968)
-- Name: edition_pulpits; Type: VIEW; Schema: public; Owner: postgres
--

CREATE VIEW public.edition_pulpits AS
 SELECT DISTINCT editions.edition_id,
    editions.edition_name,
    ( SELECT count(*) AS count
           FROM public.pulpits pulpits_1
          WHERE (pulpits_1.pulpit_edition_id = editions.edition_id)) AS amount
   FROM public.editions,
    public.pulpits;


ALTER TABLE public.edition_pulpits OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 16842)
-- Name: editions_edition_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.editions_edition_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.editions_edition_id_seq OWNER TO postgres;

--
-- TOC entry 3079 (class 0 OID 0)
-- Dependencies: 204
-- Name: editions_edition_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.editions_edition_id_seq OWNED BY public.editions.edition_id;


--
-- TOC entry 209 (class 1259 OID 16881)
-- Name: logs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.logs (
    log_id integer NOT NULL,
    log text
);


ALTER TABLE public.logs OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 16879)
-- Name: logs_log_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.logs_log_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.logs_log_id_seq OWNER TO postgres;

--
-- TOC entry 3081 (class 0 OID 0)
-- Dependencies: 208
-- Name: logs_log_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.logs_log_id_seq OWNED BY public.logs.log_id;


--
-- TOC entry 206 (class 1259 OID 16853)
-- Name: pulpits_pulpit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.pulpits_pulpit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.pulpits_pulpit_id_seq OWNER TO postgres;

--
-- TOC entry 3082 (class 0 OID 0)
-- Dependencies: 206
-- Name: pulpits_pulpit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.pulpits_pulpit_id_seq OWNED BY public.pulpits.pulpit_id;


--
-- TOC entry 201 (class 1259 OID 16822)
-- Name: teachers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.teachers (
    teacher_id integer NOT NULL,
    teacher_name text,
    teacher_discipline text,
    teacher_position text,
    teacher_telephone character varying(11)
);


ALTER TABLE public.teachers OWNER TO postgres;

--
-- TOC entry 200 (class 1259 OID 16820)
-- Name: teachers_teacher_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.teachers_teacher_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.teachers_teacher_id_seq OWNER TO postgres;

--
-- TOC entry 3084 (class 0 OID 0)
-- Dependencies: 200
-- Name: teachers_teacher_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.teachers_teacher_id_seq OWNED BY public.teachers.teacher_id;


--
-- TOC entry 203 (class 1259 OID 16833)
-- Name: workplans; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.workplans (
    workplan_id integer NOT NULL,
    workplan_direction text,
    workplan_tasks text,
    workplan_result text,
    workplan_deadlines date,
    workplan_main text
);


ALTER TABLE public.workplans OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 16831)
-- Name: workplans_workplan_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.workplans_workplan_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.workplans_workplan_id_seq OWNER TO postgres;

--
-- TOC entry 3086 (class 0 OID 0)
-- Dependencies: 202
-- Name: workplans_workplan_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.workplans_workplan_id_seq OWNED BY public.workplans.workplan_id;


--
-- TOC entry 2904 (class 2604 OID 16847)
-- Name: editions edition_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.editions ALTER COLUMN edition_id SET DEFAULT nextval('public.editions_edition_id_seq'::regclass);


--
-- TOC entry 2906 (class 2604 OID 16884)
-- Name: logs log_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.logs ALTER COLUMN log_id SET DEFAULT nextval('public.logs_log_id_seq'::regclass);


--
-- TOC entry 2905 (class 2604 OID 16858)
-- Name: pulpits pulpit_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pulpits ALTER COLUMN pulpit_id SET DEFAULT nextval('public.pulpits_pulpit_id_seq'::regclass);


--
-- TOC entry 2902 (class 2604 OID 16825)
-- Name: teachers teacher_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers ALTER COLUMN teacher_id SET DEFAULT nextval('public.teachers_teacher_id_seq'::regclass);


--
-- TOC entry 2903 (class 2604 OID 16836)
-- Name: workplans workplan_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.workplans ALTER COLUMN workplan_id SET DEFAULT nextval('public.workplans_workplan_id_seq'::regclass);


--
-- TOC entry 3067 (class 0 OID 16844)
-- Dependencies: 205
-- Data for Name: editions; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (1, 'Смирнов Владислав Георгиевич', 'Статья', 'Основы программирования на Python', 'Артстиль', 34, false, '89801452784');
INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (2, 'Павлов Кирилл Геннадьевич', 'Книга', 'Задачник по дифференциальным уравнениям', 'Спутник +', 312, true, '89205523475');
INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (3, 'Соколова Елена Александрова', 'Реферат', 'Исследование фондового рынка', 'Press-Book', 104, true, '89306759082');
INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (4, 'Медведев Дмитрий Олегович', 'Учебник', 'Курс Английского языка для ВУЗов', 'Эксмо', 286, false, '89556348702');
INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (5, 'Жуков Даниил Семёнович', 'Доклад', 'Спорт-это жизнь!', 'Полиграф сервис', 55, true, '89158864903');
INSERT INTO public.editions (edition_id, edition_name, edition_type, edition_title, edition_source, edition_pages, edition_status, edition_contacts) VALUES (15, 'Синицын', 'Книга', 'Уникальная книга', 'Press-Book', 200, true, '89074582594');


--
-- TOC entry 3071 (class 0 OID 16881)
-- Dependencies: 209
-- Data for Name: logs; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.logs (log_id, log) VALUES (1, '2021-06-06 19:56:34.936972+03Edition added: 6');
INSERT INTO public.logs (log_id, log) VALUES (2, '2021-06-06 20:00:01.213352+03 Edition pages changed: 6');
INSERT INTO public.logs (log_id, log) VALUES (3, '2021-06-06 20:01:10.691197+03 Edition deleted: 6');
INSERT INTO public.logs (log_id, log) VALUES (4, '2021-06-06 20:48:34.901525+03 Edition added: 7');
INSERT INTO public.logs (log_id, log) VALUES (5, '2021-06-06 20:53:20.640734+03 Edition added: 8');
INSERT INTO public.logs (log_id, log) VALUES (6, '2021-06-06 20:57:17.186505+03 Edition pages changed: 8');
INSERT INTO public.logs (log_id, log) VALUES (7, '2021-06-06 20:58:56.54886+03 Edition deleted: 8');
INSERT INTO public.logs (log_id, log) VALUES (8, '2021-06-06 20:59:16.286241+03 Edition deleted: 7');
INSERT INTO public.logs (log_id, log) VALUES (9, '2021-06-07 11:24:07.359967+03 Edition added: 9');
INSERT INTO public.logs (log_id, log) VALUES (10, '2021-06-07 13:57:53.505721+03 Edition added: 10');
INSERT INTO public.logs (log_id, log) VALUES (11, '2021-06-07 14:04:05.577909+03 Edition pages changed: 10');
INSERT INTO public.logs (log_id, log) VALUES (12, '2021-06-07 14:05:43.309668+03 Edition pages changed: 10');
INSERT INTO public.logs (log_id, log) VALUES (13, '2021-06-07 14:08:56.560867+03 Edition deleted: 10');
INSERT INTO public.logs (log_id, log) VALUES (14, '2021-06-07 14:16:38.925799+03 Edition added: 11');
INSERT INTO public.logs (log_id, log) VALUES (15, '2021-06-07 14:17:22.694331+03 Edition deleted: 11');
INSERT INTO public.logs (log_id, log) VALUES (16, '2021-06-07 14:44:44.112987+03 Edition deleted: 9');
INSERT INTO public.logs (log_id, log) VALUES (17, '2021-06-07 16:20:56.969436+03 Edition added: 12');
INSERT INTO public.logs (log_id, log) VALUES (18, '2021-06-07 16:25:08.043953+03 Edition pages changed: 12');
INSERT INTO public.logs (log_id, log) VALUES (19, '2021-06-07 16:27:13.793158+03 Edition deleted: 12');
INSERT INTO public.logs (log_id, log) VALUES (20, '2021-06-07 21:44:10.698172+03 Edition added: 13');
INSERT INTO public.logs (log_id, log) VALUES (21, '2021-06-07 21:46:53.524933+03 Edition pages changed: 13');
INSERT INTO public.logs (log_id, log) VALUES (22, '2021-06-07 21:48:19.490729+03 Edition deleted: 13');
INSERT INTO public.logs (log_id, log) VALUES (23, '2021-06-08 19:48:39.517993+03 Edition added: 14');
INSERT INTO public.logs (log_id, log) VALUES (24, '2021-06-08 19:55:34.249378+03 Edition deleted: 14');
INSERT INTO public.logs (log_id, log) VALUES (25, '2021-06-08 19:58:38.183235+03 Edition added: 15');
INSERT INTO public.logs (log_id, log) VALUES (26, '2021-06-08 22:16:38.072633+03 Edition added: 16');
INSERT INTO public.logs (log_id, log) VALUES (27, '2021-06-08 22:18:12.690646+03 Edition pages changed: 16');
INSERT INTO public.logs (log_id, log) VALUES (28, '2021-06-08 22:19:11.776088+03 Edition deleted: 16');


--
-- TOC entry 3069 (class 0 OID 16855)
-- Dependencies: 207
-- Data for Name: pulpits; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (2, 'Кафедра высшей математики', '3002', 'Никонов Валерий Альбертович', 2, 2, 2);
INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (3, 'Кафедра экономики', '4003', 'Попов Александр Валерьевич', 3, 3, 3);
INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (4, 'Кафедра иностранных языков', '5004', 'Кирсанова Татьяна Петровна', 4, 4, 4);
INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (5, 'Кафедра физической культуры', '6005', 'Сухоруков Павел Викторович', 5, 5, 5);
INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (12, 'Кафедра программирования', '2001', 'Черноухов Виктор Павлович', 12, 1, 1);
INSERT INTO public.pulpits (pulpit_id, pulpit_title, pulpit_telephone, pulpit_head, pulpit_teacher_id, pulpit_workplan_id, pulpit_edition_id) VALUES (16, 'Кафедра С', '5099', 'Глушаков Дмитрий Валерьевич', 19, 14, 15);


--
-- TOC entry 3063 (class 0 OID 16822)
-- Dependencies: 201
-- Data for Name: teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (2, 'Павлов Кирилл Геннадьевич', 'Дифференциальные уравнения', 'Аспирант', '89101467390');
INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (3, 'Соколова Елена Александровна', 'Экономика', 'Ведущий научный сотрудник', '89503785684');
INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (4, 'Медведев Дмитрий Олегович', 'Иностранный язык', 'Докторант', '89602866439');
INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (5, 'Жуков Даниил Семёнович', 'Физическая культура', 'Ассистент', '89707845627');
INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (12, 'Смирнов Владислав Георгиевич', 'Технологии и методы программирования', 'Доцент', '89154467308');
INSERT INTO public.teachers (teacher_id, teacher_name, teacher_discipline, teacher_position, teacher_telephone) VALUES (19, 'Синицын', 'QT', 'Аспирант', '89076892304');


--
-- TOC entry 3065 (class 0 OID 16833)
-- Dependencies: 203
-- Data for Name: workplans; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (1, 'Работа отдела программирования', 'Обучение студентов знаниям языка Python', 'Успешная сдача сессии студентами', '2021-06-18', 'Смирнов Владислав Георгиевич');
INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (2, 'Работа отдела высшей математики', 'Разбработка тестов для оценки знаний студентов', 'Наличие готовых тестов', '2021-06-09', 'Павлов Кирилл Геннадьевич');
INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (3, 'Работа отдела экономики', 'Анализ последних тенденций курса биржи', 'Отчёт анализа', '2021-07-14', 'Соколова Елена Александровна');
INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (4, 'Работа отдела иностранного языка', 'Прохождение доп. курсов для повышения квалификации', 'Повышение квалификации', '2021-06-25', 'Медведев Дмитрий Олегович');
INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (5, 'Работа отдела физической культуры', 'Подготовка сборной вуза по воллейболу к совернованиям', 'Успешное выступление на турнире', '2021-06-29', 'Жуков Даниил Семёнович');
INSERT INTO public.workplans (workplan_id, workplan_direction, workplan_tasks, workplan_result, workplan_deadlines, workplan_main) VALUES (14, 'Работа отдела QT', 'обучение', 'Сессия', '2021-06-22', 'Синицын');


--
-- TOC entry 3087 (class 0 OID 0)
-- Dependencies: 204
-- Name: editions_edition_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.editions_edition_id_seq', 16, true);


--
-- TOC entry 3088 (class 0 OID 0)
-- Dependencies: 208
-- Name: logs_log_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.logs_log_id_seq', 28, true);


--
-- TOC entry 3089 (class 0 OID 0)
-- Dependencies: 206
-- Name: pulpits_pulpit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.pulpits_pulpit_id_seq', 17, true);


--
-- TOC entry 3090 (class 0 OID 0)
-- Dependencies: 200
-- Name: teachers_teacher_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.teachers_teacher_id_seq', 20, true);


--
-- TOC entry 3091 (class 0 OID 0)
-- Dependencies: 202
-- Name: workplans_workplan_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.workplans_workplan_id_seq', 15, true);


--
-- TOC entry 2912 (class 2606 OID 16852)
-- Name: editions editions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.editions
    ADD CONSTRAINT editions_pkey PRIMARY KEY (edition_id);


--
-- TOC entry 2923 (class 2606 OID 16889)
-- Name: logs logs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.logs
    ADD CONSTRAINT logs_pkey PRIMARY KEY (log_id);


--
-- TOC entry 2921 (class 2606 OID 16863)
-- Name: pulpits pulpits_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pulpits
    ADD CONSTRAINT pulpits_pkey PRIMARY KEY (pulpit_id);


--
-- TOC entry 2908 (class 2606 OID 16830)
-- Name: teachers teachers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.teachers
    ADD CONSTRAINT teachers_pkey PRIMARY KEY (teacher_id);


--
-- TOC entry 2910 (class 2606 OID 16841)
-- Name: workplans workplans_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.workplans
    ADD CONSTRAINT workplans_pkey PRIMARY KEY (workplan_id);


--
-- TOC entry 2913 (class 1259 OID 16900)
-- Name: on_edition_contacts; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_contacts ON public.editions USING btree (edition_contacts);


--
-- TOC entry 2914 (class 1259 OID 16894)
-- Name: on_edition_name; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_name ON public.editions USING btree (edition_name);


--
-- TOC entry 2915 (class 1259 OID 16898)
-- Name: on_edition_pages; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_pages ON public.editions USING btree (edition_pages);


--
-- TOC entry 2916 (class 1259 OID 16897)
-- Name: on_edition_source; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_source ON public.editions USING btree (edition_source);


--
-- TOC entry 2917 (class 1259 OID 16899)
-- Name: on_edition_status; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_status ON public.editions USING btree (edition_status);


--
-- TOC entry 2918 (class 1259 OID 16896)
-- Name: on_edition_title; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_title ON public.editions USING btree (edition_title);


--
-- TOC entry 2919 (class 1259 OID 16895)
-- Name: on_edition_type; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX on_edition_type ON public.editions USING btree (edition_type);


--
-- TOC entry 2927 (class 2620 OID 16902)
-- Name: editions tr_edition_added; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER tr_edition_added AFTER INSERT ON public.editions FOR EACH ROW EXECUTE FUNCTION public.edition_added();


--
-- TOC entry 2928 (class 2620 OID 16906)
-- Name: editions tr_edition_deleted; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER tr_edition_deleted BEFORE DELETE ON public.editions FOR EACH ROW EXECUTE FUNCTION public.edition_deleted();


--
-- TOC entry 2929 (class 2620 OID 16904)
-- Name: editions tr_edition_pages_changed; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER tr_edition_pages_changed AFTER UPDATE OF edition_pages ON public.editions FOR EACH ROW EXECUTE FUNCTION public.edition_pages_changed();


--
-- TOC entry 2930 (class 2620 OID 16972)
-- Name: edition_pulpits trigger_update_maybe; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER trigger_update_maybe INSTEAD OF UPDATE ON public.edition_pulpits FOR EACH ROW EXECUTE FUNCTION public.update_maybe();


--
-- TOC entry 2926 (class 2606 OID 16874)
-- Name: pulpits pulpits_pulpit_edition_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pulpits
    ADD CONSTRAINT pulpits_pulpit_edition_id_fkey FOREIGN KEY (pulpit_edition_id) REFERENCES public.editions(edition_id) ON DELETE CASCADE;


--
-- TOC entry 2924 (class 2606 OID 16864)
-- Name: pulpits pulpits_pulpit_teacher_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pulpits
    ADD CONSTRAINT pulpits_pulpit_teacher_id_fkey FOREIGN KEY (pulpit_teacher_id) REFERENCES public.teachers(teacher_id) ON DELETE CASCADE;


--
-- TOC entry 2925 (class 2606 OID 16869)
-- Name: pulpits pulpits_pulpit_workplan_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pulpits
    ADD CONSTRAINT pulpits_pulpit_workplan_id_fkey FOREIGN KEY (pulpit_workplan_id) REFERENCES public.workplans(workplan_id) ON DELETE CASCADE;


--
-- TOC entry 3077 (class 0 OID 0)
-- Dependencies: 205
-- Name: TABLE editions; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public.editions TO myvariant_main;
GRANT SELECT,INSERT,UPDATE ON TABLE public.editions TO myvariant_more;
GRANT SELECT ON TABLE public.editions TO myvariant_less;


--
-- TOC entry 3078 (class 0 OID 0)
-- Dependencies: 207
-- Name: TABLE pulpits; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public.pulpits TO myvariant_main;
GRANT SELECT,INSERT,UPDATE ON TABLE public.pulpits TO myvariant_more;
GRANT SELECT ON TABLE public.pulpits TO myvariant_less;


--
-- TOC entry 3080 (class 0 OID 0)
-- Dependencies: 209
-- Name: TABLE logs; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public.logs TO myvariant_main;
GRANT SELECT,INSERT,UPDATE ON TABLE public.logs TO myvariant_more;
GRANT SELECT ON TABLE public.logs TO myvariant_less;


--
-- TOC entry 3083 (class 0 OID 0)
-- Dependencies: 201
-- Name: TABLE teachers; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public.teachers TO myvariant_main;
GRANT SELECT,INSERT,UPDATE ON TABLE public.teachers TO myvariant_more;
GRANT SELECT ON TABLE public.teachers TO myvariant_less;


--
-- TOC entry 3085 (class 0 OID 0)
-- Dependencies: 203
-- Name: TABLE workplans; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public.workplans TO myvariant_main;
GRANT SELECT,INSERT,UPDATE ON TABLE public.workplans TO myvariant_more;
GRANT SELECT ON TABLE public.workplans TO myvariant_less;


-- Completed on 2021-08-30 23:00:41

--
-- PostgreSQL database dump complete
--

