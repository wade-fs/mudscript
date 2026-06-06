#include <ansi.h>
inherit ITEM;
int do_temp(object);
int dec_kee(object);
int do_set(object);
int do_delete_temp(object);
string ud;
object obj,room;
int utime,inf;

void create() {
        set_name("魔石雕像",({"evil stone" , "stone", "evil"}));
        set("no_get",1);
        set("no_sac",1);
        set("chat_chance",15);
        set("chat_msg",({

            HIB + "陣陣透骨刺寒的陰風吹過～～\n" + NOR,
      }));
        setup();
 }

void init()
{
	utime=uptime();
	obj = this_player();
	room = environment(this_object());
	ud = geteuid(obj);//改用euid，因為badman可以變換id

	if(!room->query("no_clean_up"))
	room->set("no_clean_up",1);

//  先mark這個比對時間，發現比對時間會造成某種錯誤，造成可以重覆呼叫mob
//	if(!room->query_temp("ud"))//沒有比對的時間，設定比對時間
//	{
//	room->set_temp("ud",utime);
//	}else{
//	  if( utime - room->query_temp("ud") >= 3600)//超過一小時，重設
//	  room->set_temp("ud",utime);
//	}

	if(interactive(obj))
	{
	  if(!room->query_temp(ud)) //如果沒有該玩家名字，叫mob
	  {
	  room->set_temp(ud,utime);//在房間設上玩家來過的記號，並呼叫mob
	  do_set(obj);
	  dec_kee(obj);
	  }else{//已經有了，判斷是否大於一小時，大於一小時則重設並呼叫mob
           if( utime - room->query_temp(ud) > 300)
	    {
	    room->set_temp(ud,utime);
	    do_set(obj);
	    dec_kee(obj);
	    }
	  }
	}
}

int dec_kee(object obj)
{
	obj = this_player();
        obj->add("gin",-150);
        obj->add("kee",-250);
        obj->add("sen",-150);
        return 1;
}

int do_set(object obj)
{
        object mob;
	obj=this_player();
        if(obj->query("race") == "野獸") return 1;
        if(obj->query("max_force") < 500 &&
           obj->query("combat_exp") < 250000) return 1;
        switch(random(4)+1)
        {
           case 1  : mob=new("/open/mogi/forest/npc/mob1");
                     mob->move(environment(obj));
                     break;
           case 2  : mob=new("/open/mogi/forest/npc/mob2");
                     mob->move(environment(obj));
                     break;
           case 3  : mob=new("/open/mogi/forest/npc/mob3");
                     mob->move(environment(obj));
                     break;
           case 4  : mob=new("/open/mogi/forest/npc/mob4");
                     mob->move(environment(obj));
                     break;
           default : break;
        }
        switch(random(4)+1)
        {
           case 1  : mob=new("/open/mogi/forest/npc/mob1");
                     mob->move(environment(obj));
                     break;
           case 2  : mob=new("/open/mogi/forest/npc/mob2");
                     mob->move(environment(obj));
                     break;
           case 3  : mob=new("/open/mogi/forest/npc/mob3");
                     mob->move(environment(obj));
                     break;
           case 4  : mob=new("/open/mogi/forest/npc/mob4");
                     mob->move(environment(obj));
                     break;
           default : break;
        }

        return 1;
}
