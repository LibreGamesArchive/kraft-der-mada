drop table if exists _static_level_environment;

create table _static_level_environment
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _physics_object text
);

insert into _static_level_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk1', 'testlevel', 'base', '0/-0.5/0', 'testlevel_chunk1.mesh', 'testlevel_chunk1.mesh');

insert into _static_level_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk2', 'testlevel', 'base', '-6/0.5/0', 'testlevel_chunk2.mesh', 'testlevel_chunk2.mesh');

insert into _static_level_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk3', 'testlevel', 'base', '-7.5/4/0', 'testlevel_chunk3.mesh', 'testlevel_chunk3.mesh');

insert into _static_level_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _physics_object)
values('testlevel_chunk4', 'testlevel', 'base', '4.5/3.5/0', 'testlevel_chunk4.mesh', 'testlevel_chunk4.mesh');
