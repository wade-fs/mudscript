#include <ansi.h>

inherit NPC;

void do_patrol();
void create()
{ 
	set_name("小泥巴星球",({"server","Sserver"}));
  set("age",2);
  set("long","泥巴星球的小囉囉,屬於欺惡怕善型,專們對付利用bug頻頻來此的玩家\n");
  set("title","天界守護者");
  set("no_kill",1);
  set("combat_exp",1000000); 
  set("chat_chance",25);
  set("chat_msg", ({
  (: do_patrol :)
  }));
  setup();
}


void init() {
object obj;
::init();
        if(interactive(obj=this_player())) {
	   if(userp(obj)&&!wizardp(obj)) {
	      if(obj->query_temp("gowiz")) {
		if(obj->query("gowiz")) {
		   command("say 看樣子你似乎不怕死嘛!!..來這麼多次");
		obj->save();
		   obj->die();
		   return;		
		}
		seteuid(ROOT_UID);
		command("say 說不能來了還來....明知故犯!!找死！！");
		message_vision("$N二話不說,將$n踢出了這個世界!!\n",this_object(),obj);
		obj->set("gowiz",1);
		destruct(obj);
		return;
	      } else {
		command("say 這裡是禁止玩家參觀的,不要再來了。");
		message_vision ("$N伸手一招,將$n送離了此處。\n",this_object(),obj);
		obj->set_temp("gowiz",1);
		obj->move("/open/common/room/inn");
                obj->set("startroom","/open/common/room/inn");
		return;
	      }	 
	  }
      
        }

return;
}

void do_patrol()
{
  if( random(2) == 1)
	command("go west");
  else
	command("go east");
  return;
}


