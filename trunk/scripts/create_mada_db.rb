#!ruby

require 'sqlite3'

dbpath = ARGV.empty? ? "mada.db3" : ARGV[0]
db = SQLite3::Database.new(dbpath)

create_table_statements = <<SQL

	create table if not exists global_parameters
	(
		key text primary key,
		value text
	);
	
SQL

db.execute_batch(create_table_statements)
