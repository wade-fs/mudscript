#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC + "(斷裂)死靈骨魔爪牙" + NOR,({"ghost-king-tooth"}));
        set_weight(100);
        set("long","這是當年死靈骨魔與焚天魔王練武時，不小心被焚天魔王打斷的牙齒，由於牙齒內含有極火功\與冥魔妖氣\n兩種渾然不同的絕世內勁，所以對於冥魔戰甲具有特殊的融合強化(enrich)效果。\n");
        set("unit","個");
        set("value",100);
setup();
}

void init()
{
add_action("do_enrich","enrich");
}

int do_enrich()
{
object me,obj;

        me = this_player();
        if( present("ghost-box",me))
	    {
          message_vision("$N你已經有了冥魔寶盒，還想幹麻？！\n",me);
          return 0;
		}
if(!(me->query_temp("ko_ghost_king")))
      {
        message_vision("冥魔戰甲只幫助實力在死靈骨魔之上的人的人。\n",me);
        return 0;
      }
        if( !present("ghost-king-helmet",me) || !present("ghost-king-armor",me) || !present("ghost-king-belt",me) 
		    || !present("ghost-king-boots",me) || !present("ghost-king-cloak",me) || !present("ghost-king-gem",me) 
			|| !present("ghost-king-gloves",me) || !present("ghost-king-armband",me) || !present("ghost-king-leggings",me) 
			|| !present("ghost-king-shield",me) || !present("ghost-king-ring",me) || !present("ghost-king-pants",me) )
	    {
          message_vision("$N發覺似乎還少了什麼元素，" + HIC + "(斷裂)死靈骨魔爪牙" + NOR + "一動也沒動。\n",me);
          return 0;
	    }else{
        message_vision(CYN + "" + BBLU + "$N讓自己的意識墮入黑暗深淵，誠心祈求邪靈庇護，(斷裂)死靈骨魔爪牙幻化成一只冥魔寶盒。\n" + NOR,me);
        log_file("open-area/get_ghostbox", sprintf("%s(%s)得到冥魔寶盒於 %s\n",me->query("name"),me->query("id"), ctime(time())));
        obj = new("/autoload/ghost-eq/ghost-save-box");
        obj->move(me);
        destruct(present("ghost-king-helmet",me));
        destruct(present("ghost-king-armor",me));
        destruct(present("ghost-king-belt",me));
		destruct(present("ghost-king-boots",me));
		destruct(present("ghost-king-cloak",me));
		destruct(present("ghost-king-gem",me));
		destruct(present("ghost-king-gloves",me));
		destruct(present("ghost-king-armband",me));
		destruct(present("ghost-king-leggings",me));
		destruct(present("ghost-king-shield",me));
		destruct(present("ghost-king-ring",me));
		destruct(present("ghost-king-pants",me));
		destruct(present("ghost-king-tooth",me));
        return 1;
		}
}
