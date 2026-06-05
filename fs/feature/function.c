#include <ansi.h>
int set_function(string key,int lv)
{
	this_player()->set("functions/"+key+"/level",lv);
	return 1;
}
int query_function(string key)
{
    if(this_player())
	return this_player()->query("functions/"+key+"/level");
    else
    return 0;
}
int function_improved(string key,int point)
{
    string id,file;
    if(!this_player()) return 0;
	this_player()->add("functions/"+key+"/learned",point);
	if(this_player()->query("functions/"+key+"/learned")>=this_player()->query("functions/"+key+"/level")*this_player()->query("functions/"+key+"/level")*10)
	{
		this_player()->add("functions/"+key+"/level",1);
		this_player()->set("functions/"+key+"/learned",0);
		tell_object(this_player(),HIY);
		tell_object(this_player(),"你的"+to_chinese(key)+"功\力更上一層。\n" + NOR);
		//以下加上紀錄function進步時間  以便日後bug查詢  by frequency
                //id = geteuid(this_player());
                if(!(id=this_player()->query("old_id")))
                  id = this_player()->query("id");
                file = sprintf("function/%s/%s", id[0..0], id);
                if(userp(this_player()))
                  log_file(""+file,sprintf("%s 的%s升到 (%d級) 於 %s\n",id,to_chinese(key),this_player()->query("functions/"+key+"/level"),ctime(time())));
                  
	}
	return 1;
}

int delete_function(string key)
{
	return this_player()->delete("functions/"+key);
}
