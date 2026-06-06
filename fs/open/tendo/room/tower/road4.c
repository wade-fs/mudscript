#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "鎖妖塔入口");
  set ("long", @LONG
    這兒是傳說中的「鎖妖塔」，你仰頭算了算，塔高正好八層，塔身漆著像血漬
般的暗紅色，給人一種不寒而慄的感覺。  塔內雜草沒脛，蟲鳴如泣，偶而還夾雜
著一兩聲夜梟悲鳴之聲，和分不清是神嚎? 還是鬼哭的聲音? 塔上鬼影幢幢，忽隱
忽現，顯得格外神秘，陰森，而恐怖 !!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road3",
  "enter" : __DIR__"tower1-1",
]));
  set("outdoors",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="enter" )
        message("system",
 HIW"\n\t武林之中傳來一道消息 : "HIY""+this_player()->name()+""HIW"勇闖"HIR"鎖妖塔"HIW"第一層了 !!\n"NOR,users());
        return ::valid_leave(me, dir);
}



