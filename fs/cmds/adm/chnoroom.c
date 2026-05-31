inherit F_CLEAN_UP;


void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
	foreach(object ob in objects())
	{
		if(!environment(ob) && clonep(ob))
		{
			string file = base_name(ob);
			if(file == "/obj/user" || file == "/obj/login")
				continue;
			printf("%O \n ",ob);
			destruct(ob);
		}
	}
return 1;
}
int help()
{
        write(@TEXT

指令格式﹕chnoroom 

檢查有沒有沒有房間的物件
TEXT
        );
        return 1;
}
