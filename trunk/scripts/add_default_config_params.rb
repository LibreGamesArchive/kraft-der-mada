#!ruby

require 'sqlite3'

dbpath = ARGV.empty? ? "mada.db3" : ARGV[0]
db = SQLite3::Database.new(dbpath)

sql = <<SQL
	delete from global_parameters;
	
	insert into global_parameters (key, value)
		values('music_main_menu', 'sound/music_mainmenu.ogg');
SQL

db.execute_batch(sql)
