// Room: /open/bonze/room/k06
// 增加少林廚藝學院的quest相關
// 兩種方式 非少林 需取得許可 少林則可直接通過 2010/09/06 by blazakira

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "少林寺伙房入口");
  set ("long", @LONG
再往前走就是少林寺的伙房入口了，你看到數個師父已經開始在作
菜了，對於前來的師父，也非常熱心的招待他們。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"k01",
  "west" : __DIR__"s65",
]));
  set("no_magic", 1);
  set("no_fight", 1);
  set("light_up", 1);

  setup();
}

int valid_leave(object who, string dir)
{ //往東 且 非和尚 且 沒有通行許可 所以禁止進入 因此只要一個不符合條件即可通過東方
  //通行許可為set_temp("quests/bonze/food_pass") 因為"quests/bonze/food" 作為收集食材完畢時 快速刪除的群組
  if(dir == "east" && who->query("class") != "bonze" && !who->query_temp("quests/bonze/food_pass") )
  {
    return notify_fail("沒有經過" + HIY + "【許\可】" + NOR + "，不要隨便進人家的伙房。\n"); //天呀 括號括起來 這麼明顯的提示 還要問 我補顏色....orz by blazakira
  }
  return 1;
}
