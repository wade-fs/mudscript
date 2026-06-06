// Room: /u/d/dhk/questsfan/rm25
inherit ROOM;
#include <ansi.h>
#include "/open/open.h"
void create ()
{
  set ("short", "" + HIY + "望" + HIC + "星" + WHT + "坪" + NOR + "");
  set ("long", @LONG
穿過潮濕的〝日日甘霖〞來到一處高地，名曰『望星坪』。因為
每當月兔西升時，這裡就成了最佳觀星賞月地。當我們向東南方向望
過去時發現，那片山壁被人用利器在那片廣大平滑的山壁上題了數個
大字。～『名山之世，世間仙境，境冠群嶽』～

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rm11",
]));

        set("objects", ([ /* sizeof() == 1 */
        "/open/beggar/npc/visitor" : 1,
                ]));

  set("outdoors", "/u/d");

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=1 && who->query_temp("mime")==1)
    {
     tell_object(who,"\n" + WHT + "忽然一道黑色的人影快速往西邊離去，身形之快匪夷所思。" + NOR + "\n");
       who->set_temp("run",1);
     remove_call_out("dhk");
    }
}

