// Room: /u/w/whatup/peach/well
inherit ROOM;
#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "水井底下");
  set ("long", @LONG
原來水井底部還別有洞天，雖然陰暗潮濕，但前方卻傳來亮光，
讓人不禁興奮的向前行走，終於找到一個盒子 (box)，發出淡淡的幽
光，盒子上有個鎖。
LONG);

  set("exits", ([ /* sizeof() == 1 */
      "south" : __DIR__"well",
  ]));

  create_door ("south", "石牆", "north");
  set("need_key/south", 1);
  set("no_clean_up", 0);
  setup();
}


void init()
{
	add_action("do_look","l");
	add_action("do_look","look");
}

int do_look(string str)
{
	object me = this_player();
	if(str != "box") return 0;
		tell_object( me, "盒子上有一把刻著桃花標誌的鎖。\n");
			if(!present("peach hairpin",me))
			{
				tell_object( me,"你手邊沒有鑰匙可以開！\n");
				return 1;
			}
			
			if (me->query_temp("quests/peach/mark")==12 || me->query_temp("quests/peach/get") == 2)
			{
				tell_object( me, "你看了看手中的髮簪，又摸了摸盒子上的鎖。\n");
				if (me->query("quests/peach")!=1) // 開放前須將此設為固定變數
				{
					tell_object( me, "你順手將髮簪插入，你發現這個鎖竟然這麼輕鬆就開了。\n");
					call_out("do_give",2,me);
				}
				else
				{
					write("盒子中空無一物。\n" + NOR);
				}
				return 1;
			}
			else
			{
				write("你可以看出有人從盒中把東西拿走的痕跡。\n" + NOR);
			}
			return 1;
	return 1;
}

int do_give()
{
	object ob;
	object me = this_player();
				ob = new(__DIR__"npc/kill_pill.c");
				ob->set_amount(3);
				ob->move(me);
				write("你從盒子中取出三粒" + HIM + "醃漬桃子" + NOR);
        ob = new(__DIR__"npc/kee_pill.c");
        ob->move(me);
        write("\n你從盒子中取出一粒" + HIM + ob->name() + "\n" + NOR);
/*				write("你從盒子中取出三粒"+HIR + "生生造化丹\n" + NOR);*/
				me->set("quests/peach",1); // 開放前須將此設為固定變數
				me->delete_temp("quests/peach");
				me->delete("quest/peach");
				destruct(present("peach hairpin",me));
				write("拿完之後，你將手中的髮簪順手丟到暗處。\n");
				return 1;
}

// 每次 reborn 就會呼叫一次這個函數
void reset()
{
	::reset();
}
