// Room: /u/d/dhk/questsfan/rm10
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "" + HIY + "日日" + HIG + "甘霖" + NOR + "");
  set ("long", @LONG
這兒是一座樹種繁雜，高大的樹林。但是這座樹林最大的特色
確是沒有一刻停止的小雨，所以這座樹林的別稱就叫〝日日甘霖〞
。傳說這兒日日不停的雨是因為雨神有一次在此地休息，因為太熱
所以讓此地下一場小雨，但是他休息完卻匆匆離去，竟沒有讓這場
雨停止。所以從此這裡的雨便沒停過。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "westup" : __DIR__"rm19",
  "east" : __DIR__"rm11",
  "southdown" : __DIR__"rm10",
  "westdown" : __DIR__"rm17",
  "northup" : __DIR__"rm12",
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
  if(who->query_temp("run")!=3 && who->query_temp("run")==2)
  {
   tell_object(who,"" + WHT + "這道黑色的人影又快速往西邊山下離去，身形雖快卻似曾相識。" + NOR + "\n");
   who->set_temp("run",3);
   remove_call_out("dhk");
  }
}

