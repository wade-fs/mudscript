inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","斷陽峰");
	set( "build", 1 );
set("long",@LONG
攀上高聳的山峰之後，你赫然發現，剛剛所見的三個太陽赫然就在
眼前，周圍的土地呈現焦炭般的色澤，可說是個寸草不生，萬物俱滅之
地，然而此地已無適才的驚天魔氣，不禁令人納悶是否已走出魔宮了。

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "sun" : "

三輪炙熱異常的太陽，似乎要吞沒什麼東西似的...

            ",
]));

        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "down"   : __DIR__"room39",
        ]));
        setup();
}


void init()
{
add_action("do_throw","throw");
}

int do_throw(string arg)
{
        object me,obj,ob;
        obj = this_object();
        me = this_player();
        ob = new("/autoload/open-area/super_hands.c");
        if(!arg)
            {
                message_vision("不要隨便亂丟垃圾!!",me);
            }else{
   if(me->query_temp("can_throw"))
   {
    if(arg == "new_hero book to sun" && present("New_Hero Book",me))
    {
     message_vision(HIR + "$N猛力一擲，將" + HIC + "英雄新經" + HIR + "投向火紅的烈日中。\n\n" + NOR,me);
     destruct(present("New_Hero Book",me));
     obj->set_temp("get_new",1);
    }
    if(arg == "real_hero book to sun" && present("Real_Hero Book",me))
    {
     message_vision(HIR + "$N猛力一擲，將" + HIC + "英雄真經" + HIR + "投向火紅的烈日中。\n\n" + NOR,me);
     destruct(present("Real_Hero Book",me));
     obj->set_temp("get_real",1);
    }
    if(arg == "gold_magic book to sun" && present("Gold_Magic Book",me))
    {
     message_vision(HIR + "$N猛力一擲，將" + HIY + "魔界金典" + HIR + "投向火紅的烈日中。\n\n" + NOR,me);
     destruct(present("Gold_Magic Book",me));
     obj->set_temp("get_magic",1);
    }
    if(obj->query_temp("get_new") && obj->query_temp("get_real") && obj->query_temp("get_magic"))
    {
tell_object(users(),HIM + "\n\n
魔宮上空的三個太陽開始慢慢靠近，最後竟然合併為一。
\n\n" + NOR);
     if(!present( "xstrike-hands",me))
     {
message_vision(HIR + "
     
同時一件不凡的神器掉落於$N手中。


     " + HIW + "$N得到了" + CYN + "『" + RED + "皆傳之證" + CYN + "』\n\n" + NOR,me);
     ob->move(me);
     write_file("/log/magic_palace/get_hands",sprintf("%s(%s) 得到皆傳之證於 %s\n",me->name(1),me->query("id"),ctime(time())));
     }
      else
          {
            message_vision(HIG + "$N身上的" + RED + "皆傳之證" + HIG + "和陽光相互輝映，形成一股力量流入體內，因而增加了$N的替身上限。\n\n" + NOR,me);
            me->add("t_standby",1);
            me->add("standby",1);
            write_file("/log/magic_palace/get_standby",sprintf("%s(%s) 增加最大替身於 %s\n",me->name(1),me->query("id"),ctime(time())));
          }
     obj->delete_temp("get_new");
     obj->delete_temp("get_real");
     obj->delete_temp("get_magic");
     me->delete_temp("kill_hero");
     me->delete_temp("ask_sword");
     me->delete_temp("know_sword");
     me->delete_temp("ask_blade");
     me->delete_temp("know_blade");
     me->delete_temp("ask_fist");
     me->delete_temp("know_fist");
     me->delete_temp("ask_force");
     me->delete_temp("know_force");
     me->delete_temp("ask_steps");
     me->delete_temp("know_steps");
     me->set("startroom","/open/common/room/inn");
     call_out("do_home",1,me);
    }
   }else{
     message_vision(HIR + "$N應該不知道要丟什麼吧!?\n" + NOR,me);
        }
        
                }

return 1;

}

void do_home()
{
        int i;	
	object *ppl,me;
	me = this_player();
	ppl = all_inventory( environment(me) );
	tell_object(users(),HIW + "\n\n   
	
" + HIR + "烈日射下一道神光，將魔森林完全壟罩，


           天下妖邪之源的魔宮終於再度被封印了起來。

              \n\n" + NOR);
       for( i=0; i<sizeof(ppl); i++ )
       {
        ppl[i]->move("/open/common/room/inn");
       }
}
