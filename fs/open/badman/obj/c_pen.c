// c_pen.c by powell

#include "/open/open.h"

inherit COMBINED_ITEM;

void create()
{
	set_name("炭筆",({"pen"}));
	set("long","一支由樹枝燒製而成的碳筆, 可用來到處塗鴉 (write)。\n");
 	set("unit","支");
	set("base_unit","支");
	set("value", 10000);
 	set("base_weight", 45);
	set_amount(1);
	setup();
}
void init()
{
	add_action("do_write","write");
}
int do_write(string arg)
{
	object ob=environment(this_player());
	if (arg == 0 ){
	tell_object(this_player(),"炭筆的用法是 -- write xxxxxx \n");
	return 1;
	}
	if (ob->query("can_write") != 1){
	tell_object(this_player(),"喂!!  你以為這裡是哪兒啊??\n"+
	                          "隨便到處亂塗鴉會被圍毆喔..\n");
	return 1;
	}
        if (ob->query("word")){
        message_vision("$N吐了一些口水在手掌上, 將牆上原有的字跡抹去...\n\n",this_player() );
        
//  以下是要給任務用的, 可是任務還沒寫好  :P        
/*      if (this_player()->query_temp("") <   ){
       	tell_object(this_player(),"你突然發覺牆角有一行小字(words)..\n");
        this_player()->set_temp("", );
        }
*/         
        } 
        message_vision("$N在牆上寫上 :\n"+arg+"\n\n",this_player());
	ob ->set("word",arg);
	ob ->set("writer",this_player()->query("name"));
	tell_object(this_player(),"啊..這筆的品質可真是@#$%\n"+
				  "用沒兩下就不能用了, 你隨手便把筆丟了..\n");
	add_amount(-1);
	return 1;
}
