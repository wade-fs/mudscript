// Room: /u/p/poloer/dragon/g4

// acky 寫得小敷衍，我修改了一下幾個錯的地方，要加油。
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>

void create ()
{
  set ("short", "魔王殿一樓");
  set ("long", @LONG
這裡是魔王殿的一樓，裡面一片烏黑黑的，伸手不見五指，怪恐怖
的。不時還傳來怪物的叫聲。

    ～嘿～嘿～

LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"g5",
  "east" : __DIR__"g3",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

void init()
{
  call_out ("do_damage", 1, this_player());
}

void do_damage (object ob)
{
  mixed all;
  object obj;
  int kee, i;

  all= all_inventory(environment(ob));
  for (i=0; i<sizeof(all); i++) {
    obj= all[i];
    kee= obj->query("eff_kee");
    if (random(300) > obj->query_skill("dodge")) {
      message_vision (HIR + "突然間～谷主用千里奪命手向$N伸去，$N閃躲不及，只聽一聲哀嚎$N已被吸去精力！\n" + NOR, obj);
      obj->add("kee", -kee/10);
    }
    else
      message_vision (HIW + "突然間～谷主用千里奪命手向$N伸去，但$N不慌不忙地閃過。\n" + NOR, obj);
  }
}  
