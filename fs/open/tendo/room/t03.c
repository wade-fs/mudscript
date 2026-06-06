// Room: /open/tendo/room/t03.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("light_up",1);
	 set("short", MAG + "紫  玄  道  觀" + NOR);
set("long", @LONG

                                 __      __   ___         
           ∠¯¯¯¯¯ ◢     ∠◢    ╴◣＼∕◢         
           ▓▓   ◢▓▓◤     ▓◤  ∠╴       ◢        
                ◢◤      _____    __▓◤   ◢▓◤        
     ∠¯¯¯    ¯¯¯◢﹨  ◢  ／  ▄▄▄  ◢           
     ▓▓◤    ▓▓▓▓◤／◢◤／  ▄▄▄  ◢◤           
       ／      ＼      ／◢◤∠          ◢◤             
     ∠  ◢ ◣  ◢   ∠   ◣ ▓▓▓▓▓▓◤               
     ▓▓◤ ◥▓◤   ▓◣__________________◢             
                                                          
上頭有著一塊匾額題著紫玄道觀四個字，這兒的主人似乎偏好紫色。
前面大廳中坐著一位身著紫色道袍的道長，想必是這裡的主人。

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"t02",
"north" : __DIR__"start",
  "out" : "/open/tendo/kunlun/g1",
  "east" : __DIR__"t04",
]));
set("light_up", 1);
	setup();
}
