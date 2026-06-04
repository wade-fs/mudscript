#include <ansi.h>

int set_spell(string key,int lv)
{
	this_player()->set("spells/"+key+"/level",lv);
	return 1;
}
int query_spell(string key)
{
	return this_player()->query("spells/"+key+"/level");
}
int spell_improved(string key,int point)
{
        string id,file;
	this_player()->add("spells/"+key+"/learned",point);
	if(this_player()->query("spells/"+key+"/learned")>=this_player()->query("spells/"+key+"/level")*this_player()->query("spells/"+key+"/level")*10)
	{
		this_player()->add("spells/"+key+"/level",1);
		this_player()->set("spells/"+key+"/learned",0);
		tell_object(this_player(),HIY);
tell_object(this_player(),"你的"+to_chinese(key)+"法術更上一層。
\n" + NOR);
                id = geteuid(this_player());
                file = sprintf("spell/%s/%s", id[0..0], id);
                if(userp(this_player()))
                  log_file(""+file,sprintf("%s 的%s升到 (%d級) 於 %s\n",id,to_chinese(key),this_player()->query("spells/"+key+"/level"),ctime(time())));
	}
	return 1;
}

int delete_spell(string key)
{
	return this_player()->delete("spells/"+key);
}
