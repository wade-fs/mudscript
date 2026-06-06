#include <ansi.h>
inherit ROOM;

void create ()
{
  seteuid(getuid());
  set ("short", "花園");
  set ("long", @LONG
這裡是天龍寺中的花園,這裡不但栽滿了各式各樣的珍奇花草,
還種植了很多的稀有茶樹,像是"霓裳羽衣、步步生蓮、十八學士"
,這大概也是因為大理的茶花甲於天下,奇怪的是這裡竟然種著一
點都不搭調的竹子。在旁邊好像有一座高塔,過去看看吧。
LONG);

  set("search_desc/竹子",
         "你仔細的找一找，發現竹子的中間隱約有條路的痕跡，應該可以穿(pass)過去!!\n");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"aa51",
  "northwest" : __DIR__"aa54",
  "west" : __DIR__"aa53",
]));
}
void init()
{
    add_action("do_pass","pass");
}
int do_pass(string arg)
{
    object me=this_player();

    if(!arg) return notify_fail("你想要穿過什麼??\n");
    if(arg!="竹子") return notify_fail("你想要穿過什麼??\n");
    message_vision(HIG"$N"HIG"用手撥開竹子，往小徑走去!!\n"NOR,me);
    if(me->query("family/family_name")!="段家"){
      me->move(__DIR__"d0.c");
    }
    else{
      me->move(__DIR__"d1.c");
    }
    return 1;
}
