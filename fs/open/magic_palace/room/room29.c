inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-玄幽神殿");
set("long",@LONG
這裡是魔宮裡的中樞之地，然而卻有許多扇門陳列在四周，你感到
每扇門後都隱藏著異常強大的殺意及妖氣，似乎警告來人此地不宜久留
，但若欲深入魔宮內部，非擇一而行不可。牆上刻有幾道文字(words)。
文字縫隙似乎可以放進(put)些什麼東西...

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "words" : "
              龍魂西逝  魔神現
              
              青蛇東昇  正氣燃
                          
              千年妖心  英雄浩氣
              
              鬥心不滅  魔道歸一
            ",
]));

        set("no_auc", 1);
        set("no_fight", 1);
        set("no_plan", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "out"   : __DIR__"room28",
        ]));
        setup();
}


void init()
{
add_action("do_put","put");
}

int do_put(string arg)
{
        object me,obj;
        obj = this_object();
        me = this_player();
        if(!arg)
            {
                message_vision("要放什麼東西在哪邊!?",me);
                return 1;
            }
        if(obj->query_temp("open_snake") && arg == "snake amulet")
            {
              message_vision("神殿已得到青蛇祝福了。",me);
              return 1;
            }
        if(obj->query_temp("open_dragon") && (arg == "mdragon-ring" || arg == "fire-dragon ring" ))
            {
              message_vision("神殿已得到龍炎鬥氣了。",me);	
              return 1;
            }
        if(obj->query_temp("open_heart") && arg == "ghost heart")
            {
              message_vision("神殿已得到千年妖魂了。",me);
              return 1;
            }
        if(me->query_temp("sac_snake") && (arg == "mdragon-ring" || arg == "fire-dragon ring" || arg == "ghost heart"))
            {
              message_vision("一人只能奉獻一樣喔!!",me);
              return 1;
            }
        if(me->query_temp("sac_dragon") && (arg == "snake amulet" || arg == "ghost heart"))
            {
              message_vision("一人只能奉獻一樣喔!!",me);
              return 1;
            }
        if(me->query_temp("sac_heart") && (arg == "mdragon-ring" || arg == "fire-dragon ring" || arg == "snake amulet"))
            {
              message_vision("一人只能奉獻一樣喔!!",me);
              return 1;
            }
  /*      if(arg != "snake amulet" || arg != "mdragon-ring" || arg != "fire-dragon ring" || arg != "ghost heart")
            {
                message_vision("隨便亂擺\是想找死嗎!?",me);
                return 1;
            }*/
        if( arg == "snake amulet" && !obj->query_temp("open_snake") && present("snake amulet",me))
            {
                message_vision(HIC"$N將"HIG"青蛇護符"HIC"嵌入文字凹槽中，突然東方青光大盛，一道巨門緩緩開啟了。"NOR,me);
                me->set_temp("sac_snake",1);
                obj->set_temp("open_snake",1);
                destruct(present("snake amulet",me));
                set("exits/east",__DIR__"room31");
                return 1;
            }
        if( arg == "mdragon-ring" && present("mdragon-ring",me) && !obj->query_temp("open_dragon") )
            {
                message_vision(HIM"$N將"HIB"魔龍睛戒"HIM"嵌入文字凹槽中，突然西方紫光大盛，一道巨門緩緩開啟了。"NOR,me);
                me->set_temp("sac_dragon",1);
                obj->set_temp("open_dragon",1);
                destruct(present("mdragon-ring",me));
                set("exits/west",__DIR__"room32");
                return 1;
            }
        if( arg == "fire-dragon ring" && present("fire-dragon ring",me) && !obj->query_temp("open_dragon") )
            {
                message_vision(HIM"$N將"HIR"火龍之鱗"HIM"嵌入文字凹槽中，突然西方紫光大盛，一道巨門緩緩開啟了。"NOR,me);
                me->set_temp("sac_dragon",1);
                obj->set_temp("open_dragon",1);
                destruct(present("fire-dragon ring",me));
                set("exits/west",__DIR__"room32");
                return 1;
            }
        if( arg == "ghost heart" && present("ghost heart",me) && !obj->query_temp("open_heart") )
            {
                message_vision(HIW"$N將"HIY"妖幻之心"HIW"嵌入文字凹槽中，突然北方白光大盛，一道巨門緩緩開啟了。"NOR,me);
                me->set_temp("sac_heart",1);
                obj->set_temp("open_heart",1);
                destruct(present("ghost heart",me));
                set("exits/north",__DIR__"room30");
                return 1;
            }
return 1;

}

int valid_leave(object me,string dir)
{
        if( dir == "east" )
        {
        	if(!me->query_temp("sac_snake"))  return notify_fail("青蛇祝福不是你奉獻的，請回吧!!");
                message_vision("$N一走過門檻，大門立刻關上。\n",me);
                delete("exits/east");
        }
        if( dir == "west" )
        {
        	if(!me->query_temp("sac_dragon"))  return notify_fail("龍炎鬥氣不是你奉獻的，請回吧!!");
                message_vision("$N一走過門檻，大門立刻關上。\n",me);
                delete("exits/west");
        }
        if( dir == "north" )
        {
        	if(!me->query_temp("sac_heart"))  return notify_fail("千年妖魂不是你奉獻的，請回吧!!");
                message_vision("$N一走過門檻，大門立刻關上。\n",me);
                delete("exits/north");
        }
return 1;
}
