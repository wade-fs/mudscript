int writelog(object ob,string arg);	// ob : 誰寫   arg : 紀錄標誌
int deletelog(object ob,string arg);	// ob : 誰刪除   arg : 紀錄標誌

int writelog(object ob,string arg)
{
object obj;

	ob = this_object();

	ob->set("localway",base_name( environment(ob) ) );
	ob->move("/u/f/firedancer/log_file/logroom");

	obj = present("log man",environment(ob) );

	if ( !obj->query(arg) )
	{
		obj->set(arg,1);
		ob->move( ob->query("localway") );
		return 1;
	}
	else
	{
		ob->move( ob->query("localway") );
		return 0;
	}
return 1;
}

int deletelog(object ob,string arg)
{
object obj;

	ob = this_object();

	ob->set("localway",base_name( environment(ob) ) );
	ob->move("/u/f/firedancer/log_file/logroom");

	obj = present("log man",environment(ob) );

	obj->delete(arg);
	ob->move( ob->query("localway") );
return 1;
}
