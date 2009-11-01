create table if not exists _static_level_environment
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position blob,
   _orientation blob,
   _graphics_object text,
   _physics_object text
)

insert into _static_level_environment
      (_id,                 _level,      _layer, _graphics_object)
values('testlevel_chunk_1', 'testlevel', 'base', 'testlevel_chunk_1.mesh');