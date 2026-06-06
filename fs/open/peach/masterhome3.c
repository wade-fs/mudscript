// Room: /u/w/whatup/peach/masterhome3.c

#include <command.h>
#include <mudlib.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "村長家");
	set( "build", 12 );
  set ("long", @LONG
這裡是村長的屋子，屋子裡張燈結綵，喜氣洋洋。門口燃放著喜
慶的鞭炮聲，擺設著各式各樣桃花村特有的擺飾與美食，與看熱鬧的
村民分享喜悅。你充分感受到婚禮快樂的氣氛，有別於之前憂傷的氣
氛，且一改看似簡陋的模樣，大有一展氣派恢弘的氣勢。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"master.c",
]));

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/sheik2" : 1,
  __DIR__"npc/man2" : 1,
  __DIR__"npc/daughter2" : 1,
]));

  setup();
}
