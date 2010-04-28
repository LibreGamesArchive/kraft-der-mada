drop table if exists _categories;
create table _categories
(
   _category_name text primary key,
   _template_table_name text,
   _instance_table_name text
);

insert into _categories
      (_category_name, _template_table_name,    _instance_table_name)
values('environment',  null,                    '_instance_environment');

insert into _categories
      (_category_name, _template_table_name,    _instance_table_name)
values('person',       '_template_person', '_instance_person');

insert into _categories
      (_category_name, _template_table_name,    _instance_table_name)
values('scene_item',       '_template_scene_item', '_instance_scene_item');

drop table if exists _categories_components;
create table _categories_components
(
   _category_name text,
   _component_name text,
   primary key (_category_name, _component_name)
);

insert into _categories_components
      (_category_name, _component_name)
values('environment', 'MeshGraphicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('environment', 'PhysicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('environment', 'SoundComponent');

insert into _categories_components
      (_category_name, _component_name)
values('person', 'MeshGraphicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('person', 'PhysicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('person', 'SoundComponent');

insert into _categories_components
      (_category_name, _component_name)
values('scene_item', 'MeshGraphicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('scene_item', 'PhysicsComponent');

insert into _categories_components
      (_category_name, _component_name)
values('scene_item', 'SoundComponent');

drop table if exists _instance_environment;
create table _instance_environment
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _collision_shape text,
   _collision_box_min text,
   _collision_box_max text,
   _collision_circle_radius float,
   _sound_file text,
   _sound_volume int
);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _sound_file, -_sound_volume)
values('testlevel_chunk1', 'testlevel', 'base', '0 -0.5 0', 'testlevel_chunk1.mesh', 'BoxShape', '-5 -0.5 0', '5 0.5 0', null, 'test.wav', 100);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _sound_file, -_sound_volume)
values('testlevel_chunk2', 'testlevel', 'base', '-6 0.5 0', 'testlevel_chunk2.mesh', 'BoxShape', '-2 -0,5 0', '2 0.5 0', null, null, null);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _sound_file, -_sound_volume)
values('testlevel_chunk3', 'testlevel', 'base', '-7.5 4 0', 'testlevel_chunk3.mesh', 'BoxShape', '-0.5 -3 0', '0.5 3 0', null, null, null);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _sound_file, -_sound_volume)
values('testlevel_chunk4', 'testlevel', 'base', '4.5 3.5 0', 'testlevel_chunk4.mesh', 'BoxShape', '-0.5 3.0 0', '0.5 3.5 0', null, null, null);

insert into _instance_environment
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _sound_file, -_sound_volume)
values('testlevel', 'testlevel_pnyx', 'bg2', '0.0 0.0 0.0', 'testlevel.mesh', null, null, null, null, null, null);

drop table if exists _template_person;
create table _template_person
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _collision_shape text,
   _collision_box_min text,
   _collision_box_max text,
   _collision_circle_radius float
   _sound_file text,
   _sound_volume int
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
   _collision_shape text,
   _collision_box_min text,
   _collision_box_max text,
   _collision_circle_radius float
   _sound_file text,
   _sound_volume int
);

drop table if exists _template_scene_item;
create table _template_scene_item
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _collision_shape text,
   _collision_box_min text,
   _collision_box_max text,
   _collision_circle_radius float,
   _physics_mass float
   _sound_file text,
   _sound_volume int
);

drop table if exists _instance_scene_item;
create table _instance_scene_item
(
   _id text primary key,
   _level text not null,
   _layer text,
   _position text,
   _orientation text,
   _graphics_object text,
   _collision_shape text,
   _collision_box_min text,
   _collision_box_max text,
   _collision_circle_radius float,
   _physics_mass float
   _sound_file text,
   _sound_volume int
);

-- _collision_box_min and _collision_box_max are null. This means it is determined at runtime from mesh.
insert into _instance_scene_item
      (_id,                 _level,      _layer, _position, _graphics_object, _collision_shape, _collision_box_min, _collision_box_max, _collision_circle_radius, _physics_mass, _sound_file, _sound_volume)
values('testlevel_kiste', 'testlevel', 'base', '0 2 0', 'ver_kiste_01.mesh', 'BoxShape', null, null, null, 20.0, null, null);
