//open/prayer/room/punch1 

inherit ROOM;
#include <ansi.h>

void create ()
{
  string long;
  set ("short", "聖火教總壇");
  set( "build", 247 );
  set("valid_startroom",1);
  long = "\n"+
"　　這正是武林中傳說的「聖火教總壇」，你仰頭一看上方有一塊，用金\n"+
"底紅字的排匾，上頭寫著"+BYEL+HIR+"『聖火教』"+NOR+"，你望了四周看到的是一個寬暢無比\n"+
"及魄力十足的宮殿，僅有四支擎天般的盤龍大柱支橕著，且在紅地毯的兩\n"+
"端有兩個身材魁武的左．右護法，在紅地毯的盡頭，有個人坐在王座上，\n"+
"給人一種皇者般的壓力，給人一種不寒而慄的感覺。\n\n";
  set("long", long);
  set("objects", ([ /* sizeof() == 3 */
  "/open/prayer/npc/left1" : 1,        	//護法
  "/open/prayer/npc/right1" : 1,		//護法
  "/open/prayer/npc/pope" : 1,          //教主
]));
  set("exits", ([ /* sizeof() == 4 */
    "up" : "/open/prayer/room/prayer_talk",
	"south" : "/open/prayer/room/punch1-2",		//大聽
	"east" : "/open/prayer/room/punch1-3",		//副幫主
	"west" : "/open/prayer/room/punch1-4",		//軍師
]));
   set("light_up", 1);

  setup();
}
 
int valid_leave(object me, string dir)
{
if (dir == "up" && me ->query("class") != "prayer")
     return notify_fail(HIY"林宏昇說道:在我聖火教內亂闖,想死嗎..\n"NOR);
     return :: valid_leave(me, dir);
}
