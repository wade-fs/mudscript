// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
int transmit2();
void create () {
        set("short","山神廟");
		set("long", @LONG
這裡供奉著附近部落所崇拜的山神，一直是村民們的信仰中心，由於生活
實在太過困苦，村民供奉了許多供品給山神，但寺廟本身卻因為缺乏修繕
而千瘡百孔，神像前有一座神壇(altar)，你感到此地靈氣極盛。
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"mount04",		
      ]));
	    set("item_desc", ([
        "altar" : "這是用來供奉(enshrine)物資給山神的聖壇.
",]));

        setup();
}

void init()
{
        add_action("do_enshrine","enshrine");
}

int do_enshrine(string str)
{
  object me = this_player();
  int k = me->query_temp("ask-break-sun");
  if(!me || !k || k<15) return 0;
  
  if(str && str == "original stone")
  {
   if(!present("original stone",me))
   {
    write("你身上沒有這個東西唷!!\n");
	return 1;
   }  
   if(k > 15)
   {
    write("神壇已無位置容納你的供品了!!\n");
	return 1;
   }
   else {
   write("你將原石供奉給山神，原石開始緩慢的吸收著靈氣。\n");
   write("你不禁嘆息：若真等個十甲子，莫說村子裡的人，連我們那個時代都要被這十個太陽折磨。\n\n");
   message_vision(HIY"突然，$N腦袋裡閃過一絲靈光！\n"NOR,me);
   destruct(present("original stone",me));
   me->set_temp("ask-break-sun",16);
       }
  }
  else write("你想在這裡幹什麼!?\n");
  return 1;
}
