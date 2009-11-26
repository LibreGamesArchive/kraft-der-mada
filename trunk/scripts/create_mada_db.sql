drop table if exists _categories;
create table _categories
(
   _name text primary key,
   _template_table_name text,
   _instance_table_name text
);

insert into _categories
      (_name,         _template_table_name,    _instance_table_name)
values('environment', null,                    '_instance_environment');

insert into _categories
      (_name,         _template_table_name,    _instance_table_name)
values('person',      '_template_person', '_instance_person');


drop table if exists _instance_environment;
create table _instance_environment
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _physics_object text
);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk1', 'testlevel', 'base', '0/-0.5/0', 'testlevel_chunk1.mesh', 'testlevel_chunk1.mesh');

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk2', 'testlevel', 'base', '-6/0.5/0', 'testlevel_chunk2.mesh', 'testlevel_chunk2.mesh');

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk3', 'testlevel', 'base', '-7.5/4/0', 'testlevel_chunk3.mesh', 'testlevel_chunk3.mesh');

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk4', 'testlevel', 'base', '4.5/3.5/0', 'testlevel_chunk4.mesh', 'testlevel_chunk4.mesh');


drop table if exists _template_person;
create table _template_person
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _physics_object text
);


drop table if exists _instance_person;
create table _instance_person
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _physics_object text
);
